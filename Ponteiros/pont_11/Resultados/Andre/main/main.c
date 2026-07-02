#include <stdio.h>
#include "calculadora.h"

float adicao(float a, float b)
{

    return a + b;
}
float subtracao(float a, float b)
{

    return a - b;
}
float multiplicacao(float a, float b)
{

    return a * b;
}
float divisao(float a, float b)
{

    return a / b;
}


int main()
{


    
    char op;

    float n1, n2, n3;

    while (scanf(" %c", &op) == 1)

    {
        scanf("\n%f %f", &n1, &n2);

        switch (op)
        {
        case 'a':

            n3 = Calcular(n1, n2, adicao);

            printf("%.2f + %.2f = %.2f\n", n1, n2, n3);

            break;

        case 's':
            n3 = Calcular(n1, n2, subtracao);
            printf("%.2f - %.2f = %.2f\n", n1, n2, n3);

            break;

        case 'm':
            n3 = Calcular(n1, n2, multiplicacao);
            printf("%.2f x %.2f = %.2f\n", n1, n2, n3);
            break;

        case 'd':
            n3 = Calcular(n1, n2, divisao);
            printf("%.2f / %.2f = %.2f\n", n1, n2, n3);
            break;
        }
    }
}