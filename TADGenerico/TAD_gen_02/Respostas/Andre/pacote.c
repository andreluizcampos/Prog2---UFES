#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "pacote.h"

struct pacote
{

    void *dados;
    int soma;
    int size;
    Type t;
};

tPacote *CriaPacote(Type type, int numElem)
{

    tPacote *p = (tPacote *)malloc(sizeof(tPacote));

    p->soma = 0;
    p->t = type;
    p->size = numElem;
    p->dados = NULL;

    if (p->t == INT)
    {

        p->dados = (int *)malloc(sizeof(int) * numElem);
    }
    else if(p->t == CHAR)
    {

        p->dados = (char *)malloc(sizeof(char) * numElem);
    }
    else{

        p->dados = NULL;
    }


    if(type!=CHAR && type!=INT){

        DestroiPacote(p);
        return NULL;
    }

    return p;
}

/**
 * @brief Destroi o vetor genérico (libera a memória alocada dinamicamente)
 *
 * @param pac - O vetor genérico que terá seu conteúdo liberado/destruído
 */
void DestroiPacote(tPacote *pac)
{   

    if(pac != NULL){ 

    free(pac->dados);
    free(pac);


}

}
/**
 * @brief Lê o conteúdo do vetor genérico e salva no local adequado
 *
 * @param pac - O vetor genérico que terá seu conteúdo preenchido/lido
 */
void LePacote(tPacote *pac)
{

    if(pac!=NULL){
    switch (pac->t)
    {

    case INT:

        for (int i = 0; i < pac->size; i++)
        {
            scanf("%d", &(((int *)(pac->dados))[i]));
        }

        break;

    case CHAR:

        for (int i = 0; i < pac->size; i++)
        {
            scanf("%c", &(((char *)(pac->dados))[i]));
        }

        break;
    }
}
}

/**
 * @brief Busca uma conta na agencia que possui um id específico
 *
 * @param pac - O vetor genérico que terá seu conteúdo impresso em tela
 */
void ImprimePacote(tPacote *pac)
{

    CalculaSomaVerificacaoPacote(pac);

    printf("%d ", pac->soma);

    switch (pac->t)
    {

    case INT:

        for (int i = 0; i < pac->size; i++)
        {
            printf(" %d", (((int *)(pac->dados))[i]));
        }
        printf("\n");

        break;

    case CHAR:
        for (int i = 0; i < pac->size; i++)
        {
            printf(" %c", (((char *)(pac->dados))[i]));
        }
        printf("\n");

        break;
    }
}

/**
 * @brief Calcula a soma de verificacao de um pacote e a armazena internamente
 *
 * @param pac - O vetor genérico que terá sua soma de verificacao calculada
 */
void CalculaSomaVerificacaoPacote(tPacote *pac)
{
    switch (pac->t)
    {
    case INT:
        for (int i = 0; i < pac->size; i++)
            pac->soma += ((int *)pac->dados)[i];
        break;
    case CHAR:
        for (int i = 0; i < pac->size; i++)
            pac->soma += ((char *)pac->dados)[i];
        break;
    }
}