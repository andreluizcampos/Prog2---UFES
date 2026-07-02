#ifndef _AMBIENTE_H_
#define _AMBIENTE_H_

typedef struct ambiente tAmbiente;

/*
Considerem que o mapa do ambiente é uma matriz 10x10 de caracteres, conforme
definido abaixo:


*/

/// @brief Função que cria um ambiente ("mapa") de um jogo qualquer
/// @return Um ponteiro para uma variável que representa um ambiente
tAmbiente *criaAmbiente();


/// @brief Libera a memória alocada para esse ambiente
/// @param amb 
void liberaAmbiente(tAmbiente *amb);


/// @brief Funcao que consulta o que tem em determinada posicao do mapa 
/// @param linha da matriz que voce quer consultar 
/// @param coluna da matriz que voce quer consultar 
/// @return Retorna o "estado" da posição (linha,coluna) do mapa, conforme especificação:
///         '-' ou '|', representando paredes
///         0 (ou '\0'), representando um local sem obstáculos/estrada
///         um caractere diferente dos listados acima, representando um inimigo.
char retornaSituacaoPosicao(tAmbiente *amb, int linha, int coluna);


/// @brief Funcao que copia a posicao atual para os endereços passados como parametros
/// @param amb - variável que controle o ambiente 
/// @param *linha - Ponteiro para uma variável que irá receber a linha que o jogador está posicionado 
/// @param *coluna - Ponteiro para uma variável que irá receber a coluna que o jogador está posicionado
void retornaPosicaoAtual(tAmbiente *amb, int *linha, int *coluna);

/// @brief Funcao que altera o conteúdo do mapa.
/// @param amb - variável que controle o ambiente 
/// @param linha da matriz que representa o mapa
/// @param coluna da matriz que representa o mapa
/// @param novoConteudo - conteúdo que substituirá o conteúdo atual daquela posicao
void alteraConteudo(tAmbiente *amb, int linha, int coluna, char novoConteudo);

/// @brief Funcao que altera a posicao do jogador no mapa. O jogador passará a estar na posição (linha,coluna)
/// após essa funcao ser chamada.
/// @param amb - variável que controle o ambiente
/// @param linha - Nova posição do jogador no mapa
/// @param coluna  - Nova posição do jogador no mapa
void alteraPosicaoJogador(tAmbiente *amb, int linha, int coluna);

#endif