#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "produto.h"
#include "vector.h"

struct Produto
{

    char *name;
    float price;
    int code;
    int amount;
};

tProduto *CriaProduto(int codigo, char *nome, float preco, int quantidadeVendida)
{

    tProduto *p = (tProduto *)malloc(sizeof(tProduto));
    p->name = (char *)malloc(sizeof(char) * 50);
    strcpy(p->name, nome);
    p->code = codigo;
    p->price = preco;
    p->amount = quantidadeVendida;

    return p;
}

/**
 * @brief Função para destruir um produto.
 * @param produto Um ponteiro para o produto a ser destruído.
 */
void DestroiProduto(tProduto *produto)
{

    free(produto->name);
    free(produto);
}

/**
 * @brief Função para ler um produto de um arquivo binário.
 * @param arquivo O arquivo de onde o produto será lido.
 * Formato do arquivo:
 * Código (int)
 * Nome (string)
 * Preço (float)
 * Quantidade (int).
 * @return Um ponteiro para o produto lido.
 */
tProduto *LeProduto(FILE *arquivo)
{

    char name[50];
    int code;
    int amount;
    float price;

    fread(&code, sizeof(int), 1, arquivo);
    fread(name, sizeof(char), 50, arquivo);
    fread(&price, sizeof(float), 1, arquivo);
    fread(&amount, sizeof(int), 1, arquivo);

    tProduto *p = CriaProduto(code, name, price, amount);

    return p;
}

/**
 * @brief Função para imprimir um produto no formato "Codigo;Nome;Preco;Quantidade vendida".
 * @param produto Um ponteiro para o produto a ser impresso.
 */
void ImprimeProduto(tProduto *produto)
{


    printf("%d;%s;R$ %.2f;%d",produto->code, produto->name, produto->price,produto->amount);

}

/**
 * @brief Função para obter a quantidade vendida de um produto.
 * @param produto Um ponteiro para o produto.
 * @return A quantidade vendida do produto.
 */
int GetQuantidadeVendidaProduto(tProduto *produto)
{

    return produto->amount;
}

/**
 * @brief Função para obter o preço de um produto.
 * @param produto Um ponteiro para o produto.
 * @return O preço do produto.
 */
float GetPrecoProduto(tProduto *produto){

    return produto->price;
}
