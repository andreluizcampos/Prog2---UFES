#include "data.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Data
{

    int mes;
    int dia;
    int ano;
};

/**
 * @brief Aloca dinamicamente uma estrutura do tipo tData, e a retorna.
 * Os campos dessa estrutura devem ser preenchidos inicialmente com -1.
 *
 * @return tData - Data "Vazia"
 */
tData *CriaData()
{

    tData *data = (tData *)malloc(sizeof(tData));

    return data;
}

/**
 * @brief Lê o dia, mês e ano e armazena em uma estrutura tData alocada dinamicamente.
 *
 * @param data - Ponteiro para a estrutura onde os dados serão armazenados. Lembre-se: Não pode ter valor NULL.
 */
void LeData(tData *data)
{

    scanf("%d/%d/%d\n", &data->dia, &data->mes, &data->ano);
}

/**
 * @brief Libera a memória alocada dinamicamente para uma estrutura do tipo tData, passada como parâmetro
 * @param data - Ponteiro para a estrutura onde os dados estão armazenados.
 */
void LiberaData(tData *data)
{

    free(data);
}

/**
 * @brief Verifica se uma data é válida.
 *
 * @param data Data a ser verificada.
 * @return int 1 se a data é válida, 0 caso contrário.
 */
int VerificaDataValida(tData *data)
{

    if (data->dia < 1 || data->dia > 31)
    {

        return 0;
    }

    if (data->mes == 2)
    {

        if (VerificaBissexto(data))
        {

            if (data->dia > 29)
            {

                return 0;
            }
        }
        else
        {

            if (data->dia > 28)
            {

                return 0;
            }
        }
    }

    if (data->mes == 4 || data->mes == 6 || data->mes == 9 || data->mes == 11)
    {

        if (data->dia > 30)
        {

            return 0;
        }
    }

    return 1;
}

/**
 * @brief Imprime o mês de uma data em formato extenso.
 *
 * @param data Data cujo mês será impresso em formato extenso.
 */
void ImprimeMesExtenso(tData *data)
{

    if (data->mes == 1)
    {
        printf("Janeiro");
    }
    if (data->mes == 2)
    {
        printf("Fevereiro");
    }
    if (data->mes == 3)
    {
        printf("Março");
    }
    if (data->mes == 4)
    {
        printf("Abril");
    }
    if (data->mes == 5)
    {
        printf("Maio");
    }
    if (data->mes == 6)
    {
        printf("Junho");
    }
    if (data->mes == 7)
    {
        printf("Julho");
    }
    if (data->mes == 8)
    {
        printf("Agosto");
    }
    if (data->mes == 9)
    {
        printf("Setembro");
    }
    if (data->mes == 10)
    {
        printf("Outubro");
    }
    if (data->mes == 11)
    {
        printf("Novembro");
    }
    if (data->mes == 12)
    {
        printf("Dezembro");
    }
}

/**
 * @brief Imprime uma data em formato extenso.
 *
 * @param data Data a ser impressa em formato extenso.
 */
void ImprimeDataExtenso(tData *data)
{

    printf("%d de ", data->dia);
    ImprimeMesExtenso(data);
    printf("de %d\n", data->ano);
}

/**
 * @brief Verifica se um ano é bissexto.
 *
 * @param data Data cujo ano será verificado.
 * @return int 1 se o ano é bissexto, 0 caso contrário.
 */
int VerificaBissexto(tData *data)
{

    if ((data->ano % 4 == 0 && data->ano % 100 != 0) || (data->ano % 400 == 0))
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
int NumeroDiasMes(tData *data)
{

   
        if (data->mes == 1)
            return 31;
        if (data->mes == 2)
        {
            if ((data->ano % 4 == 0 && data->ano % 100 != 0) || (data->ano % 400 == 0))
                return 29;
            else
                return 28;
        }
        if (data->mes == 3)
            return 31;
        if (data->mes == 4)
            return 30;
        if (data->mes == 5)
            return 31;
        if (data->mes == 6)
            return 30;
        if (data->mes == 7)
            return 31;
        if (data->mes == 8)
            return 31;
        if (data->mes == 9)
            return 30;
        if (data->mes == 10)
            return 31;
        if (data->mes == 11)
            return 30;
        if (data->mes == 12)
            return 31;
        return -1; // mês inválido
    }


/**
 * @brief Compara duas datas.
 *
 * @param data1 Primeira data a ser comparada.
 * @param data2 Segunda data a ser comparada.
 * @return int 1 se data1 é maior que data2, -1 se data1 é menor que data2, 0 se as datas são iguais.
 * A data ser maior significa que ela é mais recente.
 */
int ComparaData(tData *data1, tData *data2){

    if(data1->ano == data2->ano && data1->mes == data2->mes  && data1->dia == data2->dia){

        return 0;
    }

    if(data1->ano > data2->ano){

        return 1;
    }

     else  if(data1->ano < data2->ano){

        return -1;
    }
    
    


     

}

/**
 * @brief Calcula o número de dias até o início do mês de uma determinada data.
 *
 * @param data Data cujo número de dias até o início do mês será calculado.
 * @return int Número de dias até o início do mês da data.
 */
int CalculaDiasAteMes(tData *data);

/**
 * @brief Calcula a diferença em dias entre duas datas.
 *
 * @param data1 Primeira data a ser comparada.
 * @param data2 Segunda data a ser comparada.
 * @return int Número de dias entre as duas datas.
 */
int CalculaDiferencaDias(tData *data1, tData *data2);
