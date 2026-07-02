#include<stdio.h>
#include"locadora.h"
#include"filme.h"
#include<string.h>

int main (){

char Operacao1[20] = {"Cadastrar"};
char Operacao2[20]= {"Alugar"};
char Operacao3[20] = {"Devolver"};
char Operacao4[20]={"Estoque"};

char select_operation[20];

int code = 0;
tLocadora Locadora = criarLocadora();

    while(scanf("%s",select_operation) == 1){

        if(strcmp(select_operation,Operacao1) == 0){

            code = 1;
        }
        else if(strcmp(select_operation,Operacao2) == 0){

            code = 2;
        }

        else if(strcmp(select_operation,Operacao3) == 0){

            code = 3;
        }

        else if(strcmp(select_operation,Operacao4) == 0){

            code = 4;
        }   

            switch(code){

                case 1:

                Locadora = lerCadastroLocadora(Locadora);
                printf("\n");

                code = 0;

                break;

                case 2:

                Locadora = lerAluguelLocadora(Locadora);
                printf("\n");
                code = 0;
                    break;

                case 3:

                Locadora = lerDevolucaoLocadora(Locadora);
                printf("\n");
                code = 0;

                break;

                case 4:
                Locadora = ordenarFilmesLocadora(Locadora);
                consultarEstoqueLocadora(Locadora);
              
                code = 0;

                break;
            }
}
            if(Locadora.lucro > 0){
                char c;
                scanf("%c",&c);
                consultarLucroLocadora(Locadora);
            }

    return 0;
}
