#include<stdio.h>

void Print( int N){

    int i=0, j=0, k=1;

        for(i=1;i<=N;i++){

            for(j=0;j<i;j++){

                printf("%d ",k);
                k++;
            }

            printf("\n");

        }
}

int main(){

    int N=0;
        scanf("%d",&N);

        Print(N);
}