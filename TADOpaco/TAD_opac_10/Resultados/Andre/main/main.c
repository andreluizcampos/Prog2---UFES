#include<stdio.h>
#include<stdlib.h>
#include"biblioteca.h"
#include"livro.h"


int main (){


    int n =0, option = 0, qtd = 1;
    
    tBiblioteca *Biblioteca = InicializarBiblioteca();
    tLivros **Livros = (tLivros**)malloc(sizeof(tLivros*));

    char str[100];

    printf("Lista de operacoes:\n");
    printf("1 - Cadastrar livros.\n");
    printf("2 - Remover livros.\n");
    printf("3 - Listar todos os livros cadastrados.\n");

    scanf("%d\n",&n);

    for( int i = 0;i<n;i++){


        scanf("%d\n",&option);

        switch(option){

            case 1:
            Livros[qtd-1] = CriaLivro();
            LerLivro(Livros[qtd-1]);
            AdicionarLivroNaBiblioteca(Biblioteca,Livros[qtd-1]);
            qtd++;
            Livros = (tLivros**)realloc(Livros, qtd * sizeof(tLivros*));
            break;

            case 2:
            scanf("%[^\n]\n",str);
            RemoverLivroDaBiblioteca(Biblioteca,str);
            break;

            case 3:
            ListarLivrosDaBiblioteca(Biblioteca);
            break;

            default:

            printf("Operacao invalida!\n");
              free(Livros);
    ApagaBiblioteca(Biblioteca);
    return 0;
            break;
        }
    
    }

        free(Livros);
    ApagaBiblioteca(Biblioteca);

}
