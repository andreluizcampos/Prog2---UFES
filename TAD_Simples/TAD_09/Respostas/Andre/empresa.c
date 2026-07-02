#include "funcionario.h"
#include "empresa.h"
#include <stdio.h>

/**
 * @brief Cria uma empresa a partir de um id.
 *
 * @param id Id do empresa a ser criada.
 * @return TEmpresa empresa criada a partir do Id fornecido.
 */
tEmpresa criaEmpresa(int id)
{

    tEmpresa empresa;

    empresa.id = id;
    empresa.qtdFuncionarios = 0;

    for (int i = 0; i < 20; i++)
    {

        empresa.funcionarios[i].id = -999;
    }

    return empresa;
}

/**
 * @brief Le os dados de uma empresa da entrada padrao.
 *
 * @return TEmpresa empresa criada a partir dos dados lidos.
 */
tEmpresa leEmpresa()
{

    tEmpresa empresa;

    int id = 0, qtdFuncionarios;

    scanf("%d %d", &id, &qtdFuncionarios);

    empresa = criaEmpresa(id);


        for( int i =0;i<qtdFuncionarios;i++){

            tFuncionario funcionario = leFuncionario();
            
            empresa = contrataFuncionarioEmpresa(empresa, funcionario);
        }

    return empresa;
}

/**
 * @brief Adiciona um funcionario a uma empresa caso o id do funcionario ainda nao esteja registrado na empresa.
 *
 * @param empresa Empresa em que o funcionario deve ser adicionado.
 * @param funcionario Funcionario que deve ser adicionado a empresa.
 * @return TEmpresa empresa atualizada com a nova lista de funcionarios.
 */
tEmpresa contrataFuncionarioEmpresa(tEmpresa empresa, tFuncionario funcionario)
{

    int flag = 0;

    for (int i = 0; i < empresa.qtdFuncionarios; i++)
    {
        if (funcionario.id == empresa.funcionarios[i].id)
        {

            printf("A empresa %d ja possui um funcionario com o id %d\n", empresa.id, funcionario.id);

                return empresa;
        }
    }

        empresa.funcionarios[empresa.qtdFuncionarios++] = funcionario;

            return empresa;


}

/**
 * @brief Imprime todos os dados de um empresa.
 *
 * @param empresa Empresa a ser impressa no terminal.
 */
void imprimeEmpresa(tEmpresa empresa)
{

    printf("Empresa %d:\n", empresa.id);

    for (int i = 0; i < empresa.qtdFuncionarios; i++)
    {

        imprimeFuncionario(empresa.funcionarios[i]);
    }
}