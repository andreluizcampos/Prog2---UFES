#include <stdio.h>
#define max 1000
int Soma(int V[], int i, int s)
{

    int j = i - 1;

    if (i == 0)
    {

        return s;
    }

    if (V[j] % 2 == 0)
    {
        if (V[j] >= 2)
        {

            return Soma(V, i - 1, s + V[j]);
        }
        else
        {

            return Soma(V, i - 1, s);
        }
    }

    else
    {

        return Soma(V, i - 1, s);
    }
}

int main()
{

    int N = 0, S = 0, soma = 0;
    int V[max];

    scanf("%d", &N);

    for (int i = 0; i < N; i++)
    {
        soma = 0;

        scanf("%d", &S);
        for (int j = 0; j < S; j++)
        {

            scanf("%d", &V[j]);
        }

        printf("%d\n", Soma(V, S, soma));
    }
}