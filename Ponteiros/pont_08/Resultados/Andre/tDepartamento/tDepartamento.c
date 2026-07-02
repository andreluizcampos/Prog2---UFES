#include <stdio.h>
#include <string.h>
#include "tDepartamento.h"

/**
 * @brief Cria um departamento com os dados passados via parâmetro
 *
 *
 * @param *curso1 Ponteiro para string que contém o nome do primeiro curso do departamento
 * @param *curso2 Ponteiro para string que contém o nome do segundo curso do departamento
 * @param *curso3 Ponteiro para string que contém o nome do terceiro curso do departamento
 * @param *nome Ponteiro para string que contém o nome do departamento
 * @param m1 Nota do primeiro curso (curso1)
 * @param m2 Nota do segundo curso (curso2)
 * @param m3 Nota do terceiro curso (curso3)
 * @param *diretor Ponteiro para string que contém o nome do diretor/chefe do departamento
 */
tDepartamento CriaDepartamento(char *curso1, char *curso2, char *curso3,
                               char *nome, int m1, int m2, int m3, char *diretor)
{

    tDepartamento departamento;

    strcpy(departamento.curso1, curso1);
    strcpy(departamento.curso2, curso2);
    strcpy(departamento.curso3, curso3);
    strcpy(departamento.nome, nome);
    strcpy(departamento.diretor, diretor);

    departamento.m1 = m1;
    departamento.m2 = m2;
    departamento.m3 = m3;

    return departamento;
}

/**
 * @brief Imprime os atributos de um departamento em tela
 *
 * @param depto - Um departamento que terá seus dados impressos em tela
 */

void ImprimeAtributosDepartamento(tDepartamento depto)
{

    double media=0;

    media += depto.m1 + depto.m2 + depto.m3;

    media = media / (float)3;

    printf("\nDepartamento: %s\n\t", depto.nome);
    printf("Diretor: %s\n\t1o curso: %s\n\tMedia do 1o curso: %d\n\t2o curso: %s\n\t", depto.diretor, depto.curso1, depto.m1, depto.curso2);
    printf("Media do 2o curso: %d\n\t3o curso: %s\n\tMedia do 3o curso: %d\n\tMedia dos cursos: %.2f", depto.m2, depto.curso3, depto.m3, media);
}

/**
 * @brief Ordena os departamentos de acordo com as médias das notas de cada um dos seus três cursos (da maior para a menor).
 *
 * @param *vetor_deptos - Ponteiro para um vetor de departamentos
 * @param num_deptos - O número de departamentos contidos no vetor_deptos
 */
void OrdenaDepartamentosPorMedia(tDepartamento *vetor_deptos, int num_deptos)
{

    int flag = 1;
    double media1 = 0, media2 = 0;


    while(flag)
    {

        flag = 0;

        for (int i = 0; i < num_deptos - 1; i++)
        {

            media1 = (vetor_deptos[i].m1 + vetor_deptos[i].m2 +vetor_deptos[i].m3)/(float)3;
            media2 = (vetor_deptos[i+1].m1 + vetor_deptos[i+1].m2 +vetor_deptos[i+1].m3)/(float)3;

            if (media1 < media2)
            {

                tDepartamento temp = vetor_deptos[i];
                vetor_deptos[i] = vetor_deptos[i + 1];
                vetor_deptos[i + 1] = temp;
                flag = 1;
            }
        }
    }
}
