#include<stdio.h>
#include<string.h>
#include"utils_char2.h"


int main (){


    char *vetor;

    
    int *tam = TAM_PADRAO;               // Neste exercício foi necessário atentar-se a: Range do vetor e passagem na main;
                                                // Problemas: Inserção do \0 e passagem de tam como ponteiro

        vetor = CriaVetorTamPadrao();
        vetor = LeVetor(vetor,tam );
        ImprimeString(vetor);
        LiberaVetor(vetor);
        LiberaVetor(tam);

        return 0;
}