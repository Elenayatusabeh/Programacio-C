#include <stdio.h>
#include <stdlib.h>
/*20.	Algorisme que llegeix una data d'entrada expressada en dia (1 a 31), mes (1 a 12) i any (amb número) i ens diu la data
que serà l'endemà. Se suposa que febrer té sempre 28 dies.*/

int main (void)
{
    int dia, mes, any;
    printf("Introdueix la data de naixement en format dia mes any separats per espais ");
    scanf("%d %d %d",&dia, &mes, &any);

    if(dia>31 || mes>12 || (dia>28 && mes==2) || (dia>30 && mes==(4 || 6 || 9 || 11 ))){
       printf("Error, data impossible");
       }
    else if (dia<=27){
        dia++;
        printf("Dema sera %d %d %d",dia,mes,any);
    }
    else if (mes==2){
        dia=1;
        mes++;
        printf("Dema sera %d %d %d",dia,mes,any);
    }
    else if (dia<=29){
         dia++;
        printf("Dema sera %d %d %d",dia,mes,any);
    }
    else if (dia==30 && mes==(4 || 6 || 9 || 11)){
        dia=1;
        mes++;
        printf("Dema sera %d %d %d",dia,mes,any);
    }
    else if (dia==30){
        dia++;
        printf("Dema sera %d %d %d",dia,mes,any);
    }
    else if (mes!=12){
        dia=1;
        mes++;
        printf("Dema sera %d %d %d",dia,mes,any);
    }
    else{
        dia=1;
        mes=1;
        any++;
        printf("Dema sera %d %d %d",dia,mes,any);
    }
}
