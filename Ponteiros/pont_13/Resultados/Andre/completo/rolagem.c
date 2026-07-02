#include "rolagem.h"
#include <stdio.h>
#include <string.h>

void RolaMsg(FptrMsg FuncMsg, int tamanhoDisplay, int tempoFim)
{

    int *nMsgs = 0, size = 0;
    int k = 0;
    char Msg[NUM_MAX_MSGS][TAM_MAX_MSG];
    FuncMsg(Msg, &nMsgs);
    char concatenada[NUM_MAX_MSGS * TAM_MAX_MSG]="";

    for (int i = 0; i < nMsgs; i++)
    {
        strcat(concatenada, Msg[i]);
    }

    size = strlen(concatenada); // Efeito scroll 100x, limite de 30 caracteres;



    for (int j = 0; j < tempoFim; j++)
    {
    

        for (int i = 0; i < tamanhoDisplay; i++)
        {
            
            printf("%c", concatenada[(k + i) % size]);
        
        }
        k++;
          printf("\n");
         printf("\033[H\033[J"); 
      
    }
     
}