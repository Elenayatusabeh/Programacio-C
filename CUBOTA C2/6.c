#include <stdlib.h>
#include <stdio.h>
/*
6.	Algorisme que llegeix una seq��ncia de 10 n�meros i ens diu quants s�n positius, quants s�n negatius i quants s�n zero.
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
