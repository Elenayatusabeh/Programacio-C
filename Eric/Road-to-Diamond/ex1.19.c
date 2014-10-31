#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/*19.	Algorisme que llegeix una data de naixement i ens doni el signe zodiacal corresponent.*/

int main (void)
{
    int di, mes, any;
    printf("Introdueix la data de naixement en format dia mes any separats per espais ");
    scanf("%d %d %d",&dia, &mes, &any);

    if((mes==3 && dia>=21)||(mes==4 && dia<=20)){
        printf("El teu signe del zodiac es Aries");
    }
    else if((mes==9 && dia>=23)||(mes==10 && dia<=22)){
        printf("El teu signe del zodiac es Libra");
    }
    else if((mes==4 && dia>=21)||(mes==5 && dia<=20)){
        printf("El teu signe del zodiac es Tauro");
    }
    else if((mes==10 && dia>=23)||(mes==11 && dia<=22)){
        printf("El teu signe del zodiac es Escorpio");
    }
    else if((mes==5 && dia>=21)||(mes==6 && dia<=20)){
        printf("El teu signe del zodiac es Geminis");
    }
    else if((mes==11 && dia>=23)||(mes==12 && dia<=20)){
        printf("El teu signe del zodiac es Sagitari");
    }
    else if((mes==6 && dia>=21)||(mes==7 && dia<=20)){
        printf("El teu signe del zodiac es Cancer");
    }
    else if((mes==12 && dia>=21)||(mes==1 && dia<=19)){
        printf("El teu signe del zodiac es Capricorn");
    }
    else if((mes==7 && dia>=21)||(mes==8 && dia<=21)){
        printf("El teu signe del zodiac es Leo");
    }
    else if((mes==1 && dia>=20)||(mes==2 && dia<=18)){
        printf("El teu signe del zodiac es Aquari");
    }
    else if((mes==8 && dia>=22)||(mes==9 && dia<=22)){
        printf("El teu signe del zodiac es Virgo");
    }
    else if((mes==2 && dia>=19)||(mes==3 && dia<=20)){
        printf("El teu signe del zodiac es Piscis");
    }
    else {
        printf("Data Erronea");
    }


}
