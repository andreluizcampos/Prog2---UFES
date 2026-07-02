#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "gerenciadorpacotes.h"
#include "pacote.h"

int main()
{

    int op = 0, type, size;

    tGerenciador *g = CriaGerenciador();

    int qtd = 0;

    printf("\n");
    while (1)
    {

        printf("Escolha uma opcao:\n");
        printf("\t(1) Cadastrar um novo pacote\n");
        printf("\t(2) Imprimir um pacote especifico\n");
        printf("\t(3) Imprimir todos os pacotes e sair\n");

        scanf("%d", &op);
        getchar();

        switch (op)
        {

        case 1:
            printf("Digite o tipo (0-char, 1-int) e o numero de elementos do pacote/mensagem: \n");
            scanf("%d %d", &type, &size);
            tPacote *p = CriaPacote(type, size);
            if (p != NULL)
            {
                LePacote(p);
                AdicionaPacoteNoGerenciador(g, p);
            }
            else
            {
                printf("Tipo invalido!\n");
            }

            break;



        case 2:
            int pos = 0;
            scanf("%d", &pos);
            if (pos >= 0 && pos <qtd )
            {
                ImprimirPacoteNoIndice(g, pos);
            }
            else
            {
                printf("Indice invalido!\n");
            }
            break;
        case 3:

            ImprimirTodosPacotes(g);
            DestroiGerenciador(g);
            return 0;

        default:

            printf("Escolha uma opcao valida para o menu!\n");
        }
    }

    return 0;
}
