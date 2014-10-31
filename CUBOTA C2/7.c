
#include <stdlib.h>
#include <stdio.h>
/*
7.	Algorisme que llegeix una seqüència de números enters fins a llegir un zero. Llavors ens diu quin és el número més gran.
8.	Algorisme que llegeix un número enter positiu i ens calcula el factorial (N!).
9.	Algorisme que llegeix dos números enters positius i ens dóna el producte mitjançant sumes successives.
10.	Algorisme que llegeix un número enter X i un altre número enter n i ens calcula l’N-èsima potencia de X.
11.	Algorisme que llegeix un número enter N i ens diu la llista de números que són divisors d’aquest.
12.	Algorisme que llegeix una seqüència de 10 números per teclat i en acabar ens diu el més gran, el més petit i la mitjana aritmètica de tots ells.
13.	Algorisme que llegeix una seqüència de notes entre 0 i 10. La seqüència s’acaba amb el -1. En acabar ens mostra: la mitjana aritmètica de totes les notes introduïdes, quants han tret excel•lent, quants notable, quants bé, quants suficient, quants insuficient i quants molt deficient.
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
