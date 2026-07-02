#include "calculadora.h"
#include <stdio.h>



float Calcular(float num1, float num2, CalculatoraCallback operacao){


    return operacao(num1,num2);
}