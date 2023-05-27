#include <stdio.h>

//Prototipo de la función
float PromedioEnergia(float energia[], int n);
float maximo(float vector[], int numelementos);
float minimo(float vector[], int num_elementos);


int main()
{
    int i, n;
    float hidraulica[24],turbinacion[24],nuclear[24], carbon[24],motores[24],gas[24],vapor[24],ciclocomb[24],
          hidroeol[24],eolica[24],solarfoto[24],solartermi[24],otrasren[24],congeneracion[24],residuosnoren[24],
          residuosren[24];
    char c[20];
    char aux,aux1,aux2,aux3,aux4;
    float promedio_hid, promedio_nuc;



    FILE *pf;
    pf = fopen("C:/Users/annar/Downloads/generacion_por_tecnologias_21_22_puntos_simplificado (1).csv", "r"); // Abrimos fichero para lectura //C:/Users/annar/Downloads/generacion_por_tecnologias_21_22_puntos_simplificado.csv
    // Leemos datos separados por comas   //C:/Users/annar/Downloads/generacion_por_tecnologias_21_22_puntos_simplificado (1).

    if (pf==NULL) //HACERLO SIEMPRE PARA VER SI ESTA TODO BIEN
    {
        printf("Error al abrir el archivo de lectura .\n");
        return -1;
    }



    while (aux != '\n')
    {
        fscanf(pf, "%c", &aux);
    }
    printf("Ha cambiado de linea. \n");



    while (aux1 != '\n')
    {
        fscanf(pf, "%c", &aux1);
    }
    printf("Ha cambiado de linea. \n");


    while (aux2 != '\n')
    {
        fscanf(pf, "%c", &aux2);
    }
    printf("Ha cambiado de linea. \n");


    while (aux3 != '\n')
    {
        fscanf(pf, "%c", &aux3);
    }
    printf("Ha cambiado de linea. \n");



    while (aux4 != '\n')
    {
        fscanf(pf, "%c", &aux4);
    }
    printf("Ha cambiado de linea. \n");



    /*while (aux != '\n')
    {
        fscanf(pf, "%c", &aux);
    }
    printf("Ha cambiado de linea. \n"); */





    n = fscanf(pf, "%[^,]",c);
    for (i= 0; i< 24; i++)
    {
        n= fscanf(pf, ",%f", &hidraulica[i]);

        printf("%f \t", hidraulica[i]);
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




    fclose(pf);



       promedio_hid = PromedioEnergia(hidraulica, 24);
       promedio_nuc = PromedioEnergia(nuclear,24);

        printf("\nEl promedio de la energia hidraulica es %f\n", promedio_hid);
        printf("El promedio de la energia nuclear es %f", promedio_nuc);




      float resultado_maximo = maximo(hidraulica, 24);
        printf("\nLa energia hidraulica maxima es %f", resultado_maximo);
       float resultado_minimo = minimo(hidraulica, 24);
        printf("La energia hidraulica minima es %f\n", resultado_minimo);

       resultado_maximo = maximo(nuclear, 24);
        printf("La energia nuclear maxima es %f\n", resultado_maximo);
        resultado_minimo = minimo(nuclear, 24);
        printf("La energia nuclear minima es %f\n", resultado_minimo);

    return(0);
}
float PromedioEnergia(float energia[], int n)
{
    int i;
    float suma= 0.0;
    float resul_media=0.0;

    for (i=0; i<24; i++)
    {
        suma = suma +  energia[i];
    }
    resul_media= suma/n;

    return resul_media;

}

 float maximo(float vector[], int num_elementos)
    {
        int i;
        float maximo_actual;
        //Recorrer el vector
        for(i = 0; i < num_elementos; i++)
        {
            if(i == 0)
            {
                maximo_actual = vector[0];
            }
            else
            {
                if(vector[i] > maximo_actual)
                {
                    maximo_actual = vector[i];
                }
            }
        }
    return maximo_actual;
    }

    float minimo(float vector[], int num_elementos)
    {
        int i;
        float minimo_actual;
        //Recorrer el vector
        for(i = 0; i < num_elementos; i++)
        {
            if(i == 0)
            {
                minimo_actual = vector[0];
            }
            else
            {
                if(vector[i] < minimo_actual)
                {
                    minimo_actual = vector[i];
                }
            }
        }
    return minimo_actual;
    }




