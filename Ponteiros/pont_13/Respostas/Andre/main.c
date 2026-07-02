#include <stdio.h>
#include <string.h>
#include "rolagem.h"

void leMensagens(char msg[NUM_MAX_MSGS][TAM_MAX_MSG], int *nMsg)
{


    scanf("%d",nMsg);

    for (int i = 0; i < *nMsg; i++)
    {   
        scanf(" %[^\n]", msg[i]);
    }
}
int main()
{   
    int nExecucoes; 
    scanf("%d", &nExecucoes);
    RolaMsg(leMensagens, 30, nExecucoes);

        return 0;
}