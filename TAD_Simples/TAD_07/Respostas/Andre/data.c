#include "data.h"
#include <stdio.h>
#include<stdlib.h>

tData CriaData(int dia, int mes, int ano)
{

    tData data;

    data.dia = dia, data.mes = mes, data.ano = ano;

    return data;
}

/**
 * @brief Verifica se uma data é válida.
 *
 * @param data Data a ser verificada.
 * @return int 1 se a data é válida, 0 caso contrário.
 */
int VerificaDataValida(tData data)
{

    if (data.dia > 31 || data.dia < 1)
    {

        return 0;
    }

    if (data.mes == 2)
    {

        if (VerificaBissexto(data))
        {

            if (data.dia > 29)
            {

                return 0;
            }
        }

        if (data.dia > 28)
        {

            return 0;
        }
    }

    if (data.mes < 1 || data.mes > 12)
    {

        return 0;
    }

    if (data.ano < 0)
    {

        return 0;
    }
    return 1;
}

/**
 * @brief Imprime o mês de uma data em formato extenso.
 *
 * @param data Data cujo mês será impresso em formato extenso.
 */
void ImprimeMesExtenso(tData data)
{

    switch (data.mes)
    {
    case 1:
        printf("Janeiro");
        break;
    case 2:
        printf("Fevereiro");
        break;
    case 3:
        printf("Março");
        break;
    case 4:
        printf("Abril");
        break;
    case 5:
        printf("Maio");
        break;
    case 6:
        printf("Junho");
        break;
    case 7:
        printf("Julho");
        break;
    case 8:
        printf("Agosto");
        break;
    case 9:
        printf("Setembro");
        break;
    case 10:
        printf("Outubro");
        break;
    case 11:
        printf("Novembro");
        break;
    case 12:
        printf("Dezembro");
        break;
    default:
        printf("Mes invalido");
        break;
    }
}

/**
 * @brief Imprime uma data em formato extenso.
 *
 * @param data Data a ser impressa em formato extenso.
 */
void ImprimeDataExtenso(tData data)
{

    printf("%.2d de ", data.dia);
    ImprimeMesExtenso(data);
    printf(" de %.2d\n", data.ano);
}

/**
 * @brief Verifica se um ano é bissexto.
 *
 * @param data Data cujo ano será verificado.
 * @return int 1 se o ano é bissexto, 0 caso contrário.
 */
int VerificaBissexto(tData data)
{

    if ((data.ano % 4 == 0  && data.ano % 100 != 0) || data.ano % 400 == 0)
    
    {

        return 1;
    }

    return 0;
}

/**
 * @brief Retorna o número de dias de um determinado mês.
 *
 * @param data Data cujo mês terá o número de dias retornado.
 * @return int Número de dias do mês da data.
 */
int NumeroDiasMes(tData data)
{

    int Dias[13] = {29, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (VerificaBissexto(data) && data.mes == 2)
    {

        return Dias[0];
    }

    return Dias[data.mes];
}

/**
 * @brief Compara duas datas.
 *
 * @param data1 Primeira data a ser comparada.
 * @param data2 Segunda data a ser comparada.
 * @return int 1 se data1 é maior que data2, -1 se data1 é menor que data2, 0 se as datas são iguais.
 * A data ser maior significa que ela é mais recente.
 */
int ComparaData(tData data1, tData data2)
{

    if (data1.ano == data2.ano && data1.dia == data2.dia && data1.mes == data2.mes)
    {

        return 0;
    }

    if (data1.ano > data2.ano)
    {

        return 1;
    }

    else if (data1.ano < data2.ano)
    {

        return -1;
    }

    if (data1.mes > data2.mes)
    {

        return 1;
    }

    else if (data1.mes < data2.mes)
    {

        return -1;
    }

    if (data1.dia > data2.dia)
    {

        return 1;
    }

    else if (data1.dia < data2.dia)
    {

        return -1;
    }

    return 1;
}

/**
 * @brief Calcula o número de dias até o início do mês de uma determinada data.
 *
 * @param data Data cujo número de dias até o início do mês será calculado.
 * @return int Número de dias até o início do mês da data.
 */
int CalculaDiasAteMes(tData data)
{

    int sum = 0;

    tData temp;

    temp = data;
    temp.mes = 0;



    for (int i = 1; i < data.mes; i++)
    {

        temp.mes++;
        sum += NumeroDiasMes(temp);
    }
    
    return sum;
}

/**
 * @brief Calcula a diferença em dias entre duas datas.
 *
 * @param data1 Primeira data a ser comparada.
 * @param data2 Segunda data a ser comparada.
 * @return int Número de dias entre as duas datas.
 */
int CalculaDiferencaDias(tData data1, tData data2)
{

    int i = 0, j = 0, total_dias = 0, dias_parciais1 = 0, dias_parciais2 = 0;

    tData temp1, temp2;

    temp1 = data1, temp2 = data2;

    temp1.ano = 0;
    temp2.ano = 0;

    for (i = 0; i < data1.ano; i++)
    {

        if (VerificaBissexto(temp1))
        {

            dias_parciais1 += 366;
        }

        else
        {

            dias_parciais1 += 365;
        }

        temp1.ano++;
    }


    for (i = 0; i < data2.ano; i++)
    {

        if (VerificaBissexto(temp2))
        {

            dias_parciais2 += 366;
        }

        else
        {

            dias_parciais2 += 365;
        }

        temp2.ano++;
    }

    dias_parciais1+=CalculaDiasAteMes(data1) + data1.dia;

    dias_parciais2+=CalculaDiasAteMes(data2) + data2.dia;

    return abs(dias_parciais1 - dias_parciais2);
}
