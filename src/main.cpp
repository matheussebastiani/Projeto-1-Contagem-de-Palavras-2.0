#include "processInputs.hpp"
#include <iostream>
#include "processMap.hpp"
#include <map>
#include <vector>

int main(int argc, char* argv[]){

    inp::processInputs entrada;

    

    entrada.processa_argumentos(argc, argv);

   

    entrada.processa_entrada(entrada.get_nome_arquivo());
    
    std::map<std::wstring, int> map_ref = entrada.get_map();

      mid::processMap samuel;
      samuel.pushMap(map_ref);
      
      samuel.sort_vector(entrada.get_modo_ordenacao());
      

    std::vector<std::pair<const std::wstring, int>*> vector_auxiliar = samuel.get_ordered_vector();
    



    

}

