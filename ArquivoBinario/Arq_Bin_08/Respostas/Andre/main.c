#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include"contato.h"
#include"vector.h"
#include"lista_contato.h"

int main ()
{

    char NOME[100];
    int n = 0;
    scanf("%[^\n]", NOME);
    int op = 0;

    FILE *f = fopen(NOME, "wb");


    while (1)
    {

        scanf("%d ", &op);

        if (op == 0)
        {

            break;
        }

        switch(option){

            case 1 :

            tContato *c = LeContato();
            

            
        }
    }

    
}