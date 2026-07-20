#include"produto.h"
#include<stdio.h>
#include<string.h>
#include<stdlib.h>


struct  Produto
{

    int code;
    char *name;
    float valor;
    int comprado;
    int estoque;
    
};



/**
 * @brief Cria um novo produto e define a quantidade comprada como 0.
 * 
 * @return Ponteiro para o produto criado ou encerra caso não seja possível alocar memória.
 */
Produto* CriarProduto(){

    Produto *p =(Produto*)malloc(sizeof(Produto));
    p->name = (char*)malloc(sizeof(char)*MAX_CARACTERES);

    p->code = 0;
    p->comprado = 0;
    p->estoque = 0;
    p->valor = 0;

                return p;
}

/**
 * @brief Lê um Produto do arquivo de entrada e define o código do produto.
 * 
 * @param p Ponteiro para o produto a ser lido.
*/
void LeProduto(Produto *p, int codigo){

    p->code = codigo;

        scanf(" %[^\n]",p->name);
        scanf(" %f %d\n",&p->valor, &p->estoque);
}

/**
 * @brief Libera a memória alocada para o produto.
 * 
 * @param p Ponteiro para o produto a ser destruído.
*/
void LiberaProduto (Produto* p){


    free(p->name);
    free(p);
}

/**
 * @brief Retorna o código do produto.
 * 
 * @param p Ponteiro para o produto.
 * @return Código do produto.
*/
int ObterCodigoProduto (Produto* p){

    return p->code;
}

/**
 * @brief Imprime o nome do produto.
 * 
 * @param p Ponteiro para o produto.
*/
void ImprimirNomeProduto (Produto* p){


    printf("%s",p->name);
}

/**
 * @brief Retorna o valor do produto.
 * 
 * @param p Ponteiro para o produto.
 * @return Valor do produto.
*/
float ObterValorProduto (Produto* p){


    return p->valor;
}

/**
 * @brief Retorna a quantidade em estoque do produto.
 * 
 * @param p Ponteiro para o produto.
 * @return Quantidade em estoque do produto.
*/
int ObterQtdEstoqueProduto (Produto* p){


    return  p->estoque;
}

/**
 * @brief Retorna a quantidade comprada do produto.
 * 
 * @param p Ponteiro para o produto.
 * @return Quantidade comprada do produto.
*/
int ObterQtdCompradaProduto (Produto* p){


    return p->comprado;
}

/**
 * @brief Verifica se o produto possui o código passado como parâmetro.
 * 
 * @param p Ponteiro para o produto.
 * @param codigo Código a ser comparado.
 * @return 1 se o produto possui o código passado como parâmetro, 0 caso contrário.
*/
int EhMesmoCodigoProduto (Produto* p, int codigo){


    return  p->code == codigo;
}

/**
 * @brief Incrementa a quantidade comprada e decrementa a quantidade em estoque do produto.
 * 
 * @param p Ponteiro para o produto.
*/
void ComprarProduto (Produto* p){

    p->estoque--;
    p->comprado++;
}

/**
 * @brief Incrementa a quantidade em estoque do produto.
 * 
 * @param p Ponteiro para o produto.
 * @param qtdFornecida quantidade do produto comprada pelo supermercado
*/
void AumentaEstoque (Produto* p, int qtdFornecida){

    p->estoque+=qtdFornecida;
}

/**
 * @brief Compara dois produtos pelo nome.
 * 
 * @param produto1 Ponteiro para o primeiro produto.
 * @param produto2 Ponteiro para o segundo produto.
 * @return 1 se o nome do primeiro produto for maior que o nome do segundo produto, -1 se o nome do primeiro produto for menor que o nome do segundo produto, 0 se os nomes forem iguais.
*/
int CompararNomesProdutos (Produto* produto1, Produto* produto2){


    return strcmp(produto1->name, produto2->name);
}
