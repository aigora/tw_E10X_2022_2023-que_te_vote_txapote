#include <stdio.h>
int main()
{
    int i, n;
    float hidraulica[24],turbinacion[24],nuclear[24], carbon[24],motores[24],gas[24],vapor[24],ciclocomb[24],
          hidroeol[24],eolica[24],solarfoto[24],solartermi[24],otrasren[24],congeneracion[24],residuosnoren[24],
          residuosren[24];
    char c[20];
    char aux;

    FILE *pf;
    pf = fopen("C:/Users/prestamo_admin/Documents/Informatica/IMPORTANTE/trabajo/energias.csv", "r"); // Abrimos fichero para lectura //C:/Users/annar/Downloads/generacion_por_tecnologias_21_22_puntos_simplificado.csv
    // Leemos datos separados por comas

    if (pf==NULL) //HACERLO SIEMPRE PARA VER SI ESTA TODO BIEN
    {
        printf("Error al abrir el archivo de lectura.\n");
        return -1;
    }



    while(aux != '\n')
    {
        fscanf(pf, "%c", &aux);
    }
    printf("Ha cambiado de linea. \n");



    while (aux != '\n')
    {
        fscanf(pf, "%c", &aux);
    }
    printf("Ha cambiado de linea. \n");


    while (aux != '\n')
    {
        fscanf(pf, "%c", &aux);
    }
    printf("Ha cambiado de linea. \n");


    while (aux != '\n')
    {
        fscanf(pf, "%c", &aux);
    }
    printf("Ha cambiado de linea. \n");



    while (aux != '\n')
    {
        fscanf(pf, "%c", &aux);
    }
    printf("Ha cambiado de linea. \n");



    while (aux != '\n')
    {
        fscanf(pf, "%c", &aux);
    }
    printf("Ha cambiado de linea. \n");





    n = fscanf(pf, "%[^,]",c);
   // n = fscanf(pf, "%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f",c, &hidraulica[0],
    //                 &hidraulica[1],&hidraulica[2],&hidraulica[3], &hidraulica[4],&hidraulica[5],&hidraulica[6],&hidraulica[7],&hidraulica[8],&hidraulica[9],
    //                 &hidraulica[10],&hidraulica[11],&hidraulica[12],&hidraulica[13], &hidraulica[14],&hidraulica[15],&hidraulica[16],
     //                &hidraulica[17],&hidraulica[18],&hidraulica[19],&hidraulica[20],&hidraulica[21],&hidraulica[22],&hidraulica[23]);

    for (i= 0; i< 24; i++)
    {
        n= fscanf(pf, ",%f", &hidraulica[i]);

        printf(" la energia %s es %f \t", c,  hidraulica[i]);
    }




    n = fscanf(pf, "%[^,]",c);
    for (i= 0; i< 24; i++)
    {
        n = fscanf(pf, ",%f", &turbinacion[i]);


        printf(" %f \t", turbinacion[i]);
    }


    n = fscanf(pf, "%[^,]",c);
    for (i= 0; i< 24; i++)
    {
        n = fscanf(pf, ",%f", &nuclear[i]);

        printf(" %f \t", nuclear[i]);
    }



    n = fscanf(pf, "%[^,]",c);
    for (i= 0; i< 24; i++)
    {
        n = fscanf(pf, ",%f", &carbon[i]);

        printf(" %f \t", carbon[i]);
    }




    n = fscanf(pf, "%[^,]",c);
    for (i= 0; i< 24; i++)
    {
        n = fscanf(pf, ",%f", &motores[i]);
        printf(" %f \t", motores[i]);
    }



    n = fscanf(pf, "%[^,]",c);
    for (i= 0; i< 24; i++)
    {
        n = fscanf(pf, ",%f", &gas[i]);

        printf(" %f \t", gas[i]);
    }




    n = fscanf(pf, "%[^,]",c);
    for (i= 0; i< 24; i++)
    {
        n = fscanf(pf, ",%f", &vapor[i]);

        printf(" %f \t", vapor[i]);
    }




    n = fscanf(pf, "%[^,]",c);
    for (i= 0; i< 24; i++)
    {
        n = fscanf(pf, ",%f", &ciclocomb[i]);

        printf(" %f \t", ciclocomb[i]);
    }



    n = fscanf(pf, "%[^,]",c);
    for (i= 0; i< 24; i++)
    {
        n = fscanf(pf, ",%f", &hidroeol[i]);
        printf(" %f \t", hidroeol[i]);
    }




    n = fscanf(pf, "%[^,]",c);
    for (i= 0; i< 24; i++)
    {
        n = fscanf(pf, ",%f", &eolica[i]);

        printf(" %f \t", eolica[i]);

    }


    n = fscanf(pf, "%[^,]",c);
    for (i= 0; i< 24; i++)
    {
        n = fscanf(pf, ",%f", &solarfoto[i]);

        printf(" %f \t", solarfoto[i]);
    }




    n = fscanf(pf, "%[^,]",c);
    for (i= 0; i< 24; i++)
    {
        n = fscanf(pf, ",%f", &solartermi[i]);

        printf(" %f \t", solartermi[i]);
    }




    n = fscanf(pf, "%[^,]",c);
    for (i= 0; i< 24; i++)
    {
        n = fscanf(pf, ",%f", &otrasren[i]);

        printf(" %f \t", otrasren[i]);
    }




    n = fscanf(pf, "%[^,]",c);
    for (i= 0; i< 24; i++)
    {
        n = fscanf(pf, ",%f", &congeneracion[i]);

        printf(" %f \t", congeneracion[i]);
    }





    n = fscanf(pf, "%[^,]",c);
    for (i= 0; i< 24; i++)
    {
        n = fscanf(pf, ",%f", &residuosnoren[i]);

        printf(" %f \t", residuosnoren[i]);
    }


    n = fscanf(pf, "%[^,]",c);
    for (i= 0; i< 24; i++)
    {
        n = fscanf(pf, ",%f", &residuosren[i]);
        printf(" %f \t", residuosren[i]);
    }









    //for (i= 0, i< 24; i++)
   // n = fscanf(pf, "%[^,],%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f ",c, &hidraulica[0],
                    // &num[1],&num[2],&num[3], &num[4],&num[5],&num[6],&num[7],&num[8],&num[9],&num[10],&num[11],&num[12],&num[13],
                   // &num[14],&num[15],&num[16],&num[17],&num[18],&num[19],&num[20],&num[21],&num[22],&num[23]);



    //printf("Se han leido %i argumentos.\n", n);



    fclose(pf);
    // Mostramos en pantalla lo leído
    //for (i = 0; i < 24; i++)
    //    {
     //      printf(" %f\t", num[i]);
    //    }

    return(0);
}
