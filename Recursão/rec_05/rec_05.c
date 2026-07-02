#include<stdio.h>


int Fatorial( int n, int f){

    if(n == 0){

        return f;
    }

    return Fatorial( n-1,f*n);
}

int main(){

    int n=0;

    scanf("%d",&n);

    printf("%d\n",Fatorial(n,1));
}