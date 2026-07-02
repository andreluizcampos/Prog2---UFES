#include<stdio.h>
#include<math.h>



int Pot( int N){

    int P=0;

        while(N>0){

            N=N/10;
            P++;
        }

        return P;
}

 int Org ( int N){


    double Order=0;

    int P = Pot(N) -1, K=1, R=0;

    int New=0;

    Order = pow(10,P);

        while(N>0){
            R= N%8 ;
            N=N/8;
            New+=R*K;
            K=K*10;
        }

        return New;
}

int main (){

    int N=0;
    
        scanf("%d",&N);
        N = Org(N);
        printf("%d",N);
}