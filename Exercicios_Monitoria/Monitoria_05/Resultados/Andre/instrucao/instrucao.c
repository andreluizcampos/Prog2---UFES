#include <stdio.h>
#include <stdlib.h>
#include "instrucao.h"
#include <string.h>
struct instrucao
{
    char class;
    int rd, r1, r2;
};

/**
 * @brief Cria e inicializa uma instrução.
 *
 * @return Ponteiro para a instrução criada e alocada dinamicamente.
 */
Instrucao *criaInstrucao()
{
    Instrucao *i = malloc(sizeof(Instrucao));

    scanf(" %c %d %d %d\n", &i->class, &i->rd, &i->r1, &i->r2);

    return i;
}

/**
 * @brief Escreve uma instrução em um arquivo binário.
 *
 * @param i Instrução a ser escrita.
 * @param f Arquivo binário onde a instrução será armazenada.
 */
void escreveInstrucaoArquivo(Instrucao *i, FILE *f)
{

    fwrite(&i->class, sizeof(char), 1, f);
    fwrite(&i->rd, sizeof(int), 1, f);
    fwrite(&i->r1, sizeof(int), 1, f);
    fwrite(&i->r2, sizeof(int), 1, f);
}

/**
 * @brief Lê uma instrução de um arquivo binário.
 *
 * @param f Arquivo binário de onde a instrução será lida.
 * @return Ponteiro para a instrução lida e alocada dinamicamente.
 */
Instrucao *leInstrucaoArquivo(FILE *f)
{

    Instrucao *i = criaInstrucao();

    fread(&i->class, sizeof(char), 1, f);
    fread(&i->rd, sizeof(int), 1, f);
    fread(&i->r1, sizeof(int), 1, f);
    fread(&i->r2, sizeof(int), 1, f);
    return i;
}

/**
 * @brief Retorna o opcode da instrução.
 *
 * @param i Instrução analisada.
 * @return Caractere que representa a operação da instrução.
 */
char getOpcode(Instrucao *i)
{

    return i->class;
}

/**
 * @brief Retorna o índice do registrador de destino.
 *
 * @param i Instrução analisada.
 * @return Índice do registrador de destino.
 */
int getIndiceRegDestino(Instrucao *i)
{

  return i->rd;
}

/**
 * @brief Retorna o índice do primeiro registrador de origem.
 *
 * @param i Instrução analisada.
 * @return Índice do primeiro registrador de origem.
 */
int getIndiceReg1(Instrucao *i)
{
    return i->r1;
}

/**
 * @brief Retorna o índice do segundo registrador de origem.
 *
 * @param i Instrução analisada.
 * @return Índice do segundo registrador de origem.
 */
int getIndiceReg2(Instrucao *i)
{

    return i->r2;
}
