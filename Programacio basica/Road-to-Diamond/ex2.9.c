#include <stdio.h>
#include <stdlib.h>
/*Algorisme que llegeix dos n�meros enters positius i ens d�na el producte mitjan�ant sumes successives.*/

int main (void)
{
    int n, y, x;
    printf("Introdueix dos nombres positius ");
    scanf("%d %d",&x,&y);
    if(y<=0 || x<=0){
        printf("Han de ser nombres positius ");
    }
    else{
        n=y;
        printf("%d*%d = ",x,y);
        while(n>1){
            printf("%d+",x);
            n--;

        }
    printf("%d = %d", x, x*y);
    }

}



