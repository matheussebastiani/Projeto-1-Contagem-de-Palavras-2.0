/*
                                 ---Função da classe---

A classe a seguir recebe um VECTOR contendo ponteiros para PAIR ordenados na ordem escolhida pelo usuário
e o converterá em um arquivo de saída, tambem escolhido pelo usuário,
podendo ser CSV ou HTML




*/

#ifndef PROCESSOUTPUTS_HPP
#define PROCESSOUTPUTS_HPP

#include <vector>
#include <string>

namespace out{

class processOutputs{
    private:
        std::vector<std::pair<const std::wstring, int>*> vector_saida;
    public:
        processOutputs(std::vector<std::pair<const std::wstring, int>*> vet) : vector_saida{vet}{
            
        } 

        void export_html();
        void export_csv();



};
}













#endif

