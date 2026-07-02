#include <stdio.h>
#include "agencia.h"
#include "vector.h"
#include <stdlib.h>
#include <string.h>
#include "banco.h"

int main()
{

    tBanco *b = CriaBanco();

    char option;

    while (1)
    {

        scanf("%c\n", &option);
        if (option == 'F')
        {

            ImprimeRelatorioBanco(b);
            DestroiBanco(b);
            return 0;
            break;
        }

        else if (option == 'A')
        {

            tAgencia *a;
            LeAgencia(a);
            VectorPushBack(b, a);

            scanf("%c\n", &option);
            if (option == 'F')
            {
                ImprimeRelatorioBanco(b);
                DestroiBanco(b);
                return 0;
                break;
            }

            while (option == 'C')
            {

                tConta *c = CriaConta();
                LeConta(c);
                AdicionaConta(a, c);
                scanf("%c\n", &option);
            }
        }
    }
}