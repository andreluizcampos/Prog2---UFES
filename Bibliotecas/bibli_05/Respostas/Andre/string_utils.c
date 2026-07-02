#include<stdio.h>
#include"string_utils.h"

int string_length(char *str){

    int i=0, size=0;

    while(1){

        size++;
        if(str[i]=='\0'){

            break;
        }
        i++;
    }
    return size -1;
}

void string_copy(char *src, char *dest){

    int size=string_length(src);
    int i=0;

        while(1){

            dest[i]=src[i];

                if( src[i]=='\0'){

                break;
            }

            i++;

        }
}
void string_upper(char *str){

    int size=string_length(str);


    int i=0;

        while(1){

            if( str[i] >= 'a'  && str[i] <='z'){

                str[i]= str[i] - 32;
            }   

            if( str[i]=='\0'){

                break;
            }
            i++;
        }
}
void string_lower(char *str){


    
    int i=0;

        while(1){

            if( str[i] >= 'A'  && str[i] <='Z'){

                str[i]= str[i] + 32;
            }   

            if( str[i]=='\0'){

                break;
            }
            i++;
        }

}

void string_reverse(char *str){

    int i=string_length(str);
    int j=0;

    char str1[1000];

    string_copy(str,str1);

        for( j = 0; j < i; j++ ){

            str[j] = str1[i - j - 1];
        }
    }