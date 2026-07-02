#include<stdio.h>
#include<stdlib.h>
#include"utils.h"

int main (){


int col, lin, **matriz;

    scanf("%d %d",&lin,&col);

    matriz = CriaMatriz(lin, col);
     LeMatriz(matriz, lin, col);
     ImprimeMatrizTransposta(matriz, lin, col);
     LiberaMatriz(matriz, lin);

}