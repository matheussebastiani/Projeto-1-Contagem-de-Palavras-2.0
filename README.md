# Projeto #1: Contagem de Palavras 2.0
Repositório do primeiro projeto da disciplina de Laboratório de Programação 3

# Missão:

## Requisitos:

* Criar uma nova versão do arquivo `palavras.cpp` desenvolvido em aula.
* **Não se restringir apenas em arquivos ASCII e aceitar também arquivos unicode (pesquisar sobre std::wifstream, std::wstring e wchar_t).**
* Aceitar o nome do arquivo a ser lido na linha de comando (argc/argv).

### Formas de ordenação das palavras e seus parâmetros:

1. `-ac`: Ordem alfabética ascendente da palavra (default)
2. `-ad`: Ordem alfabética descendente da palavra
3. `-nc`: Ordem ascendente do número de ocorrrências
4. `-nd`: Ordem descendente do número de ocorrrências

### Formatos de saída:

* As saídas serão em formado `.csv` ou `.html` e deverão ser passadas via linha de comando;
* `-csv` para que a saída seja um arquivo `.csv` (caso não seja passado nada, essa será a saída padrão);
* `-html` para que a saída seja um arquivo `.html`, exibindo os resultados em uma TABLE;
* Ao final da execução, apresentar na saída padrão a quantidade de caracteres e de palavras extraídas do arquivo e a quantidade de palavras distintas que foram encontradas.

### TO DO LIST

1. Implementar no algoritmo `palavras.cpp`, desenvolvido em aula, a possibilidade de receber por parâmetro o arquivo a ser lido para que seja feita a contagem de palavras;
2. Modularizar e organizar o código já feito;
3. Encontrar outras formas de organizar o `map` para assim ser possível aceitarmos outros parâmetros no algoritmo;
4. Adicionar a função de exportar a saída do algoritmo para um arquivo `.html`;
5. Pesquisar sobre arquivos Unicode;
6. Adaptar o `palavras.cpp` para exportar um arquivo `.html` ao invés de um `.csv` para fins de validação de conceito. 

#### CLASSES

1 Classe de entrada de arquivo;  
1 De tratamento de argumentos;  
2 De output.


ORDENAR ARRAY DE PONTEIROS DO MAP
PERCORRER MAP COM ITERATOR
CADA ITERAÇÃO DA UM PUSH BACK NO VECTOR E DAR UM SORT NO VECTOR

