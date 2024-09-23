#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
    // Criar um std::map com alguns elementos
    map<int, string> myMap = {
        {1, "Um"},
        {2, "Dois"},
        {3, "Três"}
    };

    // Criar um std::vector para armazenar ponteiros para os elementos do map
    vector<pair<const int, string>*> myVector;

    // Iterar sobre o map e adicionar ponteiros de cada elemento ao vector
    for (auto& elem : myMap) {
        myVector.push_back(&elem);
    }

    // Acessar os elementos do vetor e imprimir usando os ponteiros
    for (const auto& elemPtr : myVector) {
        cout << "Chave: " << elemPtr->first << ", Valor: " << elemPtr->second << endl;
    }

    return 0;
}