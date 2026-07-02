#include "data.h"
#include "lesao.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "paciente.h"
#include <stdbool.h>

int main()
{

    Paciente pacientes[10];
    Lesao lesao;
    int i = 0, qtd_lesoes = 0, qtd_cirurgias = 0, media = 0;
    char nome[100], cartaoSus[100], genero, option;
    Data data, dataBase;

    dataBase = criaData(12, 9, 2023);

    while (1)
    {

        scanf("%c\n", &option);

        if (option == 'F')
        {

            break;
        }

        switch (option)
        {

        case 'P':
            pacientes[i++] = lerPaciente();
            break;

        case 'L':
            lesao = lerLesao();

            for (int j = 0; j < i; j++)
            {
                getCartaoSusLesao(lesao, cartaoSus);

                if (!strcmp(cartaoSus, pacientes[j].cartaoSus))
                {
                    qtd_lesoes++;

                    pacientes[j] = vinculaLesaoPaciente(pacientes[j], lesao);
                    break;
                }
            }

            break;

        case 'F':
            break;
        }
    }

    for (int j = 0; j < i; j++)
    {

        media += calculaIdadePaciente(pacientes[j], dataBase);
        for (int k = 0; k < pacientes[j].numLesoes; k++)
        {

            if (verificaCirurgicaLesao(pacientes[j].lesoes[k]))
            {

                qtd_cirurgias++;
            }
        }
    }

    printf("TOTAL PACIENTES: %d\n", i);

    if (media > 0)
    {
        printf("MEDIA IDADE (ANOS): %d\n", media / i);
    }

    else
    {
        printf("MEDIA IDADE (ANOS): -\n");
    }
    printf("TOTAL LESOES: %d\n", qtd_lesoes);
    printf("TOTAL CIRURGIAS: %d\n", qtd_cirurgias);
    printf("LISTA DE PACIENTES:\n");

    for (int k = 0; k < i; k++)
    {

        imprimePaciente(pacientes[k]);
    }
}