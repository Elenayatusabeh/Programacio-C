//16.	Algorisme que llegeix una seq��ncia de lletres (que formen una frase) fins arribar al punt. La sortida ens diu el n�mero de vegades que llegeix la s�l�laba LA (tant maj�scula com a min�scula).
//17.	Algorisme que llegeix una seq��ncia de frases (un vers). El programa acaba quan li diem que no volem introduir m�s frases. La sortida ens diu per a cada frase quants car�cters t�. En acabar ens diu quantes frases hem introdu�t.
//18.	Algorisme que llegeix una seq��ncia de lletres (que formen una frase) fins arribar al punt. La sortida ens diu quantes paraules cont� la frase introdu�da.

#include <stdlib.h>
#include <stdio.h>

int main(void)
{
    char x, c;
    int la=0;
    printf("Introdueix una sequ�ncia de lletres i finalitza-la amb . i enter:\n");
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
