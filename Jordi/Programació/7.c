
#include <stdlib.h>
#include <stdio.h>
/*
7.	Algorisme que llegeix una seq��ncia de n�meros enters fins a llegir un zero. Llavors ens diu quin �s el n�mero m�s gran.
8.	Algorisme que llegeix un n�mero enter positiu i ens calcula el factorial (N!).
9.	Algorisme que llegeix dos n�meros enters positius i ens d�na el producte mitjan�ant sumes successives.
10.	Algorisme que llegeix un n�mero enter X i un altre n�mero enter n i ens calcula l�N-�sima potencia de X.
11.	Algorisme que llegeix un n�mero enter N i ens diu la llista de n�meros que s�n divisors d�aquest.
12.	Algorisme que llegeix una seq��ncia de 10 n�meros per teclat i en acabar ens diu el m�s gran, el m�s petit i la mitjana aritm�tica de tots ells.
13.	Algorisme que llegeix una seq��ncia de notes entre 0 i 10. La seq��ncia s�acaba amb el -1. En acabar ens mostra: la mitjana aritm�tica de totes les notes introdu�des, quants han tret excel�lent, quants notable, quants b�, quants suficient, quants insuficient i quants molt deficient.
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
