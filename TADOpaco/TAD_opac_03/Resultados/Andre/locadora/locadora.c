#include "locadora.h"
#include "filme.h"
#include <stdio.h>
#include <stdlib.h>

struct Locadora
{

    tFilme **filmes;
    int lucro;
    int num_filmes;
};

/**
 * @brief Cria uma nova instância de tLocadora e inicializa filme como NULL, numFilmes como 0 e lucro como 0.
 *
 * @return tLocadora* Ponteiro para a nova instância de tLocadora criada ou encerra o programa caso não haja memória suficiente.
 */
tLocadora *CriarLocadora()
{

    tLocadora *l = (tLocadora *)malloc(sizeof(tLocadora));

    /* CORRIGIDO: cast era tFilme* em vez de tFilme** */
    l->filmes = (tFilme **)malloc(sizeof(tFilme *));

    l->lucro = 0;
    l->num_filmes = 0;

    return l;
}

/**
 * @brief Destrói uma instância de tLocadora.
 *
 * @param locadora Ponteiro para a instância de tLocadora a ser destruída.
 */
void DestruirLocadora(tLocadora *locadora)
{

    for (int i = 0; i < locadora->num_filmes; i++)
    {

        free(locadora->filmes[i]);
    }
    free(locadora->filmes);
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

    for (int i = 0; i < locadora->num_filmes; i++)
    {

        if (codigo == ObterCodigoFilme(locadora->filmes[i]))
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

    int code = ObterCodigoFilme(filme);
    int flag = VerificarFilmeCadastrado(locadora, code);

    if (!flag)
    {
        /* CORRIGIDO: retorno do realloc salvo; tamanho correto em bytes;
           índice era [num_filmes - 1] antes do incremento, pulava posição 0 */
        locadora->filmes = (tFilme **)realloc(locadora->filmes, (locadora->num_filmes + 1) * sizeof(tFilme *));
        locadora->filmes[locadora->num_filmes] = filme;
        locadora->num_filmes++;
        printf("Filme cadastrado %d - ", code);
        ImprimirNomeFilme(filme);
        printf("\n");
    }
}

/**
 * @brief Lê os dados de cadastro de um filme e o cadastra na locadora.
 *
 * @param Locadora Ponteiro para a instância de tLocadora a ser atualizada.
 */
void LerCadastroLocadora(tLocadora *Locadora)
{
    char c = 'b';

    tFilme *f;
    int temp;

    while (1)
    {
        f = CriarFilme();
        scanf("%d,", &temp);
        LeFilme(f, temp);
        CadastrarFilmeLocadora(Locadora, f);
     
            if(scanf("%c",&c)!=1 || c=='#'){

                break;
            }
    }
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

    int qtd_estoque = 0;
    int qtd_alugado = 0;
    int valor = 0;

    for (int i = 0; i < quantidadeCodigos; i++)
    {

        if (VerificarFilmeCadastrado(locadora, codigos[i]))
        {

            for (int j = 0; j < locadora->num_filmes; j++)
            {
                /* CORRIGIDO: comparação usava o ponteiro como código (int code_f = locadora->filmes[j])
                   agora obtém o código corretamente via função */
                if (EhMesmoCodigoFilme(locadora->filmes[j], codigos[i]))
                {

                    qtd_estoque = ObterQtdEstoqueFilme(locadora->filmes[j]);

                    if (qtd_estoque > 0)
                    {

                        AlugarFilme(locadora->filmes[j]);
                        qtd_alugado++;
                        valor += ObterValorFilme(locadora->filmes[j]);
                    }
                    else
                    {

                        printf("Filme %d -", codigos[i]);
                        ImprimirNomeFilme(locadora->filmes[j]);
                        printf("nao disponivel no estoque. Volte mais tarde.\n");
                    }
                }
            }
        }
        else
        {

            printf("Filme %d nao cadastrado.\n", codigos[i]);
        }
    }

    printf("Total de filmes alugados: %d com custo de R$%d\n", qtd_alugado, valor);
    locadora->lucro += valor;
}

/**
 * @brief Lê o aluguel de um conjunto de filmes a partir da entrada padrão e os aluga na locadora.
 *
 * @param locadora Ponteiro para a instância de tLocadora a ser atualizada.
 */
void LerAluguelLocadora(tLocadora *locadora)
{

    int qtd = 1;
    int *f_alu = (int *)malloc(sizeof(int));

    /* CORRIGIDO: retorno do realloc salvo corretamente */
    while (scanf(" %d", &f_alu[qtd - 1]) == 1)
    {
        qtd++;
        f_alu = (int *)realloc(f_alu, sizeof(int) * (qtd + 1));
    }

    AlugarFilmesLocadora(locadora, f_alu, qtd - 1);
    free(f_alu);
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

    int qtd_alugado = 0;

    for (int i = 0; i < quantidadeCodigos; i++)
    {

        if (VerificarFilmeCadastrado(locadora, codigos[i]))
        {

            for (int j = 0; j < locadora->num_filmes; j++)
            {

                if (EhMesmoCodigoFilme(locadora->filmes[j], codigos[i]))
                {

                    qtd_alugado = ObterQtdAlugadaFilme(locadora->filmes[j]);

                    if (qtd_alugado > 0)
                    {

                        DevolverFilme(locadora->filmes[j]);
                        printf("Filme %d - ", codigos[i]);
                        ImprimirNomeFilme(locadora->filmes[j]);
                        printf(" Devolvido!\n");
                    }
                    else
                    {
                        printf("Nao e possivel devolver o filme %d - ", codigos[i]);
                        ImprimirNomeFilme(locadora->filmes[j]);
                        printf(".\n");
                    }
                }
            }
        }
        else
        {

            printf("Filme %d nao cadastrado.\n", codigos[i]);
        }
    }
}

/**
 * @brief Lê os dados de devolução de um ou mais filmes e os devolve na locadora.
 *
 * @param locadora Ponteiro para a instância de tLocadora a ser atualizada.
 */
void LerDevolucaoLocadora(tLocadora *locadora)
{

    int qtd = 1;
    int *f_alu = (int *)malloc(sizeof(int));

    /* CORRIGIDO: retorno do realloc salvo corretamente */
    while (scanf(" %d", &f_alu[qtd - 1]) == 1)
    {
        qtd++;
        f_alu = (int *)realloc(f_alu, sizeof(int) * (qtd + 1));
    }

    DevolverFilmesLocadora(locadora, f_alu, qtd - 1);
    free(f_alu);
}

/**
 * @brief Ordena os filmes cadastrados na locadora por ordem alfabética.
 *
 * @param locadora Ponteiro para a instância de tLocadora a ser atualizada.
 */
void OrdenarFilmesLocadora(tLocadora *locadora)
{

    int flag = 1;

    while (flag)
    {

        flag = 0;
        for (int i = 0; i < locadora->num_filmes - 1; i++)
        {

            if (CompararNomesFilmes(locadora->filmes[i], locadora->filmes[i + 1]) == 1)
            {

                tFilme *temp;
                temp = locadora->filmes[i];
                locadora->filmes[i] = locadora->filmes[i + 1];
                locadora->filmes[i + 1] = temp;
                flag = 1;
            }
        }
    }
}

/**
 * @brief Consulta o estoque de filmes da locadora.
 *
 * @param locadora Ponteiro para a instância de tLocadora a ser consultada.
 */
void ConsultarEstoqueLocadora(tLocadora *locadora)
{

    printf("~ESTOQUE~\n");

    for (int i = 0; i < locadora->num_filmes; i++)
    {

        printf("%d - ", ObterCodigoFilme(locadora->filmes[i]));
        ImprimirNomeFilme(locadora->filmes[i]);
        printf(" Fitas em estoque: %d\n", ObterQtdEstoqueFilme(locadora->filmes[i]));
    }
}

/**
 * @brief Consulta o lucro da locadora.
 *
 * @param locadora Ponteiro para a instância de tLocadora a ser consultada.
 */
void ConsultarLucroLocadora(tLocadora *locadora)
{
    if (locadora->lucro > 0)
    {
        printf("Lucro total R$%d\n", locadora->lucro);
    }
}