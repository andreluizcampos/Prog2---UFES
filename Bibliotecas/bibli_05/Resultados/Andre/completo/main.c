#include <stdio.h>
#include "string_utils.h"
#define max 1000

int main(void)

{
    char str[max];
  scanf("%[^\n]", str);

  int option = 0;

    

    while (1)
    {
        printf(
            "1 - Tamanho da string\n"
            "2 - Copiar string\n"
            "3 - Converter string para letras maiusculas\n"
            "4 - Converter string para letras minusculas\n"
            "5 - Imprimir string ao contrario\n"
            "6 - Encerrar o programa\n"
            "Opcao escolhida:\n");

        scanf(" %d", &option);

        if (option == 6)
        {

            break;
        }

        switch (option)
        {

        case 1:

            printf("Tamanho da string: %d\n", string_length(str));
            break;

        case 2:{

            char copy[string_length(str)];

            string_copy(str, copy);
            printf("String copiada: %s\n", copy);

            break; }

        case 3:

            string_upper(str);

            printf("String convertida para maiusculas: %s\n", str);

            break;

        case 4:

            string_lower(str);
            printf("String convertida para minusculas: %s\n", str);

            break;

        case 5:
            string_reverse(str);
            printf("String invertida: %s\n", str);

            break;

        case 6:
            break;
        }
    }
}
