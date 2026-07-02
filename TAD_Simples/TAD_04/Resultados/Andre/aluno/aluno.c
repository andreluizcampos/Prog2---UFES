
#include"aluno.h"
#include<stdio.h>
#include<string.h>

tAluno CriaAluno(char *nome, int matricula, int n1, int n2, int n3)
{

   
    tAluno aluno;

    strcpy(aluno.nome,nome);
    aluno.matricula = matricula;
    aluno.n1=n1;
    aluno.n2=n2;
    aluno.n3=n3;

        return aluno;
}


tAluno LeAluno()
{

    tAluno aluno;
    char Name[50];
    int matricula,n1,n2,n3;

        scanf("%s",Name);
        scanf("%d %d %d %d",&matricula, &n1, &n2,&n3);

    aluno = CriaAluno(Name,matricula,n1,n2,n3);

        return aluno;
}
/**
 * @brief Compara as matrículas de dois alunos.
 *
 * @param aluno1 Primeiro aluno a ser comparado.
 * @param aluno2 Segundo aluno a ser comparado.
 * @return int Retorna 1 se a matrícula do aluno1 é maior que a do aluno2, -1 se a matrícula do aluno1 é menor que a do aluno2 e 0 se as matrículas são iguais.
 */
int ComparaMatricula(tAluno aluno1, tAluno aluno2){

    if(aluno1.matricula == aluno2.matricula){

        return 0;
    }

    if(aluno1.matricula > aluno2.matricula){

        return 1;
    }

    return -1;
}

/**
 * @brief Calcula a média das notas de um aluno.
 *
 * @param aluno Aluno a ter a média calculada.
 * @return int Retorna a média das notas do aluno.
 */
int CalculaMediaAluno(tAluno aluno){


    return (aluno.n1 + aluno.n2 + aluno.n3)/3; 

}

/**
 * @brief Verifica se um aluno foi aprovado ou reprovado.
 *
 * @param aluno Aluno a ser verificado.
 * @return int Retorna 1 se o aluno foi aprovado e 0 se foi reprovado.
 */
int VerificaAprovacao(tAluno aluno){

    if (CalculaMediaAluno(aluno) >= 7){

        return 1;
    }

    return 0;
}

/**
 * @brief Imprime os dados de um aluno.
 *
 * @param aluno Aluno a ser impresso.
 */
void ImprimeAluno(tAluno aluno){

    if(VerificaAprovacao(aluno)){

        printf("%s\n",aluno.nome);
    }
}
