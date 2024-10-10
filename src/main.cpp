#include "classes/processInputs.hpp"
#include <iostream>
#include "classes/processMap.hpp"
#include <map>
#include <vector>
#include "classes/processOutputs.hpp"

int main(int argc, char* argv[]){

    inp::processInputs entrada;

    

    entrada.processa_argumentos(argc, argv);

   

    entrada.processa_entrada(entrada.get_nome_arquivo());
    
    std::map<std::wstring, int> map_ref = entrada.get_map();

      mid::processMap samuel;
      samuel.pushMap(map_ref);
      
      samuel.sort_vector(entrada.get_modo_ordenacao());
      

    std::vector<std::pair<const std::wstring, int>*> vector_auxiliar = samuel.get_ordered_vector();
    

  out::processOutputs salida(vector_auxiliar);
    if(entrada.get_formato_saida() == "-html"){
      salida.export_html();
    }else if(entrada.get_formato_saida() == "-csv"){
      salida.export_csv();
    }
  std::cout << "Caracteres lidos: " << entrada.get_qtd_caracteres() << std::endl 
  << "Palavras distintas: " << entrada.get_palavras_distintas() << std::endl 
  << "Total de palavras: " << entrada.get_total_palavras() << std::endl;

    

}

