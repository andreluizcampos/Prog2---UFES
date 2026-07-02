
#include "tAmbiente.h"
#include "tEventoMovimento.h"
#include <stdio.h>
#include <stdlib.h>

struct eventomovimento
{

    char c[4];
};

/// @brief Função que cria um evento do tipo movimento
/// @param caracteresAceitos - Vetor de QUATRO caracteres que irá representar movimento
///                             na ordem: CIMA, ESQUERDA, BAIXO, DIREITA
/// @return O ponteiro para a variável do tipo evento movimento
tEventoMovimento *criaEventoMovimento(char *caracteresAceitos)
{

    tEventoMovimento *e = (tEventoMovimento *)malloc(sizeof(tEventoMovimento));

    for (int i = 0; i < 4; i++)
    {

        e->c[i] = caracteresAceitos[i];
    }

    return e;
}
/// @brief Função que libera o evento...
/// @param eve - Ponteiro para o evento
void liberaEventoMovimento(void *eve)
{

    tEventoMovimento *e = ((tEventoMovimento *)(eve));
    free(e);
}

/// @brief Função que executará o comportamento de um evento movimento
///         No caso, deve alterar o ambiente de acordo com a tecla apertada, se for possível
/// @param amb - Ponteiro para o ambiente a ser manipulado
/// @param eve - Ponteiro para o evento de movimento
/// @param c - Caractere que foi digitado no teclado
void processaEventoMovimento(tAmbiente *amb, void *eve, char c)
{

    int vertical = 0, horizontal = 0;
    int col = 0, linha = 0;

    tEventoMovimento *e = ((tEventoMovimento *)eve);
    retornaPosicaoAtual(amb, &linha, &col);

    if(c  == e->c[0]){

        linha--;

    }
    if( c == e->c[1]){

    col--;

    }

    if(c == e->c[2]){

        linha++;
    }

    if(c == e->c[3]){

        col++;
    }

    if( linha >= 10 || col >= 10 || col <0 || linha <0){

        printf("MOVIMENTO INVALIDO POIS SAI DO MAPA!\n");

        return;
    }

    char p = retornaSituacaoPosicao(amb,linha,col);

    

    if(p!= '\0' && p!='0'){

        printf("MOVIMENTO INVALIDO POIS EXISTE OBSTACULO!\n");

            return;
    
        }

        alteraPosicaoJogador(amb, linha, col);
        

        printf("MOVIMENTO PARA POSICAO (%d,%d)\n",linha, col);

    




}

/// @brief Função que indica se um caractere apertado está registrado nos caracteres válidos de um movimento
/// @param eve - ponteiro para a variável evento
/// @param c - Caractere que foi digitado no teclado
/// @return 1 se o caractere digitado está registrado como um caractere do evento
int identificaEventoMovimento(void *eve, char c)
{

    tEventoMovimento *e = ((tEventoMovimento *)(eve));

    for (int i = 0; i < 4; i++)
    {

        if (e->c[i] == c)
        {

            return 1;
        }
    }

    return 0;
}