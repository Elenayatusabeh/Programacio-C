#include <stdlib.h>
#include <stdio.h>
/*
6.	Algorisme que llegeix una seqüència de 10 números i ens diu quants són positius, quants són negatius i quants són zero.
*/
int main(void)
   {
       int n, con, pos, neg, zero;
        con=0;
        neg=0;
        pos=0;
        zero=0;
       while(con<10){
    printf("\nIntrodueix un numero:\n");
      scanf("%d",&n);
      if(n>0){
            pos++;
             }
      else{
        if(n==0){
            zero++;
                }
        else{
            neg++;
            }
          }
       con++;
        }
    printf("Els Positius:%d \nEls Negatius:%d\nEls Zeros:%d\n",pos,neg,zero);
return 0;

   }
