
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


/*Programa que generi el sorteig d'un número entre el 0 i el 10. Després ens demana
  quin número ha sortit fins que ho encertem. Millora el programa anterior de manera
  que ens digui quantes vegades hem fet per encertar el número.*/


int main(void)
{
    int  num, ran, fail=0
    ;

    srand(time(NULL));

    ran=rand()%11;

    while(num!=ran){
        printf("Tria un numero del 0 al 10\n");
        scanf("%d",&num);

        if(num!=ran){
            printf("No has adivinat el numero\n");
            fail++;
        }
    }
    printf("Has adivinat el numero\n");
    printf("Has fallat %d vegades\n", fail);


}
