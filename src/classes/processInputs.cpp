#include "processInputs.hpp"
#include <iostream>
#include <cstring> //strcmp
#include <locale>
#include <map>
#include <string>
#include <fstream>
#include <cwctype> //checar se é alfabético

/*

                                            Aqui ficará a implementação das funções-membro da classe processInputs.

*/

namespace inp{

    /*Construtor de objetos, apenas declarado no arquivo .hpp
      Ele fora inicialmente descartado pois não vi utilidade inicial para ele, porém ao desenvolver a função processa_argumentos(), verifiquei que
      não seria necessário fazer alguma lógica complexa para detectar se não foi passado nenhum argumento de ordenação ou formato de saída, sendo apenas necessário
      iniciar essas variáveis membro com um valor padrão no construtor do objeto da classe processInputs.
    */

    processInputs::processInputs() : modo_ordenacao{"-ac"}, formato_saida{"-csv"}, caracteres{0}, total_palavras{0}, palavras_distintas{0} {}
        
    
    /*
    
        Escopo função processa_argumentos():
        Essa função receberá o argc e o argv da main, ou seja, receberá o número de argumentos passados para a execução do programa,
        e os argumentos em si. Essa função deve aceitar os parâmetros: 
        *nome do programa (argc[0]);
        *nome do arquivo a ser lido, 
        *ordem de ordenação e, 
        *formato de saída.
        A função também deve tratar da não existência de alguns parâmetros (que podem possuir valores default, como o de ordenação e o de saída).

        A implementação buscará utilizar um algoritmo que reconhecerá apenas a seguinte ordem:
        ./nomeprograma arquivo_de_texto.txt -forma_ordenacao -formato_saida
        Caso seja detectado algum parâmetro diferente desses (escrito de maneira errada), o programa não executará e retornará um comando de help;
        A função strcmp() da linguagem C foi utilizada por conta do argv ser essencialmente um array de char (estamos usando o argc e argv do C).

    */

    void processInputs::processa_argumentos(int argc, char* argv[]){

        if(argc == 1){ //se o argc for igual a 1, o usuário apenas executou o programa, sem especificar qual arquivo ele deseja ordenar

            std::cout << "Por favor, insira algum arquivo de texto para ser lido!\n";
            std::cout << "Parâmetros aceitáveis:\n";
            std::cout << "1. Nome do arquivo de texto\n";
            std::cout << "2. Ordem dos dados a serem apresentados na saída\n";
            std::cout << "-ac: Ordem alfabética ascendente da palavra\n";
            std::cout << "-ad: Ordem alfabética descendente da palavra\n";
            std::cout << "-nc: Ordem ascendente do número de ocorrrências\n";
            std::cout << "-nd: Ordem descendente do número de ocorrrências\n";
            std::cout << "3. Formatos de saída:\n";
            std::cout << "-csv\n";
            std::cout << "-html\n";

        }
        else{
        
            for(int i = 1; i < argc; i++){

                if(strcmp(argv[i], "-ac") == 0 || strcmp(argv[i], "-ad") == 0 || strcmp(argv[i], "-nc") == 0 || strcmp(argv[i], "-nd") == 0){
                    
                    modo_ordenacao = argv[i]; //processa o modo de ordenação. -ac pode ser considerado redundante. 
                    
                }

                else if(strcmp(argv[i], "-html") == 0){
                    
                    formato_saida = "-html"; //caso for csv, permanece na declaração do construtor
                
                }
                else if(strcmp(argv[i], "-csv") == 0){
                    formato_saida = "-csv";
                }

                else
                    nome_arquivo = argv[i];


            }

        }

    }

    /*  
        Escopo da função processa_entrada():
        Esse codigo utiliza caracteres wchar_t (16 bits) e strings wstring (string larga) para manipulação de textos com suporte ao padrão unicode. Para isso, foi utilizado 
        wifstream e wofstream para leitura e saida dos dados no formato wide.
        A configuração da classe locate com a função membro imbue foi aplicada para suportar o padrão UTF-8.
        Essa função é baseada no uso do locale e classe wide para manipular os caracteres de 16 bits, como utilizado nesta classe.
        Essa funcao vai receber uma string, le um arquivo de texto (se consegue ser aberto ou nao) e depoiis insere as palavras possiveis dentro de um arquivo de texto
        em um map.


    */
   
    void processInputs::processa_entrada(std::string arquivo) {

        std::wifstream wif;
        auto pt = std::locale(""); //UTF8
        std::locale::global(pt); //define o padrão de execução como UTF8
        wif.open(arquivo);
        wif.imbue(pt); 


        if (wif.fail()) {
            std::cout << "Erro ao abrir o arquivo de entrada." << std::endl; 
            return;
        }

        wchar_t ch;
        std::wstring palavra;

        while(wif.get(ch)){ //lê um wchar_t por vez do arquivo
            if(iswalpha(ch)){ //É uma letra?
                caracteres++; //conta os caracteres
                palavra += tolower(ch); //concatenamos em uma wstring o caractere sempre em minusculo
            }
            else if(palavra.size()>0){
                ocorrencias[palavra]++;
                total_palavras++;
                palavra.clear();
            }
    }
    //     palavras_distintas=ocorrencias.size();
    //     for(auto [k,v] : ocorrencias){
    //     std::wcout << "[" << k << ", " << v << "]" << std::endl;
    // }
        wif.close();
    }
    
};  //namespace inp
// falar com o brusso sobre a ultima palavra com um arquivo de texto que não termine com um caracter na próxima aula.