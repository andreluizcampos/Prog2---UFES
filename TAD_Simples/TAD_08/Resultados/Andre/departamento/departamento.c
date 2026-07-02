#include "departamento.h"
#include <stdio.h>
#include <string.h>
#include <math.h>

tDepartamento criaDepartamento(char *c1, char *c2, char *c3, char *nome, int m1, int m2, int m3, char *diretor)
{

    tDepartamento departamento;

    strcpy(departamento.c1, c1);
    strcpy(departamento.c2, c2);
    strcpy(departamento.c3, c3);
    strcpy(departamento.nome, nome);
    strcpy(departamento.diretor, diretor);
    departamento.m1 = m1;
    departamento.m2 = m2;
    departamento.m3 = m3;
    float media_geral = calculaMediaGeralDepartamento(departamento);
    departamento.media_geral = media_geral;

    return departamento;
}

/**
 * @brief Imprime os atributos do departamento, sendo eles: cursos, nome do departamento, média por curso e nome do diretor.
 *
 * @param depto Departamento cujos atributos serão impressos.
 */
void imprimeAtributosDepartamento(tDepartamento depto)
{
    printf("ATRIBUTOS:\n");
    printf("departamento => %s\n", depto.nome);
    printf("diretor => %s\n", depto.diretor);
    printf("curso1 => %s, media1 => %d\n", depto.c1, depto.m1);
    printf("curso2 => %s, media2 => %d\n", depto.c2, depto.m2);
    printf("curso3 => %s, media3 => %d\n", depto.c3, depto.m3);
    printf("media geral => %.2f\n", depto.media_geral);
    printf("desvio padrao => %.2f\n\n",calculaDesvioPadraoDepartamento(depto));
}

/**
 * @brief Verifica se a media inserida é valida, ou seja, pertence à [0, 10].
 *
 * @param media Valor a ser validado.
 * @return int Se é válida (1) ou não (0).
 */
int validaMediaDepartamento(int media)
{

    return (media >= 0 && media <= 10);
}

/**
 * @brief Calcula o Desvio Padrão das médias por curso de um departamento.
 *
 * @param depto Departamento cujo Desvio Padrão de médias por curso deve ser calculado.
 * @return double Valor do cálculo do Desvio Padrão.
 */
double calculaDesvioPadraoDepartamento(tDepartamento depto)
{

    double desvio_p = 0, somatorio = 0;

    int V[3] = {depto.m1, depto.m2, depto.m3};

    for (int i = 0; i < 3; i++)
    {

        somatorio += pow((V[i] - depto.media_geral), 2);
    }

    somatorio = somatorio / 3;

    return sqrt(somatorio);
}

/**
 * @brief Calcula a média simples das notas dos cursos do departamento.
 *
 * @param depto Departamento cuja media simples deve ser calculada.
 * @return double Valor do calculo da média simples.
 */
double calculaMediaGeralDepartamento(tDepartamento depto)
{

    double media_geral = ((float)depto.m1 + (float)depto.m2 + (float)depto.m3) / 3;

    return media_geral;
}

/**
 * @brief Ordena o vetor de departamentos em ordem decrescente de acordo com as médias dos departamentos.
 *
 * @param d Vetor de departamentos a ser ordenado.
 * @param tamanho Tamanho do vetor a ser ordenado.
 */
void ordenaPorMediaDepartamentos(tDepartamento d[], int tamanho)
{

    int flag = 1;

    while (flag)
    {

        flag = 0;

        for (int i = 0; i < tamanho - 1; i++)
        {

            if (d[i].media_geral < d[i + 1].media_geral)
            {

                flag = 1;
                tDepartamento dep;
                dep = d[i + 1];
                d[i + 1] = d[i];
                d[i] = dep;
            }
        }
    }

}
