#include <stdio.h>

float PromedioEnergia(FILE*pf);

int main()
{
    FILE*plectura, *pescritura;
    float *prim;
    float primpromeio;

    plectura= fopen ("C:/Users/annar/Downloads/generacion_por_tecnologias_21_22_puntos_simplificado.csv", "r");

    if (plectura==NULL) //HACERLO SIEMPRE PARA VER SI ESTA TODO BIEN
    {
        printf("Error al abrir el archivo de lectura .\n");
        return -1;
    }

    else
    {
        primpromeio = PromedioEnergia(plectura);
        printf("El promedio es %f", primpromeio );

    }



    return 0;
}

float PromedioEnergia(FILE*pf)
{
    int i;
    char c[30];
    float num[24];
    float promedio=0;

    for (i=0; i<=23; i++)
    {
        while (fscanf(pf, "%s,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f", c, &num[i]==24))
            promedio= promedio + num[i];
    }
        promedio = promedio / 24.0;

    return promedio;
}

