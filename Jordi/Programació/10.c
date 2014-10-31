#include <stdlib.h>
#include <stdio.h>
/*
9.	Algorisme que llegeix dos n�meros enters positius i ens d�na el producte mitjan�ant sumes successives.
10.	Algorisme que llegeix un n�mero enter X i un altre n�mero enter n i ens calcula l�N-�sima potencia de X.
11.	Algorisme que llegeix un n�mero enter N i ens diu la llista de n�meros que s�n divisors d�aquest.
12.	Algorisme que llegeix una seq��ncia de 10 n�meros per teclat i en acabar ens diu el m�s gran, el m�s petit i la mitjana aritm�tica de tots ells.
13.	Algorisme que llegeix una seq��ncia de notes entre 0 i 10. La seq��ncia s�acaba amb el -1. En acabar ens mostra: la mitjana aritm�tica de totes les notes introdu�des, quants han tret excel�lent, quants notable, quants b�, quants suficient, quants insuficient i quants molt deficient.
*/
int main(void)
   {
        int n1, n2, x;
        printf("Introdueix un numero enter positiu:");
        scanf("%d",&n1);
        printf("Introdueix un segon numero enter positiu:");
        scanf("%d",&n2);

        x=n2;

        if(n1>0 && n2>0)
        {
            printf("%d*%d= ",n1,n2);
            while(x>1) //El while acaba un n�mero abans perqu� en el �ltim d�git no es mostri el signe +
            {
               printf("%d+",n1);
               x--;
            }
            printf("%d = %d",n1,n1*n2); //Aqu� es posa l'�ltim n1 i el resultat.
        }
        else
        {
            printf("Has d'introdu�r un nombres enters i positius.");
        }

    return 0;

   }
