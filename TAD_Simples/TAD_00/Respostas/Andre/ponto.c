#include"ponto.h"
#include<stdio.h>
#include<math.h>


Ponto pto_cria(float x, float y)
{

    Ponto p;

    p = pto_atribui_x(p, x);
    p = pto_atribui_y(p, y);

    return p;
}

float pto_acessa_x(Ponto p)
{

    return p.x;
}

float pto_acessa_y(Ponto p)
{

    return p.y;
}

Ponto pto_atribui_x(Ponto p, float x)
{

    p.x = x;

    return p;
}

Ponto pto_atribui_y(Ponto p, float y)
{

    p.y = y;

    return p;
}

float pto_distancia(Ponto p1, Ponto p2)
{

    float dx = 0, dy = 0;

    dx = pto_acessa_x(p1) - pto_acessa_x(p2);
    dy = pto_acessa_y(p1) - pto_acessa_y(p2);

    return sqrt(dx * dx + dy * dy);
}
