#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "usuario.h"
#include "cpu.h"
#include "instrucao.h"

int main()
{
    Cpu *c = criaCpu();
    int n;
    scanf(" %d", &n);
    getchar();
    Usuario *u = criaUsuario(n);
    FILE *f = fopen("memoria.bin","wb");
    adicionaInstrucao(u, f);
    fclose(f);
   f = fopen("memoria.bin","rb");
    realizaInstrucao(c, f, n);
    imprimeRegistradores(c);
    liberaCpu(c);
    liberaUsuario(u);
    fclose(f);
}