#include"temperature_conversor.h"
#include<stdio.h>

float convert_celsius_to_kelvin(float temperature){


            return temperature + 273.15;
}

float convert_celsius_to_fahrenheit(float temperature){

               return ((temperature*9)/5) + 32;
}
float convert_kelvin_to_celsius(float temperature){

   return temperature  - 273.15;
}

float convert_kelvin_to_fahrenheit(float temperature){

    float k=0;

    k=convert_kelvin_to_celsius(temperature);

    return convert_celsius_to_fahrenheit(k);
}

float convert_fahrenheit_to_celsius(float temperature){

    return ((temperature - 32) * 5)/9;
}

float convert_fahrenheit_to_kelvin(float temperature){

    float f=0;
    f=convert_fahrenheit_to_celsius(temperature);
     
    return convert_celsius_to_kelvin(f);
}

float convert_temperature(float temperature, float convert_func(float temperature)){

        return convert_func(temperature);
}
