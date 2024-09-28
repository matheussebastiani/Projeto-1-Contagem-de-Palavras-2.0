#include <iostream>
#include <fstream> //para ler o arquivo de texto. stream -> fluxo de dados de entrada e saída
#include <map>
#include <locale>
#include <string>
#include <cwctype> //para checar se o caractere é alfabético

/*

    Aqui será testado o uso de caracteres wchar_t, caracteres de 16 bits do padrão unicode. Para trabalharmos com esse tipo de caractere de 16 bits, teremos que utilizar
    componentes diferentes da biblioteca fstream, como o wifstream, que permite que os arquivos a serem lidos trabalhem com o tipo wchar_t. Uma string de wchar_t é uma
    wstring (wide string, ou string larga pois é composta por caracteres de 16 bits). A aplicação em questão será exatamente igual ao algoritmo de aula e será futuramente
    utilizado em uma classe.
    A classe locale permite que trabalhemos com diferentes "padrões de escrita de diferentes locais do mundo" podemos utilizar a função membro imbue, para "dizer" para
    a nossa wifstream como deve ser o "padrão de escrita" do nosso arquivo de saída.

    PARA ISSO DEVO ESPECIFICAR QUE UTILIZAREI CARACTERES DE 16 BITS (wchar_t), STRINGS DE CARACTERES DE 16 BITS (wstring), ARQUIVOS DE ENTRADA "GRANDES"
    (WIDE INPUT FILE) e ARQUIVOS "GRANDES" DE SAÍDA (WIDE OUTPUT FILE)

*/


using namespace std;

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
    csv << "\"Palavra\";\"N\"\n"; //coloca os titulos das colunas do CSV
    for(auto [k, v] : ocorrencias){
        csv << '"' << k << '"' << ';' << v << std::endl; //mandamos para o csv. a string precisa estar entre aspas
    }

    std::cout << pt.name() << std::endl; //FORMATADO
}
