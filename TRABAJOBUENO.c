#include <stdio.h>

typedef struct
{
    char mes [100]; // En el año 20221
    float dem; // En GW/h, de la demanda total a nivel nacional de todas las energias juntas
    float emisiones_CO2; // en tCO2 eq. las emisiones nacionales de CO2 mensualmente en el año 2021

}demanda;


//Prototipo de la función
float PromedioEnergia(float energia[], int n);
float maximo_energia_creada(float vector[], int numelementos);
float minimo_energia_creada(float vector[], int num_elementos);
float diferencia_energia(float vector[], int mes_inicio, int mes_fin);

float max_demanda(demanda mensual[], int Mes);
float minim_demanda(demanda mensual[], int Mes);
float promedio_demanda(demanda mensual[], int Mes);

float maxim_emsiones_Co2(demanda mensual[], int Mes);
float min_emsiones_Co2(demanda mensual[], int Mes);
float prom_emsiones_Co2(demanda mensual[], int Mes);


void leerfichero(float hidraulica[24], float turbinacion[24], float nuclear[24], float carbon[24], float motores[24],float gas[24], float vapor[24],
                  float ciclocomb[24], float hidroeol[24], float eolica[24], float solarfoto[24], float solartermi[24], float otrasren[24],
                  float congeneracion[24], float residuosnoren[24], float residuosren[24]);

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

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

    float hid[24],nuc[24],turb[24],carb[24],mot[24],gas[24],vap[24],ciclo[24],hidro[24],eol[24],solarf[24],solart[24],ren[24],cong[24],resno[24],resren[24];

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



    //Programar el menú con las opciones
    printf("               MENU             \n");
    printf("Elige una de las siguientes opciones: \n");
    printf("\t1.Mostrar datos\n\t2.Operaciones\n\t3.Comparacion de datos\n\t4.Salir\n");
    char op, op1, op2, op3, op4, op5;
    do
    {
        scanf("%i", &op);
        switch(op)
        {
        case 1:
            printf(" A continuación se mostrarán todos los resultados en un nuevo fichero");
            leerfichero(hid,turb,nuc,carb,mot,gas,vap,ciclo,hidro,eol,solarf,solart,ren,cong,resno,resren);
            break;
        case 2:
            printf("Cual de las siguientes operaciones desea realizar?\n");
            printf("  \t 1. -> Media\n\t 2. -> Maximo\n\t 3. -> Minimo\n\t");
                scanf("%d", &op1);
                switch (op1)
                {
                case 1:
                   printf("De qué quiere saber la media?\n");
                    printf("  \t 1. -> De cada energía por separado\n\t 2. -> De la demanda energética de todas las energías en 2021\n\t 3. -> De la emisión de Co2 de todas las energías en 2021 \n\t");
                        scanf("%d", &op2);
                        switch (op2)
                        {
                        case 1:
                             leerfichero(hid,turb,nuc,carb,mot,gas,vap,ciclo,hidro,eol,solarf,solart,ren,cong,resno,resren);

                             printf("El promedio de la energia hidraulica es %f GWh\n",PromedioEnergia(hid, 24));
                             printf("El promedio de la energia creada a traves del proceso de turbinacion bombeo es %f GWh\n", PromedioEnergia(turb, 24));
                             printf("El promedio de la energia nuclear es %f GWh\n", PromedioEnergia(nuc, 24));
                             printf("El promedio de la energia creada a traves del carbon es %f GWh\n", PromedioEnergia(carb, 24));
                             printf("El promedio de la energia creada a traves del motor diesel es %f GWh\n",PromedioEnergia(mot, 24));
                             printf("El promedio de la energia creada a traves del proceso de turbinacion gas es %f GWh\n", PromedioEnergia(gas, 24));
                             printf("El promedio de la energia creada a traves del proceso de turbinacion vapor es %f GWh\n", PromedioEnergia(vap, 24));
                             printf("El promedio de la energia creada a traves del ciclo combinado es %f GWh\n", PromedioEnergia(ciclo, 24));
                             printf("El promedio de la energia hidroeolica es %f GWh\n", PromedioEnergia(hidro, 24));
                             printf("El promedio de la energia eolica es %f GWh\n",PromedioEnergia(eol, 24));
                             printf("El promedio de la energia solar fotovoltaica es %fGWh\n", PromedioEnergia(solarf, 24));
                             printf("El promedio de la energia solar termica es %f GWh\n", PromedioEnergia(solart, 24));
                             printf("El promedio de le energia de otras renovables es %f GWh\n",PromedioEnergia(ren, 24));
                             printf("El promedio de la energia creada a traves de la congeneracion es %f GWh\n", PromedioEnergia(cong, 24));
                             printf("El promedio de la energia creada a traves de residuos no renovables es %f GWh\n", PromedioEnergia(resno, 24));
                             printf("El promedio de la energia creada a traves de residuos renovables es %f GWh\n",PromedioEnergia(resren, 24));
                             break;

                        case 2:
                             promed= promedio_demanda(mensual, 12);
                             printf("El promedio de la energia demandada en 2021 es = %f:\n", promed);
                             break;
                        case 3:
                             prome = prom_emsiones_Co2( mensual,12);
                             printf("El promedio de la emision de Co2 en 2021 es = %f:\n", prome);
                             break;
                        }
                case 2:
                   printf("De qué quiere saber el máximo?\n");
                    printf("  \t 1. -> De cada energía por separado\n\t 2. -> De la energía demandada en 2021 (por mes)\n\t 3. -> De la emisión de Co2 en 2021 \n\t");
                        scanf("%d", &op3);
                        switch (op3)
                        {
                        case 1:
                            leerfichero(hid,turb,nuc,carb,mot,gas,vap,ciclo,hidro,eol,solarf,solart,ren,cong,resno,resren);

                            printf("La energia hidraulica maxima es %f GWh\n", maximo_energia_creada(hid, 24));
                            printf("La energia por turbinacion bombeo maxima es %f GWh\n", maximo_energia_creada(turb, 24));
                            printf("La energia nuclear maxima es %f GWh\n", maximo_energia_creada(nuc, 24));
                            printf("La energia por carbon maxima es %f GWh\n", maximo_energia_creada(carb, 24));
                            printf("La energia por motores diesel maxima es %f GWh\n", maximo_energia_creada(mot, 24));
                            printf("La energia por turbinacion gas maxima es %f GWh\n", maximo_energia_creada(gas, 24));
                            printf("La energia por turbinacion vapor maxima es %f GWh\n", maximo_energia_creada(vap, 24));
                            printf("La energia por ciclo combinado maxima es %f GWh\n", maximo_energia_creada(ciclo, 24));
                            printf("La energia hidroeolica maxima es %f GWh\n", maximo_energia_creada(hidro, 24));
                            printf("La energia eolica maxima es %f GWh\n", maximo_energia_creada(eol, 24));
                            printf("La energia solar fotovoltaica maxima es %f GWh\n", maximo_energia_creada(solarf, 24));
                            printf("La energia solar termica maxima es %f GWh\n", maximo_energia_creada(solart, 24));
                            printf("La energia por otras renovables maxima es %f GWh\n", maximo_energia_creada(ren, 24));
                            printf("La energia por congeneracion maxima es %f GWh\n", maximo_energia_creada(cong, 24));
                            printf("La energia por residuos no renovables maxima es %f GWh\n", maximo_energia_creada(resno, 24));
                            printf("La energia por residuos renovables maxima es %f GWh\n", maximo_energia_creada(resren, 24));
                            break;
                        case 2:
                            result_demanda_max=max_demanda(mensual, 12);
                            printf("El mes que mas se ha demandad0 ha sido %s con un total de  %f GW/h:\n", mensual[result_demanda_max].mes, mensual[result_demanda_max].dem);
                            break;
                        case 3:
                            result_emisiones_max= maxim_emsiones_Co2(mensual,12);
                            printf( "El mes que mas CO2 se ha emitido ha sido %s con un total de %f tCo2 eq. :\n", mensual [result_emisiones_max].mes, mensual[result_emisiones_max].emisiones_CO2);
                            break;
                        }
                case 3:
                  printf("De qué quiere saber el máximo?\n");
                    printf("  \t 1. -> De cada energía por separado\n\t 2. -> De la energía demandada en 2021 (por mes)\n\t 3. -> De la emisión de Co2 en 2021 \n\t");
                        scanf("%d", &op4);
                        switch (op4)
                        {
                        case 1:
                            leerfichero(hid,turb,nuc,carb,mot,gas,vap,ciclo,hidro,eol,solarf,solart,ren,cong,resno,resren);

                            printf("La energia hidraulica minima es %f GWh\n", minimo_energia_creada(hid, 24));
                            printf("La energia por turbinacion bombeo minima es %f GWh\n", minimo_energia_creada(turb, 24));
                            printf("La energia nuclear minima es %f GWh\n", minimo_energia_creada(nuc, 24));
                            printf("La energia por carbon minima es %f GWh\n", minimo_energia_creada(carb, 24));
                            printf("La energia por motores diesel minima es %f GWh\n", minimo_energia_creada(mot, 24));
                            printf("La energia por turbinacion gas minima es %f GWh\n", minimo_energia_creada(gas, 24));
                            printf("La energia por turbinacion vapor minima es %f GWh\n", minimo_energia_creada(vap, 24));
                            printf("La energia por ciclo combinado minima es %f GWh\n", minimo_energia_creada(ciclo, 24));
                            printf("La energia hidroeolica minima es %f GWh\n", minimo_energia_creada(hidro, 24));
                            printf("La energia eolica minima es %f GWh\n", minimo_energia_creada(eol, 24));
                            printf("La energia solar fotovoltaica minima es %f GWh\n", minimo_energia_creada(solarf, 24));
                            printf("La energia solar termica es %f GWh\n", minimo_energia_creada(solart, 24));
                            printf("La energia de otras renovables minima es %f GWh\n", minimo_energia_creada(ren, 24));
                            printf("La energia por congeneracion minima es %f GWh\n", minimo_energia_creada(cong, 24));
                            printf("La energia por residuos no renovables minima es %f GWh\n", minimo_energia_creada(resno, 24));
                            printf("La energia por residuos renovables minima es %f GWh\n", minimo_energia_creada(resren, 24));
                            break;
                        case 2:
                            result_demanda_min= minim_demanda(mensual, 12);
                            printf("El mes que menos se ha demandado ha sido %s con un total de  %f GW/h:\n", mensual[result_demanda_min].mes, mensual[result_demanda_min].dem);
                            break;
                        case 3:
                            result_emisiones_min = min_emsiones_Co2(mensual, 12);
                            printf( "El mes que menos CO2 se ha emitido ha sido %s con un total de %f tCo2 eq. :\n", mensual [result_emisiones_min].mes, mensual[result_emisiones_min].emisiones_CO2);
                            break;
                        }
                    break;

                    }





        case 3:
            printf("De que desea año desea comparar la diferencia de energía/métodos de produccion?");
              printf(" \t 1. -> 2021 \n\t 2. -> 2022");
              scanf("%d", &op5);
              switch(op5)
              {
              case 1:
                  leerfichero(hid,turb,nuc,carb,mot,gas,vap,ciclo,hidro,eol,solarf,solart,ren,cong,resno,resren);

                  printf("La diferencia de energia hidraulica entre enero y diciembre de 2021 fue de: %.4f GWh\n", diferencia_energia(hid, 0, 11));
                  printf("La diferencia de energia nuclear entre enero y diciembre de 2021 fue de: %.4f GWh\n", diferencia_energia(nuc, 0, 11));
                  printf("La diferencia de energia por turbinacion bombeo entre enero y diciembre de 2021 fue de: %.4f GWh\n", diferencia_energia(turb, 0, 11));
                  printf("La diferencia de energia por carbon entre enero y diciembre de 2021 fue de: %.4f GWh\n", diferencia_energia(carb, 0, 11));
                  printf("La diferencia de energia por motores diesel entre enero y diciembre de 2021 fue de: %.4f GWh\n", diferencia_energia(mot, 0, 11));
                  printf("La diferencia de energia por turbinacion gas entre enero y diciembre de 2021 fue de: %.4f GWh\n", diferencia_energia(gas, 0, 11));
                  printf("La diferencia de energia por turbinacion vapor entre enero y diciembre de 2021 fue de: %.4f GWh\n", diferencia_energia(vap, 0, 11));
                  printf("La diferencia de energia por ciclo combinado entre enero y diciembre de 2021 fue de: %.4f GWh\n", diferencia_energia(ciclo, 0, 11));
                  printf("La diferencia de energia hidroeolica entre enero y diciembre de 2021 fue de: %.4f GWh\n", diferencia_energia(hidro, 0, 11));
                  printf("La diferencia de energia solar fotovoltaica entre enero y diciembre de 2021 fue de: %.4f GWh\n", diferencia_energia(solarf, 0, 11));
                  printf("La diferencia de energia solar termica entre enero y diciembre de 2021 fue de: %.4f GWh\n", diferencia_energia(solart, 0, 11));
                  printf("La diferencia de energia de otras renovables entre enero y diciembre de 2021 fue de: %.4f GWh\n", diferencia_energia(ren, 0, 11));
                  printf("La diferencia de energia por congeneracion entre enero y diciembre de 2021 fue de: %.4f GWh\n", diferencia_energia(cong, 0, 11));
                  printf("La diferencia de energia por reiduos no renovables entre enero y diciembre de 2021 fue de: %.4f GWh\n", diferencia_energia(resno, 0, 11));
                  printf("La diferencia de energia por residuos renovables entre enero y diciembre de 2021 fue de: %.4f GWh\n", diferencia_energia(resren, 0, 11));
                  break;

                case 2:
                  leerfichero(hid,turb,nuc,carb,mot,gas,vap,ciclo,hidro,eol,solarf,solart,ren,cong,resno,resren);

                  printf("La diferencia de energia hidraulica entre enero y diciembre de 2022 fue de: %.4f GWh\n", diferencia_energia(hid, 12, 23));
                  printf("La diferencia de energia nuclear entre enero y diciembre de 2022 fue de: %.4f GWh\n", diferencia_energia(nuc, 12, 23));
                  printf("La diferencia de energia por turbinacion bombeo entre enero y diciembre de 2022 fue de: %.4f GWh\n", diferencia_energia(turb, 12, 23));
                  printf("La diferencia de energia por carbon entre enero y diciembre de 2022 fue de: %.4f GWh\n", diferencia_energia(carb, 12, 23));
                  printf("La diferencia de energia por motores diesel entre enero y diciembre de 2022 fue de: %.4f GWh\n", diferencia_energia(mot, 12, 23));
                  printf("La diferencia de energia por turbinacion gas entre enero y diciembre de 2022 fue de: %.4f GWh\n", diferencia_energia(gas, 12, 23));
                  printf("La diferencia de energia por turbinacion vapor entre enero y diciembre de 2022 fue de: %.4f GWh\n", diferencia_energia(vap, 12, 23));
                  printf("La diferencia de energia por ciclo combinado entre enero y diciembre de 2022 fue de: %.4f GWh\n", diferencia_energia(ciclo, 12, 23));
                  printf("La diferencia de energia hidroeolica entre enero y diciembre de 2022 fue de: %.4f GWh\n", diferencia_energia(hidro, 12, 23));
                  printf("La diferencia de energia eolica entre enero y diciembre de 2022 fue de: %.4f GWh\n", diferencia_energia(eol, 12, 23));
                  printf("La diferencia de energia solar fotovoltaica entre enero y diciembre de 2022 fue de: %.4f GWh\n", diferencia_energia(solarf, 12, 23));
                  printf("La diferencia de energia solar termica entre enero y diciembre de 2022 fue de: %.4f GWh\n", diferencia_energia(solart, 12, 23));
                  printf("La diferencia de energia por otras renovables entre enero y diciembre de 2022 fue de: %.4f GWh\n", diferencia_energia(ren, 12, 23));
                  printf("La diferencia de energia por congeneracion entre enero y diciembre de 2022 fue de: %.4f GWh\n", diferencia_energia(cong, 12, 23));
                  printf("La diferencia de energia por residuos no renovables entre enero y diciembre de 2022 fue de: %.4f GWh\n", diferencia_energia(resno, 12, 23));
                  printf("La diferencia de energia por residuos renovables entre enero y diciembre de 2022 fue de: %.4f GWh\n", diferencia_energia(resno, 12, 23));
                  break;

               }

                default:
                    printf("Se ha equivocado de tecla\n");

                }

        break;


        }while (op!=4);




   /*

    case 'z':     //Diferencia de las enrgias/métodos de producción en 2021
        diferencia2021_hid = diferencia_energia(hid, 0, 11);
        diferencia2021_nuc = diferencia_energia(nuc, 0, 11);
        diferencia2021_turbi = diferencia_energia(turb, 0, 11);
        diferencia2021_carbon = diferencia_energia(carb, 0, 11);
        diferencia2021_motores = diferencia_energia(mot, 0, 11);
        diferencia2021_gas = diferencia_energia(gas, 0, 11);
        diferencia2021_vapor = diferencia_energia(vap, 0, 11);
        diferencia2021_ciclo = diferencia_energia(ciclo, 0, 11);
        diferencia2021_hidroeol = diferencia_energia(hidro, 0, 11);
        diferencia2021_eolica = diferencia_energia(eol, 0, 11);
        diferencia2021_solarfoto = diferencia_energia(solarf, 0, 11);
        diferencia2021_solartermi = diferencia_energia(solart, 0, 11);
        diferencia2021_otrasren = diferencia_energia(ren, 0, 11);
        diferencia2021_congeneracion = diferencia_energia(cong, 0, 11);
        diferencia2021_residuosnoren = diferencia_energia(resno, 0, 11);
        diferencia2021_residuosren = diferencia_energia(resren, 0, 11);

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


    case 'w':    //Diferencia de las enrgias/métodos de producción en 2022
        diferencia2022_hid = diferencia_energia(hid, 12, 23);
        diferencia2022_nuc = diferencia_energia(nuc, 12, 23);
        diferencia2022_turbi = diferencia_energia(turb, 12, 23);
        diferencia2022_carbon = diferencia_energia(carb, 12, 23);
        diferencia2022_motores = diferencia_energia(mot, 12, 23);
        diferencia2022_gas = diferencia_energia(gas, 12, 23);
        diferencia2022_vapor = diferencia_energia(vap, 12, 23);
        diferencia2022_ciclo = diferencia_energia(ciclo, 12, 23);
        diferencia2022_hidroeol = diferencia_energia(hidro, 12, 23);
        diferencia2022_eolica = diferencia_energia(eol, 12, 23);
        diferencia2022_solarfoto = diferencia_energia(solarf, 12, 23);
        diferencia2022_solartermi = diferencia_energia(solart, 12, 23);
        diferencia2022_otrasren = diferencia_energia(ren, 12, 23);
        diferencia2022_congeneracion = diferencia_energia(cong, 12, 23);
        diferencia2022_residuosnoren = diferencia_energia(resno, 12, 23);
        diferencia2022_residuosren = diferencia_energia(resren, 12, 23);

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
        result_demanda_max=max_demanda(mensual, 12);
    printf("El mes que mas se ha demandad0 ha sido %s con un total de  %f GW/h:\n", mensual[result_demanda_max].mes, mensual[result_demanda_max].dem);

    result_demanda_min= minim_demanda(mensual, 12);
    printf("El mes que menos se ha demandado ha sido %s con un total de  %f GW/h:\n", mensual[result_demanda_min].mes, mensual[result_demanda_min].dem);

    promed= promedio_demanda(mensual, 12);
    printf(" El promedio de la energia demandada en 2021 es = %f:\n", promed);
       break;

    case 'r':

    result_emisiones_max= maxim_emsiones_Co2(mensual,12);
    printf( "El mes que mas CO2 se ha emitido ha sido %s con un total de %f tCo2 eq. :\n", mensual [result_emisiones_max].mes, mensual[result_emisiones_max].emisiones_CO2);

    result_emisiones_min = min_emsiones_Co2(mensual, 12);
    printf( "El mes que menos CO2 se ha emitido ha sido %s con un total de %f tCo2 eq. :\n", mensual [result_emisiones_min].mes, mensual[result_emisiones_min].emisiones_CO2);

    prome = prom_emsiones_Co2( mensual,12);
    printf(" El promedio de la emision de Co2 en 2021 es = %f:\n", prome);
        break;

    default:
        printf("Se ha equivocado de tecla");


    }

    }
    while (tecla != 'f'); */

    //Almacenamos todos los resultados en un nuevo fichero llamado results en modo lectura
    FILE*pf;
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

    //Escribir en el nuevo fichero los resultados para el máximo y el mínimo
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

    // Escribir en el fichero el maximo y el minimo de la energia demandada así como el promedio de energía demandada
    fprintf(pf,"El mes que mas se ha demandad0 ha sido %s con un total de  %f GW/h:\n", mensual[result_demanda_max].mes, mensual[result_demanda_max].dem);
    fprintf(pf,"El mes que menos se ha demandado ha sido %s con un total de  %f GW/h:\n", mensual[result_demanda_min].mes, mensual[result_demanda_min].dem);
    fprintf(pf,"El promedio de la energia demandada en 2021 es = %f:\n", promed);

    // Escribir en el fichero el maximo y el minimo de las emisiones de Co2 así como el promedio de energía
    fprintf(pf, "El mes que mas CO2 se ha emitido ha sido %s con un total de %f tCo2 eq. :\n", mensual [result_emisiones_max].mes, mensual[result_emisiones_max].emisiones_CO2);
    fprintf(pf, "El mes que menos CO2 se ha emitido ha sido %s con un total de %f tCo2 eq. :\n", mensual [result_emisiones_min].mes, mensual[result_emisiones_min].emisiones_CO2);
    fprintf(pf, "El promedio de la emision de Co2 en 2021 es = %f:\n", prome);
    //Cerramos el fichero de escritura
    fclose(pf);

    return(0);
}

void leerfichero(float hidraulica[24], float turbinacion[24], float nuclear[24], float carbon[24], float motores[24],float gas[24], float vapor[24],
                  float ciclocomb[24], float hidroeol[24], float eolica[24], float solarfoto[24], float solartermi[24], float otrasren[24],
                  float congeneracion[24], float residuosnoren[24], float residuosren[24])
{
    int i, n;
    char c[20];
    //Variables auxiliares
    char aux,aux1,aux2,aux3,aux4;


    //Abrir el fichero (excel) en modo lectura
    FILE *pf;
    pf = fopen("C:/Users/aleja/Downloads/generacion_por_tecnologias_21_22_puntos_simplificado.csv", "r"); // Abrimos fichero para lectura //C:/Users/annar/Downloads/generacion_por_tecnologias_21_22_puntos_simplificado.csv
    // Leemos datos separados por comas   //C:/Users/annar/Downloads/generacion_por_tecnologias_21_22_puntos_simplificado (1).

    if (pf==NULL) //HACERLO SIEMPRE PARA VER SI ESTA TODO BIEN
    {
        printf("Error al abrir el archivo de lectura .\n");
        return -1;
    }


    //Programar cinco bucles de tipo 'while' para poder saltar las cinco primeras líneas del fichero
    while (aux != '\n')
    {
        fscanf(pf, "%c", &aux);
    }
    //printf("Ha cambiado de linea. \n");


    while (aux1 != '\n')
    {
        fscanf(pf, "%c", &aux1);
    }


    while (aux2 != '\n')
    {
        fscanf(pf, "%c", &aux2);
    }


    while (aux3 != '\n')
    {
        fscanf(pf, "%c", &aux3);
    }


    while (aux4 != '\n')
    {
        fscanf(pf, "%c", &aux4);
    }

    //Leer cada línea del fichero e ir almacenando estos datos en un vector independiente
    n = fscanf(pf, "%[^,]",c);
    for (i= 0; i< 24; i++)
    {
        n= fscanf(pf, ",%f", &hidraulica[i]);

      //  printf("%f \t", hidraulica[i]);
    }




    n = fscanf(pf, "%[^,]",c);
    for (i= 0; i< 24; i++)
    {
        n = fscanf(pf, ",%f", &turbinacion[i]);


      //  printf(" %f \t", turbinacion[i]);
    }


    n = fscanf(pf, "%[^,]",c);
    for (i= 0; i< 24; i++)
    {
        n = fscanf(pf, ",%f", &nuclear[i]);

      //  printf(" %f \t", nuclear[i]);
    }



    n = fscanf(pf, "%[^,]",c);
    for (i= 0; i< 24; i++)
    {
        n = fscanf(pf, ",%f", &carbon[i]);

      //  printf(" %f \t", carbon[i]);
    }




    n = fscanf(pf, "%[^,]",c);
    for (i= 0; i< 24; i++)
    {
        n = fscanf(pf, ",%f", &motores[i]);
      //  printf(" %f \t", motores[i]);
    }



    n = fscanf(pf, "%[^,]",c);
    for (i= 0; i< 24; i++)
    {
        n = fscanf(pf, ",%f", &gas[i]);

      //  printf(" %f \t", gas[i]);
    }




    n = fscanf(pf, "%[^,]",c);
    for (i= 0; i< 24; i++)
    {
        n = fscanf(pf, ",%f", &vapor[i]);

     //   printf(" %f \t", vapor[i]);
    }




    n = fscanf(pf, "%[^,]",c);
    for (i= 0; i< 24; i++)
    {
        n = fscanf(pf, ",%f", &ciclocomb[i]);

     //   printf(" %f \t", ciclocomb[i]);
    }



    n = fscanf(pf, "%[^,]",c);
    for (i= 0; i< 24; i++)
    {
        n = fscanf(pf, ",%f", &hidroeol[i]);
       // printf(" %f \t", hidroeol[i]);
    }




    n = fscanf(pf, "%[^,]",c);
    for (i= 0; i< 24; i++)
    {
        n = fscanf(pf, ",%f", &eolica[i]);

      //  printf(" %f \t", eolica[i]);

    }


    n = fscanf(pf, "%[^,]",c);
    for (i= 0; i< 24; i++)
    {
        n = fscanf(pf, ",%f", &solarfoto[i]);

      //  printf(" %f \t", solarfoto[i]);
    }




    n = fscanf(pf, "%[^,]",c);
    for (i= 0; i< 24; i++)
    {
        n = fscanf(pf, ",%f", &solartermi[i]);

      //  printf(" %f \t", solartermi[i]);
    }




    n = fscanf(pf, "%[^,]",c);
    for (i= 0; i< 24; i++)
    {
        n = fscanf(pf, ",%f", &otrasren[i]);

      //  printf(" %f \t", otrasren[i]);
    }




    n = fscanf(pf, "%[^,]",c);
    for (i= 0; i< 24; i++)
    {
        n = fscanf(pf, ",%f", &congeneracion[i]);

       // printf(" %f \t", congeneracion[i]);
    }



    n = fscanf(pf, "%[^,]",c);
    for (i= 0; i< 24; i++)
    {
        n = fscanf(pf, ",%f", &residuosnoren[i]);

       // printf(" %f \t", residuosnoren[i]);
    }


    n = fscanf(pf, "%[^,]",c);
    for (i= 0; i< 24; i++)
    {
        n = fscanf(pf, ",%f", &residuosren[i]);
       // printf(" %f \t", residuosren[i]);
    }



    //Cerrar el fichero de lectura
    fclose(pf);






}




//Esta función va a permitir al programa calcular el promedio de energía creada durante el año 2021 y 2022
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

//Esta función va a permitir al programa calcular el máximo de energía creada en ambos años
float maximo_energia_creada(float vector[], int num_elementos)
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

//Esta función va a permitir al programa calcular el minimo de energía creada en ambos años
float minimo_energia_creada(float vector[], int num_elementos)
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
    float maxim_emsiones_Co2(demanda mensual[], int Mes) // funcion del maximo de emisiones de Co2
{
    int o, iMaX= 0, v=12;
    for(o=1; o<v; o++)
      if(mensual[o].emisiones_CO2> mensual[iMaX].emisiones_CO2)
    {
        iMaX = o;
    }
    return iMaX;
}

float max_demanda(demanda mensual[], int M) // funcion del maximo de la demanda de la energia
{
    int i, iMax= 0, n=12;
    for(i=1; i<n; i++)
      if(mensual[i].dem > mensual[iMax].dem)
    {
        iMax = i;
    }
    return iMax;
}

float min_emsiones_Co2(demanda mensual[], int Z) // funcion minimo de las emisiones de CO2
{
    int e, iMiN= 0, d=12;
    for(e=1; e<d; e++)
      if(mensual[e].emisiones_CO2 < mensual[iMiN].emisiones_CO2)
    {
        iMiN = e;
    }
    return iMiN;
}

float minim_demanda(demanda mensual[], int W) // funcion minimo de la demanda de energia
{
    int i, iMin= 0, p=12;
    for(i=1; i<p; i++)
      if(mensual[i].dem < mensual[iMin].dem)
    {
        iMin = i;
    }
    return iMin;
}
float promedio_demanda(demanda mensual[], int K)  // funcion del promedio de la demanda
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

float prom_emsiones_Co2(demanda mensual[], int T) //funcion del promedio de las emisiones de C02
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


//Esta función va a permitir al programa calcular la diferencia de energía entre el mes de enero y de diciembre tanto del año 2021 como del 2022
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

