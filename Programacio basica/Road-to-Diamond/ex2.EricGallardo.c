#include <stdio.h>
#include <stdlib.h>

int main (void)
{
    int dia, mes, rest;
    printf("Introdueix el dia i el mes separats per espais ");
    scanf("%d %d",&dia, &mes);

    if(dia>31 || mes>12 || (dia>28 && mes==2) || (dia>30 && (mes==4 || mes==6 || mes==9 || mes==11 )) || (dia<1 || mes<1)){
       printf("Error, data impossible\n");
       }
    if(mes==2){
        if(dia==28){
            printf("Ja es fi de mes", rest);
        }
        else{
        rest=28-dia;
        printf("Falten %d dies per a fi de mes", rest);
        }
    }
    else if(mes==4 || mes==6 || mes==9 || mes==11 ){
        if(dia==30){
            printf("Ja es fi de mes", rest);
        }
        else{
        rest=30-dia;
        printf("Falten %d dies per a fi de mes", rest);
        }
    }
    else{
        if(dia==31){
            printf("Ja es fi de mes", rest);
        }
        rest=31-dia;
        printf("Falten %d dies per a fi de mes", rest);
    }
}

