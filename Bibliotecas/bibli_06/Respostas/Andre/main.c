// #include<stdio.h>
// #include"temperature_conversor.h"

// int main()
// {

//     float temperature = 0, temp1=0;

//     char u1 = 'k', u2 = 'b';

//     scanf("%f %c %c", &temperature, &u1, &u2);

//     if (u1 == 'c')
//     {

//         if (u2 == 'k')
//         {

//             temp1=convert_temperature(temperature,convert_celsius_to_kelvin);
//             printf("Temperature: %.2fK", temp1);
//         }
//            if (u2 == 'f')
//         {
//                 temp1=convert_temperature(temperature,convert_celsius_to_fahrenheit);
//             printf("Temperature: %.2fFº", temp1);
//         }
//     }

//     if (u1 == 'k')
//     {

//         if (u2 == 'c')
//         {
//                 temp1=convert_temperature(temperature,convert_kelvin_to_celsius);
//             printf("Temperature: %.2fCº", temp1);   
//         }

//         if (u2 == 'f')
//         {
//             temp1=convert_temperature(temperature,convert_kelvin_to_fahrenheit);
//             printf("Temperature: %.2fFº",temp1);
//         }
//     }


//        if (u1 == 'f'){

//         if(u2 == 'c'){
//             temp1=convert_temperature(temperature,convert_fahrenheit_to_celsius);
//             printf("Temperature: %.2fCº", temp1);
//         }

//         if(u2 == 'k'){
//                         temp1=convert_temperature(temperature,convert_fahrenheit_to_kelvin);
//               printf("Temperature: %.2fK", temp1);  
//         }
//        }
// }

#include <stdio.h>
#include <stdlib.h>
#include "temperature_conversor.h"

int main(void) {
    float temp;
    char curr_unit, goal_unit;
    scanf("%f %c %c", &temp, &curr_unit, &goal_unit);

    float temp_c;
    switch (curr_unit) {
        case 'c': {
            temp_c = temp;
            break;
        }
        case 'k': {
            temp_c = convert_temperature(temp, convert_kelvin_to_celsius);
            break;
        }
        case 'f': {
            temp_c = convert_temperature(temp, convert_fahrenheit_to_celsius);
            break;
        }
        default: {
            break;
        }
    }

    switch (goal_unit) {
        case 'c': {
            printf("Temperature: %.2fCº\n", temp_c);
            break;
        }
        case 'k': {
            printf("Temperature: %.2fK\n",
                   convert_temperature(temp_c, convert_celsius_to_kelvin));
            break;
        }
        case 'f': {
            printf("Temperature: %.2fFº\n",
                   convert_temperature(temp_c, convert_celsius_to_fahrenheit));
            break;
        }
        default: {
            break;
        }
    }

    return EXIT_SUCCESS;
}
