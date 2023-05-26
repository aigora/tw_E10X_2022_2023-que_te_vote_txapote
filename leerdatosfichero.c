#include <stdio.h>
int main()
{
    int i, n, num[24];
    char c[20];
    FILE *pf;
    pf = fopen("C:/Users/annar/OneDrive/Documents/caca.csv", "r"); // Abrimos fichero para lectura
    // Leemos datos separados por comas
    n = fscanf(pf, "%[^,],%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f ",c, &num[0],
                     &num[1],&num[2],&num[3], &num[4],&num[5],&num[6],&num[7],&num[8],&num[9],&num[10],&num[11],&num[12],&num[13],
                    &num[14],&num[15],&num[16],&num[17],&num[18],&num[19],&num[20],&num[21],&num[22],&num[23]);



    printf("Se han leido %i argumentos.\n", n);



    fclose(pf);
    // Mostramos en pantalla lo leído
    for (i = 0; i < 24; i++)
        {
           printf(" %i\t", num[i]);
        }

    return(0);
}
