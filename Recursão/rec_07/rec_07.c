#include<stdio.h>
#include<string.h>
#define max 1000

int Soma( char V[], int S, int N){

    int i=N-1;

    if(N == 0){

        return S;

    }

    return Soma(V,S + (V[i] - '0'), N-1);

}

int main(){

    char V[max];
    int N=0;
    scanf("%s",V);
    N=strlen(V);

    printf("%d\n",Soma(V,0,N));

}