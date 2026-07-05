#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "estabelecimento.h"
#include "vector.h"
#include "produto.h"

struct Estabelecimento
{
    Vector *products;
    float t_vendas;
    int t_unidades;
};

/**
 * @brief Função para criar um novo estabelecimento.
 * @return Um ponteiro para o estabelecimento recém-criado. Se houver erro na alocação, o programa é encerrado.
 */
tEstabelecimento *CriaEstabelecimento()
{

    tEstabelecimento *e = malloc(sizeof(tEstabelecimento));
    e->products = VectorConstruct();
    e->t_unidades = 0;
    e->t_vendas = 0;

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

    char nome[50];
    scanf("%s ", nome);

    FILE *f = fopen(nome, "rb");
    int n;

    fread(&n, sizeof(int), 1, f);

    for (int i = 0; i < n; i++)
    {

        tProduto *p = LeProduto(f);
        estabelecimento->t_unidades += GetQuantidadeVendidaProduto(p);
        estabelecimento->t_vendas += (GetPrecoProduto(p) * GetQuantidadeVendidaProduto(p));
        AdicionaProdutoEstabelecimento(estabelecimento, p);
    }

    fclose(f);
}

/**
 * @brief Função para obter o valor total de produtos vendidos em um estabelecimento.
 * @param estabelecimento Um ponteiro para o estabelecimento.
 * @return O valor total de produtos vendidos.
 */
float GetValorTotalVendidoEstabelecimento(tEstabelecimento *estabelecimento)
{

    return estabelecimento->t_vendas;
}

/**
 * @brief Função para imprimir na tela um relatório de um estabelecimento, cotendo o valor total vendido e a porcentagem de cada produto relativo ao total vendido.
 * Formato: Codigo;Nome;Preco;Quantidade vendida
 * @param estabelecimento Um ponteiro para o estabelecimento.
 */
void ImprimeRelatorioEstabelecimento(tEstabelecimento *estabelecimento)
{

    printf("Valor total vendido: R$ %.2f\n", estabelecimento->t_vendas);
    printf("Produtos vendidos: \n");
    printf("Codigo;Nome;Preco;Quantidade vendida;Porcentagem\n");

    for (int i = 0; i < VectorSize(estabelecimento->products); i++)
    {

        ImprimeProduto(VectorGet(estabelecimento->products, i));
        tProduto *p = VectorGet(estabelecimento->products, i);
        float p_price = GetPrecoProduto(p);
        int p_qtd = GetQuantidadeVendidaProduto(p);
        float t_v = p_price * p_qtd;
        float percent = t_v / estabelecimento->t_vendas;
        printf(";%.2f%\n",percent*100);
    }
}