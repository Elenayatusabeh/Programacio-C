#include <stdlib.h>
#include <stdio.h>
/*
8.	Algorisme que llegeix un n�mero enter positiu i ens calcula el factorial (N!).
9.	Algorisme que llegeix dos n�meros enters positius i ens d�na el producte mitjan�ant sumes successives.
10.	Algorisme que llegeix un n�mero enter X i un altre n�mero enter n i ens calcula l�N-�sima potencia de X.
11.	Algorisme que llegeix un n�mero enter N i ens diu la llista de n�meros que s�n divisors d�aquest.
12.	Algorisme que llegeix una seq��ncia de 10 n�meros per teclat i en acabar ens diu el m�s gran, el m�s petit i la mitjana aritm�tica de tots ells.
13.	Algorisme que llegeix una seq��ncia de notes entre 0 i 10. La seq��ncia s�acaba amb el -1. En acabar ens mostra: la mitjana aritm�tica de totes les notes introdu�des, quants han tret excel�lent, quants notable, quants b�, quants suficient, quants insuficient i quants molt deficient.
*/
int main(void)
   {
       int n, x, y;
       printf("Introdueix un numero enter positiu:");
       scanf("%d",&n);
       if(n>0)
       {
           x=1;
           y=1;
           while(x<=n)
           {
              y=y*x;
              x++;
           }
           printf("\nEl factorial de %d es: %d.\n",n,y);
       }
       else
       {
           printf("El nombre ha de ser m�s gran que 0.");
       }

return 0;

   }
