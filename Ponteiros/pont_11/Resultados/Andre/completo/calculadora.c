#include "calculadora.h"
#include <stdio.h>

float A(float, float);
float S(float, float);
float M(float, float);
float D(float, float);

float A(float a, float b)
{

    return a + b;
}
float S(float a, float b)
{

    return a - b;
}
float M(float a, float b)
{

    return a * b;
}
float D(float a, float b)
{

    return a / b;
}


float Calcular(float num1, float num2, CalculatoraCallback operacao){


    return operacao(num1,num2);
}