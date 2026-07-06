#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "vector.h"
#include "database.h"
#include "professor.h"
#include "aluno.h"

struct Database
{
    Vector *students;
    Vector *teachers;
    int n1;
    int n2;
    int bytes;
};

/**
 * @brief Cria um nova database.
 * @return Um ponteiro para a estrutura database criada. Caso a alocação falhe, a função termina o programa.
 */
tDatabase *CriaDatabase()
{

    tDatabase *d = (tDatabase *)malloc(sizeof(tDatabase));
    d->students = VectorConstruct();
    d->teachers = VectorConstruct();
    d->bytes = 0;
    d->n1 = 0;
    d->n2 = 0;

    return d;
}

/**
 * @brief Destroi uma database.
 * @param db Ponteiro para a estrutura da database a ser destruída.
 */
void DestroiDatabase(tDatabase *db)
{

    VectorDestroy(db->students, DestroiAluno);
    VectorDestroy(db->teachers, DestroiProfessor);
    free(db);
}

/**
 * @brief Lê uma database da entrada padrão.
 * @param db Ponteiro para a estrutura da database a ser lida.
 */
void LeDatabase(tDatabase *db)
{

    int n1 = 0;
    int n2 = 0;

    scanf("%d", &n1);

    for (int i = 0; i < n1; i++)
    {

        tAluno *a = LeAluno();

        VectorPushBack(db->students, a);
    }

    scanf(" %d", &n2);

    for (int i = 0; i < n2; i++)
    {

        tProfessor *p = LeProfessor();

        VectorPushBack(db->teachers, p);
    }

    db->n1 = n1;
    db->n2 = n2;

    getchar();
}

/**
 * @brief Ordena uma database, primeiro os alunos e depois os professores, de acordo com o nome.
 * @param db Ponteiro para a estrutura da database a ser ordenada.
 */
void OrdenaDatabase(tDatabase *db)
{

    int n1 = db->n1;
    int n2 = db->n2;

    int FLAG = 1;

    while (FLAG)
    {

        FLAG = 0;

        for (int i = 0; i < n1 - 1; i++)
        {

            tAluno *a1 = (tAluno *)VectorGet(db->students, i);
            tAluno *a2 = (tAluno *)VectorGet(db->students, i + 1);

            int flag = ComparaNomeAluno(a1, a2);

            if (flag > 0)
            {

                VectorSwap(db->students, i, i + 1);
                FLAG = 1;
            }
        }
    }

    FLAG = 1;

    while (FLAG)
    {

        FLAG = 0;
        for (int i = 0; i < n2 - 1; i++)
        {
            tProfessor *a1 = (tProfessor *)VectorGet(db->teachers, i);
            tProfessor *a2 = (tProfessor *)VectorGet(db->teachers, i + 1);

            int flag = ComparaNomeProfessor(a1, a2);

            if (flag > 0)
            {
                FLAG = 1;
                VectorSwap(db->teachers, i, i + 1);
            }
        }
    }
}

/**
 * @brief Salva uma database em um arquivo binário.
 * @param db Ponteiro para a estrutura da database a ser salva.
 * @param file Ponteiro para o arquivo onde a database será salva.
 * @return Um inteiro indicando o total de bytes salvos.
 */
int SalvarDatabase(tDatabase *db, FILE *file)
{

    int bytes = 0;

    bytes += fwrite(&db->n1, 4, 1, file);

    for (int i = 0; i < db->n1; i++)
    {

        tAluno *a = (tAluno *)VectorGet(db->students, i);
        bytes += SalvaAluno(a, file);
    }
    bytes += fwrite(&db->n2, 4, 1, file);

    for (int i = 0; i < db->n2; i++)
    {

        tProfessor *p = (tProfessor *)VectorGet(db->teachers, i);
        bytes += SalvaProfessor(p, file);
    }

    return bytes;
}

/**
 * @brief Carrega uma database de um arquivo binário.
 * @param db Ponteiro para a estrutura da database a ser carregada.
 * @param file Ponteiro para o arquivo de onde a database será carregada.
 * @return Um inteiro indicando o total de bytes lidos.
 */
int CarregaDatabase(tDatabase *db, FILE *file)
{

    int bytes = 0;

    bytes += fread(&db->n1, 4, 1, file);

    for (int i = 0; i < db->n1; i++)
    {

        tAluno *a = CriaAluno("", "", "", 0, 0);
        bytes += CarregaAluno(a, file);
        VectorPushBack(db->students, a);
    }
    bytes += fread(&db->n2, 4, 1, file);

    for (int i = 0; i < db->n2; i++)
    {

        tProfessor *p = CriaProfessor("", "", "");
        bytes += CarregaProfessor(p, file);
        VectorPushBack(db->teachers, p);
    }

    return bytes;
}

/**
 * @brief Imprime uma database, primeiro os alunos e depois os professores. Apenas os nomes são impressos.
 * @param db Ponteiro para a estrutura da database a ser impressa.
 */
void ImprimeDatabase(tDatabase *db)
{

    OrdenaDatabase(db);
    printf("Alunos:\n");

    for (int i = 0; i < db->n1; i++)
    {

        tAluno *a = (tAluno *)VectorGet(db->students, i);
        ImprimeNomeAluno(a);
    }

    printf("\nProfessores:\n");

    for (int i = 0; i < db->n2; i++)
    {

        tProfessor *a = (tProfessor *)VectorGet(db->teachers, i);
        ImprimeNomeProfessor(a);
    }
}
