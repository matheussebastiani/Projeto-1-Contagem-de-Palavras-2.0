/*
                                                        CLASSE processMap

    A classe processMap será uma classe intermediária, tendo o objetivo de basicamente receber "ordens" da classe inp::processInputs, como se ela fosse uma classe "slave"
    Ela receberá o map que fora processado anteriormente, e o lerá e o colocará em um vector de ponteiros para pairs.
    Após inserir os dados em um vector de ponteiros para pairs, a classe em questão ordenará o vector, baseado no que fora (ou não) passado pelo usuário via terminal.
    Após deixar o vector ordenado, o bastão será passado para a(s) classe(s) de saída.
    Essa classe terá o namespace mid, pois representa o "meio" do programa.

*/
#ifndef PROCESS_MAP_HPP
#define PROCESS_MAP_HPP

#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <iostream>
#include <stdlib.h>

namespace mid{

    class processMap{

        private:

        std::vector<std::pair<const std::wstring, int>*> pointer_vector;
        
        public:

        processMap();
        
        void pushMap(std::map<std::wstring, int>& palavrasLidas);

        void sort_vector(std::string modo);

        std::vector<std::pair<const std::wstring, int>*> get_ordered_vector(){
            
            if(pointer_vector.size() > 0){
                return pointer_vector;
            }
            else{
                std::cout << "Não há elementos no vector em questão!" << std::endl;
                return pointer_vector;
            }
         }
                
    };

} //namespace mid

#endif