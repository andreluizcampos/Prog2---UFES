
#include"utils.h"
#include<stdio.h>
#include <stdlib.h>


/**
 * Cria um vetor de inteiros de tamanho especificado, alocado dinamicamente.
 * Se houver erro na alocação, imprime uma mensagem de erro e encerra o programa.
 * 
 * @param tamanho Tamanho do vetor a ser criado.
 * @return Ponteiro para o vetor criado.
 */
int *CriaVetor(int tamanho){

    int *vetor = calloc(tamanho,sizeof(int));

            return vetor;
}

/**
 * Lê um vetor de inteiros de tamanho especificado.
 * 
 * @param vetor Ponteiro para o vetor a ser lido.
 * @param tamanho Tamanho do vetor a ser lido.
*/
void LeVetor(int *vetor, int tamanho){

    int i = 0;
    while(tamanho){

        scanf("%d",&vetor[i]);
        i++;
        tamanho--;
    }

}

/**
 * Calcula a média dos valores de um vetor de inteiros de tamanho especificado.
 * 
 * @param vetor Ponteiro para o vetor a ser lido.
 * @param tamanho Tamanho do vetor a ser lido.
 * @return Média dos valores do vetor.
*/
float CalculaMedia(int *vetor, int tamanho){

    float sum  = 0;

    for( int i = 0;i<tamanho;i++){

        sum+=vetor[i];
    }

    return sum/(float)tamanho;


}

/**
 * Libera a memória alocada para um vetor de inteiros.
 * 
 * @param vetor Ponteiro para o vetor a ser liberado.
*/
void LiberaVetor(int *vetor){

    free(vetor);
    vetor = NULL;
}