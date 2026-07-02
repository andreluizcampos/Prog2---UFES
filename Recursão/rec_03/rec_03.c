#include <stdio.h>
#define max 1000

int Rec(int V[], int S, int P, int K)
{

    int j = S - 1;

    if (S == 0)
    {

        return K;
    }

    if (V[j] == P)
    {

        return Rec(V, S - 1, P, K + 1);
    }
    else
    {

        return Rec(V, S - 1, P, K);
    }
}

int main()
{

    int N = 0, S = 0, P = 0, V[max], K=0;

    scanf("%d", &N);

    for (int i = 0; i < N; i++)
    {

        K=0;

        scanf("%d %d", &P, &S);

        for (int j = 0; j < S; j++)
        {

            scanf("%d", &V[j]);
        }
        printf("%d\n",Rec(V, S, P, K));
    }
}