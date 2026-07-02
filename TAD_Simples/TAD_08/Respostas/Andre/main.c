#include"departamento.h"
#include<stdio.h>

int main (){

int quantidade_departamentos = 0;

char dep_name[15];
char dire_name[40];
char c1_name[40];
char c2_name[40];
char c3_name[40];
int m1 = 0, m2 = 0, m3 = 0;




scanf("%d",&quantidade_departamentos);

 tDepartamento departamentos[quantidade_departamentos];

         for( int i = 0;i<quantidade_departamentos;i++){

            scanf(" %[^\n]",dep_name);
            scanf(" %[^\n]",dire_name);
            scanf(" %[^\n]",c1_name);
            scanf(" %[^\n]",c2_name);
            scanf(" %[^\n]",c3_name);
            scanf("%d %d %d",&m1,&m2,&m3);

            departamentos[i] = criaDepartamento(c1_name,c2_name,c3_name,dep_name,m1,m2,m3,dire_name);
         }       

         ordenaPorMediaDepartamentos(departamentos, quantidade_departamentos);
         
         
         for( int i = 0;i<quantidade_departamentos;i++){

            imprimeAtributosDepartamento(departamentos[i]);
         }

}