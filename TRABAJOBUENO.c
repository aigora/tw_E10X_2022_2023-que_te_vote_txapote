#include <stdio.h>

//Prototipo de la función
float PromedioEnergia(float energia[], int n);
float maximo(float vector[], int numelementos);
float minimo(float vector[], int num_elementos);
float diferencia_energia(float vector[], int mes_inicio, int mes_fin);


int main()
{
    int i, n;
    float hidraulica[24],turbinacion[24],nuclear[24], carbon[24],motores[24],gas[24],vapor[24],ciclocomb[24],
          hidroeol[24],eolica[24],solarfoto[24],solartermi[24],otrasren[24],congeneracion[24],residuosnoren[24],
          residuosren[24];
    char c[20];
    char aux,aux1,aux2,aux3,aux4;
    float promedio_hid, promedio_nuc, diferencia2021, diferencia2022, resultado_maximo, resultado_minimo;



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
    printf("\nPulse la tecla 'm' para observar el numero maximo de cada tipo de energia generada\n");
    printf("\nPulse la tecla 'n' para observar el numero minimo de cada tipo de energia generada\n");
    printf("\nPulse la tecla 'z' para observar la diferencia entre la energia producida entre el mes de enero y de diciembre de 2021\n");
    printf("\nPulse la tecla 'w' para observar la diferencia entre la energia producida entre el mes de enero y de diciembre de 2022\n");


    char tecla;
    scanf("%c ", &tecla);
    
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

        printf("El promedio de la energia hidraulica es %f GWh\n", promedio_hid);
        printf("El promedio de la energia nuclear es %f- GWh\n", promedio_nuc);
        printf("El promedio de la energia creada a traves del proceso de turbinacion bombeo es %f GWh\n", promedio_turbi_bombeo);
        printf("El promedio de la energia creada a traves del carbon es %f GWh\n", promedio_carbon);
        printf("El promedio de la energia creada a traves del proceso de turbinacion gas es %f GWh\n", promedio_turbi_gas);
        printf("El promedio de la energia creada a traves del motor diesel es %f GWh\n", promedio_motordie);
        printf("El promedio de la energia creada a traves del proceso de turbinacion vapor es %f GWh\n", promedio_turbi_vapor);
        printf("El promedio de la energia creada a traves del ciclo combinado es %f GWh\n", promedio_ciclo_comb);
        printf("El promedio de la energia hidroeolica es %f GWh\n", promedio_hidroeolica);
        printf("El promedio de la energia eolica es %f GWh\n", promedio_eolica);
        printf("El promedio de la energia solar fotovoltaica es %fGWh\n", promedio_sol_foto);
        printf("El promedio de la energia solar termica es %f GWh\n", promedio_sol_termi);
        printf("El promedio de le energia de otras renovables es %f GWh\n", promedio_otras_ren);
        printf("El promedio de la energia creada a traves de la congeneracion es %f GWh\n", promedio_congeneracion);
        printf("El promedio de la energia creada a traves de residuos renovables es %f GWh\n", promedio_residuos_ren);
        printf("El promedio de la energia creada a traves de residuos no renovables es %f GWh\n", promedio_residuos_no_ren);
        break;

    case 'm':
        resultado_maximo = maximo(hidraulica, 24);
        printf("La energia hidraulica maxima es %f GWh\n", resultado_maximo);
        resultado_maximo = maximo(nuclear, 24);
        printf("La energia nuclear maxima es %f GWh\n", resultado_maximo);
        resultado_maximo = maximo(turbinacion, 24);
        printf("La energia por turbinacion bombeo maxima es %f GWh\n", resultado_maximo);
        resultado_maximo = maximo(carbon, 24);
        printf("La energia por carbon maxima es %f GWh\n", resultado_maximo);
        resultado_maximo = maximo(motores, 24);
        printf("La energia por motores diesel maxima es %f GWh\n", resultado_maximo);
        resultado_maximo = maximo(gas, 24);
        printf("La energia por turbinacion gas maxima es %f GWh\n", resultado_maximo);
        resultado_maximo = maximo(vapor, 24);
        printf("La energia por turbinacion vapor maxima es %f GWh\n", resultado_maximo);
        resultado_maximo = maximo(ciclocomb, 24);
        printf("La energia por ciclo combinado maxima es %f GWh\n", resultado_maximo);
        resultado_maximo = maximo(hidroeol, 24);
        printf("La energia hidroeolica maxima es %f GWh\n", resultado_maximo);
        resultado_maximo = maximo(eolica, 24);
        printf("La energia eolica maxima es %f GWh\n", resultado_maximo);
        resultado_maximo = maximo(solarfoto, 24);
        printf("La energia solar fotovoltaica maxima es %f GWh\n", resultado_maximo);
        resultado_maximo = maximo(solartermi, 24);
        printf("La energia solar termica maxima es %f GWh\n", resultado_maximo);
        resultado_maximo = maximo(otrasren, 24);
        printf("La energia por otras renovables maxima es %f GWh\n", resultado_maximo);
        resultado_maximo = maximo(congeneracion, 24);
        printf("La energia por congeneracion maxima es %f GWh\n", resultado_maximo);
        resultado_maximo = maximo(residuosnoren, 24);
        printf("La energia por residuos no renovables maxima es %f GWh\n", resultado_maximo);
        resultado_maximo = maximo(residuosren, 24);
        printf("La energia por residuos renovables maxima es %f GWh\n", resultado_maximo);
        break;


    case 'n':
        resultado_minimo = minimo(hidraulica, 24);
        printf("La energia hidraulica minima es %f GWh\n", resultado_minimo);
        resultado_minimo = minimo(nuclear, 24);
        printf("La energia nuclear minima es %f GWh\n", resultado_minimo);
        resultado_minimo = minimo(turbinacion, 24);
        printf("La energia por turbinacion bombeo minima es %f GWh\n", resultado_minimo);
        resultado_minimo = minimo(carbon, 24);
        printf("La energia por carbon minima es %f GWh\n", resultado_minimo);
        resultado_minimo = minimo(motores, 24);
        printf("La energia por motores diesel minima es %f GWh\n", resultado_minimo);
        resultado_minimo = minimo(gas, 24);
        printf("La energia por turbinacion gas minima es %f GWh\n", resultado_minimo);
        resultado_minimo = minimo(vapor, 24);
        printf("La energia por turbinacion vapor minima es %f GWh\n", resultado_minimo);
        resultado_minimo = minimo(ciclocomb, 24);
        printf("La energia por ciclo combinado minima es %f GWh\n", resultado_minimo);
        resultado_minimo = minimo(hidroeol, 24);
        printf("La energia hidroeolica minima es %f GWh\n", resultado_minimo);
        resultado_minimo = minimo(eolica, 24);
        printf("La energia eolica minima es %f GWh\n", resultado_minimo);
        resultado_minimo = minimo(solarfoto, 24);
        printf("La energia solar fotovoltaica minima es %f GWh\n", resultado_minimo);
        resultado_minimo = minimo(solartermi, 24);
        printf("La energia solar termica es %f GWh\n", resultado_minimo);
        resultado_minimo = minimo(otrasren, 24);
        printf("La energia de otras renovables minima es %f GWh\n", resultado_minimo);
        resultado_minimo = minimo(congeneracion, 24);
        printf("La energia por congeneracion minima es %f GWh\n", resultado_minimo);
        resultado_minimo = minimo(residuosnoren, 24);
        printf("La energia por residuos no renovables minima es %f GWh\n", resultado_minimo);
        resultado_minimo = minimo(residuosren, 24);
        printf("La energia por residuos renovables minima es %f GWh\n", resultado_minimo);
        break;
            
            
    case 'z':
        diferencia2021 = diferencia_energia(hidraulica, 0, 11);
        printf("La diferencia de energia hidraulica entre enero y diciembre de 2021 fue de: %.4f GWh\n", diferencia2021);
        diferencia2021 = diferencia_energia(nuclear, 0, 11);
        printf("La diferencia de energia nuclear entre enero y diciembre de 2021 fue de: %.4f GWh\n", diferencia2021);
        diferencia2021 = diferencia_energia(turbinacion, 0, 11);
        printf("La diferencia de energia por turbinacion bombeo entre enero y diciembre de 2021 fue de: %.4f GWh\n", diferencia2021);
        diferencia2021 = diferencia_energia(carbon, 0, 11);
        printf("La diferencia de energia por carbon entre enero y diciembre de 2021 fue de: %.4f GWh\n", diferencia2021);
        diferencia2021 = diferencia_energia(motores, 0, 11);
        printf("La diferencia de energia por motores diesel entre enero y diciembre de 2021 fue de: %.4f GWh\n", diferencia2021);
        diferencia2021 = diferencia_energia(gas, 0, 11);
        printf("La diferencia de energia por turbinacion gas entre enero y diciembre de 2021 fue de: %.4f GWh\n", diferencia2021);
        diferencia2021 = diferencia_energia(vapor, 0, 11);
        printf("La diferencia de energia por turbinacion vapor entre enero y diciembre de 2021 fue de: %.4f GWh\n", diferencia2021);
        diferencia2021 = diferencia_energia(ciclocomb, 0, 11);
        printf("La diferencia de energia por ciclo combinado entre enero y diciembre de 2021 fue de: %.4f GWh\n", diferencia2021);
        diferencia2021 = diferencia_energia(hidroeol, 0, 11);
        printf("La diferencia de energia hidroeolica entre enero y diciembre de 2021 fue de: %.4f GWh\n", diferencia2021);
        diferencia2021 = diferencia_energia(eolica, 0, 11);
        printf("La diferencia de energia eolica entre enero y diciembre de 2021 fue de: %.4f GWh\n", diferencia2021);
        diferencia2021 = diferencia_energia(solarfoto, 0, 11);
        printf("La diferencia de energia solar fotovoltaica entre enero y diciembre de 2021 fue de: %.4f GWh\n", diferencia2021);
        diferencia2021 = diferencia_energia(solartermi, 0, 11);
        printf("La diferencia de energia solar termica entre enero y diciembre de 2021 fue de: %.4f GWh\n", diferencia2021);
        diferencia2021 = diferencia_energia(otrasren, 0, 11);
        printf("La diferencia de energia de otras renovables entre enero y diciembre de 2021 fue de: %.4f GWh\n", diferencia2021);
        diferencia2021 = diferencia_energia(congeneracion, 0, 11);
        printf("La diferencia de energia por congeneracion entre enero y diciembre de 2021 fue de: %.4f GWh\n", diferencia2021);
        diferencia2021 = diferencia_energia(residuosnoren, 0, 11);
        printf("La diferencia de energia por reiduos no renovables entre enero y diciembre de 2021 fue de: %.4f GWh\n", diferencia2021);
        diferencia2021 = diferencia_energia(residuosren, 0, 11);
        printf("La diferencia de energia por residuos renovables entre enero y diciembre de 2021 fue de: %.4f GWh\n", diferencia2021);
        break;

            
    case 'w':
        diferencia2022 = diferencia_energia(hidraulica, 12, 23);
        printf("La diferencia de energia hidraulica entre enero y diciembre de 2022 fue de: %.4f GWh\n", diferencia2022);
        diferencia2022 = diferencia_energia(nuclear, 12, 23);
        printf("La diferencia de energia nuclear entre enero y diciembre de 2022 fue de: %.4f GWh\n", diferencia2022);
        diferencia2022 = diferencia_energia(turbinacion, 12, 23);
        printf("La diferencia de energia por turbinacion bombeo entre enero y diciembre de 2022 fue de: %.4f GWh\n", diferencia2022);
        diferencia2022 = diferencia_energia(carbon, 12, 23);
        printf("La diferencia de energia por carbon entre enero y diciembre de 2022 fue de: %.4f GWh\n", diferencia2022);
        diferencia2022 = diferencia_energia(motores, 12, 23);
        printf("La diferencia de energia por motores diesel entre enero y diciembre de 2022 fue de: %.4f GWh\n", diferencia2022);
        diferencia2022 = diferencia_energia(gas, 12, 23);
        printf("La diferencia de energia por turbinacion gas entre enero y diciembre de 2022 fue de: %.4f GWh\n", diferencia2022);
        diferencia2022 = diferencia_energia(vapor, 12, 23);
        printf("La diferencia de energia por turbinacion vapor entre enero y diciembre de 2022 fue de: %.4f GWh\n", diferencia2022);
        diferencia2022 = diferencia_energia(ciclocomb, 12, 23);
        printf("La diferencia de energia por ciclo combinado entre enero y diciembre de 2022 fue de: %.4f GWh\n", diferencia2022);
        diferencia2022 = diferencia_energia(hidroeol, 12, 23);
        printf("La diferencia de energia hidroeolica entre enero y diciembre de 2022 fue de: %.4f GWh\n", diferencia2022);
        diferencia2022 = diferencia_energia(eolica, 12, 23);
        printf("La diferencia de energia eolica entre enero y diciembre de 2022 fue de: %.4f GWh\n", diferencia2022);
        diferencia2022 = diferencia_energia(solarfoto, 12, 23);
        printf("La diferencia de energia solar fotovoltaica entre enero y diciembre de 2022 fue de: %.4f GWh\n", diferencia2022);
        diferencia2022 = diferencia_energia(solartermi, 12, 23);
        printf("La diferencia de energia solar termica entre enero y diciembre de 2022 fue de: %.4f GWh\n", diferencia2022);
        diferencia2022 = diferencia_energia(otrasren, 12, 23);
        printf("La diferencia de energia por otras renovables entre enero y diciembre de 2022 fue de: %.4f GWh\n", diferencia2022);
        diferencia2022 = diferencia_energia(congeneracion, 12, 23);
        printf("La diferencia de energia por congeneracion entre enero y diciembre de 2022 fue de: %.4f GWh\n", diferencia2022);
        diferencia2022 = diferencia_energia(residuosnoren, 12, 23);
        printf("La diferencia de energia por residuos no renovables entre enero y diciembre de 2022 fue de: %.4f GWh\n", diferencia2022);
        diferencia2022 = diferencia_energia(residuosren, 12, 23);
        printf("La diferencia de energia por residuos renovables entre enero y diciembre de 2022 fue de: %.4f GWh\n", diferencia2022);
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


float diferencia_energia(float vector[], int mes_inicio, int mes_fin)
{
    float energia_inicio = vector[mes_inicio];
    float energia_fin = vector[mes_fin];

    // Considerar la diferencia entre un número menor y otro mayor
    if (energia_inicio > energia_fin)
        {
        return energia_inicio - energia_fin;
        }
        else
            {
        return energia_fin - energia_inicio;
            }
}



