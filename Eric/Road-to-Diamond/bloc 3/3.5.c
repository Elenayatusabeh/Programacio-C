#include <stdlib.h>
#include <stdio.h>
#include <time.h>


/*5.	Un programa fa el sorteig d'un n�mero entre 1 i 1000. Despr�s ens demana per
 un n�mero fins que ho encertem. Per facilitar la recerca dona una pista cada vegada
 que consisteix en dir a l'usuari si el n�mero entrat �s major o menor que el sortejat.*/


int main(void)
{
    int num, ran;

    srand(time(NULL));

    ran=rand()%1000+1;


    while(num!=ran){
        printf("\nTria un numero ");
		scanf("%d",&num);
        if(num>ran){
			printf("\nEl numero es menor a %d",num);
		}
		else if(num<ran){
			printf("\nEl numero es major a %d",num);
		}
    }
	printf("Has encertat el numero");
}
