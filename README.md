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

- [X] 1. ~~Implementar no algoritmo `palavras.cpp`, desenvolvido em aula, a possibilidade de receber por parâmetro o arquivo a ser lido para que seja feita a contagem de palavras;~~
- [ ] 2. Modularizar e organizar o código já feito;
- [X] 3. ~~Encontrar outras formas de organizar o `map` para assim ser possível aceitarmos outros parâmetros no algoritmo;~~
- [X] 4. ~~Adicionar a função de exportar a saída do algoritmo para um arquivo `.html`;~~
- [X] 5. ~~Pesquisar sobre arquivos Unicode;~~
- [X] 6. ~~Adaptar o `palavras.cpp` para exportar um arquivo `.html` ao invés de um `.csv` para fins de validação de conceito.~~
- [ ] 7. Implementar classes contendo as funções desenvolvidas nos programas de estudos.
- [X] 8. Desenvolver uma func membro da classe processInputs que leia um arq de texto utf-8 com caracter string wchar e wifstream e wofstream (colocar os arquivos dentro de um map)
- [X] 9. Enquanto estiver lendo o arquivo, deve contar quantas palavras foram lidas, quantos caracteres foram lidos e quantas palavras distintas (usando o tamanho do map).
- [X] 10. Antes de executar qualquer arq, verificar se ele é utf-8 e se ele consegue ser aberto.
- [ ] 11. Fazer uma classe que receba um map e o insira em um vector com ponteiros para pair.
- [ ] 12. Fazer novas classes que recebem o vector ordenado e o convertem para um arquivo de saída `.html` ou `.csv`.

#### CLASSES

1 Classe de entrada de arquivo;  
1 De tratamento de argumentos;  
2 De output.


* ORDENAR ARRAY DE PONTEIROS DO MAP  
* PERCORRER MAP COM ITERATOR  
* CADA ITERAÇÃO DA UM PUSH BACK NO VECTOR E DAR UM SORT NO VECTOR  

