#include<stdio.h>
#include<stdlib.h>
#include "conta.h"
#include"vector.h"


struct Conta
{   

    int n;
    char *nome;
    float saldo;
    
};


/**
 * @brief Função para criar uma nova conta bancária.
 * @return Um ponteiro para a nova conta bancária criada. Se a memória não puder ser alocada, a função imprime uma mensagem de erro e termina o programa.
 */
tConta *CriaConta(){

    tConta *c = (tConta*)malloc(sizeof(tConta));
    c->nome = malloc(sizeof(char)*2000);
    c->saldo = 0;

            return c;
}

/**
 * @brief Função para destruir uma conta bancária.
 * @param conta A conta bancária a ser destruída.
 */
void DestroiConta(DataType conta){

       free(((tConta*)conta)->nome);
       free(((tConta*)conta)); 


}

/**
 * @brief Função para ler uma conta bancária no formato "numero;nome do cliente;saldo inicial".
 * @param conta A conta bancária a ser lida.
 */
void LeConta(tConta *conta){

    scanf("%d;",&conta->n);
    scanf("%[^;];",conta->nome);
    scanf("%f\n",&conta->saldo);

}

/**
 * @brief Função para obter o saldo de uma conta bancária.
 * @param conta A conta bancária.
 * @return O saldo da conta bancária.
 */
float GetSaldoConta(tConta *conta){

    return conta->saldo;
}

