#include <iostream>
#include <fstream> 
#include <cctype> 
#include <map>
#include <string>
using namespace std;

/*
    Primeiro teste de implementação: argc e argv no script feito em aula.
    Mudanças em relação ao código feito em aula:
    * adicionados os argumentos argc e argv para a função main.
    * criado a string out, para armazenar o nome do arquivo de texto lido e evitar conflitos
    * to do: fazer com que a string out tenha apenas o nome do arquivo, sem sua extensão.

*/




int main(int argc, char **argv){

    ifstream arq; 
    arq.open(argv[1]); //indice 0 -> chamada do programa no SO. indice 1 -> nome do arquivo passado
    string out = argv[1];
    out[out.find_first_of(".")] = '_';
    ofstream csv(out += "_out.csv"); 

    char ch; 
    string palavra;

    map<string, int> ocorrencias;

    while(arq.get(ch)){ 
       if(isalpha(ch)){ 
        palavra += tolower(ch); 
       }
       else if(palavra.size() > 0){
//      cout << palavra << endl;
        ocorrencias[palavra]++; 
        palavra.clear(); 
       }

    }
    csv << "\"Palavra\";\"N\"\n"; 
    for(auto [k, v] : ocorrencias){
        csv << '"' << k << '"' << ';' << v << endl; 
    }

}
