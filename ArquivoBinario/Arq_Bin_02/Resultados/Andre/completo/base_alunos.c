#include "aluno.h"
#include "base_alunos.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct BaseAlunos
{

    int n;
    tAluno **alunos;
};

/**
 * @brief Função para criar uma nova base de alunos.
 *
 * @return Um ponteiro para a base de alunos recém-criada. Se houver erro na alocação de memória, o programa é encerrado.
 */
tBaseAlunos *CriarBaseAlunos()
{

    tBaseAlunos *b = (tBaseAlunos *)malloc(sizeof(tBaseAlunos));
    b->alunos = (tAluno **)malloc(sizeof(tAluno *));
    b->n = 0;

    return b;
}

/**
 * @brief Função para destruir uma base de alunos.
 *
 * @param baseAlunos A base de alunos a ser destruída.
 */
void DestruirBaseAlunos(tBaseAlunos *baseAlunos)
{

    for (int i = 0; i < baseAlunos->n; i++)
    {

        DestruirAluno(baseAlunos->alunos[i]);
    }

    free(baseAlunos->alunos);
    free(baseAlunos);
}

/**
 * @brief Função para ler uma base de alunos de um arquivo binário.
 *
 * @param baseAlunos A base de alunos para ler o arquivo.
 * @param nomeArquivo O nome do arquivo a ser lido.
 */
void LerBaseAlunos(tBaseAlunos *baseAlunos, char *nomeArquivo)
{

    FILE *f = fopen(nomeArquivo, "rb");

    int n = 0;

    fread(&n, sizeof(n), 1, f);
    baseAlunos->n = n;
  
    baseAlunos->alunos = (tAluno **)realloc(baseAlunos->alunos, sizeof(tAluno *) * n);

    for (int i = 0; i < n; i++)
    {

        baseAlunos->alunos[i] = LeAluno(f);
    }

    fclose(f);
}

/**
 * @brief Função para obter o coeficiente de rendimento médio de uma base de alunos.
 *
 * @param baseAlunos A base de alunos para obter o coeficiente de rendimento médio.
 * @return O coeficiente de rendimento médio da base de alunos.
 */
float GetCoeficienteRendimentoMedioBaseAlunos(tBaseAlunos *baseAlunos)
{

    float average_gpa = 0;

    for (int i = 0; i < baseAlunos->n; i++)
    {

        average_gpa += GetCoeficienteRendimentoAluno(baseAlunos->alunos[i]);
    }

    average_gpa = average_gpa / baseAlunos->n;

    return average_gpa;
}
