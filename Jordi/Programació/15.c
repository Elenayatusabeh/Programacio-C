//15.	Millora de l’exercici anterior per tal que ens digui el número de vegades que llegeix cada vocal.

#include <stdlib.h>
#include <stdio.h>

int main(void)
{
    char x;
    int a=0, e=0, i=0, o=0, u=0;
    printf("Introdueix una sequència de lletres i finalitza-la amb . i enter:\n");
    fflush(stdin);
    while(x!='.')
    {

        scanf("%c",&x);
        switch(x)
        {
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

        }
    }
    printf("\nLa lletra A ha aparegut %d cops.\nLa lletra E ha aparegut %d cops.\nLa lletra I ha aparegut %d cops.\nLa lletra O ha aparegut %d cops.\nLa lletra U ha aparegut %d cops.",a,e,i,o,u);
}
