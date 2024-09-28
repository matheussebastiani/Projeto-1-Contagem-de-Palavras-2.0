#include <iostream>
#include <fstream> //para ler o arquivo de texto. stream -> fluxo de dados de entrada e saída
#include <cctype> //O C VAI NOS SALVAR!!!!!!!!!!!! (nao vai nãokkkkkkkkj)
#include <map>

using namespace std;

int main(){

    ifstream arq; //ifstream -> para ler um arquivo if = INPUT FILE
    arq.open("gpl.txt");//nao esqueça de abrir o arquivo, bocó
    ofstream csv("palavras.csv"); //comma separated values

    char ch; //desta vez, vamos ler caractere a caractere do arquivo
    string palavra;

    map<string, int> ocorrencias;

    while(arq.get(ch)){ //lê um char por vez do arquivo
       if(isalpha(ch)){ //É uma letra?
        palavra += tolower(ch); //concatenamos em uma string o caractere sempre em minusculo
       }
       else if(palavra.size() > 0){
//      cout << palavra << endl;
        ocorrencias[palavra]++; //a palavra é a chave. procura no map a palavra, incrementa o valor acessado pela chave. nos aproveitamos do bug de antes, que caso ele nao exista no map, ele insere com o valor default
        palavra.clear(); //precisamos limpar a palavra após usá-la
       }

    }
    csv << "\"Palavra\";\"N\"\n"; //coloca os titulos das colunas do CSV
    for(auto [k, v] : ocorrencias){
        csv << '"' << k << '"' << ';' << v << endl; //mandamos para o csv. a string precisa estar entre aspas
    }

}
