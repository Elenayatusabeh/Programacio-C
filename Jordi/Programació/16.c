//16.	Algorisme que llegeix una seqüència de lletres (que formen una frase) fins arribar al punt. La sortida ens diu el número de vegades que llegeix la síl•laba LA (tant majúscula com a minúscula).
//17.	Algorisme que llegeix una seqüència de frases (un vers). El programa acaba quan li diem que no volem introduir més frases. La sortida ens diu per a cada frase quants caràcters té. En acabar ens diu quantes frases hem introduït.
//18.	Algorisme que llegeix una seqüència de lletres (que formen una frase) fins arribar al punt. La sortida ens diu quantes paraules conté la frase introduïda.

#include <stdlib.h>
#include <stdio.h>

int main(void)
{
    char x, c;
    int la=0;
    printf("Introdueix una sequència de lletres i finalitza-la amb . i enter:\n");
    fflush(stdin);
    while(x!='.')
    {

        scanf("%c",&x);
        if(x=='l' || x=='L')
        {
            c=1;
        }
        else
        {
            c=0;
        }
        if((x=='a' || x=='A')&&(c==1))
        {
            la++;
        }
        }

    printf("\nLa silaba LA ha aparegut %d cops.",la);
}
