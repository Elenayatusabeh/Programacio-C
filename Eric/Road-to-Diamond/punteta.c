#include <stdio.h>
#include <stdlib.h>

int main (void){

    float f;
    int n;

    printf("Introdueix una xifra ");
    scanf("%f",&f);
    f=f*100;
    if(f/50000>=1){
        printf("%.0f bitllets de 500\n",(f/50000));
        printf("%f\n",(f/50000));
        f=f-(50000*(f/50000));
    printf("%f\n",(f/50000));
    }
    if(f/20000>=1){
        printf("%.0f bitllets de 200\n",(f/20000));
        f=f-20000*(f/20000);
    }
    if(n/10000>=1){
        printf("%d bitllets de 100\n",(n/10000));
        n=n-10000*(n/10000);
    }
    if(n/5000>=1){
        printf("%d bitllets de 50\n",(n/5000));
        n=n-5000*(n/5000);
    }
    if(n/2000>=1){
        printf("%d bitllets de 20\n",(n/2000));
        n=n-2000*(n/2000);
    }
    if(n/1000>=1){
        printf("%d bitllets de 10\n",(n/1000));
        n=n-1000*(n/1000);
    }
    if(n/500>=1){
        printf("%d bitllets de 5\n",(n/500));
        n=n-500*(n/500);
    }
    if(n/200>=1){
        printf("%d monedes de 2\n",(n/200));
        n=n-200*(n/200);
    }
    if(n/100>=1){
        printf("%d monedes de 1\n",(n/100));
        n=n-100*(n/100);
    }
    if(n/50>=1){
        printf("%d monedes de 50 centims\n",(n/50));
        n=n-50*(n/50);
    }
    if(n/20>=1){
        printf("%d monedes de 20 centims\n",(n/20));
        n=n-20*(n/20);
    }
    if(n/10>=1){
        printf("%d monedes de 10 centims\n",(n/10));
        n=n-10*(n/10);
    }
    if(n/5>=1){
        printf("%d monedes de 5 centims\n",(n/5));;
        n=n-5*(n/5);
    }
    if(n/2>=1){
        printf("%d monedes de 2 centims\n",(n/2));
        n=n-2*(n/2);
    }
    if(n/1>=1){
        printf("%d monedes de 1 centims\n",(n/1));
    }
}
