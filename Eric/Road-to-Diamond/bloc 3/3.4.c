#include <stdio.h>
#include <stdlib.h>
#include <time.h>


/*Un programa fa el sorteig d'un n�mero N i despr�s escriu N aes.*/


int main(void)
{
    int con, ran;

    srand(time(NULL));

    ran=rand()%100;
    con=0;

    while(con<ran){
        printf("a");
        con++;
    }
}
