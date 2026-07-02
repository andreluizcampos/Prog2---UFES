#include "nba.h"
#include "franquia.h"
#include <stdio.h>
#include <stdlib.h>
#include<string.h>

struct franquia
{

    char *nome;
    char *conf;
    int v_c;
    int v_f;
    int d_c;
    int d_f;
};

/**
 * @brief Lê uma franquia da entrada padrao e retorna um ponteiro para ela.
 *
 * @return tFranquia Retorna um ponteiro para a franquia lida.
 */
tFranquia LeFranquia()
{

    tFranquia f = (tFranquia)malloc(sizeof(struct franquia));
	f->nome = malloc((MAX_NOME + 1) * sizeof(*f->nome));
	f->conf = malloc((MAX_NOME + 1) * sizeof(*f->conf));
    
    f->d_c = 0;
    f->d_f = 0;
    f->v_c = 0;
    f->v_f = 0;


	scanf(" %s", f->nome);
	scanf(" %s", f->conf);
	getchar();
    
    return f;
}

/**
 * @brief Libera a memória alocada para uma franquia.
 *
 * @param f Ponteiro para a franquia a ser liberada.
 */
void LiberaFranquia(tFranquia f)
{

    free(f->conf);
    free(f->nome);

    free(f);
}

/**
 * @brief Imprime as informações de uma franquia.
 *
 * @param f Ponteiro para a franquia a ser impressa.
 */
void ImprimeFranquia(tFranquia f)
{

    int choice = 0;

    choice = (strcmp(f->conf,"LESTE") == 0);


    int partidas = f->d_c + f->d_f  +f->v_c + f->v_f;
    int total_v =  f->v_c + f->v_f;
    int total_d = f->d_f + f->d_c;
    if(partidas == 0){

        partidas = 1;
    }

    float app =  (float) total_v/(float)partidas;
    app  = app *100.0;

    if(choice){ 
    printf("%s [CL] %d %d %.2f %d %d\n", f->nome, total_v, total_d, app,f->v_c, f->v_f);
}
else{

      printf("%s [CO] %d %d %.2f %d %d\n", f->nome, total_v, total_d, app,f->v_c, f->v_f);
}

}

/**
 * @brief Retorna o nome da franquia.
 *
 * @param f Ponteiro para a franquia.
 * @return char* Retorna o nome da franquia.
 */
char *GetNomeFranquia(tFranquia f){


    return f->nome;
}

/**
 * @brief Retorna a conferência da franquia.
 *
 * @param f Ponteiro para a franquia.
 * @return char* Retorna a conferência da franquia.
 */
char *GetConferenciaFranquia(tFranquia f){

    return f->conf;
}

/**
 * @brief Adiciona uma vitória em casa para a franquia.
 *
 * @param f Ponteiro para a franquia.
 */
void AdicionaVitoriaCasaFranquia(tFranquia f){

    f->v_c++;
}

/**
 * @brief Adiciona uma vitória fora de casa para a franquia.
 *
 * @param f Ponteiro para a franquia.
 */
void AdicionaVitoriaForaFranquia(tFranquia f){

    f->v_f++;
}

/**
 * @brief Adiciona uma derrota em casa para a franquia.
 *
 * @param f Ponteiro para a franquia.
 */
void AdicionaDerrotaCasaFranquia(tFranquia f){

        f->d_c++;
}

/**
 * @brief Adiciona uma derrota fora de casa para a franquia.
 *
 * @param f Ponteiro para a franquia.
 */
void AdicionaDerrotaForaFranquia(tFranquia f){

        f->d_f++;
}

/**
 * @brief Retorna o número de vitórias em casa da franquia.
 *
 * @param f Ponteiro para a franquia.
 * @return int Retorna o número de vitórias em casa da franquia.
 */
int GetVitoriaCasaFranquia(tFranquia f){

    return f->v_c;
}

/**
 * @brief Retorna o número de vitórias fora de casa da franquia.
 *
 * @param f Ponteiro para a franquia.
 * @return int Retorna o número de vitórias fora de casa da franquia.
 */
int GetVitoriaForaFranquia(tFranquia f){

     return f->v_f;
}

/**
 * @brief Retorna o número de derrotas em casa da franquia.
 *
 * @param f Ponteiro para a franquia.
 * @return int Retorna o número de derrotas em casa da franquia.
 */
int GetDerrotaCasaFranquia(tFranquia f){


    return f->d_c;
}

/**
 * @brief Retorna o número de derrotas fora de casa da franquia.
 *
 * @param f Ponteiro para a franquia.
 * @return int Retorna o número de derrotas fora de casa da franquia.
 */
int GetDerrotaForaFranquia(tFranquia f){

    return f->d_f;
}
