
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


/*Programa que generi el sorteig d'un número entre el 0 i el 10. Després ens demana
  quin número ha sortit fins que ho encertem.*/


int main(void)
{
    int  num, ran;

    srand(time(NULL));

    ran=rand()%11;
    num=-1;
    while(num!=ran){
        printf("\nTria un numero del 0 al 10 ");
        scanf("%d",&num);
        while(!(num>=0 && num<=10)){
            printf("\nHa de ser un numero entre 0 i 10");
            printf("\nTria un numero del 0 al 10 ");
            fflush(stdin);
            scanf("%d",&num);
        }
        if(num!=ran){
            printf("\nNo has adivinat el numero");
        }
    }
    printf("\nHas adivinat el numero");

}
