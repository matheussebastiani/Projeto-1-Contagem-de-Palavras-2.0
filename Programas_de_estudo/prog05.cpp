#include <iostream>
#include <fstream> //para ler o arquivo de texto. stream -> fluxo de dados de entrada e saída
#include <map>
#include <locale>
#include <string>
#include <cwctype> //para checar se o caractere é alfabético
#include <vector>
#include <algorithm>
using namespace std;

/*      Aqui tentaremos ordenar ponteiros para map de diferentes formas em um vector*/

void ordena_tupla(vector<pair<const wstring, int>*>& vet, string forma){

    if(forma == "-ac"){ //ascendente wstring

        sort(vet.begin(), vet.end(), [](const pair<const wstring, int>* a, const pair<const wstring, int>* b){ //estamos no fundo ordenando ponteiros para estruturas do tipo pair
            
            return a->first < b->first; //compara string com string

        }); //redundante, mas pode ser útil para um unordered_map

    }

    else if(forma == "-ad"){ //descentente wstring

        sort(vet.begin(), vet.end(), [](const pair<const wstring, int>* a, const pair<const wstring, int>* b){ 
            
            return a->first > b->first; //compara wstring com wstring

        });
    }
    else if(forma == "-nc"){ //ascendente ocorrencias

        sort(vet.begin(), vet.end(), [](const pair<const wstring, int>* a , const pair<const wstring, int>* b){ 
            
            return a->second < b->second; //compara inteiro com inteiro

        });
    
    }

    else if(forma == "-nd"){ //descendente ocorrencias

        sort(vet.begin(), vet.end(), [](const pair<const wstring, int>* a, pair<const wstring, int>* b){ 
            
            return a->second > b->second; //compara inteiro com inteiro

        });
    
    }


}



int main(){

    wifstream arq; //tipo de arquivo conhecido como WIDE INPUT FILE
    
    auto pt = locale(""); //UTF8
    
    locale::global(pt); //define o padrão dos próximos objetos do tipo locale como UTF8
    
    arq.open("gpl.txt");
    
    arq.imbue(pt); //formata o arquivo de saída para UTF-8
    
    wofstream csv("palavras.csv"); // wide output file: comma separated values
    

    wchar_t ch; //desta vez, vamos ler caractere a caractere do arquivo
    wstring palavra;

    map<wstring, int> ocorrencias; //ajuste o map para wstring

    while(arq.get(ch)){ //lê um wchar_t por vez do arquivo
       if(iswalpha(ch)){ //É uma letra?
        palavra += tolower(ch); //concatenamos em uma wstring o caractere sempre em minusculo
       }
       else if(palavra.size() > 0){
//      cout << palavra << endl;
        ocorrencias[palavra]++; //a palavra é a chave. procura no map a palavra, incrementa o valor acessado pela chave. nos aproveitamos do bug de antes, que caso ele nao exista no map, ele insere com o valor default
        palavra.clear(); //precisamos limpar a palavra após usá-la
       }

    }
    
    
    cout << ocorrencias.size() << endl;

    vector<pair<const wstring, int>*> vetor; //Estrutura pair, faremos um vector de ponteiros para TUPLAS, que recebeão o endereço do map tendo um valor first e second
    //ou seja, percorreremos um mapa e o colocaremos em uma tupla

    for(auto& elementos : ocorrencias){
        vetor.push_back(&elementos); //inserindo endereços para o map no vector de tuplas
    }
    
    wcout << vetor[0]->first << " " << vetor[0]->second << endl; //WIDE COUT


    string qual;

    cout << "Escolha como você gostaria de ordenar o arquivo de saída:\n";
    cout << "-ac: ordem alfabética ascendente\n";
    cout << "-ad ordem alfabética descendente \n";
    cout << "-nc ordenado por número de aparições de maneira ascendente\n";
    cout << "-nd ordenado por número de aparições de maneira descendente\n";


    cin >> qual;

    ordena_tupla(vetor, qual);

    
    csv << "\"Palavra\";\"N\"\n"; //coloca os titulos das colunas do CSV
    for(auto matheus : vetor){
        csv << '"' << matheus->first << '"' << ';' << matheus->second << endl; //mandamos para o csv. a string precisa estar entre aspas
    }

    cout << pt.name() << endl; //FORMATADO

}