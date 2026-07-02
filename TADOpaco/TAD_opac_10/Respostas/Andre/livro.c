#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "livro.h"

struct Livros
{

    char *nome;
    char *autor;
    int ano;
};

/**
 * Cria um livro "vazio". Ponteiros devem receber null e os atributos numéricos valor -1;
 *
 * @return Um ponteiro para um livro livro "vazio"
 */
tLivros *CriaLivro()
{

    tLivros *l = (tLivros *)malloc(sizeof(struct Livros));

    l->ano = 0;
    l->autor = malloc(100);
    l->nome = malloc(100);

    return l;
}

/**
 * Lê os atributos de um livro a partir da entrada padrão (teclado).
 *
 * @param livro Um ponteiro para um livro que receberá os atributos lidos
 */
void LerLivro(tLivros *livro)
{

    scanf("%[^\n]\n", livro->nome);

    scanf("%[^\n]\n", livro->autor);

    scanf("%d\n",&livro->ano);
}

/**
 * Imprime os atributos da TAD tLivros (título, autor e ano de publicação).
 *
 * @param livro Um ponteiro para o livro cujos atributos serão impressos
 */
void ImprimeLivro(tLivros *livro){


    printf("Titulo: %s\n",livro->nome);
    printf("Autor: %s\n", livro->autor);
    printf("Ano de Publicacao: %d\n",livro->ano);


}

/**
 * Retorna o título do livro.
 *
 * @param livro Ponteiro para o livro cujo título será retornado.
 * @return O título do livro.
 */
char *getTitulo(tLivros *livro){


    return livro->nome;
}

/**
 * Função para liberar toda a memória alocada por um livro
 *
 * @param livro Um ponteiro para o livro cujos atributos serão apagados/liberados
 */
void ApagaLivro(tLivros *livro){

    free(livro->nome);
    free(livro->autor);
    free(livro);
}
