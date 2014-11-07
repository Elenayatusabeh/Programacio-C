#include <stdlib.h>
#include <stdio.h>
#include <time.h>


/*5.	Un programa fa el sorteig d'un n�mero entre 1 i 1000. Despr�s ens demana per
 un n�mero fins que ho encertem. Per facilitar la recerca dona una pista cada vegada
 que consisteix en dir a l'usuari si el n�mero entrat �s major o menor que el sortejat.
 6.Millora el programa anterior de manera que al final ens informi de quantes vegades hem fet per encertar el n�mero.*/


int main(void)
{
    int num, ran, n;

    srand(time(NULL));

    ran=rand()%1000+1;

    n=1;

    while(num!=ran){
        printf("\nTria un numero ");
		scanf("%d",&num);
		n++;
        if(num>ran){
			printf("\nEl numero es menor a %d\n",num);
		}
		else if(num<ran){
			printf("\nEl numero es major a %d",num);
		}
    }
	printf("Has encertat el numero\n");
	printf("Has necessitat %d intents\n",n);
}
