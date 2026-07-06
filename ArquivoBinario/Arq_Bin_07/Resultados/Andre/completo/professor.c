#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "professor.h"

struct Professor
{
    char *dept;
    char *name;
    char *birthday;
};

tProfessor *CriaProfessor(char *nome, char *dataNascimento, char *departamento)
{

    tProfessor *p = (tProfessor *)malloc(sizeof(tProfessor));

    p->birthday = calloc(12, sizeof(char));
    p->dept = calloc(50, 4);
    p->name = calloc(50, 4);

    strcpy(p->name, nome);
    strcpy(p->birthday, dataNascimento);
    strcpy(p->dept, departamento);

    return p;
}

/**
 * @brief Destroi um professor.
 * @param prof Ponteiro para a estrutura do professor a ser destruída.
 */
void DestroiProfessor(tProfessor *prof)
{

    free(prof->birthday);
    free(prof->dept);
    free(prof->name);

    free(prof);
}

/**
 * @brief Lê um professor da entrada padrão.
 * @return Um ponteiro para a estrutura do professor lida.
 */
tProfessor *LeProfessor()
{

    char name[50];
    char dept[50];
    char birthday[50];

    scanf(" %[^\n]", name);
    scanf(" %[^\n]", birthday);
    scanf(" %[^\n]", dept);

    tProfessor *p = CriaProfessor(name, birthday, dept);

    return p;
}

/**
 * @brief Compara o nome de dois professores.
 * @param prof1 Ponteiro para a estrutura do primeiro professor.
 * @param prof2 Ponteiro para a estrutura do segundo professor.
 * @return Um inteiro indicando o resultado da comparação, conforme a função strcmp.
 */
int ComparaNomeProfessor(tProfessor *prof1, tProfessor *prof2)
{

    return strcmp(prof1->name, prof2->name);
}

/**
 * @brief Salva um professor em um arquivo binário.
 * @param prof Ponteiro para a estrutura do professor a ser salva.
 * @param file Ponteiro para o arquivo onde o professor será salvo.
 * @return Um inteiro indicando o número de bytes salvos deste professor.
 */
int SalvaProfessor(tProfessor *prof, FILE *file)
{

    int b_salvos = 0;

    b_salvos += fwrite(prof->name, 1, 50, file);
    b_salvos += fwrite(prof->birthday, 1, 12, file);
    b_salvos += fwrite(prof->dept, 1, 50, file);

    return b_salvos;
}

/**
 * @brief Carrega um professor de um arquivo binário.
 * @param prof Ponteiro para a estrutura do professor a ser carregada.
 * @param file Ponteiro para o arquivo de onde o professor será carregado.
 * @return Um inteiro indicando o número de bytes lidos deste professor.
 */
int CarregaProfessor(tProfessor *prof, FILE *file)
{

    int b_salvos = 0;

    b_salvos += fread(prof->name, 1, 50, file);
    b_salvos += fread(prof->birthday, 1, 12, file);
    b_salvos += fread(prof->dept, 1, 50, file);

    return b_salvos;
}


/**
 * @brief Imprime o nome de um professor.
 * @param prof Ponteiro para a estrutura do professor cujo nome será impresso.
 */
void ImprimeNomeProfessor(tProfessor *prof){


    printf("%s\n",prof->name);
}
