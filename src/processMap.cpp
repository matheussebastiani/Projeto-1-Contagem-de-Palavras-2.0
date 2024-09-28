#include "processMap.hpp"


/*

                                            Aqui ficará a implementação das funções-membro da classe processMap.

*/

namespace mid{

    
    //TO DO: implementar função membro pushMap


    /*

        Escopo da função membro pushMap():
        A função membro pushMap receberá o map da classe inp::processInputs e será responsável por iterar item a item do map contendo as palavras lidas,
        e fará a inserção dos campos do map em um vector de ponteiros para pair, estrutura que possui dois atributos: first e second. 
        O (pair-> first) armazenará a chave do map recebido, e o (pair->second) receberá a quantidade de ocorrências da palavra (pair->first).
        Essa ação é necessária para posteriormente iterarmos com o vector de pairs e ordená-lo por meio da função sort_vector(), da maneira escolhida pelo usuário

    */

    void processMap::pushMap(std::map<std::wstring, int> palavrasLidas){
        for(auto& palavras : palavrasLidas){
            pointer_vector.push_back(&palavras);
        }
    }


    //TO DO: implementar a função membro sort_vector

    /*

        Escopo da função membro sort_vector():
        A função sort_vector() receberá por parâmetro o vector contendo ponteiros para pair, o modo de ordenação processado pela classe inp::processInputs e 
        ordenará o vector de ponteiros da forma desejada, para posteriormente retorná-lo para outra classe responsável por enviar as palavras para um arquivo de saída.
    
    */

    void sort_vector(std::vector<std::pair<const std::wstring, int>*> vet, std::string forma){
        
    }





} //namespace mid