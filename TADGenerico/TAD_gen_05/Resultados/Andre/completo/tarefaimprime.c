#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tarefaimprime.h"

struct impr
{

    int p;
    char *string;
};

/**
 *
 * @brief Cria uma tarefa do tipo impressão em tela
 *
 * @param msg - A mensagem que deve ser impressa em tela
 *
 * @return Um ponteiro para a tarefa criada
 */
tImpr *CriaTarefaImprimir(char *msg)
{

    tImpr *i = (tImpr *)malloc(sizeof(tImpr));
    i->string = (char *)malloc(sizeof(char) * 60);

    strcpy(i->string, msg);
    return i;
}

/**
 * @brief Função que executa uma tarefa de impressão em tela
 *
 * @param imp - Ponteiro para a tarefa a ser executada
 *
 */
void ExecutaTarefaImprimir(void *imp)
{

    tImpr *i = ((tImpr *)imp);
    printf("\n%s\n", i->string);
}

/**
 * @brief Função que destrói (libera a memória) uma tarefa de impressão em tela
 *
 * @param imp - Ponteiro para a tarefa a ser destruída
 *
 */
void DestroiTarefaImprimir(void *imp)
{
    tImpr *i = ((tImpr *)imp);
    free(i->string);
    free(i);
}