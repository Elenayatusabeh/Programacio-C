#include <stdio.h>
#include <stdlib.h>

int main (void){

    float f;
    int n, b, b2, b3;
    b=0;
    b2=0;
    b3=0;
    printf("Introdueix una xifra ");
    scanf("%f",&f);
    printf("Introdueix el billet o moneda mes gran que vols ");
    scanf("%d.%d",&b,&b2);
    if(b2==05 || b2==02 || b2==01){
        b=b*100+b2;

    }
    else{
        b=b*100+b2;
    }


    while(b!=50000 && b!=20000 && b!=10000 && b!=5000 && b!=2000 && b!=1000 && b!=5000 && b!=200 && b!=100 && b!=50 && b!=20 && b!=10 && b!=5 && b!=2 && b!=1){
        printf("\nEl bitllet o moneda es incorrecte");
        printf("Introdueix el billet o moneda mes gran que vols ");
        scanf("%d.%d",&b,&b2,&b3);
        if(b2==05 || b2==02 || b2==01){
            b=b*100+(b2);
        }
        else{
            b=b*100+(b2);

        }
    }
    f=(f+0.00004)*100;
    n=f;

    if(n/50000>=1 && b==50000 ){
        printf("%d bitllets de 500\n",(n/50000));
        n=n-50000*(n/50000);

    }
    if(n/20000>=1 && b>=20000){
        printf("%d bitllets de 200\n",(n/20000));
        n=n-20000*(n/20000);
    }
    if(n/10000>=1 && b>=10000){
        printf("%d bitllets de 100\n",(n/10000));
        n=n-10000*(n/10000);
    }
    if(n/5000>=1 && b>=5000){
        printf("%d bitllets de 50\n",(n/5000));
        n=n-5000*(n/5000);
    }
    if(n/2000>=1 && b>=2000){
        printf("%d bitllets de 20\n",(n/2000));
        n=n-2000*(n/2000);
    }
    if(n/1000>=1 && b>=1000){
        printf("%d bitllets de 10\n",(n/1000));
        n=n-1000*(n/1000);
    }
    if(n/500>=1 && b>=500){
        printf("%d bitllets de 5\n",(n/500));
        n=n-500*(n/500);
    }
    if(n/200>=1 && b>=200){
        printf("%d monedes de 2\n",(n/200));
        n=n-200*(n/200);
    }
    if(n/100>=1 && b>=100){
        printf("%d monedes de 1 euro\n",(n/100));
        n=n-100*(n/100);
    }
    if(n/50>=1 && b>=50){
        printf("%d monedes de 50 centims\n",(n/50));
        n=n-50*(n/50);
    }
    if(n/20>=1 && b>=20){
        printf("%d monedes de 20 centims\n",(n/20));
        n=n-20*(n/20);
    }
    if(n/10>=1 && b>=10){
        printf("%d monedes de 10 centims\n",(n/10));
        n=n-10*(n/10);
    }
    if(n/5>=1 && b>=5){
        printf("%d monedes de 5 centims\n",(n/5));;
        n=n-5*(n/5);
    }
    if(n/2>=1 && b>=2){
        printf("%d monedes de 2 centims\n",(n/2));
        n=n-2*(n/2);
    }
    if(n/1>=1 && b>=1){
        printf("%d monedes de 1 centims\n",n);
    }
}
