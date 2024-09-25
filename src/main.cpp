#include "processInputs.hpp"
#include <iostream>


int main(int argc, char* argv[]){

    inp::processInputs entrada;

    std::cout << entrada.get_formato_saida() << std::endl;
    std::cout << entrada.get_modo_ordenacao() << std::endl;

    entrada.processa_argumentos(argc, argv);

    std::cout << entrada.get_formato_saida() << std::endl;
    std::cout << entrada.get_modo_ordenacao() << std::endl;

    std::cout << entrada.get_nome_arquivo() << std::endl;


}