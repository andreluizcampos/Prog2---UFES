#include <stdio.h>
#include <stdlib.h>
#include "banco.h"
#include "conta.h"
#include "usuario.h"

struct Banco
{

    tConta **contas;
    int qtd_acc;
};

/**
 * @brief Cria um novo banco, com 5 contas alocadas e nenhuma conta aberta.
 * Se não for possível alocar memória, o programa é encerrado.
 *
 * @return Um ponteiro para o novo banco criado.
 */
tBanco *CriaBanco()
{

    tBanco *b = (tBanco*)malloc((sizeof(tBanco)));
    b->qtd_acc = 0;

    b->contas = (tConta **) malloc((sizeof(tConta *)));

    return b;
}

/**
 * @brief Desaloca a memória de um banco e de todas as suas contas.
 *
 * @param banco Ponteiro para o banco a ser destruído.
 */
void DestroiBanco(tBanco *banco)
{

    for (int i = 0; i < banco->qtd_acc; i++)
    {
        DestroiConta(banco->contas[i]);
    }

    free(banco->contas);

    free(banco);
}

/**
 * @brief Abre uma nova conta no banco e a adiciona ao vetor de contas.
 *
 * @param banco Ponteiro para o banco onde a conta será aberta.
 */
void AbreContaBanco(tBanco *banco)
{

    banco->contas[banco->qtd_acc] = CriaConta();

    LeConta(banco->contas[banco->qtd_acc]);

    banco->qtd_acc++;

    banco->contas = realloc(banco->contas, (banco->qtd_acc + 1) * sizeof(tConta*));
}

/**
 * @brief Realiza um saque em uma conta do banco se ela existir e tiver saldo suficiente.
 * Nessa função é necessário ler o número da conta e o valor do saque.
 *
 * @param banco Ponteiro para o banco onde a conta será sacada.
 */
void SaqueContaBanco(tBanco *banco)
{

    int id = 0, acc_id = 0;

    float value = 0;

    scanf("%d", &id);

    for (int i = 0; i < banco->qtd_acc; i++)
    {

        if (VerificaConta(banco->contas[i], id))
        {

            scanf("%f\n", &value);
            SaqueConta(banco->contas[i], value);
        }
    }
}

/**
 * @brief Realiza um depósito em uma conta do banco se ela existir.
 * Nessa função é necessário ler o número da conta e o valor do depósito.
 *
 * @param banco Ponteiro para o banco onde a conta será depositada.
 */
void DepositoContaBanco(tBanco *banco)
{

    int id = 0, acc_id = 0;

    float value = 0;

    scanf("%d", &id);

    for (int i = 0; i < banco->qtd_acc; i++)
    {

        if (VerificaConta(banco->contas[i], id))
        {

            scanf("%f\n", &value);
            DepositoConta(banco->contas[i], value);
        }
    }
}

/**
 * @brief Realiza uma transferência entre duas contas do banco se elas existirem e a conta de origem tiver saldo suficiente.
 * Nessa função é necessário ler o número da conta de origem, o número da conta de destino e o valor da transferência.
 *
 * @param banco Ponteiro para o banco onde as contas estão.
 */
void TransferenciaContaBanco(tBanco *banco)
{

    int id = 0, acc_id = 0, id2 = 0;

    float value = 0;

    scanf("%d %d", &id, &id2);

    for (int i = 0; i < banco->qtd_acc; i++)
    {

        if (VerificaConta(banco->contas[i], id))
        {

            for (int j = 0; j < banco->qtd_acc; j++)
            {

                if (VerificaConta(banco->contas[j], id2))
                {

                    scanf("%f ", &value);

                    TransferenciaConta(banco->contas[i], banco->contas[j], value);
                }
            }
        }
    }
}

/**
 * @brief Imprime o relatório do banco, com todas as contas e seus respectivos dados.
 *
 * @param banco Ponteiro para o banco a ser impresso.
 */
void ImprimeRelatorioBanco(tBanco *banco){


        printf("===| Imprimindo Relatorio |===\n");

    for(int i = 0;i<banco->qtd_acc;i++){

        ImprimeConta(banco->contas[i]);
    }
}