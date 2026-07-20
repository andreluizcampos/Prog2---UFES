#include "supermercado.h"
#include "produto.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Supermercado
{

    Produto **produtos;
    int qtd_alocado;
    int qtd;
    float lucro;
};

Supermercado *CriarSupermercado()
{

    Supermercado *s = (Supermercado *)malloc(sizeof(Supermercado));

    s->produtos = (Produto **)malloc(sizeof(Produto *));
    s->qtd = 0;
    s->qtd_alocado = 0;
    s->lucro = 0;

    return s;
}

void LiberaSupermercado(Supermercado *s)
{

    for (int i = 0; i < s->qtd; i++)
    {
        LiberaProduto(s->produtos[i]);
    }

    free(s->produtos);
    free(s);
}

int VerificarProdutoCadastrado(Supermercado *s, int codigo)
{

    for (int i = 0; i < s->qtd; i++)
    {
        if (ObterCodigoProduto(s->produtos[i]) == codigo)
        {
            return 1;
        }
    }

    return 0;
}

void LerCadastroSupermercado(Supermercado *s)
{

    int code;
    Produto *p = CriarProduto();
    scanf("%d", &code);
    LeProduto(p, code);
    CadastrarProdutoSupermercado(s, p);
}

void CadastrarProdutoSupermercado(Supermercado *s, Produto *p)
{

    if (!VerificarProdutoCadastrado(s, ObterCodigoProduto(p)))
    {

        s->produtos = realloc(s->produtos, (s->qtd + 1) * sizeof(Produto *));
        s->produtos[s->qtd] = p;
        s->qtd++;
        s->qtd_alocado++;
        ImprimirNomeProduto(p);
        printf(" foi cadastrado(a)\n");
    }
    else
    {
        LiberaProduto(p);
    }
}
void ComprarProdutoSupermercado(Supermercado *s, int codigo)
{
    int flag = 0;

    for (int i = 0; i < s->qtd; i++)
    {
        if (EhMesmoCodigoProduto(s->produtos[i], codigo))
        {
            flag = 1;

            if (ObterQtdEstoqueProduto(s->produtos[i]) > 0)
            {
                ComprarProduto(s->produtos[i]);
                s->lucro += ObterValorProduto(s->produtos[i]);
                ImprimirNomeProduto(s->produtos[i]);
                printf(" foi comprado(a)\n");
            }
            else
            {
                ImprimirNomeProduto(s->produtos[i]);
                printf(" sem estoque\n");
            }
        }
    }

    if (!flag)
    {
        printf("Codigo nao cadastrado no supermercado\n");
    }
}
void LerCompraSupermercado(Supermercado *s)
{
    int qtd;
    scanf("%d\n", &qtd);

    for (int i = 0; i < qtd; i++)
    {
        int id;
        scanf("%d\n", &id);
        ComprarProdutoSupermercado(s, id);
    }
}

void FornecerProdutoSupermercado(Supermercado *s, int codigo, int qtdFornecida)
{

    int flag  = 0;
    for (int i = 0; i < s->qtd; i++)
    {
        if (EhMesmoCodigoProduto(s->produtos[i], codigo))
        {
            AumentaEstoque(s->produtos[i], qtdFornecida);
            ImprimirNomeProduto(s->produtos[i]);
            printf(" teve estoque aumentado\n");
            flag  = 1;
        }
    }

    if(!flag){

        printf("Codigo nao cadastrado no supermercado\n");
    }
}

void LerFornecimento(Supermercado *s)
{

    int code, qtd;
    scanf("%d %d\n", &code, &qtd);
    FornecerProdutoSupermercado(s, code, qtd);
}

void OrdenarProdutosSupermercado(Supermercado *s)
{

    for (int i = 0; i < s->qtd - 1; i++)
    {
        for (int j = 0; j < s->qtd - i - 1; j++)
        {
            if (CompararNomesProdutos(s->produtos[j], s->produtos[j + 1]) > 0)
            {
                Produto *temp = s->produtos[j];
                s->produtos[j] = s->produtos[j + 1];
                s->produtos[j + 1] = temp;
            }
        }
    }
}

void ConsultarEstoqueSupermercado(Supermercado *s)
{

    OrdenarProdutosSupermercado(s);

    for (int i = 0; i < s->qtd; i++)
    {
        printf("%d - ", ObterCodigoProduto(s->produtos[i]));
        ImprimirNomeProduto(s->produtos[i]);
        printf(" - %d\n", ObterQtdEstoqueProduto(s->produtos[i]));
    }
}

void ConsultarLucroSupermercado(Supermercado *s)
{

    printf("Lucro do supermercado: %.2f\n", s->lucro);
}