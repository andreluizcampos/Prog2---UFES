#include <stdio.h>
#include <stdlib.h>
#include "empresa.h"
#include "funcionario.h"

struct empresa
{

    int qtd;
    tFuncionario **f;
    int id;
    int reg;
};

/**
 * @brief Cria uma empresa "vazia"
 *
 * Seus atributos devem ser inicializados com NULL (ponteiros), ou -1 caso contrário
 * @return TEmpresa* Ponteiro para empresa criada a partir do Id fornecido.
 */
tEmpresa *CriaEmpresa()
{

    tEmpresa *e = (tEmpresa *)malloc(sizeof(tEmpresa));

    int id, qtd;
    e->reg =0;

    scanf("%d %d\n", &id, &qtd);

    e->f = (tFuncionario **) malloc(sizeof(tFuncionario *)*qtd);

 

    e->id = id;
    e->qtd = qtd;

    return e;
}

/**
 * @brief Le os dados de uma empresa da entrada padrao.
 * @param *empresa - ponteiro para empresa que terá seus dados preenchidos
 */
void LeEmpresa(tEmpresa *empresa)
{

    tFuncionario **funcionarios;

    funcionarios = (tFuncionario **)malloc(sizeof(tFuncionario *) * empresa->qtd);

    for (int i = 0; i < empresa->qtd; i++)
    {
        funcionarios[i] = CriaFuncionario();
        LeFuncionario(funcionarios[i]);
        ContrataFuncionarioEmpresa(empresa, funcionarios[i]);
    }

    free(funcionarios);
}

/**
 * @brief Libera toda a memória alocada dinamicamente para uma empresa
 * @param *empresa - ponteiro para empresa que terá seus dados apagados e memória liberada
 */
void ApagaEmpresa(tEmpresa *empresa)
{

    for (int i = 0; i < empresa->reg; i++)
    {

        ApagaFuncionario(empresa->f[i]);
    }

    free(empresa->f);
    free(empresa);
}

/**
 * @brief Adiciona um funcionario a uma empresa caso o id do funcionario ainda nao esteja registrado na empresa.
 *
 * @param empresa Ponteiro para Empresa em que o funcionario deve ser adicionado.
 * @param funcionario Ponteiro para Funcionario que deve ser adicionado a empresa.
 */
void ContrataFuncionarioEmpresa(tEmpresa *empresa, tFuncionario *funcionario)
{

    int id1 = GetIdFuncionario(funcionario), flag  = 1;

    for (int i = 0; i < empresa->reg; i++)
    {

        int id2 = GetIdFuncionario(empresa->f[i]);

        if(id2 == id1){

            printf("A empresa %d ja possui um funcionario com o id %d\n", empresa->id, id1);
            flag = 0;
            ApagaFuncionario(funcionario);
        }
    }

    if(flag){

        empresa->f[empresa->reg++] = funcionario;

    }
}

/**
 * @brief Imprime todos os dados de um empresa.
 *
 * @param empresa Ponteiro para Empresa a ser impressa no terminal.
 */
void ImprimeEmpresa(tEmpresa *empresa)
{
    printf("Empresa %d:\n", empresa->id);

    for (int i = 0; i < empresa->reg; i++)
    {

        ImprimeFuncionario(empresa->f[i]);
    }
}