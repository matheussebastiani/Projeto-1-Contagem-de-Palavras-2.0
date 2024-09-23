#include <iostream>
#include <fstream> //para ler o arquivo de texto. stream -> fluxo de dados de entrada e saída
#include <map>
#include <locale>
#include <string>

/*

    Aqui será testado o uso de caracteres wchar_t, caracteres de 16 bits do padrão unicode. Para trabalharmos com esse tipo de caractere de 16 bits, teremos que utilizar
    componentes diferentes da biblioteca fstream, como o wifstream, que permite que os arquivos a serem lidos trabalhem com o tipo wchar_t. Uma string de wchar_t é uma
    wstring (wide string, ou string larga pois é composta por caracteres de 16 bits). A aplicação em questão será exatamente igual ao algoritmo de aula e será futuramente
    utilizado em uma classe.
    A classe locale permite que trabalhemos com diferentes "padrões de escrita de diferentes locais do mundo" podemos utilizar a função membro imbue, para "dizer" para
    a nossa wifstream como deve ser o "padrão de escrita" do nosso arquivo de saída.

*/


using namespace std;

int main(){

    auto pt = locale(""); //definição da localidade do sistema, como não passo nada, pega a que está por padrão no sistema. no trabalho, deixaremos assim
    //pois caso passemos algum parâmetro diferente, é necessário que o padrão esteja instalado no SO do dispositivo que está executando o programa.
    cout.imbue(pt); //formata a função de saída de acordo com o locale em questão. imbue -> função membro da biblioteca fstream
    double teste = 3.904342;
    cout << "A localização selecionada é a: " << pt.name() << endl;
    cout << teste << endl; //veja aqui como é a formatação do arquivo de saída. como no Brasil usamos a vírgula, a saída é com vírgula por conta do cout.imbue(pt)
    locale::global(pt); //comente e descomente essa linha para ver a diferença de name do objeto da classe locale abaixo
    //a função membro locale faz com que todos os objetos locale daí em diante possuam o padrão de escrita enviado como parâmetro para ela

    locale teste1; //criação de um objeto da classe locale
    cout << teste1.name() << endl;
}
