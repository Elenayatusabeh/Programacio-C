#include <stdio.h>
#include <stdlib.h>


/*Un programa demana números sencers positius fins que s'escriu el número 32300.
 Després de donar-li cada número el programa ens diu si és parell o senar.*/


int main(void)
{
    int  num;

    num=0;

    while(num!=32300){

        printf("\nIntrodueix un numero positiu ");
        scanf("%d",&num);

        if(num<1){
            printf("Ha de ser positiu");
        }
        else if(num%2==0){
            printf("Es parell");
        }
        else {
            printf("Es senar");
        }
    }


}
