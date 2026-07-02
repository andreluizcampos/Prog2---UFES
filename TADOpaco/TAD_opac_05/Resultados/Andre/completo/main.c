#include<stdio.h>
#include<stdlib.h>
#include"banco.h"
#include"usuario.h"
#include"conta.h"
#include<string.h>

int main (){


    char option;

    tBanco *b = CriaBanco();

    while(1){

        scanf("%c\n", &option);

        switch(option){

            case 'A':
            AbreContaBanco(b);
            break;

            case 'D':
            DepositoContaBanco(b);
            break;

            case 'T':
            TransferenciaContaBanco(b);
            break;
            
            case 'S':
            SaqueContaBanco(b);
            break;  

            case 'R':
            ImprimeRelatorioBanco(b);
            break;

            case 'F':

            DestroiBanco(b);
            return  0;
            break;
            
            default:
            break;

        }
    }

    DestroiBanco(b);

        return 0;

}
