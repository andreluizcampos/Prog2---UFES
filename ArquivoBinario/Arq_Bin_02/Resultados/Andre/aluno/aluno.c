#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "aluno.h"

#define MAX_STR 100
#define BDAY 11
#define DEGREE 50

struct Aluno
{

    char *name;
    char *birthday;
    char *degree;
    int year;
    float gpa;
};

tAluno *CriarAluno(char *nome, char *dataNascimento, char *curso, int periodo, float coeficienteRendimento)
{

    tAluno *a = (tAluno *)malloc(sizeof(tAluno));
    a->gpa = coeficienteRendimento;
    a->year = periodo;

    a->name = (char *)malloc(sizeof(char) * MAX_STR);
    a->birthday = (char *)malloc(sizeof(char) * MAX_STR);
    a->degree = (char *)malloc(sizeof(char) * MAX_STR);

    strcpy(a->birthday, dataNascimento);
    strcpy(a->degree, curso);
    strcpy(a->name, nome);

    return a;
}

/**
 * @brief Função para destruir um aluno.
 *
 * @param aluno O aluno a ser destruído.
 */
void DestruirAluno(tAluno *aluno)
{

    free(aluno->name);
    free(aluno->birthday);
    free(aluno->degree);
    free((aluno));
}

/**
 * @brief Função para ler um aluno de um arquivo binário.
 *
 * @param arquivo_binario O arquivo binário para ler o aluno.
 * @return Um ponteiro para o aluno lido.
 */
tAluno *LeAluno(FILE *arquivo_binario)
{

    int s1 = 0, s2 = 0, s3 = 0;

    char name[100], degree[100], birthday[100];

    float gpa;
    int year;

    s1 = fread(name, sizeof(char), MAX_STR, arquivo_binario);
    s2 = fread(birthday, sizeof(char), BDAY, arquivo_binario);
    s3 = fread(degree, sizeof(char), DEGREE, arquivo_binario);
    fread(&year, sizeof(int), 1, arquivo_binario);
    fread(&gpa, sizeof(float), 1, arquivo_binario);

    tAluno *a = CriarAluno(name, birthday, degree, year, gpa);

    return a;
}

/**
 * @brief Função para obter o coeficiente de rendimento de um aluno.
 *
 * @param aluno O aluno para obter o coeficiente de rendimento.
 * @return O coeficiente de rendimento do aluno.
 */
float GetCoeficienteRendimentoAluno(tAluno *aluno)
{

    return aluno->gpa;
}
