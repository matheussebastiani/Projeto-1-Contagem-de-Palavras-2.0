#include <iostream>

/*
                                        ########## Explicação resumida ##########

    argc e argv são dois parâmetros enviados para a função main quando desejamos enviar parâmetros para o programa via SO;
    
    o argc conta a quantidade de parâmetros enviados para o SO e o argv guarda em formato de string (**argv, ponteiro de "duas dimensões)
    os parâmetros enviados;

    uma observação importante, é que o primeiro parâmetro, ao chamar o script via SO, será o próprio nome do programa;
    então, caso eu execute o comando ./prog0.cpp teste1 teste2, minhas saídas serão:
    
    3 (quantidade de argumentos passados via SO);
    ./prog0.cpp (a própria chamada do SO, argv[0]. O SO EM QUESTÃO É UM LINUX DISTRO UBUNTU);
    teste1 (argv[i]);
    teste2 (argv[2]);
*/

int main(int argc, char **argv){ 

    std::cout << argc << std::endl;

    std::cout << argv[0] << std::endl;
    std::cout << argv[1] << std::endl;
    std::cout << argv[2] << std::endl;
    
}
