#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "usuario.h"
#include "cpu.h"

struct usuario
{

    Instrucao **instrucoes;
    int qtd;
    int n_inst;
};

/**
 * @brief Cria e inicializa um usuário.
 *
 * @param nInstrucoes Número de instruções que o usuário irá fornecer.
 * @return Ponteiro para o usuário criado e alocado dinamicamente.
 */
Usuario *criaUsuario(int nInstrucoes)
{

    Usuario *u = (Usuario *)malloc(sizeof(Usuario));
    u->n_inst = nInstrucoes;
    u->instrucoes = (Instrucao **)malloc(sizeof(Instrucao *) * nInstrucoes);

    for (int i = 0; i < nInstrucoes; i++)
    {

        u->instrucoes[i] = criaInstrucao();
    }

    return u;
}

/**
 * @brief Lê uma instrução da entrada padrão e a grava no arquivo binário.
 *
 * @param u Usuário que está fornecendo a instrução.
 * @param f Arquivo binário onde a instrução será escrita.
 */
void adicionaInstrucao(Usuario *u, FILE *f)
{

    for (int i = 0; i < u->n_inst; i++)
    {

        escreveInstrucaoArquivo(u->instrucoes[i],f);
    }

}

/**
 * @brief Libera toda a memória associada ao usuário.
 *
 * @param u Usuário a ser liberado.
 */
void liberaUsuario(Usuario *u)
{

    for (int i = 0; i < u->n_inst; i++)
    {

        free(u->instrucoes[i]);
    }

    free(u->instrucoes);
    free(u);
}
