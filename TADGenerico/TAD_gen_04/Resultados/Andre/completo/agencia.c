#include "agencia.h"
#include "conta.h"
#include "vector.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * @brief Estrutura para representar uma agência bancária.
 */
struct Agencia
{

    int n;
    char *nome;
    int n_conta;
    Vector *contas;
};

/**
 * @brief Função para criar uma nova agência bancária.
 * @return Um ponteiro para a nova agência bancária criada. Se a memória não puder ser alocada, a função imprime uma mensagem de erro e termina o programa.
 */
tAgencia *CriaAgencia()
{

    tAgencia *a = malloc(sizeof(tAgencia));
    a->contas = VectorConstruct();
    a->n_conta = 0;
    a->nome =(char*) malloc(sizeof(char)*100);
    return a;
}

/**
 * @brief Função para destruir uma agência bancária.
 * @param agencia A agência bancária a ser destruída.
 */
void DestroiAgencia(DataType agencia)
{

    VectorDestroy(((tAgencia*)agencia)->contas,DestroiConta);
    free(((tAgencia*)agencia)->nome);
    free(agencia);

}

    /**
     * @brief Função para ler uma agência bancária no formato "numero;nome".
     * @param agencia A agência bancária a ser lida.
     */
    void LeAgencia(tAgencia * agencia)
    {

        scanf("%d;%[^\n]\n", &agencia->n, agencia->nome);
    }

    /**
     * @brief Função para adicionar uma conta bancária a uma agência bancária.
     * @param agencia A agência bancária.
     * @param conta A conta bancária a ser adicionada.
     */
    void AdicionaConta(tAgencia * agencia, tConta * conta)
    {

        if (agencia != NULL && conta != NULL)
        {
            VectorPushBack(agencia->contas, conta);
            agencia->n_conta++;
        }
    }

    /**
     * @brief Função para comparar um número de agência bancária com uma agência bancária.
     * @param numAgencia O número da agência bancária.
     * @param agencia2 A agência bancária a ser comparada.
     * @return 1 se os números forem iguais, 0 caso contrário.
     */
    int ComparaAgencia(int numAgencia, tAgencia *agencia2)
    {

        return numAgencia == agencia2->n;
    }

    /**
     * @brief Função para obter o saldo médio das contas de uma agência bancária.
     * @param agencia A agência bancária.
     * @return O saldo médio das contas da agência.
     */
    float GetSaldoMedioAgencia(tAgencia * agencia)
    {

        float saldo = 0;

        for (int i = 0; agencia->n_conta > i; i++)
        {

            saldo += GetSaldoConta(VectorGet(agencia->contas, i));
        }

        return saldo / ((float)agencia->n_conta);
    }

    /**
     * @brief Função para imprimir os dados de uma agência bancária (nome, número, número de contas cadastradas e saldo médio).
     * @param agencia A agência bancária.
     */
    void ImprimeDadosAgencia(tAgencia * agencia)
    {

        printf("\tNome: %s\n \tNumero: %d\n \tNumero de contas cadastradas: %d\n \tSaldo médio: R$%.2f\n\n", agencia->nome, agencia->n, agencia->n_conta, GetSaldoMedioAgencia(agencia));
    }
