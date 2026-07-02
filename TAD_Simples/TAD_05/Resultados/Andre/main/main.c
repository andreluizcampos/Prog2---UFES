#include <stdio.h>
#include "conta.h"
#include "usuario.h"

int main()
{

    int OP_code = -1, users_amount = 0, conta = 0;
    float valor = 0;
    char Name[50], CPF[15];
    tUsuario user_u;

    scanf("%d", &users_amount);

    tConta contas[users_amount];

    printf("===| Imprimindo Relatorio |===\n");

    int i = 0, user = 0;

    while (1)
    {

        if (OP_code == 0)
        {

            break;
        }

        scanf(" %d", &OP_code);

        switch (OP_code)
        {

        case 0:

            break;

        case 1:

            scanf(" %d %f", &user, &valor);
            contas[user - 1] = SaqueConta(contas[user - 1], valor);
            break;

        case 2:
            scanf(" %d %f", &user, &valor);
            contas[user - 1] = DepositoConta(contas[user - 1], valor);
            break;

        case 3:
            char c;
            scanf("%c %[^ ] %[^ ] %d", &c, Name, CPF, &conta);
            user_u = CriaUsuario(Name, CPF);
            contas[conta - 1] = CriaConta(conta, user_u);
            i++;

            break;

        case 4:

            for (int j = 0; j < i; j++)
            {

                ImprimeConta(contas[j]);
            }

            break;

        default:

            printf("Error");
        }
    }

    return 0;
}