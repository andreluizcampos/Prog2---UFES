#include <stdio.h>
#include "data.h"
#include <stdlib.h>

int verificaDataValida(int dia, int mes, int ano)
{

    if (ano < 1)
    {

        return 0;
    }

    if (mes > 12 || mes < 1)
    {

        return 0;
    }

    if (dia >= 32 || dia < 1)
    {

        return 0;
    }

    if (mes == 2 && dia > 29)
    {

        return 0;
    }

    if ((mes == 4 || mes == 6 || mes == 9 || mes == 11) && dia > 30)
    {

        return 0;
    }

    return 1;
}

void imprimeMesExtenso(int mes)
{

    if (mes == 1)
    {
        printf("Janeiro");
    }

    if (mes == 2)
    {
        printf("Fevereiro");
    }

    if (mes == 3)
    {
        printf("Março");
    }

    if (mes == 4)
    {
        printf("Abril");
    }

    if (mes == 5)
    {
        printf("Maio");
    }

    if (mes == 6)
    {
        printf("Junho");
    }

    if (mes == 7)
    {
        printf("Julho");
    }

    if (mes == 8)
    {
        printf("Agosto");
    }

    if (mes == 9)
    {
        printf("Setembro");
    }

    if (mes == 10)
    {
        printf("Outubro");
    }

    if (mes == 11)
    {
        printf("Novembro");
    }

    if (mes == 12)
    {
        printf("Dezembro");
    }
}
void imprimeDataExtenso(int dia, int mes, int ano)
{

    printf("%.2d de ", dia);
    imprimeMesExtenso(mes);
    printf(" de %d\n", ano);
}
int verificaBissexto(int ano)
{

    if (ano % 4 == 0 && ano % 100 != 0 || ano % 400 == 0)
    {

        return 1;
    }

    return 0;
}
int numeroDiasMes(int mes, int ano)
{

    if (mes == 4 || mes == 6 || mes == 9 || mes == 11)
    {

        return 30;
    }

    if (mes == 2)
    {

        if (verificaBissexto(ano))
        {

            return 29;
        }

        return 28;
    }

    return 31;
}

int comparaData(int dia1, int mes1, int ano1, int dia2, int mes2, int ano2)
{

    if (ano1 == ano2 && mes1 == mes2 && dia1 == dia2)
    {

        return 0;
    }

    if (ano1 > ano2)
    {

        return 1;
    }

    else if (ano2 > ano1)
    {

        return -1;
    }

    if (mes1 > mes2)
    {

        return 1;
    }

    else if (mes2 > mes1)
    {

        return -1;
    }

    if (dia1 > dia2)
    {

        return 1;
    }

    return -1;
}
int calculaDiasAteMes(int mes, int ano)
{

    int s = 0;

    for (int i = 1; i < mes; i++)
    {

        s += numeroDiasMes(i, ano);
    }

    return s;
}

int calculaDiferencaDias(int dia1, int mes1, int ano1, int dia2, int mes2, int ano2)
{

    int d1 = 0, d2 = 0;

    

        d1 += calculaDiasAteMes(mes1, ano1);
        d1 += dia1;

        d2 += calculaDiasAteMes(mes2, ano2);
        d2 += dia2;

    for (int i = 1; i < ano1; i++)
    {

        if (verificaBissexto(i))
        {

            d1 += 366;
        }
        else
        {

            d1 += 365;
        }
    }

    for (int i = 1; i < ano2; i++)
    {

        if (verificaBissexto(i))
        {

            d2 += 366;
        }
        else
        {

            d2 += 365;
        }
    }

    return abs(d1 - d2);
}
