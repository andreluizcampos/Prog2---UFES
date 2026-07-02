#include <stdio.h>
#include <stdlib.h>
#include "agendatarefas.h"
#include <string.h>

struct task
{

    void *task;
    int p;
    void (*executa)(void *);
    void (*libera)(void *);
};

struct agendatarefas
{
    int qtd;
    struct task **tarefas;
    int inserted;
};

/**
 * @brief Cria uma variável para um tipo genérico que representa uma Agenda de Tarefas
 *
 * @param numElem A quantidade de tarefas que serão armazenadas no agendador
 *
 * @return Um ponteiro para a agenda de tarefas
 */
tAgendaTarefas *CriaAgendaDeTarefas(int numElem)
{

    tAgendaTarefas *a = (tAgendaTarefas *)malloc(sizeof(tAgendaTarefas));

    a->tarefas = malloc(sizeof(struct task *) * numElem);
    a->qtd = numElem;
    a->inserted = 0;
    return a;
}

/**
 * @brief Destroi a agenda de tarefas (libera a memória)
 *
 * @param tar - A agenda que terá seu conteúdo liberado/destruído
 */
void DestroiAgendaDeTarefas(tAgendaTarefas *tar)
{

    free(tar->tarefas);
    free(tar);
}

/**
 * @brief Cadastra uma tarefa em um agendador de tarefas
 *
 * @param tar - Pointeiro para a agenda de tarefas
 * @param prioridade - Prioridade de execução da nova tarefa
 * @param tarefa - Ponteiro para nova tarefa a ser executada
 * @param executa - Ponteiro para função (callback) que será chamada quando for a hora de executar a tarefa
 * @param destroi - Ponteiro para função (callback) que será chamada quando for a hora de destruir a tarefa (liberar a memória)
 *
 */
void CadastraTarefaNaAgenda(tAgendaTarefas *tar, int prioridade, void *tarefa, void (*executa)(void *), void (*destroi)(void *))
{

    tar->tarefas[tar->inserted] = malloc(sizeof(struct task));
    tar->tarefas[tar->inserted]->executa = executa;
    tar->tarefas[tar->inserted]->task = tarefa;
    tar->tarefas[tar->inserted]->libera = destroi;
    tar->tarefas[tar->inserted]->p = prioridade;
    tar->inserted++;
}

/**
 * @brief Executa as tarefas que estão salvas na agenda de tarefas passada como parâmetro.
 *
 * @param tar Agenda de tarefas
 *
 */
void ExecutarTarefasDaAgenda(tAgendaTarefas *tar)
{

    int flag = 1;

    while (flag)
    {

        flag = 0;

        for (int i = 0; i < tar->qtd - 1; i++)
        {

            if (tar->tarefas[i]->p < tar->tarefas[i + 1]->p)
            {
                struct task *temp = tar->tarefas[i];
                tar->tarefas[i] = tar->tarefas[i + 1];
                tar->tarefas[i + 1] = temp;
                flag = 1;
            }
        }
    }

    for (int i = 0; i < tar->qtd; i++)
    {

        struct task *t = tar->tarefas[i];
        t->executa(t->task);
        t->libera(t->task);
        free(tar->tarefas[i]);
    }
}
