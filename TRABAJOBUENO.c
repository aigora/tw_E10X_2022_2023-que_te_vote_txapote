#include <stdio.h>

//Prototipo de la funci�n
float PromedioEnergia(float energia[], int n);
float maximo(float vector[], int numelementos);
float minimo(float vector[], int num_elementos);
float diferencia_energia(float vector[], int mes_inicio, int mes_fin);

typedef struct
{
    char mes [100]; // En el a�o 20221
    float dem; // En GW/h, de la demanda total a nivel nacional de todas las energias juntas
    float emisiones_CO2; // en tCO2 eq. las emisiones nacionales de CO2 mensualmente en el a�o 2021

}demanda;
float max(demanda mensual[], int Mes);
float minim(demanda mensual[], int Mes);
float promedio(demanda mensual[], int Mes);

float maxim(demanda mensual[], int Mes);
float min(demanda mensual[], int Mes);
float prom(demanda mensual[], int Mes);


int main()
{
    int result_demanda_min;
    int result_demanda_max;
    float promed;

    int result_emisiones_max;
    int result_emisiones_min;
    float prome;

    demanda mensual[12] = {{"Enero",23.909,2859091 }, {"Febrero", 20.182, 1783746}, {"Marzo", 21.823, 2244987}, {"Abril",19.940, 2683142}, {"Mayo",20.347,2376488}, {"Junio",20.728, 2971569}, {"Julio", 22.922,2938935},
                           { "Agosto", 22.060,3070670}, {"Septiembre", 20.973, 3601296}, {"Octubre", 20.197, 3400058}, {"Noviembre",21.433, 4137428} , {"Diciembre",22.030, 3840931}};
    int i, n;
    //Crear 16 vectores (cada uno de ellos representa un tipo de energ�a o producci�n de la misma
    //con una capacidad para 24 elementos, de los cuales los 12 primeros pertenecen a los 12 meses del a�o 2021 y los 12 restantes a los 12 meses del a�o 2022
    float hidraulica[24],turbinacion[24],nuclear[24], carbon[24],motores[24],gas[24],vapor[24],ciclocomb[24],
          hidroeol[24],eolica[24],solarfoto[24],solartermi[24],otrasren[24],congeneracion[24],residuosnoren[24],
          residuosren[24];
    char c[20];
    //Variables auxiliares
    char aux,aux1,aux2,aux3,aux4;
   float promedio_hid, promedio_nuc, promedio_turbi_bombeo, promedio_carbon, promedio_motordie, promedio_turbi_gas, promedio_turbi_vapor, promedio_ciclo_comb, promedio_hidroeolica,promedio_eolica,
          promedio_sol_foto, promedio_sol_termi , promedio_otras_ren , promedio_congeneracion, promedio_residuos_no_ren, promedio_residuos_ren;
    float resultado_max_hid, resultado_max_nuc, resultado_max_turbi, resultado_max_carbon, resultado_max_motores, resultado_max_gas, resultado_max_vapor, resultado_max_ciclo, resultado_max_hidroeol, resultado_max_eolica, resultado_max_solarfoto,
          resultado_max_solartermi, resultado_max_otrasren, resultado_max_congeneracion, resultado_max_residuosnoren, resultado_max_residuosren;
    float resultado_min_hid, resultado_min_nuc, resultado_min_turbi, resultado_min_carbon, resultado_min_motores, resultado_min_gas, resultado_min_vapor, resultado_min_ciclo, resultado_min_hidroeol, resultado_min_eolica, resultado_min_solarfoto,
          resultado_min_solartermi, resultado_min_otrasren, resultado_min_congeneracion, resultado_min_residuosnoren, resultado_min_residuosren;
    float diferencia2021_hid, diferencia2021_nuc, diferencia2021_turbi, diferencia2021_carbon, diferencia2021_motores, diferencia2021_gas, diferencia2021_vapor, diferencia2021_ciclo, diferencia2021_hidroeol, diferencia2021_eolica, diferencia2021_solarfoto, diferencia2021_solartermi,
          diferencia2021_otrasren, diferencia2021_congeneracion, diferencia2021_residuosnoren, diferencia2021_residuosren;
    float diferencia2022_hid, diferencia2022_nuc, diferencia2022_turbi, diferencia2022_carbon, diferencia2022_motores, diferencia2022_gas, diferencia2022_vapor, diferencia2022_ciclo, diferencia2022_hidroeol, diferencia2022_eolica, diferencia2022_solarfoto, diferencia2022_solartermi, diferencia2022_otrasren, diferencia2022_congeneracion,
          diferencia2022_residuosnoren, diferencia2022_residuosren;



    //Abrir el fichero (excel) en modo lectura
    FILE *pf;
    pf = fopen("C:/Users/aleja/Downloads/generacion_por_tecnologias_21_22_puntos_simplificado.csv", "r"); // Abrimos fichero para lectura //C:/Users/annar/Downloads/generacion_por_tecnologias_21_22_puntos_simplificado.csv
    // Leemos datos separados por comas   //C:/Users/annar/Downloads/generacion_por_tecnologias_21_22_puntos_simplificado (1).

    if (pf==NULL) //HACERLO SIEMPRE PARA VER SI ESTA TODO BIEN
    {
        printf("Error al abrir el archivo de lectura .\n");
        return -1;
    }


  //Programar cinco bucles de tipo 'while' para poder saltar las cinco primeras l�neas del fichero
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




    //Leer cada l�nea del fichero e ir almacenando estos datos en un vector independiente
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



    //Cerrar el fichero de lectura
    fclose(pf);


    //Programar el men� con las opciones
    printf("\n\n\nPulse la tecla 'p' para realizar el promedio de todos los tipos de energias\n");
    printf("\nPulse la tecla 'm' para observar el numero maximo de cada tipo de energia generada\n");
    printf("\nPulse la tecla 'n' para observar el numero minimo de cada tipo de energia generada\n");
    printf("\nPulse la tecla 'z' para observar la diferencia entre la energia producida entre el mes de enero y de diciembre de 2021\n");
    printf("\nPulse la tecla 'w' para observar la diferencia entre la energia producida entre el mes de enero y de diciembre de 2022\n");
    printf("\nPulse la tecla 't' para observar el maximo (mensual), minimo(mensual) y el promedio (anual), de la demanda total de energias en el a�o 2021 ");
    printf("\nPulse la tecla 'r' para observar el maximo (mensual), minimo(mensual) y el promedio (anual), de la emisi�n de Co2  en el a�o 2021 ");
    char tecla;
    scanf("%c ", &tecla);

    switch (tecla)
    {
    case 'p':  //Promedio de las enrgias/m�todos de producci�n
        promedio_hid = PromedioEnergia(hidraulica, 24);
        promedio_nuc = PromedioEnergia(nuclear,24);
        promedio_turbi_bombeo = PromedioEnergia(turbinacion,24);
        promedio_carbon = PromedioEnergia(carbon,24);
        promedio_motordie = PromedioEnergia(motores,24);
        promedio_turbi_gas = PromedioEnergia(gas,24);
        promedio_turbi_vapor = PromedioEnergia(vapor,24);
        promedio_ciclo_comb = PromedioEnergia(ciclocomb,24);
        promedio_hidroeolica = PromedioEnergia(hidroeol,24);
        promedio_eolica = PromedioEnergia(eolica,24);
        promedio_sol_foto = PromedioEnergia(solarfoto, 24);
        promedio_sol_termi = PromedioEnergia(solartermi,24);
        promedio_otras_ren = PromedioEnergia(otrasren,24);
        promedio_congeneracion = PromedioEnergia(congeneracion,24);
        promedio_residuos_no_ren = PromedioEnergia(residuosnoren,24);
        promedio_residuos_ren = PromedioEnergia(residuosren,24);

            //Imprimirlo por pantalla
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

    case 'm':   //M�ximo de las enrgias/m�todos de producci�n
        resultado_max_hid = maximo(hidraulica, 24);
        resultado_max_nuc = maximo(nuclear, 24);
        resultado_max_turbi = maximo(turbinacion, 24);
        resultado_max_carbon = maximo(carbon, 24);
        resultado_max_motores = maximo(motores, 24);
        resultado_max_gas = maximo(gas, 24);
        resultado_max_vapor = maximo(vapor, 24);
        resultado_max_ciclo = maximo(ciclocomb, 24);
        resultado_max_hidroeol = maximo(hidroeol, 24);
        resultado_max_eolica = maximo(eolica, 24);
        resultado_max_solarfoto = maximo(solarfoto, 24);
        resultado_max_solartermi = maximo(solartermi, 24);
        resultado_max_otrasren = maximo(otrasren, 24);
        resultado_max_congeneracion = maximo(congeneracion, 24);
        resultado_max_residuosnoren = maximo(residuosnoren, 24);
        resultado_max_residuosren = maximo(residuosren, 24);

           //Imprimirlo por pantalla
        printf("La energia hidraulica maxima es %f GWh\n", resultado_max_hid);
        printf("La energia nuclear maxima es %f GWh\n", resultado_max_nuc);
        printf("La energia por turbinacion bombeo maxima es %f GWh\n", resultado_max_turbi);
        printf("La energia por carbon maxima es %f GWh\n", resultado_max_carbon);
        printf("La energia por motores diesel maxima es %f GWh\n", resultado_max_motores);
        printf("La energia por turbinacion gas maxima es %f GWh\n", resultado_max_gas);
        printf("La energia por turbinacion vapor maxima es %f GWh\n", resultado_max_vapor);
        printf("La energia por ciclo combinado maxima es %f GWh\n", resultado_max_ciclo);
        printf("La energia hidroeolica maxima es %f GWh\n", resultado_max_hidroeol);
        printf("La energia eolica maxima es %f GWh\n", resultado_max_eolica);
        printf("La energia solar fotovoltaica maxima es %f GWh\n", resultado_max_solarfoto);
        printf("La energia solar termica maxima es %f GWh\n", resultado_max_solartermi);
        printf("La energia por otras renovables maxima es %f GWh\n", resultado_max_otrasren);
        printf("La energia por congeneracion maxima es %f GWh\n", resultado_max_congeneracion);
        printf("La energia por residuos no renovables maxima es %f GWh\n", resultado_max_residuosnoren);
        printf("La energia por residuos renovables maxima es %f GWh\n", resultado_max_residuosren);

        break;


    case 'n':    //M�nimo de las enrgias/m�todos de producci�n
        resultado_min_hid = minimo(hidraulica, 24);
        resultado_min_nuc = minimo(nuclear, 24);
        resultado_min_turbi = minimo(turbinacion, 24);
        resultado_min_carbon = minimo(carbon, 24);
        resultado_min_motores = minimo(motores, 24);
        resultado_min_gas = minimo(gas, 24);
        resultado_min_vapor = minimo(vapor, 24);
        resultado_min_ciclo = minimo(ciclocomb, 24);
        resultado_min_hidroeol = minimo(hidroeol, 24);
        resultado_min_eolica = minimo(eolica, 24);
        resultado_min_solarfoto = minimo(solarfoto, 24);
        resultado_min_solartermi = minimo(solartermi, 24);
        resultado_min_otrasren = minimo(otrasren, 24);
        resultado_min_congeneracion = minimo(congeneracion, 24);
        resultado_min_residuosnoren = minimo(residuosnoren, 24);
        resultado_min_residuosren = minimo(residuosren, 24);

            //Imprimirlo por pantalla
        printf("La energia hidraulica minima es %f GWh\n", resultado_min_hid);
        printf("La energia nuclear minima es %f GWh\n", resultado_min_nuc);
        printf("La energia por turbinacion bombeo minima es %f GWh\n", resultado_min_turbi);
        printf("La energia por carbon minima es %f GWh\n", resultado_min_carbon);
        printf("La energia por motores diesel minima es %f GWh\n", resultado_min_motores);
        printf("La energia por turbinacion gas minima es %f GWh\n", resultado_min_gas);
        printf("La energia por turbinacion vapor minima es %f GWh\n", resultado_min_vapor);
        printf("La energia por ciclo combinado minima es %f GWh\n", resultado_min_ciclo);
        printf("La energia hidroeolica minima es %f GWh\n", resultado_min_hidroeol);
        printf("La energia eolica minima es %f GWh\n", resultado_min_eolica);
        printf("La energia solar fotovoltaica minima es %f GWh\n", resultado_min_solarfoto);
        printf("La energia solar termica es %f GWh\n", resultado_min_solartermi);
        printf("La energia de otras renovables minima es %f GWh\n", resultado_min_otrasren);
        printf("La energia por congeneracion minima es %f GWh\n", resultado_min_congeneracion);
        printf("La energia por residuos no renovables minima es %f GWh\n", resultado_min_residuosnoren);
        printf("La energia por residuos renovables minima es %f GWh\n", resultado_min_residuosren);
        break;

    case 'z':     //Diferencia de las enrgias/m�todos de producci�n en 2021
        diferencia2021_hid = diferencia_energia(hidraulica, 0, 11);
        diferencia2021_nuc = diferencia_energia(nuclear, 0, 11);
        diferencia2021_turbi = diferencia_energia(turbinacion, 0, 11);
        diferencia2021_carbon = diferencia_energia(carbon, 0, 11);
        diferencia2021_motores = diferencia_energia(motores, 0, 11);
        diferencia2021_gas = diferencia_energia(gas, 0, 11);
        diferencia2021_vapor = diferencia_energia(vapor, 0, 11);
        diferencia2021_ciclo = diferencia_energia(ciclocomb, 0, 11);
        diferencia2021_hidroeol = diferencia_energia(hidroeol, 0, 11);
        diferencia2021_eolica = diferencia_energia(eolica, 0, 11);
        diferencia2021_solarfoto = diferencia_energia(solarfoto, 0, 11);
        diferencia2021_solartermi = diferencia_energia(solartermi, 0, 11);
        diferencia2021_otrasren = diferencia_energia(otrasren, 0, 11);
        diferencia2021_congeneracion = diferencia_energia(congeneracion, 0, 11);
        diferencia2021_residuosnoren = diferencia_energia(residuosnoren, 0, 11);
        diferencia2021_residuosren = diferencia_energia(residuosren, 0, 11);

            //Imprimirlo por pantalla
        printf("La diferencia de energia hidraulica entre enero y diciembre de 2021 fue de: %.4f GWh\n", diferencia2021_hid);
        printf("La diferencia de energia nuclear entre enero y diciembre de 2021 fue de: %.4f GWh\n", diferencia2021_nuc);
        printf("La diferencia de energia por turbinacion bombeo entre enero y diciembre de 2021 fue de: %.4f GWh\n", diferencia2021_turbi);
        printf("La diferencia de energia por carbon entre enero y diciembre de 2021 fue de: %.4f GWh\n", diferencia2021_carbon);
        printf("La diferencia de energia por motores diesel entre enero y diciembre de 2021 fue de: %.4f GWh\n", diferencia2021_motores);
        printf("La diferencia de energia por turbinacion gas entre enero y diciembre de 2021 fue de: %.4f GWh\n", diferencia2021_gas);
        printf("La diferencia de energia por turbinacion vapor entre enero y diciembre de 2021 fue de: %.4f GWh\n", diferencia2021_vapor);
        printf("La diferencia de energia por ciclo combinado entre enero y diciembre de 2021 fue de: %.4f GWh\n", diferencia2021_ciclo);
        printf("La diferencia de energia hidroeolica entre enero y diciembre de 2021 fue de: %.4f GWh\n", diferencia2021_hidroeol);
        printf("La diferencia de energia eolica entre enero y diciembre de 2021 fue de: %.4f GWh\n", diferencia2021_eolica);
        printf("La diferencia de energia solar fotovoltaica entre enero y diciembre de 2021 fue de: %.4f GWh\n", diferencia2021_solarfoto);
        printf("La diferencia de energia solar termica entre enero y diciembre de 2021 fue de: %.4f GWh\n", diferencia2021_solartermi);
        printf("La diferencia de energia de otras renovables entre enero y diciembre de 2021 fue de: %.4f GWh\n", diferencia2021_otrasren);
        printf("La diferencia de energia por congeneracion entre enero y diciembre de 2021 fue de: %.4f GWh\n", diferencia2021_congeneracion);
        printf("La diferencia de energia por reiduos no renovables entre enero y diciembre de 2021 fue de: %.4f GWh\n", diferencia2021_residuosnoren);
        printf("La diferencia de energia por residuos renovables entre enero y diciembre de 2021 fue de: %.4f GWh\n", diferencia2021_residuosren);
        break;


    case 'w':    //Diferencia de las enrgias/m�todos de producci�n en 2022
        diferencia2022_hid = diferencia_energia(hidraulica, 12, 23);
        diferencia2022_nuc = diferencia_energia(nuclear, 12, 23);
        diferencia2022_turbi = diferencia_energia(turbinacion, 12, 23);
        diferencia2022_carbon = diferencia_energia(carbon, 12, 23);
        diferencia2022_motores = diferencia_energia(motores, 12, 23);
        diferencia2022_gas = diferencia_energia(gas, 12, 23);
        diferencia2022_vapor = diferencia_energia(vapor, 12, 23);
        diferencia2022_ciclo = diferencia_energia(ciclocomb, 12, 23);
        diferencia2022_hidroeol = diferencia_energia(hidroeol, 12, 23);
        diferencia2022_eolica = diferencia_energia(eolica, 12, 23);
        diferencia2022_solarfoto = diferencia_energia(solarfoto, 12, 23);
        diferencia2022_solartermi = diferencia_energia(solartermi, 12, 23);
        diferencia2022_otrasren = diferencia_energia(otrasren, 12, 23);
        diferencia2022_congeneracion = diferencia_energia(congeneracion, 12, 23);
        diferencia2022_residuosnoren = diferencia_energia(residuosnoren, 12, 23);
        diferencia2022_residuosren = diferencia_energia(residuosren, 12, 23);

            //Imprimirlo por pantalla
        printf("La diferencia de energia hidraulica entre enero y diciembre de 2022 fue de: %.4f GWh\n", diferencia2022_hid);
        printf("La diferencia de energia nuclear entre enero y diciembre de 2022 fue de: %.4f GWh\n", diferencia2022_nuc);
        printf("La diferencia de energia por turbinacion bombeo entre enero y diciembre de 2022 fue de: %.4f GWh\n", diferencia2022_turbi);
        printf("La diferencia de energia por carbon entre enero y diciembre de 2022 fue de: %.4f GWh\n", diferencia2022_carbon);
        printf("La diferencia de energia por motores diesel entre enero y diciembre de 2022 fue de: %.4f GWh\n", diferencia2022_motores);
        printf("La diferencia de energia por turbinacion gas entre enero y diciembre de 2022 fue de: %.4f GWh\n", diferencia2022_gas);
        printf("La diferencia de energia por turbinacion vapor entre enero y diciembre de 2022 fue de: %.4f GWh\n", diferencia2022_vapor);
        printf("La diferencia de energia por ciclo combinado entre enero y diciembre de 2022 fue de: %.4f GWh\n", diferencia2022_ciclo);
        printf("La diferencia de energia hidroeolica entre enero y diciembre de 2022 fue de: %.4f GWh\n", diferencia2022_hidroeol);
        printf("La diferencia de energia eolica entre enero y diciembre de 2022 fue de: %.4f GWh\n", diferencia2022_eolica);
        printf("La diferencia de energia solar fotovoltaica entre enero y diciembre de 2022 fue de: %.4f GWh\n", diferencia2022_solarfoto);
        printf("La diferencia de energia solar termica entre enero y diciembre de 2022 fue de: %.4f GWh\n", diferencia2022_solartermi);
        printf("La diferencia de energia por otras renovables entre enero y diciembre de 2022 fue de: %.4f GWh\n", diferencia2022_otrasren);
        printf("La diferencia de energia por congeneracion entre enero y diciembre de 2022 fue de: %.4f GWh\n", diferencia2022_congeneracion);
        printf("La diferencia de energia por residuos no renovables entre enero y diciembre de 2022 fue de: %.4f GWh\n", diferencia2022_residuosnoren);
        printf("La diferencia de energia por residuos renovables entre enero y diciembre de 2022 fue de: %.4f GWh\n", diferencia2022_residuosren);
       break;

    case 't':
        result_demanda_max=max(mensual, 12);
    printf("El mes que mas se ha generado ha sido %s con un total de  %f GW/h:\n", mensual[result_demanda_max].mes, mensual[result_demanda_max].dem);

    result_demanda_min= minim(mensual, 12);
    printf("El mes que menos se ha generado ha sido %s con un total de  %f GW/h:\n", mensual[result_demanda_min].mes, mensual[result_demanda_min].dem);

    promed= promedio(mensual, 12);
    printf(" El promedio de la energia demandada en 2021 es = %f:\n", promed);
       break;

    case 'r':

    result_emisiones_max= maxim(mensual,12);
    printf( "El mes que mas CO2 se ha emitido ha sido %s con un total de %f tCo2 eq. :\n", mensual [result_emisiones_max].mes, mensual[result_emisiones_max].emisiones_CO2);

    result_emisiones_min = min(mensual, 12);
    printf( "El mes que menos CO2 se ha emitido ha sido %s con un total de %f tCo2 eq. :\n", mensual [result_emisiones_min].mes, mensual[result_emisiones_min].emisiones_CO2);

    prome = prom( mensual,12);
    printf(" El promedio de la emision de Co2 en 2021 es = %f:\n", prome);
        break;

    default:
        printf("Se ha equivocado de tecla");


    }

    //Almacenamos todos los resultados en un nuevo fichero llamado results en modo lectura
    pf = fopen("C:/Users/aleja/Downloads/Informatica.txt", "w");
    if (pf==NULL) //HACERLO SIEMPRE PARA VER SI ESTA TODO BIEN
    {
        printf("Error al abrir el archivo de lectura .\n");
        return -1;
    }

    //Escribir en el nuevo fichero los resultados para el promedio
    fprintf(pf, "El promedio de la energia hidraulica es %f\n",promedio_hid);
    fprintf(pf, "El promedio de la energia nuclear es %f- GWh\n", promedio_nuc);
    fprintf(pf, "El promedio de la energia creada a traves del proceso de turbinacion bombeo es %f GWh\n", promedio_turbi_bombeo);
    fprintf(pf, "El promedio de la energia creada a traves del carbon es %f GWh\n", promedio_carbon);
    fprintf(pf, "El promedio de la energia creada a traves del proceso de turbinacion gas es %f GWh\n", promedio_turbi_gas);
    fprintf(pf, "El promedio de la energia creada a traves del motor diesel es %f GWh\n", promedio_motordie);
    fprintf(pf, "El promedio de la energia creada a traves del proceso de turbinacion vapor es %f GWh\n", promedio_turbi_vapor);
    fprintf(pf, "El promedio de la energia creada a traves del ciclo combinado es %f GWh\n", promedio_ciclo_comb);
    fprintf(pf, "El promedio de la energia hidroeolica es %f GWh\n", promedio_hidroeolica);
    fprintf(pf, "El promedio de la energia eolica es %f GWh\n", promedio_eolica);
    fprintf(pf, "El promedio de la energia solar fotovoltaica es %fGWh\n", promedio_sol_foto);
    fprintf(pf, "El promedio de la energia solar termica es %f GWh\n", promedio_sol_termi);
    fprintf(pf, "El promedio de le energia de otras renovables es %f GWh\n", promedio_otras_ren);
    fprintf(pf, "El promedio de la energia creada a traves de la congeneracion es %f GWh\n", promedio_congeneracion);
    fprintf(pf, "El promedio de la energia creada a traves de residuos renovables es %f GWh\n", promedio_residuos_ren);
    fprintf(pf, "El promedio de la energia creada a traves de residuos no renovables es %f GWh\n", promedio_residuos_no_ren);

    //Escribir en el nuevo fichero los resultados para el m�ximo y el m�nimo
    fprintf(pf, "La energia hidraulica maxima es %f GWh y la minima es %f Gwh\n", resultado_max_hid, resultado_min_hid);
    fprintf(pf,"La energia nuclear maxima es %f GWh y la minima es %f Gwh\n", resultado_max_nuc,resultado_min_nuc);
    fprintf(pf,"La energia por turbinacion bombeo maxima es %f GWh y la minima es %f Gwh\n", resultado_max_turbi,resultado_min_turbi);
    fprintf(pf,"La energia por carbon maxima es %f GWh y la minima es %f Gwh\n", resultado_max_carbon,resultado_min_carbon);
    fprintf(pf,"La energia por motores diesel maxima es %f GWh y la minima es %f Gwh\n", resultado_max_motores,resultado_min_motores);
    fprintf(pf,"La energia por turbinacion gas maxima es %f GWh y la minima es %f Gwh\n", resultado_max_gas,resultado_min_gas);
    fprintf(pf,"La energia por turbinacion vapor maxima es %f GWh y la minima es %f Gwh\n", resultado_max_vapor,resultado_min_vapor);
    fprintf(pf,"La energia por ciclo combinado maxima es %f GWh y la minima es %f Gwh\n", resultado_max_ciclo,resultado_min_ciclo);
    fprintf(pf,"La energia hidroeolica maxima es %f GWh y la minima es %f Gwh\n", resultado_max_hidroeol,resultado_min_hidroeol);
    fprintf(pf,"La energia eolica maxima es %f GWh y la minima es %f Gwh\n", resultado_max_eolica,resultado_min_eolica);
    fprintf(pf,"La energia solar fotovoltaica maxima es %f GWh y la minima es %f Gwh\n", resultado_max_solarfoto,resultado_min_solarfoto);
    fprintf(pf,"La energia solar termica maxima es %f GWh y la minima es %f Gwh\n", resultado_max_solartermi,resultado_min_solartermi);
    fprintf(pf,"La energia por otras renovables maxima es %f GWh y la minima es %f Gwh\n", resultado_max_otrasren,resultado_min_otrasren);
    fprintf(pf,"La energia por congeneracion maxima es %f GWh y la minima es %f Gwh\n", resultado_max_congeneracion,resultado_min_congeneracion);
    fprintf(pf,"La energia por residuos no renovables maxima es %f GWh y la minima es %f Gwh\n", resultado_max_residuosnoren,resultado_min_residuosnoren);
    fprintf(pf,"La energia por residuos renovables maxima es %f GWh y la minima es %f Gwh\n", resultado_max_residuosren,resultado_min_residuosren);

    //Escribir en el nuevo fichero los resultados de la diferencia
    fprintf(pf,"La diferencia de energia hidraulica entre enero y diciembre de 2021 fue de: %.4f GWh y de 2022 fue de: %.4f GWh\n", diferencia2021_hid, diferencia2022_hid);
    fprintf(pf,"La diferencia de energia nuclear entre enero y diciembre de 2021 fue de: %.4f GWh y de 2022 fue de: %.4f GWh\n", diferencia2021_nuc, diferencia2022_nuc);
    fprintf(pf,"La diferencia de energia por turbinacion bombeo entre enero y diciembre de 2021 fue de: %.4f GWh y de 2022 fue de: %.4f GWh\n", diferencia2021_turbi, diferencia2022_turbi);
    fprintf(pf,"La diferencia de energia por carbon entre enero y diciembre de 2021 fue de: %.4f GWh y de 2022 fue de: %.4f GWh\n", diferencia2021_carbon, diferencia2022_carbon);
    fprintf(pf,"La diferencia de energia por motores diesel entre enero y diciembre de 2021 fue de: %.4f GWh y de 2022 fue de: %.4f GWh\n", diferencia2021_motores, diferencia2022_motores);
    fprintf(pf,"La diferencia de energia por turbinacion gas entre enero y diciembre de 2021 fue de: %.4f GWh y de 2022 fue de: %.4f GWh\n", diferencia2021_gas, diferencia2022_gas);
    fprintf(pf,"La diferencia de energia por turbinacion vapor entre enero y diciembre de 2021 fue de: %.4f GWh y de 2022 fue de: %.4f GWh\n", diferencia2021_vapor, diferencia2022_vapor);
    fprintf(pf,"La diferencia de energia por ciclo combinado entre enero y diciembre de 2021 fue de: %.4f GWh y de 2022 fue de: %.4f GWh\n", diferencia2021_ciclo, diferencia2022_ciclo);
    fprintf(pf,"La diferencia de energia hidroeolica entre enero y diciembre de 2021 fue de: %.4f GWh y de 2022 fue de: %.4f GWh\n", diferencia2021_hidroeol, diferencia2022_hidroeol);
    fprintf(pf,"La diferencia de energia eolica entre enero y diciembre de 2021 fue de: %.4f GWh y de 2022 fue de: %.4f GWh\n", diferencia2021_eolica, diferencia2022_eolica);
    fprintf(pf,"La diferencia de energia solar fotovoltaica entre enero y diciembre de 2021 fue de: %.4f GWh y de 2022 fue de: %.4f GWh\n", diferencia2021_solarfoto, diferencia2022_solarfoto);
    fprintf(pf,"La diferencia de energia solar termica entre enero y diciembre de 2021 fue de: %.4f GWh y de 2022 fue de: %.4f GWh\n", diferencia2021_solartermi, diferencia2022_solartermi);
    fprintf(pf,"La diferencia de energia por otras renovables entre enero y diciembre de 2021 fue de: %.4f GWh y de 2022 fue de: %.4f GWh\n", diferencia2021_otrasren, diferencia2022_otrasren);
    fprintf(pf,"La diferencia de energia por congeneracion entre enero y diciembre de 2021 fue de: %.4f GWh y de 2022 fue de: %.4f GWh\n", diferencia2021_congeneracion, diferencia2022_congeneracion);
    fprintf(pf,"La diferencia de energia por residuos no renovables entre enero y diciembre de 2021 fue de: %.4f GWh y de 2022 fue de: %.4f GWh\n", diferencia2021_residuosnoren, diferencia2022_residuosnoren);
    fprintf(pf,"La diferencia de energia por residuos renovables entre enero y diciembre de 2021 fue de: %.4f GWh y de 2022 fue de: %.4f GWh\n", diferencia2021_residuosren, diferencia2022_residuosren);


    //Cerramos el fichero de escritura
    fclose(pf);

    return(0);
}

//Esta funci�n va a permitir al programa calcular el promedio de energ�a creada durante el a�o 2021 y 2022
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

//Esta funci�n va a permitir al programa calcular el m�ximo de energ�a creada en ambos a�os
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

//Esta funci�n va a permitir al programa calcular el minimo de energ�a creada en ambos a�os
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
    float maxim(demanda mensual[], int Mes) // funcion del maximo de emisiones de Co2
{
    int o, iMaX= 0, v=12;
    for(o=1; o<v; o++)
      if(mensual[o].emisiones_CO2> mensual[iMaX].emisiones_CO2)
    {
        iMaX = o;
    }
    return iMaX;
}

float max(demanda mensual[], int M) // funcion del maximo de la demanda de la energia
{
    int i, iMax= 0, n=12;
    for(i=1; i<n; i++)
      if(mensual[i].dem > mensual[iMax].dem)
    {
        iMax = i;
    }
    return iMax;
}

float min(demanda mensual[], int Z) // funcion minimo de las emisiones de CO2
{
    int e, iMiN= 0, d=12;
    for(e=1; e<d; e++)
      if(mensual[e].emisiones_CO2 < mensual[iMiN].emisiones_CO2)
    {
        iMiN = e;
    }
    return iMiN;
}

float minim(demanda mensual[], int W) // funcion minimo de la demanda de energia
{
    int i, iMin= 0, p=12;
    for(i=1; i<p; i++)
      if(mensual[i].dem < mensual[iMin].dem)
    {
        iMin = i;
    }
    return iMin;
}
float promedio(demanda mensual[], int K)  // funcion del promedio de la demanda
{
    int u;
    float suma =0.0, resultado_medio=0.0;
    for(u=0; u<12; u++)
    {
        suma = suma + mensual[u].dem;
    }
    resultado_medio = suma/12;
    return resultado_medio;
}

float prom(demanda mensual[], int T) //funcion del promedio de las emisiones de C02
{
    int a;
    float sum =0.0, result_medio=0.0;
    for(a=0; a<12; a++)
    {
        sum = sum + mensual[a].emisiones_CO2;
    }
    result_medio = sum/12;
    return result_medio;
}


//Esta funci�n va a permitir al programa calcular la diferencia de energ�a entre el mes de enero y de diciembre tanto del a�o 2021 como del 2022
float diferencia_energia(float vector[], int mes_inicio, int mes_fin)
{
    float energia_inicio = vector[mes_inicio];
    float energia_fin = vector[mes_fin];

    // Considerar la diferencia entre un n�mero menor y otro mayor
    if (energia_inicio > energia_fin)
        {
        return energia_inicio - energia_fin;
        }
        else
            {
        return energia_fin - energia_inicio;
            }
}

