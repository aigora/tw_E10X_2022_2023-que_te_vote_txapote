#include <stdio.h>

int main ()
{
long  double hidraulica21[12], bombeo21[12], nuclear21[12], carbon21[12], motordie21[12], gas21[12], vapor21[12], ciclocomb21[12], hidroeolica21[12], eolica21[12], fotovoltaica21[12], termica21[12], otras21[12], cogen21[12], renob21[12], norenob21[12];
long double hidraulica22[12], bombeo22[12], nuclear22[12], carbon22[12], motordie22[12], gas22[12], vapor22[12], ciclocomb22[12], hidroeolica22[12], eolica22[12], fotovoltaica22[12], termica22[12], otras22[12], cogen22[12], renob22[12], norenob22[12];
long double n, i;
FILE *f;
f = fopen("C:/Users/prestamo_admin/Downloads/generacion_por_tecnologias_21_22_puntos_simplificado.csv", "r"); // Abrimos el fichero para lectura

if(f==NULL)
{
    printf("Error al abrir el fichero");
    return -1;
}
else
{
    while (fscanf(f, "%ld, %ld, %ld, %ld, %ld, %ld, %, %ld, %ld, %ld, %ld, %ld, %ld, %ld, %ld, %ld, %ld, %ld, %ld, %ld, %ld, %ld, %ld, %ld\n", &hidraulica21[12], &bombeo21[12], &nuclear21[12], &carbon21[12], &motordie21[12], &gas21[12], &vapor21[12], &ciclocomb21[12], &hidroeolica21[12], &eolica21[12], &fotovoltaica21[12], &termica21[12], &otras21[12], &cogen21[12], &renob21[12], &norenob21[12], &hidraulica22[12], &bombeo22[12], &nuclear22[12], &carbon22[12], &motordie22[12], &gas22[12], &vapor22[12], &ciclocomb22[12], &hidroeolica22[12], &eolica22[12], &fotovoltaica22[12], &termica22[12], &otras22[12], &cogen22[12], &renob22[12], norenob22[12] != EOF));
    {
        printf("bien");
    }

    fclose(f);
    return 0;
}

}
