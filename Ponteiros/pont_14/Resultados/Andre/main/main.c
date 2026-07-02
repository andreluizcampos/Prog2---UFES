#include<stdio.h>
#include<stdlib.h>
#include"tela.h"
#include"botao.h"

void imprimeS(){


    printf("- Botao de SALVAR dados ativado!");
}

void imprimeE(){

    
    printf("- Botao de EXCLUIR dados ativado!");
}

void imprimeO(){


    printf("- Botao de OPCOES ativado!\n");

}






int main (){

Botao b1,b2,b3;
Tela Tela;

    b1 = CriarBotao("Salvar",12,"FFF",1,imprimeS);
    b2 = CriarBotao("Excluir",18,"000",1,imprimeE);
    b3 = CriarBotao("Opcoes",10,"FF0000",2,imprimeO);


    Tela = CriarTela(400,200);
     RegistraBotaoTela(&Tela, b1);
     RegistraBotaoTela(&Tela,b2);
     RegistraBotaoTela(&Tela,b3);

     DesenhaTela(Tela);
     OuvidorEventosTela(Tela);


}