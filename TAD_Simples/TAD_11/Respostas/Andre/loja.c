
#include "vendedor.h"
#include <string.h>
#include "loja.h"
#include <stdio.h>
#include <stdlib.h>

tLoja AbreLoja(int id, float aluguel)
{

    tLoja loja;

    loja.id = id;
    loja.aluguel = aluguel;
    loja.totalVendedores = 0;
    loja.lucro = 0;

    return loja;
}

/**
 * @brief Verifica se o ID de uma loja é igual a outro.
 *
 * @param loja Estrutura do tipo tLoja contendo os dados da loja a ser verificada.
 * @param id ID da loja a ser comparado.
 * @return int Retorna 1 se o ID da loja é igual ao ID passado como parâmetro, ou 0 caso contrário.
 */
int VerificaIdLoja(tLoja loja, int id)
{

    return (loja.id == id);
}

/**
 * @brief Contrata um novo vendedor para a loja.
 *
 * @param loja Estrutura do tipo tLoja contendo os dados da loja.
 * @param vendedor Estrutura do tipo tVendedor contendo os dados do vendedor a ser contratado.
 * @return tLoja Retorna a estrutura do tipo tLoja atualizada com o novo vendedor contratado.
 */
tLoja ContrataVendedor(tLoja loja, tVendedor vendedor)
{

    loja.vendedores[loja.totalVendedores++] = vendedor;

    return loja;
}

/**
 * @brief Registra uma nova venda para um vendedor da loja.
 *
 * @param loja Estrutura do tipo tLoja contendo os dados da loja.
 * @param nome Nome do vendedor que realizou a venda.
 * @param valor Valor da venda a ser registrada.
 * @return tLoja Retorna a estrutura do tipo tLoja atualizada com a venda registrada.
 */
tLoja RegistraVenda(tLoja loja, char nome[50], float valor)
{

    for (int i = 0; i < loja.totalVendedores; i++)
    {

        if (!strcmp(loja.vendedores[i].nome, nome))
        {

            loja.vendedores[i].valor_vendido += valor;

            return loja;
        }
    }
}

/**
 * @brief Calcula o lucro da loja.
 *
 * @param loja Estrutura do tipo tLoja contendo os dados da loja.
 * @return tLoja Retorna a estrutura do tipo tLoja atualizada com o lucro calculado.
 */
tLoja CalculaLucro(tLoja loja)
{

    loja.lucro -= loja.aluguel;

    for (int i = 0; i < loja.totalVendedores; i++)
    {

        loja.lucro -= GetTotalRecebido(loja.vendedores[i]);
        loja.lucro += GetTotalVendido(loja.vendedores[i]);
    }

    return loja;
}

/**
 * @brief Imprime o relatório da loja.
 *
 * @param loja Estrutura do tipo tLoja contendo os dados da loja.
 */
void ImprimeRelatorioLoja(tLoja loja)
{

    printf("Loja %d: Lucro total: R$ %.2f\n", loja.id, loja.lucro);
    for (int i = 0; i < loja.totalVendedores; i++)
    {

        ImprimeRelatorioVendedor(loja.vendedores[i]);
    }
}
