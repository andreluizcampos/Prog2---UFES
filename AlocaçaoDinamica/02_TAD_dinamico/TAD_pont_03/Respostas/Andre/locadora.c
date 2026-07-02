#include "filme.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "locadora.h"
/**
 * @brief Cria uma nova instância de tLocadora e inicializa filme como NULL, numFilmes como 0 e lucro como 0.
 *
 * @return tLocadora* Ponteiro para a nova instância de tLocadora criada ou encerra o programa caso não haja memória suficiente.
 */
tLocadora *CriarLocadora()
{

    tLocadora *locadora = malloc(sizeof(tLocadora));

    locadora->numFilmes = 0;
    locadora->lucro = 0;

    return locadora;
}

/**
 * @brief Destrói uma instância de tLocadora.
 *
 * @param locadora Ponteiro para a instância de tLocadora a ser destruída.
 */
void DestruirLocadora(tLocadora *locadora)
{

    free(locadora);
}

/**
 * @brief Verifica se um filme está cadastrado na locadora.
 *
 * @param locadora Ponteiro para a instância de tLocadora a ser verificada.
 * @param codigo Código do filme a ser verificado.
 * @return int 1 se o filme está cadastrado, 0 caso contrário.
 */
int VerificarFilmeCadastrado(tLocadora *locadora, int codigo)
{

    for (int i = 0; i < locadora->numFilmes; i++)
    {

        int filme_code = 0;

        filme_code = ObterCodigoFilme(locadora->filme[i]);

        if (filme_code == codigo)
        {

            return 1;
        }
    }

    return 0;
}

/**
 * @brief Cadastra um novo filme na locadora caso ele não esteja cadastrado.
 *
 * @param locadora Ponteiro para a instância de tLocadora a ser atualizada.
 * @param filme Ponteiro para o filme a ser cadastrado.
 */
void CadastrarFilmeLocadora(tLocadora *locadora, tFilme *filme)
{

    for (int i = 0; i < locadora->numFilmes; i++)
    {

        int get_code_movie = ObterCodigoFilme(filme);

        if (!VerificarFilmeCadastrado(locadora, filme))
        {
            locadora->filme[i] = filme;
        }
    }
}

/**
 * @brief Lê os dados de cadastro de um filme e o cadastra na locadora.
 *
 * @param Locadora Ponteiro para a instância de tLocadora a ser atualizada.
 */
void LerCadastroLocadora(tLocadora *Locadora)
{

    tFilme *filme;
    int code;
    scanf("%d,", &code);
    LeFilme(filme, code);
    CadastrarFilmeLocadora(Locadora, filme);
}

/**
 * @brief Aluga um ou mais filmes da locadora.
 *
 * @param locadora Ponteiro para a instância de tLocadora a ser atualizada.
 * @param codigos Vetor contendo os códigos dos filmes a serem alugados.
 * @param quantidadeCodigos Número de códigos de filmes a serem alugados.
 */
void AlugarFilmesLocadora(tLocadora *locadora, int *codigos, int quantidadeCodigos)
{

    int amount = 0, spent = 0, flag = 0, quantidade = 0;

    for (int i = 0; i < quantidadeCodigos; i++)
    {

        flag = 0;

        for (int j = 0; j < locadora->numFilmes; j++)
        {

            amount = ObterQtdAlugadaFilme(locadora->filme[j]);
            if (!VerificarFilmeCadastrado(locadora, codigos[i]))
            {

                flag = 1;

                if (amount > 0)
                {

                    AlugarFilme(locadora->filme[j]);
                    spent += ObterValorFilme(locadora->filme[j]);
                    quantidade++;
                }
            }
        }

        if (!flag)
        {

            printf("Filme %d - Nao cadastrado\n");
        }
    }

    printf("Total de filmes alugados: %d com custo de R$%d\n", quantidade, spent);
}

/**
 * @brief Lê o aluguel de um conjunto de filmes a partir da entrada padrão e os aluga na locadora.
 *
 * @param locadora Ponteiro para a instância de tLocadora a ser atualizada.
 */
void LerAluguelLocadora(tLocadora *locadora)
{

    int qtd_filmes = 0;
    int alugados[MAX_CARACTERES];

    while (scanf("%d\n", &alugados[qtd_filmes++]) == 1)
    {

        continue;
    }

    AlugarFilmesLocadora(locadora, alugados, qtd_filmes);
}

/**
 * @brief Devolve um ou mais filmes alugados da locadora.
 *
 * @param locadora Ponteiro para a instância de tLocadora a ser atualizada.
 * @param codigos Vetor contendo os códigos dos filmes a serem devolvidos.
 * @param quantidadeCodigos Número de códigos de filmes a serem devolvidos.
 */
void DevolverFilmesLocadora(tLocadora *locadora, int *codigos, int quantidadeCodigos)
{

    int flag = 0, amount = 0;

    for (int i = 0; i < quantidadeCodigos; i++)
    {

        flag = 0;

        for (int j = 0; j < locadora->numFilmes; j++)
        {

            amount = ObterQtdAlugadaFilme(locadora->filme[j]);

            if (amount > 0)
            {

                if (VerificarFilmeCadastrado(locadora, i)){

                    printf("Filme %d - %s devolvido!", ImprimirNomeFilme(Filme))
                }
            }
        }
    }
}

/**
 * @brief Lê os dados de devolução de um ou mais filmes e os devolve na locadora.
 *
 * @param locadora Ponteiro para a instância de tLocadora a ser atualizada.
 */
void LerDevolucaoLocadora(tLocadora *locadora);

/**
 * @brief Ordena os filmes cadastrados na locadora por ordem alfabética.
 *
 * @param locadora Ponteiro para a instância de tLocadora a ser atualizada.
 */
void OrdenarFilmesLocadora(tLocadora *locadora);

/**
 * @brief Consulta o estoque de filmes da locadora.
 *
 * @param locadora Ponteiro para a instância de tLocadora a ser consultada.
 */
void ConsultarEstoqueLocadora(tLocadora *locadora);

/**
 * @brief Consulta o lucro da locadora.
 *
 * @param locadora Ponteiro para a instância de tLocadora a ser consultada.
 */
void ConsultarLucroLocadora(tLocadora *locadora);
