/*
13.	Algorisme que llegeix una seqüència de notes entre 0 i 10. La seqüència s’acaba amb el -1. En acabar ens mostra: la mitjana aritmètica de totes les notes introduïdes, quants han tret excel•lent, quants notable, quants bé, quants suficient, quants insuficient i quants molt deficient.
*/
int main(void)
   {
    int x, e, n, b, s, i, ii, m, c;

    e=0;
    n=0;
    b=0;
    s=0;
    i=0;
    ii=0;
    m=0;
    c=0;
    printf("Introdueix notes (0-10) per finalitzar introdueix -1:\n");
    while(x!=-1)
    {
        scanf("%d",&x);
        m=m+x;
        switch(x){
            case 10:
            case 9:
                e++;
            break;

            case 8:
            case 7:
                n++;
            break;

            case 6:
                b++;
            break;

            case 5:
                s++;
            break;

            case 4:
            case 3:
                i++;
            break;

            case 2:
            case 1:
                ii++;
            break;

            case -1: //No fa res, és perque no surti el default de nota incorrecte.
                break;

            default:
                printf("Nota incorrecte.");
        }
        c++;

    }
    printf("Excelents: %d\nNotables: %d\nBes: %d\nSuficients: %d\nInsuficients: %d\nMolt Insuficients: %d\nLa mitjana aritmetica es: %d",e,n,b,s,i,ii,m/(c-1));
    return 0;

   }
