/*
                                                                CLASSE processInputs
    
    Como o próprio nome já diz, a classe terá funções membro (métodos) que realizarão uma interface com a função main no processamento dos argumentos de entrada via SO;

    Essas funções membro manipularão variáveis membro (atributos) que conterão maps com os arquivos de entrada, o nome do arquivo de entrada e o formato de saída.

    A função membro que processará os dados de entrada deve levar em consideração que:
        * Os argumentos podem vir em ordem sortida;
        * Podem não haver argumetos, sendo necessário tratar a ausência de parâmetros adicionais para método de ordenação e formato de saída;
        * Avisar ao usuário caso ele envie parâmetros não aceitáveis, elaborando um tipo de --help
    
    A classe também deverá implementar o padrão Unicode.

    Após as funções membro da classe processarem todos os dados de entrada, uma segunda classe ordenará e organizará o map em um vector de tuplas.


*/


#ifndef PROCESSINPUTS_HPP
#define PROCESSINPUTS_HPP

#include <string>
#include <map>


namespace inp{

class processInputs{

    private:

        std::string modo_ordenacao;

        std::string nome_arquivo;

        std::string formato_saida;

        std::map<std::wstring, int> ocorrencias;

        int caracteres;
        int total_palavras;
        int palavras_distintas;

    public:

        processInputs();

        void processa_argumentos(int argc, char* argv[]);

        void processa_entrada(std::string arquivo);
        
        //funções de get:

        std::string get_modo_ordenacao(){
            return modo_ordenacao;
        }

        std::string get_formato_saida(){
            return formato_saida;
        }

        std::string get_nome_arquivo(){
            return nome_arquivo;
        }

        int get_qtd_caracteres(){
            return caracteres;
        }
        int get_total_palavras(){
            return total_palavras;
        }

        int get_palavras_distintas(){
            return palavras_distintas;
        }
        //funções de set não serão implementadas pois as variáveis membro serão alteradas por dentro da classe.
        
        std::map<std::wstring, int> get_map(){
            return ocorrencias;
        }

};

}

#endif


/*       

    To Do: implementar funções para processar os argumentos recebidos do SO;
           implementar função que lê o arquivo de texto e insere seu conteúdo em um map;
           não esquecer que essa classe deverá permitir que seja feita a comunicação com outras classes por meio de seus objetos;

*/