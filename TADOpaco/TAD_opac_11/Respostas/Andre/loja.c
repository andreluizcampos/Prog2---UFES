#include<stdio.h>
#include<stdlib.h>
#include"vendedor.h"
#include"loja.h"

struct Loja
{
    int qtd;
    tVendedor **v;
    float aluguel;
    int id;
    float lucro;
};


tLoja* AbreLoja(int id, float aluguel){

    tLoja *l = (tLoja*)malloc(sizeof(tLoja));
    l->id = id;
    l->aluguel = aluguel;
    l->v = (tVendedor**)malloc(sizeof(tVendedor*));
    l->qtd = 0;
    l->lucro = 0;

        return l;
}

/**
 * @brief Libera a memória alocada para uma loja.
 * 
 * @param loja Ponteiro para uma loja a ser apagado.
 */
void ApagaLoja(tLoja* loja){


    for( int i = 0;i<loja->qtd;i++){

        ApagaVendedor(loja->v[i]);
    }

    free(loja->v);
    free(loja);

}

/**
 * @brief Verifica se o ID de uma loja é igual a outro.
 * 
 * @param loja Estrutura do tipo tLoja contendo os dados da loja a ser verificada.
 * @param id ID da loja a ser comparado.
 * @return int Retorna 1 se o ID da loja é igual ao ID passado como parâmetro, ou 0 caso contrário.
 */
int VerificaIdLoja(tLoja* loja, int id){


    return loja->id == id;
}

/**
 * @brief Contrata um novo vendedor para a loja.
 * 
 * @param loja Estrutura do tipo tLoja contendo os dados da loja.
 * @param vendedor Estrutura do tipo tVendedor contendo os dados do vendedor a ser contratado.
 * @return tLoja Retorna a estrutura do tipo tLoja atualizada com o novo vendedor contratado.
 */
void ContrataVendedor(tLoja* loja, tVendedor* vendedor){

    loja->v[loja->qtd] = vendedor;
    loja->qtd++;
    loja->v = realloc(loja->v,(loja->qtd+1)*(sizeof(tVendedor*)));
}

/**
 * @brief Registra uma nova venda para um vendedor da loja.
 * 
 * @param loja Estrutura do tipo tLoja contendo os dados da loja.
 * @param nome Nome do vendedor que realizou a venda.
 * @param valor Valor da venda a ser registrada.
 * @return tLoja Retorna a estrutura do tipo tLoja atualizada com a venda registrada.
 */
void RegistraVenda(tLoja* loja, char* nome, float valor){

    for( int i = 0;i<loja->qtd;i++){

        if(VerificaNomeVendedor(loja->v[i], nome)){

            ContabilizaVenda(loja->v[i],valor);
        }
    }

}

/**
 * @brief Calcula o lucro da loja.
 * 
 * @param loja Estrutura do tipo tLoja contendo os dados da loja.
 * @return tLoja Retorna a estrutura do tipo tLoja atualizada com o lucro calculado.
 */
void CalculaLucro(tLoja* loja){


    float lucro = 0;
    float t_v = 0;

        for( int i = 0;i<loja->qtd;i++){

          
            lucro+=GetTotalVendido(loja->v[i]) - GetTotalRecebido(loja->v[i]);
        }

        loja->lucro = lucro - loja->aluguel;
}

/**
 * @brief Imprime o relatório da loja.
 * 
 * @param loja Estrutura do tipo tLoja contendo os dados da loja.
 */
void ImprimeRelatorioLoja(tLoja* loja){

    printf("Loja %d: Lucro total: R$ %.2f\n", loja->id, loja->lucro);

        for( int i = 0;i<loja->qtd;i++){


            ImprimeRelatorioVendedor(loja->v[i]);

        }
    
    
}
