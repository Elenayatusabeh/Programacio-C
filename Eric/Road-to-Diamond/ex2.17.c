#include <stdio.h>
#include <stdlib.h>
#define true 1
#define false 0
/*Algorisme que llegeix una seq��ncia de frases (un vers).
El programa acaba quan li diem que no volem introduir m�s frases.
La sortida ens diu per a cada frase quants car�cters t�.
En acabar ens diu quantes frases hem introdu�t.*/

int main (void)
{
    int n, f, x;
    char c, res;
    n=0;
    f=0;
    x=true;

    while(x==true){
        x=false;
        fflush(stdin);
        scanf("%c",&c);
        while(c!='\n'){

            n++;
            scanf("%c",&c);

        }
        printf("\nCaracters = %d\n",n);
        n=0;
        f++;
        fflush(stdin);
        printf("Vols introduir una altre frase?(respon si o no)");
        scanf("%c",&res);
        switch(res){

            case 's':
            case 'S':
            fflush(stdin);
            x=true;
            break;

            case 'n':
            case 'N':
            x=false;
            break;

            default:
            printf("Ha de ser si o no");
            x=false;
        }

    }
    printf("\nFrases = %d\n",f);

}
