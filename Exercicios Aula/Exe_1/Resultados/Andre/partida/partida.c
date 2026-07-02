#include<stdio.h>
#include<stdlib.h>
#include"partida.h"
#include"franquia.h"
#include<string.h>

/*
Função que incializa os dados de uma partida e retorna o tPartida. 
@param char *time1: String com o nome do primeiro time da partida
@param char *time2: String com o nome do segundo time da partida
@param int pontosTime1: Inteiro com o número de pontos do primeiro time da partida
@param int pontosTime2: Inteiro com o número de pontos do segundo time da partida

@return tPartida: Retorna uma variável do tipo tPartida criada
*/
tPartida lerPartida(char *timeFora, char *timeCasa, int pontosTimeFora, int pontosTimeCasa){

    tPartida partida;
    
    strcpy(partida.nomeTimeCasa, timeCasa);
    strcpy(partida.nomeTimeFora, timeFora);

    partida.pontosTimeCasa = pontosTimeCasa;
    partida.pontosTimeFora = pontosTimeFora;

                return partida;

}

/*
Função que imprime todos os dados de uma partida (diferente dos casos de teste).

@param tFranquia f: Tipo tPartida a ser impresso
*/
void imprimePartida(tPartida p){

    //Null
}

/*
Função que retorna os dados de uma partida.
*/
void obtemDadosPartida(tPartida p, char *nomeTimeFora, char *nomeTimeCasa, int* pontosTimeFora, int* pontosTimeCasa){

    strcpy(nomeTimeCasa, p.nomeTimeCasa);
    strcpy(nomeTimeFora, p.nomeTimeFora);

    *pontosTimeCasa = p.pontosTimeCasa;
    *pontosTimeFora = p.pontosTimeFora;

}