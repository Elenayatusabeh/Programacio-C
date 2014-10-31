#include <stdio.h>
#include <stdlib.h>
/*Millora de l’exercici anterior per tal que ens digui el número de vegades que llegeix cada vocal.*/

int main (void)
{
    int a, e, i, o, u;
    char c;
    a=0;
    e=0;
    i=0;
    o=0;
    u=0;
    fflush(stdin);
    while(c!='.'){

        scanf("%c",&c);
        switch(c){
            case 'A':
            case 'a':
                a++;
            break;
            case 'E':
            case 'e':
                e++;
            break;
            case 'I':
            case 'i':
                i++;
            break;
            case 'O':
            case 'o':
                o++;
            break;
            case 'U':
            case 'u':
                u++;
            break;
            default:
            break;
        }

    }

    printf("El numero de lletres A es %d\n",a);
    printf("El numero de lletres E es %d\n",e);
    printf("El numero de lletres I es %d\n",i);
    printf("El numero de lletres O es %d\n",o);
    printf("El numero de lletres U es %d\n",u);

}
