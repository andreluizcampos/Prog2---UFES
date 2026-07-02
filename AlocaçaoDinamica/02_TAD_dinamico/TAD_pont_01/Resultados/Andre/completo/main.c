#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "jogo.h"

int main(void) {
    bool executar = true;
    while (executar) {
        tJogo *jogo = CriaJogo();

        ComecaJogo(jogo);

        DestroiJogo(jogo);

        executar = ContinuaJogo();
    }

    return EXIT_SUCCESS;
}