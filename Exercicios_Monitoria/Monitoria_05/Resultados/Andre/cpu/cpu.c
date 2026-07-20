
#include <stdlib.h>
#include <stdio.h>
#include "instrucao.h"
#include "cpu.h"

struct cpu
{
    int regs[8];
    Instrucao **instrucoes;
    int n_inst;
};

Cpu *criaCpu()
{

    Cpu *c = (Cpu *)malloc(sizeof(Cpu));

    for (int i = 0; i < 8; i++)
    {

        c->regs[i] = 0;
    }
    c->instrucoes = (Instrucao **)malloc(sizeof(Instrucao *));
    for (int i = 0; i < 8; i++)
    {

        scanf("%d", &c->regs[i]);
    }
    c->n_inst = 0;

    getchar();

    return c;
}

/**
 * @brief Lê e executa um conjunto de instruções a partir de um arquivo binário.
 *
 * Essa função lê as instruções armazenadas no arquivo e as executa
 * sequencialmente na CPU.
 *
 * @param c CPU que executará as instruções.
 * @param f Arquivo binário de onde as instruções serão lidas.
 * @param nInstrucoes Quantidade de instruções a serem executadas.
 */
void realizaInstrucao(Cpu *c, FILE *f, int nInstrucoes)
{

    for (int i = 0; i < nInstrucoes; i++)
    {
        Instrucao *i = leInstrucaoArquivo(f);
        c->instrucoes[c->n_inst] = i;
        c->n_inst++;
        c->instrucoes = (Instrucao **)realloc(c->instrucoes, sizeof(Instrucao *) * (c->n_inst + 1));
        executaInstrucao(c, i);
    }
}

/**
 * @brief Executa uma única instrução na CPU.
 *
 * A instrução é interpretada e aplicada sobre os registradores da CPU,
 * substituindo o valor do registrador de destino pelo resultado da operação.
 *
 * @param c CPU que executará a instrução.
 * @param i Instrução a ser executada.
 */
void executaInstrucao(Cpu *c, Instrucao *i)
{

    int rd = getIndiceRegDestino(i);
    int r1 = getIndiceReg1(i);
    int r2 = getIndiceReg2(i);
    char op = getOpcode(i);

    switch (op)
    {

    case 'A':

        c->regs[rd] = c->regs[r1] + c->regs[r2];
        break;

    case 'S':

        c->regs[rd] = c->regs[r1] - c->regs[r2];
        break;

    case 'D':

        c->regs[rd] = c->regs[r1] / c->regs[r2];
        break;

    case 'M':

        c->regs[rd] = c->regs[r1] * c->regs[r2];
        break;

    default:

        break;
    }
}

/**
 * @brief Imprime o conteúdo dos 8 registradores da CPU.
 *
 * Os registradores são impressos em ordem, do registrador 0 ao 7.
 *
 * @param c CPU cujos registradores serão impressos.
 */
void imprimeRegistradores(Cpu *c)
{

    for (int i = 0; i < 8; i++)
    {

        printf("%d ", c->regs[i]);
    }

    printf("\n");
}

/**
 * @brief Libera toda a memória associada à CPU.
 *
 * @param c CPU a ser liberada.
 */
void liberaCpu(Cpu *c)
{

    for (int i = 0; i < c->n_inst; i++)
    {

        free(c->instrucoes[i]);
    }

    free(c->instrucoes);
    free(c);
}
