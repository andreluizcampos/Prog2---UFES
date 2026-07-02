#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "livro.h"
#include "biblioteca.h"

struct Biblioteca
{

    tLivros **livros;
    int qtd_livros;
};

/**
 * Inicializa uma biblioteca vazia.
 * Ponteiros são inicializados com NULL;
 * @return A biblioteca inicializada.
 */
tBiblioteca *InicializarBiblioteca()
{

    tBiblioteca *b = (tBiblioteca *)malloc(sizeof(tBiblioteca));

    b->qtd_livros = 0;
    b->livros = (tLivros **)malloc(sizeof(tLivros *));
    return b;
}

/**
 * Apaga toda a memória alocada dinamicamente dentro de uma biblioteca
 * Ponteiros são inicializados com NULL;
 * @return A biblioteca inicializada.
 */
void ApagaBiblioteca(tBiblioteca *biblioteca)
{

    for (int i = 0; i < biblioteca->qtd_livros; i++)
    {

        ApagaLivro(biblioteca->livros[i]);
    }

    free(biblioteca->livros);

    free(biblioteca);
}

/**
 * Adiciona um livro à biblioteca.
 * Se estiver dentro do tamanho máximo de livros, imprime "Livro adicionado com sucesso!"
 * Senão, imprime "A biblioteca está cheia. Não é possível adicionar mais livros."
 *
 * @param biblioteca Ponteiro para a biblioteca onde o livro será adicionado.
 * @param livro Ponteiro para o livro a ser adicionado.
 */
void AdicionarLivroNaBiblioteca(tBiblioteca *biblioteca, tLivros *livro)
{

    printf("Livro adicionado com sucesso!\n");
    biblioteca->livros[biblioteca->qtd_livros] = livro;
    biblioteca->qtd_livros++;
    biblioteca->livros = (tLivros **)realloc(biblioteca->livros, (biblioteca->qtd_livros + 1) * sizeof(tLivros *));
}

/**
 * Remove um livro da biblioteca pelo título.
 * Se o título for encontrado, imprime "Livro removido com sucesso!",
 * Senão, imprime "Livro não encontrado na biblioteca."
 *
 * @param biblioteca Ponteiro para a biblioteca da qual o livro será removido.
 * @param titulo O título do livro a ser removido.
 */
void RemoverLivroDaBiblioteca(tBiblioteca *biblioteca, char *titulo)
{

    int flag = 1;
    for (int i = 0; i < biblioteca->qtd_livros; i++)
    {

        if (strcmp(getTitulo(biblioteca->livros[i]), titulo) == 0)
        {

            ApagaLivro(biblioteca->livros[i]);
            printf("Livro removido com sucesso!\n");

            for (int j = i + 1; j < biblioteca->qtd_livros; j++)
            {

                biblioteca->livros[j - 1] = biblioteca->livros[j]; // LeftShift
            }
            biblioteca->qtd_livros--;

            if (biblioteca->qtd_livros != 0)
            {
                biblioteca->livros = (tLivros **)realloc(biblioteca->livros, (biblioteca->qtd_livros) * sizeof(tLivros *));
            }
            else{

                      biblioteca->livros = (tLivros **)realloc(biblioteca->livros, (1) * sizeof(tLivros *));
            }

            flag = 0;
        }
    }

    if (flag)
    {

        printf("Livro nao encontrado na biblioteca.\n");
    }
}

/**
 * Verifica se o título digitado é igual ao título do livro.
 *
 * @param livro Ponteiro para o livro cujo título será verificado.
 * @param titulo O título digitado pelo usuário.
 * @return se o título for igual, retorna 0.
 */
int VerificaTituloDoLivroNaBiblioteca(tLivros *livro, char *titulo)
{

    return strcmp(getTitulo(livro), titulo);
}

/**
 * Lista todos os livros presentes na biblioteca.
 * Se não houver livros na biblioteca, imprime "A biblioteca esta vazia!"
 *
 * @param biblioteca Ponteiro para a biblioteca cujos livros serão listados.
 */
void ListarLivrosDaBiblioteca(tBiblioteca *biblioteca)
{

    if (biblioteca->qtd_livros == 0)
    {

        printf("A biblioteca esta vazia!\n");
    }

    else
    {
        printf("\nLista de Livros na Biblioteca:\n");

        for (int i = 0; i < biblioteca->qtd_livros; i++)
        {

            ImprimeLivro(biblioteca->livros[i]);
        }
    }
}
