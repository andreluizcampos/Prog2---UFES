#!/bin/bash
# "Shebang": indica que este script deve ser executado com o interpretador Bash

# Cria o diretório 'bin' para armazenar o programa compilado
# A flag -p ("parents") evita erro se o diretório já existir
mkdir -p bin

# Compila todos os arquivos .c do diretório atual em um único executável
# Explicação das flags:
# -std=c99       -> Usa o padrão C99 da linguagem C
# -pedantic      -> Força o compilador a seguir estritamente o padrão.
# -Wall          -> Ativa todos os warnings recomendados
# -Werror        -> Trata warnings como erros (obriga a corrigir)
# -Werror=vla    -> Trata o uso de VLA (arrays de tamanho variável) como erro
# -g             -> Gera informações de debug (útil para gdb/valgrind)
# -lm            -> Linka a biblioteca matemática (-lm é necessário para
#                   funções como sqrt, pow etc.)
gcc *.c -o bin/prog -lm

# Cria a pasta onde os arquivos de saída do programa serão salvos
mkdir -p output_prog

# Imprime uma linha em branco só para dar espaço visual no início
echo ""

# Itera sobre todos os arquivos da pasta input/ em ordem natural
# (sort -V ordena corretamente test_1, test_2, ..., test_10)
for f in $(ls input/* | sort -V); do
    # Extrai só o nome do arquivo (remove o caminho), ex: arquivo003.txt
    base=$(basename "$f")

    # Extrai o(s) número(s) do nome do arquivo, ex: 003
    # grep -o -> extrai apenas os trechos que batem com a expressão
    # [0-9]\+ -> um ou mais dígitos (expressão regular para números)
    num=$(echo "$base" | grep -o '[0-9]\+')

    # Formata o número com zeros à esquerda, para manter sempre 3 dígitos
    # (ex: 3 → 003)
    num_padded=$(printf "%03d" "$num")

    # Imprime a identificação do teste sem quebrar linha (-n evita o \n)
    echo -n ">> Teste $num_padded: "

    # Executa o programa usando o conteúdo do arquivo como entrada,
    # e salva a saída gerada em output_prog/test_X
    ./bin/prog < "$f" > "output_prog/$base"

    # Compara a saída gerada com a saída esperada
    # diff -q ("quiet") -> só informa se os arquivos são diferentes (para de
    # comparar na primeira diferença)
    # > /dev/null       -> redireciona a saída do diff para o "vazio", para
    # não poluir a tela
    if diff -q "output_prog/$base" "output/$base" > /dev/null; then
        # Se forem idênticos, imprima...
        echo "✅"
    else
        # Se forem diferentes, imprima...
        echo "❌"

        # Linha em branco
        echo ""

        # Mostra as diferenças linha a linha
        # As linhas com < vêm do arquivo esperado, as com > vêm do gerado
        diff "output/$base" "output_prog/$base"

        # Outra linha em branco
        echo ""

        # Interrompe o loop para facilitar a correção (para no primeiro erro)
        break
    fi

    echo ""
done