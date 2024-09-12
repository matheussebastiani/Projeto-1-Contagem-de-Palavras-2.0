# Projeto #1: Contagem de Palavras 2.0
Repositório do primeiro projeto da disciplina de Laboratório de Programação 3

# Missão:

## Requisitos:

* Criar uma nova versão do arquivo `palavras.cpp` desenvolvido em aula.
* **Não se restringir apenas em arquivos ASCII e aceitar também arquivos unicode.**
* Aceitar o nome do arquivo a ser lido na linha de comando (argc/argv).

### Formas de ordenação das palavras e seus parâmetros:

1. `-ac`: Ordem alfabética ascendente da palavra (default)
2. `-ad`: Ordem alfabética descendente da palavra
3. `-nc`: Ordem ascendente do número de ocorrrências
4. `-nd`: Ordem descendente do número de ocorrrências

### Formatos de saída:

* `CSV` e `HTML`.
* Ao final da execução, apresentar na saída padrão a quantidade de caracteres e de palavras extraídas do arquivo e a quantidade de palavras distintas que foram encontradas.

### TO DO LIST

1. Implementar no algoritmo `palavras.cpp`, desenvolvido em aula, a possibilidade de receber por parâmetro o arquivo a ser lido para que seja feita a contagem de palavras;
2. Modularizar e organizar o código já feito;
3. Encontrar outras formas de organizar o `map` para assim ser possível aceitarmos outros parâmetros no algoritmo;
4. Adicionar a função de exportar a saída do algoritmo para um arquivo `.html`.
