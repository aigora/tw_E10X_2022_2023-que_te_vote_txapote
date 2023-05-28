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

    printf("\n\n\nPulse la tecla 'p' para realizar el promedio de todos los tipos de energias\n");
    printf("\nPulse la tecla 'm' para observar el número máximo que ha generado la energia hidraulica y la nuclear\n");
    printf("\nPulse la tecla 'n' para observar el número mínimo que ha generado la energia hidraulica y la nuclear\n");

    char tecla;
    scanf("%c ", &tecla);
    float resultado_maximo, resultado_minimo;
    switch (tecla)
    {
    case 'p':
        promedio_hid = PromedioEnergia(hidraulica, 24);
        promedio_nuc = PromedioEnergia(nuclear,24);
        float promedio_turbi_bombeo = PromedioEnergia(turbinacion,24);
        float promedio_carbon = PromedioEnergia(carbon,24);
        float promedio_motordie = PromedioEnergia(motores,24);
        float promedio_turbi_gas = PromedioEnergia(gas,24);
        float promedio_turbi_vapor = PromedioEnergia(vapor,24);
        float promedio_ciclo_comb = PromedioEnergia(ciclocomb,24);
        float promedio_hidroeolica = PromedioEnergia(hidroeol,24);
        float promedio_eolica = PromedioEnergia(eolica,24);
        float promedio_sol_foto = PromedioEnergia(solarfoto, 24);
        float promedio_sol_termi = PromedioEnergia(solartermi,24);
        float promedio_otras_ren = PromedioEnergia(otrasren,24);
        float promedio_congeneracion = PromedioEnergia(congeneracion,24);
        float promedio_residuos_no_ren = PromedioEnergia(residuosnoren,24);
        float promedio_residuos_ren = PromedioEnergia(residuosren,24);

        printf("El promedio de la energia hidraulica es %f\n", promedio_hid);
        printf("El promedio de la energia nuclear es %f\n", promedio_nuc);
        printf("El promedio de la energia creada a traves del proceso de turbinacion bombeo es %f\n", promedio_turbi_bombeo);
        printf("El promedio de la energia creada a traves del carbon es %f\n", promedio_carbon);
        printf("El promedio de la energia creada a traves del proceso de turbinacion gas es %f\n", promedio_turbi_gas);
        printf("El promedio de la energia creada a traves del motor diesel es %f\n", promedio_motordie);
        printf("El promedio de la energia creada a traves del proceso de turbinacion vapor es %f\n", promedio_turbi_vapor);
        printf("El promedio de la energia creada a traves del ciclo combinado es %f\n", promedio_ciclo_comb);
        printf("El promedio de la energia hidroeolica es %f\n", promedio_hidroeolica);
        printf("El promedio de la energia eolica es %f\n", promedio_eolica);
        printf("El promedio de la energia solar fotovoltaica es %f\n", promedio_sol_foto);
        printf("El promedio de la energia solar termica es %f\n", promedio_sol_termi);
        printf("El promedio de le energia de otras renovables es %f\n", promedio_otras_ren);
        printf("El promedio de la energia creada a traves de la congeneracion es %f\n", promedio_congeneracion);
        printf("El promedio de la energia creada a traves de residuos renovables es %f\n", promedio_residuos_ren);
        printf("El promedio de la energia creada a traves de residuos no renovables es %f\n", promedio_residuos_no_ren);
        break;

    case 'm':
        resultado_maximo = maximo(hidraulica, 24);
        printf("La energia hidraulica maxima es %f\n", resultado_maximo);
        resultado_maximo = maximo(nuclear, 24);
        printf("La energia nuclear maxima es %f\n", resultado_maximo);
        resultado_maximo = maximo(turbinacion, 24);
        printf("La energia por turbinacion bombeo maxima es %f\n", resultado_maximo);
        resultado_maximo = maximo(carbon, 24);
        printf("La energia por carbon maxima es %f\n", resultado_maximo);
        resultado_maximo = maximo(motores, 24);
        printf("La energia por motores diesel maxima es %f\n", resultado_maximo);
        resultado_maximo = maximo(gas, 24);
        printf("La energia por turbinacion gas maxima es %f\n", resultado_maximo);
        resultado_maximo = maximo(vapor, 24);
        printf("La energia por turbinacion vapor maxima es %f\n", resultado_maximo);
        resultado_maximo = maximo(ciclocomb, 24);
        printf("La energia por ciclo combinado maxima es %f\n", resultado_maximo);
        resultado_maximo = maximo(hidroeol, 24);
        printf("La energia hidroeolica maxima es %f\n", resultado_maximo);
        resultado_maximo = maximo(eolica, 24);
        printf("La energia eolica maxima es %f\n", resultado_maximo);
        resultado_maximo = maximo(solarfoto, 24);
        printf("La energia solar fotovoltaica maxima es %f\n", resultado_maximo);
        resultado_maximo = maximo(solartermi, 24);
        printf("La energia solar termica maxima es %f\n", resultado_maximo);
        resultado_maximo = maximo(otrasren, 24);
        printf("La energia por otras renovables maxima es %f\n", resultado_maximo);
        resultado_maximo = maximo(congeneracion, 24);
        printf("La energia por congeneracion maxima es %f\n", resultado_maximo);
        resultado_maximo = maximo(residuosnoren, 24);
        printf("La energia por residuos no renovables maxima es %f\n", resultado_maximo);
        resultado_maximo = maximo(residuosren, 24);
        printf("La energia por residuos renovables maxima es %f\n", resultado_maximo);
        break;


    case 'n':
        resultado_minimo = minimo(hidraulica, 24);
        printf("La energia hidraulica minima es %f\n", resultado_minimo);
        resultado_minimo = minimo(nuclear, 24);
        printf("La energia nuclear minima es %f\n", resultado_minimo);
        resultado_minimo = minimo(turbinacion, 24);
        printf("La energia por turbinacion bombeo minima es %f\n", resultado_minimo);
        resultado_minimo = minimo(carbon, 24);
        printf("La energia por carbon minima es %f\n", resultado_minimo);
        resultado_minimo = minimo(motores, 24);
        printf("La energia por motores diesel minima es %f\n", resultado_minimo);
        resultado_minimo = minimo(gas, 24);
        printf("La energia por turbinacion gas minima es %f\n", resultado_minimo);
        resultado_minimo = minimo(vapor, 24);
        printf("La energia por turbinacion vapor minima es %f\n", resultado_minimo);
        resultado_minimo = minimo(ciclocomb, 24);
        printf("La energia por ciclo combinado minima es %f\n", resultado_minimo);
        resultado_minimo = minimo(hidroeol, 24);
        printf("La energia hidroeolica minima es %f\n", resultado_minimo);
        resultado_minimo = minimo(eolica, 24);
        printf("La energia eolica minima es %f\n", resultado_minimo);
        resultado_minimo = minimo(solarfoto, 24);
        printf("La energia solar fotovoltaica minima es %f\n", resultado_minimo);
        resultado_minimo = minimo(solartermi, 24);
        printf("La energia solar termica es %f\n", resultado_minimo);
        resultado_minimo = minimo(otrasren, 24);
        printf("La energia de otras renovables minima es %f\n", resultado_minimo);
        resultado_minimo = minimo(congeneracion, 24);
        printf("La energia por congeneracion minima es %f\n", resultado_minimo);
        resultado_minimo = minimo(residuosnoren, 24);
        printf("La energia por residuos no renovables minima es %f\n", resultado_minimo);
        resultado_minimo = minimo(residuosren, 24);
        printf("La energia por residuos renovables minima es %f\n", resultado_minimo);
        break;


    default:
        printf("Se ha equivocado de tecla");


    }


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




