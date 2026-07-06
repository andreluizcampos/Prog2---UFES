#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "aluno.h"

#define MAX_STR 50

struct Aluno
{
    char *name;
    char *degree;
    char *birthday;
    float gpa;
    float percentage;
};

tAluno *CriaAluno(char *nome, char *dataNascimento, char *curso, float prctConclusao, float cfRendimento)
{

    tAluno *a = (tAluno *)malloc(sizeof(tAluno));
    a->percentage = prctConclusao;
    a->gpa = cfRendimento;

    a->name = calloc(MAX_STR, sizeof(char));
    a->birthday = calloc(12, sizeof(char));
    a->degree = calloc(MAX_STR, sizeof(char));

    strcpy(a->name, nome);
    strcpy(a->birthday, dataNascimento);
    strcpy(a->degree, curso);

    return a;
}

/**
 * @brief Destroi um aluno.
 * @param aluno Ponteiro para a estrutura do aluno a ser destruída.
 */
void DestroiAluno(tAluno *aluno)
{

    free(aluno->birthday);
    free(aluno->name);
    free(aluno->degree);
    free(aluno);
}

/**
 * @brief Lê um aluno da entrada padrão.
 * @return Um ponteiro para a estrutura do aluno lida.
 */
tAluno *LeAluno()
{

    char name[MAX_STR];
    char birthday[12];
    char degree[MAX_STR];
    float gpa, percentage;

    scanf(" %[^\n]", name);
    scanf(" %[^\n]", birthday);
    scanf(" %[^\n]", degree);
    scanf(" %f", &percentage);
    scanf(" %f", &gpa);

    tAluno *a = CriaAluno(name, birthday, degree, percentage, gpa);

    return a;
}

/**
 * @brief Compara o nome de dois alunos.
 * @param aluno1 Ponteiro para a estrutura do primeiro aluno.
 * @param aluno2 Ponteiro para a estrutura do segundo aluno.
 * @return Um inteiro indicando o resultado da comparação, conforme a função strcmp.
 */
int ComparaNomeAluno(tAluno *aluno1, tAluno *aluno2)
{

    return strcmp(aluno1->name, aluno2->name);
}

/**
 * @brief Salva um aluno em um arquivo binário.
 * @param aluno Ponteiro para a estrutura do aluno a ser salva.
 * @param file Ponteiro para o arquivo onde o aluno será salvo.
 * @return Um inteiro indicando o número de bytes salvos deste aluno.
 */
int SalvaAluno(tAluno *aluno, FILE *file)
{

    int t_bytes = 0;

    t_bytes += fwrite(aluno->name, sizeof(char), MAX_STR, file);
    t_bytes += fwrite(aluno->birthday, sizeof(char), 12, file);
    t_bytes += fwrite(aluno->degree, sizeof(char), MAX_STR, file);
    t_bytes += fwrite(&aluno->percentage, sizeof(float), 1, file);
    t_bytes += fwrite(&aluno->gpa, sizeof(float), 1, file);

    return t_bytes;
}

/**
 * @brief Carrega um aluno de um arquivo binário.
 * @param aluno Ponteiro para a estrutura do aluno a ser carregada.
 * @param file Ponteiro para o arquivo de onde o aluno será carregado.
 * @return Um inteiro indicando o número de bytes lidos deste aluno.
 */
int CarregaAluno(tAluno *aluno, FILE *file)
{

    int t_bytes = 0;

    t_bytes += fread(aluno->name, sizeof(char), MAX_STR, file);
    t_bytes += fread(aluno->birthday, sizeof(char), 12, file);
    t_bytes += fread(aluno->degree, sizeof(char), MAX_STR, file);
    t_bytes += fread(&aluno->percentage, sizeof(float), 1, file);
    t_bytes += fread(&aluno->gpa, sizeof(float), 1, file);

    return t_bytes;
}

/**
 * @brief Imprime o nome de um aluno na saída padrão.
 * @param aluno Ponteiro para a estrutura do aluno cujo nome será impresso.
 */
void ImprimeNomeAluno(tAluno *aluno)
{

    printf("%s\n", aluno->name);
}
