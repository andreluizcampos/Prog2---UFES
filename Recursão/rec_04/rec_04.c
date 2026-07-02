#include<stdio.h>
#include<string.h>
#define max 1000

int Palindromo(char S[], int i, int A){


    if(S[A]!= S[i-1]){

        return 0;
    }

    if(i>0){

        return Palindromo(S,i-1,A+1);
    }
    return 1;

}

int main (){

    char S[max];
    int i=0;

     while(scanf("%s",S)==1){
     i=strlen(S);
    
     if(Palindromo(S,i,0)){

        printf("SIM\n");
     }
     else{

        printf("NAO\n");
     }

} 
}