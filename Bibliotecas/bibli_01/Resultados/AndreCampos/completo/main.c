#include<stdio.h>
#include"esfera_utils.h"

int main(){

float f=0;
    scanf("%f",&f);

    float A=0, V=0;
        V=calcula_volume(f);
        A=calcula_area(f);

        printf("Area: %.2f\nVolume: %.2f",A,V);

}
