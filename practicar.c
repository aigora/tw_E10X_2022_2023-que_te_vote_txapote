#include <stdio.h>

int main ()
{
double Hidraulica21[12], bombeo21[12], nuclear21[12], carbon21[12], motordie21[12], gas21[12, vapor21[12], ciclocomb21[12], hidroeolica21[12], eolica21[12], fotovoltaica21[12], termica21[12], otras21[12], cogeneracion21[12], renob21[12], norenob21[12]
double Hidraulica22[12], bombeo22[12], nuclear22[12], carbon22[12], motordie22[12], gas22[12, vapor22[12], ciclocomb22[12], hidroeolica22[12], eolica22[12], fotovoltaica22[12], termica22[12], otras22[12], cogeneracion22[12], renob22[12], norenob22[12]
FILE *f21;
f21 = fopen("generación_mensual_2022_puntos_simplificado.csvArchivo.txt", "r"); // Abrimos el fichero para lectura

if(f21 == NULL)
{
    printf("Error al abrir el fichero");
    return 0;
}
else
{
    while (fscanf(f21, "%d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d\n", &Hidraulica21[12], &bombeo21[12], &nuclear21[12], &carbon21[12], &motordie21[12], &gas21[12, &vapor21[12], &ciclocomb21[12], &hidroeolica21[12], &eolica21[12], &fotovoltaica21[12], &termica21[12], &otras21[12], &cogen21[12], &renob21[12], &norenob21[12] != EOF);
    {

    }

    fclose(pf);
    return 0;
}

FILE *f22;
f22 = fopen("generación_mensual_2022_puntos_simplificado.csvArchivo.txt", "r"); // Abrimos el fichero para lectura

if(f22 == NULL)
{
    printf("Error al abrir el fichero");
    return 0;
}
else
{
    while (fscanf(f22, "%d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d\n", &Hidraulica22[12], &bombeo22[12], &nuclear22[12], &carbon22[12], &motordie22[12], &gas22[12, &vapor22[12], &ciclocomb22[12], &hidroeolica22[12], &eolica22[12], &fotovoltaica22[12], &termica22[12], &otras22[12], &cogen22[12], &renob22[12], &norenob22[12] != EOF);
    {

    }

    fclose(pf);
    return 0;
}

}
