#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "aluno.h"
struct aluno
{
    float CR;
    int percentual_concluído;
    char *nome;
    char *ano;
    char *nascimento;
    char *degree;
};
Aluno **CriaVetorAlunos(int numeroAlunos)
{
    Aluno **students = (Aluno **)malloc(sizeof(Aluno *) * numeroAlunos);
    return students;
}
Aluno *CriaAluno(char *nome, char *dtNasc, char *cursoUfes, char *periodoIngresso, int percConclusao, float CRA)
{
    Aluno *student = (Aluno *)malloc(sizeof(Aluno));
    student->percentual_concluído = percConclusao;
    student->nome = (char *)malloc(sizeof(char) * 100);
    student->nascimento = (char *)malloc(sizeof(char) * 100);
    student->CR = CRA;
    student->degree = (char *)malloc(sizeof(char) * 100);
    student->ano = (char *)malloc(sizeof(char) * 100);
    strcpy(student->nome, nome);
    strcpy(student->degree, cursoUfes);
    strcpy(student->nascimento, dtNasc);
    strcpy(student->ano, periodoIngresso);
    return student;
}
void LeAlunos(Aluno **vetorAlunos, int numeroAlunos)
{
    char name[100], data[100], degree[100], year[100];
    float CR;
    int percent;
    for (int i = 0; i < numeroAlunos; i++)
    {
        scanf(" %[^\n]", name);
        scanf(" %[^\n]", data);
        scanf(" %[^\n]", degree);
        scanf(" %[^\n]", year);
        scanf(" %d", &percent);
        scanf(" %f", &CR);
        vetorAlunos[i] = CriaAluno(name, data, degree, year, percent, CR);
    }
}
void LiberaAlunos(Aluno **alunos, int numeroAlunos)
{
    for (int i = 0; i < numeroAlunos; i++)
    {
        Aluno *a = alunos[i];
        free(a->ano);
        free(a->nome);
        free(a->nascimento);
        free(a->degree);
        free(a);
    }
    free(alunos);
}
void SalvaAlunosBinario(Aluno **alunos, char *fileName, int numeroAlunos)
{
    FILE *f = fopen(fileName, "wb");
    fwrite(&numeroAlunos, sizeof(numeroAlunos), 1, f);
    for (int i = 0; i < numeroAlunos; i++)
    {
        Aluno *a = alunos[i];
        int t1 = strlen(a->nome) + 1;
        int t2 = strlen(a->nascimento) + 1;
        int t3 = strlen(a->degree) + 1;
        int t4 = strlen(a->ano) + 1;
        fwrite(&t1, sizeof(int), 1, f);
        fwrite(a->nome, sizeof(char), t1, f);
        fwrite(&t2, sizeof(int), 1, f);
        fwrite(a->nascimento, sizeof(char), t2, f);
        fwrite(&t3, sizeof(int), 1, f);
        fwrite(a->degree, sizeof(char), t3, f);
        fwrite(&t4, sizeof(int), 1, f);
        fwrite(a->ano, sizeof(char), t4, f);
        fwrite(&a->percentual_concluído, sizeof(a->percentual_concluído), 1, f);
        fwrite(&a->CR, sizeof(a->CR), 1, f);
    }
    fclose(f);
}
void CarregaAlunosBinario(Aluno **alunos, char *fileName)
{
    FILE *f = fopen(fileName, "rb");
    int numeroALunos;
    int percentual_concluido;
    int qtd_bytes = 0;

    float CR;
   qtd_bytes+= fread(&numeroALunos, sizeof(numeroALunos), 1, f)*4;
    for (int i = 0; i < numeroALunos; i++)
    {
        int t1, t2, t3, t4;
        qtd_bytes += fread(&t1, sizeof(int), 1, f) * 4;
        char *nome = (char *)malloc(t1);
        qtd_bytes += fread(nome, sizeof(char), t1, f) - 1;
        qtd_bytes += fread(&t2, sizeof(int), 1, f) * 4;
        char *nascimento = (char *)malloc(t2);
        qtd_bytes += fread(nascimento, sizeof(char), t2, f) - 1;
        qtd_bytes += fread(&t3, sizeof(int), 1, f) * 4;
        char *degree = (char *)malloc(t3);
        qtd_bytes += fread(degree, sizeof(char), t3, f) - 1;
        qtd_bytes += fread(&t4, sizeof(int), 1, f) * 4;
        char *ano = (char *)malloc(t4);
        qtd_bytes += fread(ano, sizeof(char), t4, f) - 1;
        qtd_bytes += fread(&percentual_concluido, sizeof(percentual_concluido), 1, f) * 4;
        qtd_bytes += fread(&CR, sizeof(CR), 1, f) * 4;
        alunos[i] = CriaAluno(nome, nascimento, degree, ano, percentual_concluido, CR);

        free(nome);
        free(nascimento);
        free(degree);
        free(ano);
    }

    printf("Numero de bytes salvos: %d\n", qtd_bytes);
    fclose(f);
}
void ImprimeAlunos(Aluno **alunos, int numeroAlunos)
{
    for (int i = 0; i < numeroAlunos; i++)
    {
        Aluno *a = alunos[i];
        printf("Aluno %d:\n", i);
        printf("Nome: %s\n", a->nome);
        printf("Data Nascimento: %s\n", a->nascimento);
        printf("Curso: %s\n", a->degree);
        printf("Periodo Ingresso: %s\n", a->ano);
        printf("%% Conclusao do Curso: %d\n", a->percentual_concluído);
        printf("CRA: %.2f\n", a->CR);
    }
}