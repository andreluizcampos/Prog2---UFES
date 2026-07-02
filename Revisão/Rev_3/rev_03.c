#include <stdio.h>
#define max 4000

typedef struct
{

    int V[max];
    int N;
} Lista;

Lista List(Lista L)
{

    L.N = 0;
    scanf("%d", &L.N);
    for (int i = 0; i < L.N; i++)
    {

        scanf("%d", &L.V[i]);
    }
    return L;
}

void Check(Lista L)
{

    int j = 0, i = 0;
    int flag = 0;
    int M = 0;
    int k = 0, p = 0, l = 0, temp = 0;
    int V[max];

    for (j = k; j < L.N; j++)
    {

        flag = 0;
        M = 0;

        for (i = 0; i < L.N; i++)
        {

            if (i != j)
            {

                if (L.V[i] == L.V[j])
                {

                    flag = 1;
                    M = 1;
                }
            }
        }

        if (!flag)
        {

            V[l] = L.V[j];
            l++;
            p = 1;
        }
        k++;
    }

    if (M == 1 && p == 0)
    {

        printf("NENHUM");
    }

    flag = 1;

    while (flag)
    {

        flag = 0;

        for (i = 0; i < l - 1; i++)
        {

            if (V[i] > V[i + 1])
            {
                temp = V[i];
                V[i] = V[i + 1];
                V[i + 1] = temp;
            }
        }
    }

    if (p)
    {

        for (i = 0; i < l; i++)
        {

            printf("%d ", V[i]);
        }
    }
}

int main()
{

    Lista L;
    L = List(L);
    Check(L);
}