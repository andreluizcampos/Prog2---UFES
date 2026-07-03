#include "vector.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "estabelecimento.h"

struct Estabelecimento
{

    Vector *products;
};

/**
 * @brief Função para criar um novo estabelecimento.
 * @return Um ponteiro para o estabelecimento recém-criado. Se houver erro na alocação, o programa é encerrado.
 */
tEstabelecimento *CriaEstabelecimento()
{

    tEstabelecimento *e = (tEstabelecimento *)malloc(sizeof(tEstabelecimento));

    e->products = VectorConstruct();

    return e;
}

/**
 * @brief Função para destruir um estabelecimento.
 * @param estabelecimento Um ponteiro para o estabelecimento a ser destruído.
 */
void DestroiEstabelecimento(tEstabelecimento *estabelecimento)
{

    VectorDestroy(estabelecimento->products, DestroiProduto);
    free(estabelecimento);
}

/**
 * @brief Função para adicionar um produto a um estabelecimento.
 * @param estabelecimento Um ponteiro para o estabelecimento.
 * @param produto Um ponteiro para o produto a ser adicionado.
 */
void AdicionaProdutoEstabelecimento(tEstabelecimento *estabelecimento, tProduto *produto)
{

    VectorPushBack(estabelecimento->products, produto);
}

/**
 * @brief Função para ler um estabelecimento de um arquivo binário.
 * Inicialmente, deverá ser lido o nome do arquivo binário pela entrada padrão.
 * O arquivo binário deverá ser composto por um inteiro que representa a quantidade de produtos no estabelecimento, seguido pelos produtos.
 * @param estabelecimento Um ponteiro para o estabelecimento a ser lido.
 */
void LeEstabelecimento(tEstabelecimento *estabelecimento)
{

    char name[60];
    scanf("%s\n", name);
    FILE *f = fopen(name, "rb");
    int n = 0;
    fread(&n, sizeof(int), 1, f);

    for (int i = 0; i < n; i++)
    {

        tProduto *p = LeProduto(f);
        AdicionaProdutoEstabelecimento(estabelecimento, p);
    }

    fclose(f);
}

/**
 * @brief Função para imprimir produtos que estão faltando em um estabelecimento no seguinte formato: Codigo;Nome;Preco
 * @param estabelecimento Um ponteiro para o estabelecimento.
 */
void ImprimeProdutosEmFaltaEstabelecimento(tEstabelecimento *estabelecimento)
{

    int n = VectorSize(estabelecimento->products);
    int flag = 1;

    printf("Produtos em falta:\nCodigo;Nome;Preco\n");

    for (int i = 0; i < n; i++)
    {

        int qtd = TemEstoqueProduto(VectorGet(estabelecimento->products, i));

        if (qtd == 0)
        {

            ImprimeProduto(VectorGet(estabelecimento->products, i));
            flag  = 0;
        }
    }


    if(flag){

        printf("Nao ha produtos em falta!\n");
    }
}