#include<stdio.h>
#include<stdlib.h>
#include"empresa.h"
#include"funcionario.h"


int main (){


    int qtd = 0;

    scanf("%d\n",&qtd);

    tEmpresa **empresa = (tEmpresa**)malloc(sizeof(tEmpresa*)*qtd);


    for( int i = 0;i<qtd;i++){

        empresa[i] = CriaEmpresa();
        LeEmpresa(empresa[i]);

    }

    for( int i = 0;i<qtd;i++){

        ImprimeEmpresa(empresa[i]);
    }

    for( int i = 0;i<qtd;i++){

        ApagaEmpresa(empresa[i]);
    }

        free(empresa);

}