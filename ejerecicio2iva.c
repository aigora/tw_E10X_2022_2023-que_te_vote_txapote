#include <stdio.h>

int main()
{
float precio, iva;

printf("Introduzca un numero con valor en euros\n");
scanf ("%f", &precio);

iva = ((precio*21)/100);
printf ("El valor del IVA es: %f\n", iva);



  return 0;
}
