#include <stdio.h>
#include <stdlib.h>

int main (void){

    char n;

    printf("Introdueix un caràcter ");
    scanf("%c",&n);

    switch(n){


        case 'B':
        case 'C':
        case 'D':
        case 'F':
        case 'G':
        case 'H':
        case 'J':
        case 'K':
        case 'L':
        case 'M':
        case 'N':
        case 'P':
        case 'Q':
        case 'R':
        case 'S':
        case 'T':
        case 'V':
        case 'W':
        case 'X':
        case 'Y':
        case 'Z':
            printf("Es una lletra de l'alfabet angles i es majuscula\n");
            printf("Es una consonant\n");
        break;

        case 'A':
        case 'I':
        case 'E':
        case 'O':
        case 'U':
            printf("Es una lletra de l'alfabet angles i es majuscula\n");
            printf("Es una vocal\n");
        break;

        case 'b':
        case 'c':
        case 'd':
        case 'f':
        case 'g':
        case 'h':
        case 'j':
        case 'k':
        case 'l':
        case 'm':
        case 'n':
        case 'p':
        case 'q':
        case 'r':
        case 's':
        case 't':
        case 'v':
        case 'w':
        case 'x':
        case 'y':
        case 'z':
            printf("Es una lletra de l'alfabet angles i es minuscula\n");
            printf("Es una consonant\n");
        break;

        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
            printf("Es una lletra de l'alfabet angles i es minuscula\n");
            printf("Es una vocal\n");
        break;

        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9':
        case '0':
            printf("Es un digit entre el 0 i el 9\n");
        break;

        default:
             printf("No es ni lletra ni numero\n");
        break;

    }
}
