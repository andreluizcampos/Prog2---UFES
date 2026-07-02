#include <stdio.h>
#include <string.h>
#include <ctype.h>

int Print(char str[], int i)
{

    if (i == -1)
    {

        return 0;
    }

    printf("%c", str[i]);
    return Print(str, i - 1);
}

int TemLetra(char str[], int i)
{
 int flag=0;

    for (int j = 0; j <= i ; j++)
    {

        if (isalpha(str[j]) || ispunct(str[j]) || isalnum(str[j]) && str[j+1] && j+1 <= i)
        {
            return 1;
        }

       
    }
    return 0;
}

int main()
{

    char str[1000];
    int i = 0;

    while (scanf("%s", str) == 1)
    {
        i = strlen(str) - 1;

        if (TemLetra(str, i))
        {
            Print(str, i);
        }

        else
        {
            printf("%s", str);
        }
        printf(" ");
    }
}