#include <stdio.h>
#include <stdlib.h>

int main (void){

    int n1, n2, res;
    char o;

    printf("Introdueix l'operador ");
    scanf("%c",&o);
    printf("Introdueix dos nombres enters ");
    scanf("%d %d",&n1, &n2);

    if((o=='/' && n2==0)||(o=='%' && n2==0)){
        printf("Error, el resultat donaria infinit");
    }
    else{
        switch(o){
            case'+':
            res=n1+n2;
                printf("El resultat es %d",res);
            break;

            case'-':
            res=n1-n2;
                printf("El resultat es %d",res);
            break;

            case'*':
            res=n1*n2;
                printf("El resultat es %d",res);
            break;

            case'/':
            res=n1/n2;
                printf("El resultat es %d",res);
            break;

            case'%':
            res=n1%n2;
                printf("El resultat es %d",res);
            break;

            default:
                printf("Operador incorrecte");
            break;
        }
    }
}
