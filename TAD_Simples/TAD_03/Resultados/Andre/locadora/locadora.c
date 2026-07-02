#include <stdio.h>
#include "locadora.h"
#include "filme.h"
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

/**
 * @brief Cria uma nova locadora.
 * @return Locadora criada.
 */
tLocadora criarLocadora()
{

    tLocadora locadora;

    locadora.numFilmes = 0;
    locadora.lucro = 0;

    return locadora;
}

/**
 * @brief Verifica se um filme está cadastrado na locadora.
 * @param locadora Locadora a ser consultada.
 * @param codigo Código do filme a ser verificado.
 * @return 1 se o filme está cadastrado, 0 caso contrário.
 */
int verificarFilmeCadastrado(tLocadora locadora, int codigo)
{

    for (int i = 0; i < locadora.numFilmes; i++)
    {

        if (ehMesmoCodigoFilme(locadora.filme[i], codigo))
        {

            return 1;
        }
    }
    return 0;
}

/**
 * @brief Cadastra um filme na locadora, desde que ele não esteja cadastrado.
 * @param locadora Locadora a ser atualizada.
 * @param filme Filme a ser cadastrado.
 * @return Locadora atualizada.
 */
tLocadora cadastrarFilmeLocadora(tLocadora locadora, tFilme filme)
{

    int codigo = obterCodigoFilme(filme);

    if (verificarFilmeCadastrado(locadora, codigo))
    {

        printf("Filme ja cadastrado no estoque\n");
    }

    else
    {

        locadora.filme[locadora.numFilmes++] = filme;
        printf("Filme cadastrado %d - ", codigo);
        imprimirNomeFilme(filme);
        printf("\n");
    }

    return locadora;
}

/**
 * @brief Lê o cadastro de um ou mais filmes a partir da entrada padrão e o cadastra na locadora.
 * @param locadora Locadora a ser atualizada.
 * @return Locadora atualizada.
 */
tLocadora lerCadastroLocadora(tLocadora locadora)
{

    char control = '#';

    int code = 0;

    while (scanf(" %d,", &code) == 1)
    {

        tFilme filme = leFilme(code);
        locadora = cadastrarFilmeLocadora(locadora, filme);
    }

    if (scanf(" %c ", &control) != 1 || control != '#')
    {

        exit(EXIT_FAILURE);
    }

    return locadora;
}

/**
 * @brief Aluga um conjunto de filmes da locadora.
 * @param locadora Locadora a ser atualizada.
 * @param codigos Array com os códigos dos filmes a serem alugados.
 * @param quantidadeCodigos Quantidade de códigos no array.
 * @return Locadora atualizada.
 */
tLocadora alugarFilmesLocadora(tLocadora locadora, int *codigos, int quantidadeCodigos)
{

    int custo = 0, qtd_alugados = 0, cadastrado = 0;

    for (int i = 0; i < quantidadeCodigos; i++)
    {
        cadastrado = 0;

        for (int j = 0; j < locadora.numFilmes; j++)
        {

            if (ehMesmoCodigoFilme(locadora.filme[j], codigos[i]))
            {

                if (obterQtdEstoqueFilme(locadora.filme[j]) > 0)
                {

                    locadora.filme[j] = alugarFilme(locadora.filme[j]);
                    custo += locadora.filme[j].valor;
                    qtd_alugados++;
                    cadastrado = 1;
                }

                else
                {

                    printf("Filme %d - ", obterCodigoFilme(locadora.filme[j]));
                    imprimirNomeFilme(locadora.filme[j]);
                    printf(" nao disponivel no estoque. Volte mais tarde.\n");
                    cadastrado = 1;
                }

                cadastrado = 1;
            }
        }

        if (!cadastrado)
        {

            printf("Filme %d nao cadastrado.\n", codigos[i]);
        }
    }

    if (qtd_alugados > 0)
    {

        printf("Total de filmes alugados: %d com custo de R$%d\n", qtd_alugados, custo);
    }

    return locadora;
}

/**
 * @brief Lê o aluguel de um conjunto de filmes a partir da entrada padrão e os aluga na locadora.
 * @param locadora Locadora a ser atualizada.
 * @return Locadora atualizada.
 */
tLocadora lerAluguelLocadora(tLocadora locadora)
{

    int Codes[MAX_FILMES], qtd_filmes = 0;
    int code = 0;
    char c = '#';

    while (scanf(" %d ", &code) == 1)
    {
        Codes[qtd_filmes] = code;
        qtd_filmes++;
    }

    if (scanf(" %c ", &c) != 1 || c != '#')
    {

        exit(EXIT_SUCCESS);
    }

    return alugarFilmesLocadora(locadora, Codes, qtd_filmes);
}

/**
 * @brief Devolve um conjunto de filmes alugados da locadora.
 * @param locadora Locadora a ser atualizada.
 * @param codigos Array com os códigos dos filmes a serem devolvidos.
 * @param quantidadeCodigos Quantidade de códigos no array.
 * @return Locadora atualizada.
 */
tLocadora devolverFilmesLocadora(tLocadora locadora, int *codigos, int quantidadeCodigos)
{

    int cadastrado = 0;

    for (int i = 0; i < quantidadeCodigos; i++)
    {
        cadastrado = 0;

        for (int j = 0; j < locadora.numFilmes; j++)
        {

            if (ehMesmoCodigoFilme(locadora.filme[j], codigos[i]))
            {

                if (locadora.filme[j].qtdAlugada > 0)
                {
                    locadora.filme[j] = devolverFilme(locadora.filme[j]);
                    printf("Filme %d - ", obterCodigoFilme(locadora.filme[j]));
                    imprimirNomeFilme(locadora.filme[j]);
                    printf(" Devolvido!\n");
                    locadora.lucro += locadora.filme[j].valor;
                }
                else
                {

                    printf("Nao e possivel devolver o filme %d - ", obterCodigoFilme(locadora.filme[j]));
                    imprimirNomeFilme(locadora.filme[j]);
                    printf(".\n");
                }
                cadastrado  = 1;
            }
        }

        if(!cadastrado){

            printf("Filme %d nao cadastrado.\n", codigos[i]);
        }
    }
    return locadora;
}

/**
 * @brief Lê a devolução de um conjunto de filmes a partir da entrada padrão e os devolve na locadora.
 * @param locadora Locadora a ser atualizada.
 * @return Locadora atualizada.
 */
tLocadora lerDevolucaoLocadora(tLocadora locadora)
{

    char c = '#';
    int Codes[MAX_FILMES], qtd_devo = 0, code = 0;

    while (scanf(" %d", &code) == 1)
    {
        Codes[qtd_devo] = code;
        qtd_devo++;

        continue;
    }

    if (scanf(" %c ", &c) != 1 || c != '#')
    {

        exit(EXIT_FAILURE);
    }

    return devolverFilmesLocadora(locadora, Codes, qtd_devo);
}

/**
 * @brief Ordena os filmes da locadora por nome.
 * @param locadora Locadora a ser ordenada.
 * @return Locadora ordenada.
 */
tLocadora ordenarFilmesLocadora(tLocadora locadora)
{

    int flag = 1;

    while (flag)
    {

        flag = 0;
        for (int i = 0; i < locadora.numFilmes - 1; i++)
        {

            if (strcmp(locadora.filme[i].nome, locadora.filme[i + 1].nome) > 0)
            {

                tFilme temp = locadora.filme[i];
                locadora.filme[i] = locadora.filme[i + 1];
                locadora.filme[i + 1] = temp;
                flag = 1;
            }
        }
    }

    return locadora;
}

/**
 * @brief Imprime o estoque da locadora.
 * @param locadora Locadora a ser consultada.
 */
void consultarEstoqueLocadora(tLocadora locadora)
{

    printf("~ESTOQUE~\n");
    for (int i = 0; i < locadora.numFilmes; i++)
    {

        printf("%d - ", obterCodigoFilme(locadora.filme[i]));
        imprimirNomeFilme(locadora.filme[i]);
        printf(" Fitas em estoque: %d\n", obterQtdEstoqueFilme(locadora.filme[i]));
    }
}

/**
 * @brief Imprime o lucro da locadora.
 * @param locadora Locadora a ser consultada.
 */
void consultarLucroLocadora(tLocadora locadora)
{

    if (locadora.lucro > 0)
    {

        printf("\nLucro total R$%d\n", locadora.lucro);
    }
}