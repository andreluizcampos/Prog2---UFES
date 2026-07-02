#include "vector.h"
#include <stdio.h>
#include "aluno.h"

/**
 * @brief Aloca memoria para um aluno
 *
 * @return A estrutura tAluno inicializada. Caso não seja possível alocar memória, o programa é encerrado.
 */

struct Aluno
{

    char *nome;
    float nota;
    char gen;
};

tAluno *CriaAluno()
{
    tAluno *a = (tAluno *)malloc(sizeof(tAluno));
    a->nome = (char *)malloc(sizeof(char)*100);
    a->nota = 0;
    a->gen = 'N';

    return a;
}

/**
 * @brief Libera a memoria alocada para um aluno
 *
 * @param aluno Ponteiro para o aluno
 * Dica: Foi usado data_type para generalizar a funcao e usar na estrutura Vector. Por isso, é necessário fazer um cast para tAluno* dentro da função.
 */
void DestroiAluno(data_type aluno)
{

    tAluno *a = ((tAluno *)aluno);

    free(a->nome);
    free(a);
}

/**
 * @brief Le os dados de um aluno
 *
 * @param aluno Ponteiro para o aluno
 */
void LeAluno(tAluno *aluno)
{

    scanf("%[^;];%c;%f\n", aluno->nome, &aluno->gen, &aluno->nota);

}

/**
 * @brief Retorna o genero de um aluno
 *
 * @param aluno Ponteiro para o aluno
 * @return char Genero do aluno
 */
char GetGeneroAluno(tAluno *aluno){


        return aluno->gen;

}

/**
 * @brief Retorna a nota de um aluno
 *
 * @param aluno Ponteiro para o aluno
 * @return float Nota do aluno
 */
float GetNotaAluno(tAluno *aluno){


            return aluno->nota;

}
