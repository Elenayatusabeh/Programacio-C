//14.	Algorisme que llegeix una seqüència de lletres (que formen una frase) fins arribar al punt. La sortida ens diu el número de vegades que llegeix la lletra A (tant majúscula com a minúscula).
#include <stdlib.h>
#include <stdio.h>

int main(void)
{
    char x;
    int y=0;
    printf("Introdueix una sequència de lletres i finalitza-la amb . i enter:\n");
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
