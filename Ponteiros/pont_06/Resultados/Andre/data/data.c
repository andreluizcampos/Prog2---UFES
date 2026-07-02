#include <stdio.h>
#include "data.h"

void InicializaDataParam(int dia, int mes, int ano, tData *data)
{

    data->ano = ano;
    data->mes = mes;
    data->dia = dia;
}

/**
 * @brief Lê uma data do usuário.
 *
 * Esta função lê do usuário o dia, mês e ano de uma data e armazena esses valores na estrutura tData correspondente.
 *
 * @param data Ponteiro para a estrutura tData que será preenchida com os valores lidos.
 */
void LeData(tData *data)
{

    int dia, mes, ano;
    scanf("%d %d %d", &dia, &mes, &ano);

    InicializaDataParam(dia, mes, ano, data);
    
   if ( data->mes > 12){

        data->mes = 12;
        
    }
    int qtd_mes = 0, qtd_dias = 0;

    qtd_mes = InformaQtdDiasNoMes(data);

    if (data->dia > qtd_mes)
    {

        data->dia = qtd_mes;
    }

}

/**
 * @brief Imprime uma data na tela.
 *
 * Esta função recebe como parâmetro uma estrutura tData e imprime na tela o dia, mês e ano correspondentes.
 *
 * @param data Ponteiro para a estrutura tData que será impressa.
 */
void ImprimeData(tData *data)
{

    printf("'%.2d/%.2d/%d'", data->dia, data->mes, data->ano);
}

/**
 * @brief Verifica se um ano é bissexto.
 *
 * Esta função recebe como parâmetro uma estrutura tData e verifica se o ano correspondente é bissexto.
 *
 * @param data Ponteiro para a estrutura tData que será verificada.
 * @return 1 se o ano é bissexto, 0 caso contrário.
 */
int EhBissexto(tData *data)
{

    if ((data->ano % 4 == 0 && data->ano % 100 != 0) || data->ano % 400 == 0)
    {

        return 1;
    }
    return 0;
}

/**
 * @brief Informa a quantidade de dias no mês de uma data.
 *
 * Esta função recebe como parâmetro uma estrutura tData e informa a quantidade de dias no mês correspondente.
 *
 * @param data Ponteiro para a estrutura tData que será verificada.
 * @return Quantidade de dias no mês correspondente.
 */
int InformaQtdDiasNoMes(tData *data)
{

    if (data->mes == 2)
        return EhBissexto(data) ? 29 : 28;

    if (data->mes == 4 || data->mes == 6 || data->mes == 9 || data->mes == 11)
        return 30;

    if (data->mes >= 1 && data->mes <= 12)
        return 31;

    return -1;
}

/**
 * @brief Avança uma data para o dia seguinte.
 *
 * Esta função recebe como parâmetro uma estrutura tData e avança a data correspondente para o dia seguinte.
 *
 * @param data Ponteiro para a estrutura tData que será avançada.
 */
void AvancaParaDiaSeguinte(tData *data)
{


int  qtd_mes = InformaQtdDiasNoMes(data);

    data->dia++;

    if (data->dia > qtd_mes)
    {
        data->dia = 1;
        data->mes++;

    if (data->mes > 12)
    {

        data->mes = 1;
        data->ano++;
    }
            
    }

    
}

/**
 * @brief Verifica se duas datas são iguais.
 *
 * Esta função recebe como parâmetro duas estruturas tData e verifica se elas representam a mesma data.
 *
 * @param data1 Ponteiro para a primeira estrutura tData que será comparada.
 * @param data2 Ponteiro para a segunda estrutura tData que será comparada.
 * @return 1 se as datas são iguais, 0 caso contrário.
 */
int EhIgual(tData *data1, tData *data2)
{

    return (data1->dia == data2->dia) && (data1->mes == data2->mes) && (data1->ano == data2->ano);
}
