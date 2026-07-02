#include <stdio.h>
#include <stdlib.h>
#include "livro.h"
#include "biblioteca.h"

/**
 * Cria um livro "vazio". Ponteiros devem receber null e os atributos numéricos valor -1;
 *
 * @return Um ponteiro para um livro livro "vazio"
 */
tLivros *CriaLivro()
{

    tLivros *l = malloc(sizeof(tLivros));

    l->anoPublicacao = -1;
    l->autor = NULL;
    l->titulo = NULL;

    return l;
}

/**
 * Lê os atributos de um livro a partir da entrada padrão (teclado).
 *
 * @param livro Um ponteiro para um livro que receberá os atributos lidos
 */
void LerLivro(tLivros *livro)
{

    livro->autor = malloc(100);
    livro->titulo = malloc(100);

    scanf("%[^\n]\n", livro->titulo);
    scanf("%[^\n]\n", livro->autor);
    scanf("%d\n", &livro->anoPublicacao);
}

/**
 * Imprime os atributos da TAD tLivros (título, autor e ano de publicação).
 *
 * @param livro Um ponteiro para o livro cujos atributos serão impressos
 */
void ImprimeLivro(tLivros *livro){


    printf("Titulo: %s\n Autor: %s\n Ano de Publicacao: %d\n",livro->titulo, livro->autor, livro->anoPublicacao);
  

}

/**
 * Função para liberar toda a memória alocada por um livro
 *
 * @param livro Um ponteiro para o livro cujos atributos serão apagados/liberados
 */
void ApagaLivro(tLivros *livro){


    free(livro->autor);
    free(livro->titulo);
    free(livro);
}