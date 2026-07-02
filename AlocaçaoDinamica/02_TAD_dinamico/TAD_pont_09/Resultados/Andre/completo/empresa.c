#include "empresa.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Cria uma empresa "vazia"
 *
 * Seus atributos devem ser inicializados com NULL (ponteiros), ou -1 caso contrário
 * @return TEmpresa* Ponteiro para empresa criada a partir do Id fornecido.
 */
tEmpresa *CriaEmpresa()
{

    tEmpresa *e = malloc(sizeof(tEmpresa));

    e->funcionarios = NULL;
    e->id = -1;
    e->qtdFuncionarios = 0;

    return e;
}

/**
 * @brief Le os dados de uma empresa da entrada padrao.
 * @param *empresa - ponteiro para empresa que terá seus dados preenchidos
 */
void LeEmpresa(tEmpresa *empresa)
{

    int qtd = 0;

    scanf("%d %d\n", &empresa->id, &qtd);

    empresa->funcionarios = malloc(sizeof(tFuncionario *) * qtd);

    tFuncionario **funcionarios = malloc(sizeof(tFuncionario *) * qtd);

    for (int i = 0; i < qtd; i++)
    {

        funcionarios[i] = CriaFuncionario();
        LeFuncionario(funcionarios[i]);
    }

    for (int i = 0; i < qtd; i++)
    {
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

    for (int i = 0; i < empresa->qtdFuncionarios; i++)
    {

        ApagaFuncionario(empresa->funcionarios[i]);
    }

    free(empresa->funcionarios);
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

    int id_f = GetIdFuncionario(funcionario), flag = 1;

    for (int i = 0; i < empresa->qtdFuncionarios; i++)
    {

        if (id_f == GetIdFuncionario(empresa->funcionarios[i]))
        {

            flag = 0;
            printf("A empresa %d ja possui um funcionario com o id %d\n", empresa->id, GetIdFuncionario(funcionario));
            ApagaFuncionario(funcionario);
        }
    }

    if (flag)
    {

        empresa->funcionarios[empresa->qtdFuncionarios] = funcionario;
        empresa->qtdFuncionarios++;
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

    for (int i = 0; i < empresa->qtdFuncionarios; i++)
    {

        ImprimeFuncionario(empresa->funcionarios[i]);
    }
}
