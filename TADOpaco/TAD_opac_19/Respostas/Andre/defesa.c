#include<stdio.h>
#include"defesa.h"
#include"missil.h"
#include<stdlib.h>
#include<math.h>

struct defesa {
    char *nome;
    float x, y;
    char tipo;
    float tamanho;
    float poder;
    int quantidade;
};




tDefesa LeDefesa(){


    tDefesa d = (tDefesa)malloc(sizeof(tDefesa));
    d->nome = malloc(MAX_TAM+1);

    scanf("%s %f %f %c %f %f %d\n", d->nome, &d->x, &d->y, &d->tipo, &d->tamanho, &d->poder, &d->quantidade);

    return d;


}

/**
 * @brief Imprime as informações da defesa.
 * 
 * @param defesa Ponteiro para a defesa que será impressa.
 */
void ImprimeDefesa(tDefesa defesa){

    printf("D-%s: %d\n", defesa->quantidade);
}

/**
 * @brief Libera a memória alocada para a defesa.
 * 
 * @param defesa Ponteiro para a defesa que terá a memória liberada.
 */
void LiberaDefesa(tDefesa defesa){

    free(defesa->nome);
    free(defesa);
}

/**
 * @brief Verifica se um ponto está dentro da área de defesa.
 * 
 * @param defesa Ponteiro para a defesa que será verificada.
 * @param x Coordenada x do ponto.
 * @param y Coordenada y do ponto.
 * @return int 1 se o ponto está dentro da área de defesa, 0 caso contrário.
 */
int VerificaSeDentroArea(tDefesa defesa, float x, float y){


    



}

/**
 * @brief Usa a defesa, diminuindo seu poder de defesa.
 * 
 * @param defesa Ponteiro para a defesa que será usada.
 */
void UsaDefesa(tDefesa defesa);

/**
 * @brief Obtém o poder de defesa da defesa.
 * 
 * @param defesa Ponteiro para a defesa que terá o poder de defesa obtido.
 * @return float Poder de defesa da defesa.
 */
float GetDefesaPoder(tDefesa defesa);

/**
 * @brief Verifica se a defesa pode defender.
 * 
 * @param defesa Ponteiro para a defesa que será verificada.
 * @return int 1 se a defesa pode defender, 0 caso contrário.
 */
int PodeDefender(tDefesa defesa);
