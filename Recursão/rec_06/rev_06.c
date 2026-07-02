#include<stdio.h>

int Fibonacci( int a, int b, int n){

  

    if(n==0){

        return a;
    }


    return Fibonacci(b,a+b,n-1);
             
            
}

int main(){

    int N=0;

    scanf("%d",&N);

    printf("%d\n",Fibonacci(0,1,N));

}