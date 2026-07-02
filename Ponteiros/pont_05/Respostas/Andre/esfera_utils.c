#include<stdio.h>
#include"esfera_utils.h"

#define PI 3.14

/**
 * @brief Calcula o volume de uma esfera com raio R.
 * @param R O raio da esfera.
 * @param volume Um ponteiro para uma variável float para armazenar o volume calculado.
 */
void CalculaVolume (float R, float *volume){


    
    *volume = 4*(PI*R*R*R)/(float)3;
}

/**
 * @brief Calcula a área de uma esfera com raio R.
 * @param R O raio da esfera.
 * @param area Um ponteiro para uma variável float para armazenar a área calculada.
 */
void CalculaArea (float R, float *area){

    *area = 4*(R *PI * R);
}
