#include<stdio.h>
#include<stdlib.h>
#include"gerenciadorpacotes.h"
#include"pacote.h"

struct gerenciadorpacotes{

tPacote **pacotes;
int qtd;


};


/**
 * @brief Cria uma TAD que gerencia pacotes. O pacote é um TAD genérico.
 *
 *
 * @return O gerenciador de pacotes
 */
tGerenciador* CriaGerenciador(){


    tGerenciador *g = (tGerenciador*)malloc(sizeof(tGerenciador));

    g->pacotes =  (tPacote**)malloc(sizeof(tPacote*));
    g->qtd = 0;

        return g;


}

/**
 * @brief Adiciona um pacote ao gerenciador de pacotes.
 *
 * @param geren O gerenciador de pacotes que armazenará o pacote 
 * @param pac O pacote que queremos adicionar no gerenciador.
 *
 */
void AdicionaPacoteNoGerenciador(tGerenciador* geren, tPacote* pac){

    if(pac!=NULL){
    geren->pacotes[geren->qtd] = pac;
    geren->qtd++;
    geren->pacotes = (tPacote**)realloc(geren->pacotes, (geren->qtd+1) * sizeof(tPacote*));
    geren->pacotes[geren->qtd-1] = NULL;
    

}

}


/**
 * @brief Destrói um gerenciador de pacotes
 *
 * @param geren O gerenciador de pacotes que será destruído (memória liberada)
 *
 */
void DestroiGerenciador(tGerenciador* geren){

    if(geren!=NULL){

    for( int i = 0;i<geren->qtd;i++){

        DestroiPacote(geren->pacotes[i]);
    }

    free(geren->pacotes);
    free(geren);
}
}

/**
 * @brief Imprime um pacote específico do gerenciador de pacotes.
 *
 * @param geren - O gerenciador de pacotes que terá um pacote impresso
 * @param idx - O índice do pacote a ser impresso (começa em zero!)
 *
 */
void ImprimirPacoteNoIndice(tGerenciador* geren, int idx){

    ImprimePacote(geren->pacotes[idx]);
}


/**
 * @brief Imprime todos os pacotes de um gerenciador de pacotes
 *
 * @param geren O gerenciador de pacotes que terá seus pacotes impressos
 *
 */
void ImprimirTodosPacotes(tGerenciador* geren){


    for( int i = 0;i<geren->qtd;i++){

            ImprimePacote(geren->pacotes[i]);
    }
}