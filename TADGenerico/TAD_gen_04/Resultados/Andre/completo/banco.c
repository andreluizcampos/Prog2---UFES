#include <stdio.h>
#include "agencia.h"
#include "vector.h"
#include <stdlib.h>
#include <string.h>
#include "banco.h"

/**
 * @brief Estrutura para representar um banco.
 */
struct Banco
{
    int qtd;
    char *nome;
    int id;
    Vector *agencias;
};

/**
 * @brief Função para criar um novo banco.
 * @return Um ponteiro para o novo banco criado. Se a memória não puder ser alocada, a função imprime uma mensagem de erro e termina o programa.
 */
tBanco *CriaBanco()
{

    tBanco *b = (tBanco*)malloc(sizeof(tBanco));
    b->qtd = 0;
    b->nome = (char *)malloc(sizeof(char) * 1000);
    b->agencias = VectorConstruct();

    return b;
}

/**
 * @brief Função para destruir um banco.
 * @param banco O banco a ser destruído.
 */
void DestroiBanco(tBanco *banco)
{

    VectorDestroy(banco->agencias, DestroiAgencia);
    free(banco->nome);
    free(banco);
}

/**
 * @brief Função para ler o nome de um banco.
 * @param banco O banco a ser lido.
 */
void LeBanco(tBanco *banco)
{

    scanf("%[^\n]\n", banco->nome);
}

/**
 * @brief Função para adicionar uma agência a um banco.
 * @param banco O banco.
 * @param agencia A agência a ser adicionada.
 */
void AdicionaAgencia(tBanco *banco, tAgencia *agencia)
{
    
    VectorPushBack(banco->agencias, agencia);
}

/**
 * @brief Função para inserir uma conta em uma agência pertencente ao banco.
 * @param banco O banco.
 * @param numAgencia O número da agência.
 * @param cliente A conta a ser inserida.
 * @pre A agência deve pertencer ao banco.
 */
void InsereContaBanco(tBanco *banco, int numAgencia, tConta *cliente)
{

    int flag =0;
    
    int qtd = VectorSize(banco->agencias);


    for (int i = 0;i< qtd; i++)
    {

        if (ComparaAgencia(numAgencia, VectorGet(banco->agencias, i)))
        {
            AdicionaConta((tAgencia*)VectorGet(banco->agencias,i),cliente);  // Erro: Esquecer da função!
                                                                            // Erro 2: Entendimento certo na pushback, porém, incapacidade de itera o agencia n, o que dava seg fault;
            flag = 1;
        }
    }

    if(!flag){

        DestroiConta(cliente);
    }
}

/**
 * @brief Função para imprimir o relatório de um banco, com o nome do banco e a lista de agências.
 * @param banco O banco.
 */
void ImprimeRelatorioBanco(tBanco *banco){
    int qtd = VectorSize(banco->agencias);
    printf("%s\n",banco->nome);
    printf("Lista de agencias:\n");

        for( int i = 0;i<qtd;i++){

            ImprimeDadosAgencia((VectorGet(banco->agencias,i)));
        }

}
