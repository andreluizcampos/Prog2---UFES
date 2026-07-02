#include "biblioteca.h"
#include "livro.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{

    tBiblioteca *biblioteca = InicializarBiblioteca();
    tLivros **livros = malloc(sizeof(tLivros *));

    int k = 1;

    for (int i = 0; i < 10; i++)
    {

        livros[i] = CriaLivro();
    }

    char str[100];

    printf("Lista de operacoes:\n1 - Cadastrar livros.\n2 - Remover livros.\n3 - Listar todos os livros cadastrados.\n");

    int option = 0, action = 0;

    scanf("%d\n", &option);

    for (int i = 0; i < option; i++)
    {

        scanf("%d\n", &action);

        switch (action)
        {

        case 1:

            LerLivro(livros[k - 1]);
            AdicionarLivroNaBiblioteca(biblioteca, livros[k - 1]);
            k++;
            realloc(livros, k * sizeof(tLivros *));
            break;

        case 2:
            scanf(" %[^\n]\n", str);
            RemoverLivroDaBiblioteca(biblioteca, str);
            break;

        case 3:
            ListarLivrosDaBiblioteca(biblioteca);
            break;

        default:
            printf("Operacao invalida!\n");
            ApagaBiblioteca(biblioteca);
            free(livros);

            return 0;
        }
    }
    ApagaBiblioteca(biblioteca);
    free(livros);

    return 0;
}
