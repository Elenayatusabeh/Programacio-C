//14.	Algorisme que llegeix una seq��ncia de lletres (que formen una frase) fins arribar al punt. La sortida ens diu el n�mero de vegades que llegeix la lletra A (tant maj�scula com a min�scula).
#include <stdlib.h>
#include <stdio.h>

int main(void)
{
    char x;
    int y=0;
    printf("Introdueix una sequ�ncia de lletres i finalitza-la amb . i enter:\n");
    fflush(stdin);
    while(x!='.')
    {

        scanf("%c",&x);
        if(x=='A' || x=='a')
        {
            y++;
        }
    }
    printf("\nLa lletra A ha aparegut %d cops.",y);
}
