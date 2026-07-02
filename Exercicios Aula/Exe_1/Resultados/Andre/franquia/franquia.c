
#include "franquia.h"
#include <stdio.h>
#include <stdlib.h>

/*
Função que cria os dados de uma franquia e retorna o tFranquia.
@param char *nomeFranquia: String com o nome da franquia criada
@param char *nomeConferencia: String com o nome da conferência criada

@return tFranquia: Retorna uma variável do tipo tFranquia criada
*/
tFranquia lerFranquia(char *nomeFranquia, char *nomeConferencia)
{

    tFranquia franquia;

    franquia.derrotaCasa = franquia.derrotaFora = franquia.nPartidasJogadas = franquia.vitoriaCasa = franquia.vitoriaFora = 0;

    strcpy(franquia.nome, nomeFranquia);
    strcpy(franquia.conferencia, nomeConferencia);

    return franquia;
}

/*
Função que imprime todos os dados de uma franquia (diferente dos casos de teste).

@param tFranquia f: Tipo tFranquia a ser impresso
*/
void imprimeFranquia(tFranquia f)
{

    char conf[5];
    double aproveitamento = 0;

    if (strcmp(f.conferencia, "OESTE") == 0)
    {

        strcpy(conf, "[CO]");
    }

    else
    {

        strcpy(conf, "[CL]");
    }

    if (f.nPartidasJogadas > 0)
    {

        float vitorias = 0, partidas = f.nPartidasJogadas;
        vitorias = f.vitoriaCasa + f.vitoriaFora;
        aproveitamento = vitorias / partidas;
        aproveitamento = aproveitamento * 100;
    }

    printf("%s %s %d %d %.2f %d %d\n", f.nome, conf, f.vitoriaCasa + f.vitoriaFora, f.derrotaCasa + f.derrotaFora, aproveitamento, f.vitoriaFora, f.vitoriaCasa);
}

/*
Função que atualiza os dados de franquia a partir de dados de uma partida jogada.
Deve-se obter os dados da partida, percorrer todos os times das franquias passadas e verificar
quais jogadores ganharam, perderam, quais foram suas pontuações e se a vitória foi em casa ou
fora dela. Por fim, os times relacionados na partida devem ter seus dados atualizados

@param tFranquia *franquias: Vetor de tFranquias
@param int qtdFranquias: Inteiro com o tamanho de franquias cadastradas
@param tPartida p: Nova partida a ser utilizada para atualizar dados de times das franquias
*/
void insereDadosPartida(tFranquia *franquias, int qtdFranquias, tPartida p)
{

    for (int i = 0; i < qtdFranquias; i++)
    {

        if (strcmp(p.nomeTimeCasa, franquias[i].nome) == 0)
        {

            if (p.pontosTimeCasa > p.pontosTimeFora)
            {

                franquias[i].vitoriaCasa++;
                franquias[i].nPartidasJogadas++;
            }
            else if (p.pontosTimeCasa < p.pontosTimeFora)
            {

                franquias[i].derrotaCasa++;
                franquias[i].nPartidasJogadas++;
            }
        }

        if (strcmp(p.nomeTimeFora, franquias[i].nome) == 0)
        {

            if (p.pontosTimeCasa < p.pontosTimeFora)
            {

                franquias[i].vitoriaFora++;
                franquias[i].nPartidasJogadas++;
            }
            else if (p.pontosTimeCasa > p.pontosTimeFora)
            {

                franquias[i].derrotaFora++;
                franquias[i].nPartidasJogadas++;
            }
        }
    }
}

/*
Função que imprime os dados de das franquias de acordo com os casos de teste de saída.

@param tFranquia *franquias: Vetor do tipo tFranquia a ser impresso
@param int qtdFranquias: Inteiro com o tamanho do vetor de franquias
*/
void ImprimeDadosFranquia(tFranquia *franquias, int qtdFranquias)
{

    for (int i = 0; i < qtdFranquias; i++)
    {

        imprimeFranquia(franquias[i]);
    }
}

/*
Função que imprime os dados de uma conferência de acordo com os casos de teste de saída.
Deve-se calcular os valores de vitórias e derrotas dentro e fora de casa para cada franquia
de cada conferência (LESTE e OESTE), imprimindo as estatísticas ao final da chamada da função.

@param tFranquia *franquias: Vetor do tipo tFranquia a ser impresso
@param int qtdFranquias: Inteiro com o tamanho do vetor de franquias
*/
void ImprimeDadosConferencia(tFranquia *franquias, int qtdFranquias)
{

    int v_leste = 0, d_leste = 0, d_oeste = 0, v_oeste = 0;
    float a_leste = 0, a_oeste = 0;

    for (int i = 0; i < qtdFranquias; i++)
    {

        if (strcmp(franquias[i].conferencia, "OESTE") == 0)
        {
            v_oeste += franquias[i].vitoriaCasa + franquias[i].vitoriaFora;
            d_oeste += franquias[i].derrotaFora + franquias[i].derrotaCasa;
        }

        else
        {

            v_leste += franquias[i].vitoriaCasa + franquias[i].vitoriaFora;
            d_leste += franquias[i].derrotaFora + franquias[i].derrotaCasa;
        }
    }

    if (v_leste + d_leste > 0)
    {

        a_leste = ((float)v_leste / ((float)v_leste + (float)d_leste));
    }

    if (v_oeste + d_oeste > 0)
    {

        a_oeste = ((float)v_oeste / ((float)v_oeste + (float)d_oeste));
    }

    printf("LESTE %d %d %.2f\n", v_leste, d_leste, a_leste * 100.0);
    printf("OESTE %d %d %.2f\n", v_oeste, d_oeste, a_oeste * 100.0);
}
