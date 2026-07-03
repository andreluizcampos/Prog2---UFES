#include "produto.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Produto
{

    int code;
    float price;
    char *name;
    int amount;
};

/**
 * @brief Função para criar um novo produto.
 * @param codigo O código do produto.
 * @param nome O nome do produto.
 * @param preco O preço do produto.
 * @param quantidade A quantidade do produto em estoque.
 * @return Um ponteiro para o produto recém-criado. Se houver erro na alocação de memória, a função aborta o programa.
 */
tProduto *CriaProduto(int codigo, char *nome, float preco, int quantidade)
{

    tProduto *p = (tProduto *)malloc(sizeof(tProduto));
    p->name = (char *)malloc(sizeof(char) * 50);

    strcpy(p->name, nome);
    p->code = codigo;
    p->amount = quantidade;
    p->price = preco;

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
    int amount, code;
    float price;

    fread(&code, sizeof(amount), 1, arquivo);
    fread(name, sizeof(char), 50, arquivo);
    fread(&price, sizeof(float), 1, arquivo);
    fread(&amount, __SIZEOF_INT__, 1, arquivo);

    tProduto *p = CriaProduto(code, name, price, amount);

    return p;
}

/**
 * @brief Função para verificar se um produto tem estoque.
 * @param produto Um ponteiro para o produto.
 * @return 1 se o produto tem estoque, 0 caso contrário.
 */
int TemEstoqueProduto(tProduto *produto)
{

    return produto->amount > 0;
}

/**
 * @brief Função para imprimir um produto no formato "Codigo;Nome;Preco".
 * @param produto Um ponteiro para o produto a ser impresso.
 */
void ImprimeProduto(tProduto *produto)
{

    printf("%d;%s;%.2f\n", produto->code, produto->name, produto->price);
}