#include <stdio.h>
#include <math.h>

int Colisao(float x1, float y1, float r1, float x2, float y2, float r2)
{

    float d = pow(x1 - x2, 2) + pow(y1 - y2, 2);
    float r = pow(r1 + r2, 2);

    if (d <= r)
    {

        return 1;
    }

    return 0;
}

int main()
{

    float x1, y1, r1, x2, y2, r2;

    scanf("%f %f %f %f %f %f", &x1, &y1, &r1, &x2, &y2, &r2);

    if (Colisao(x1, y1, r1, x2, y2, r2))
    {

        printf("ACERTOU");
        return 0;
    }

    printf("ERROU");
    return 0;
}
