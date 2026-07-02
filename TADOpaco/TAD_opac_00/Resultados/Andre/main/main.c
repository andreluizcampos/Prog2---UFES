#include"ponto.h"
#include"circulo.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){


    float c1,c2,r,p1,p2;

    tCirculo circ;
    tPonto p;
    scanf("%f %f %f %f %f",&c1,&c2,&r,&p1,&p2);

    circ = Circulo_Cria(c1,c2,r);
    p = Pto_Cria(p1,p2);

    printf("%d",Circulo_Interior(circ,p));

    Pto_Apaga(p);
    Circulo_Apaga(circ);




}