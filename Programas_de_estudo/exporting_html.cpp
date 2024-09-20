#include <iostream>
#include <map>
#include <string>
#include <fstream>

using namespace std;

/*
                                    TESTE VALIDAÇÃO DE CONCEITO: CONSTRUÇÃO DE TABELA EM HTML VIA C++

    * O script em questão não se importa com fluidez/otimização e sentido do código, servindo apenas para validar o conceito de construção de uma tabela
    em HTML através de iterações com um map.
    * É importante salientar que não devem ser esquecidas as quebras de linha após cada linha do HTML;
    * Além disso, existem várias aspas ("") dentro da sintaxe HTML. na hora de mandá-lo para o ofstream, é necessário colocar uma contrabarra (\) antes das aspas
*/

int main(){


    map<string, int> teste;
    string nome_saida = "Eu sou a página HTML de saída!";
    teste["palavra1"] = 2;
    teste["palavra2"] = 1;
    teste["palavra3"] = 3;

    ofstream html("saida.html"); //criação de um objeto para escrever no arquivo de saída.

    html << "<!DOCTYPE html>\n";
    html << "<html lang=\"pt-br\">\n";
    html << "<head>\n";
    html << "    <meta charset=\"UTF-8\">\n";
    html << "    <meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\">\n";
    html << "    <title>" << nome_saida << "</title>\n";
    //agora vai a perfumaria da tabela HTML, por quê? porque sim!!
    html << "    <style>\n";
    html << "        table {\n";
    html << "            width: 100%;\n";
    html << "            border-collapse: collapse;\n"; //remove espaços entre bordas de células
    html << "        }\n";
    html << "        th, td {\n"; //th -> table header cell. td -> table data cell 
    html << "            border: 1px solid black;\n"; //coloca borda nas células
    html << "            padding: 8px;\n"; //coloca espaçamento interno nas células
    html << "            text-align: left;\n"; //centraliza o texto
    html << "        }\n";
    html << "        th {\n";
    html << "            background-color: #f2f2f2;\n"; //adiciona uma cor de fundo aos cabeçalhos
    html << "        }\n";
    html << "    </style>\n";
    html << "</head>\n";
    html << "<body>\n";
    html << "\n";
    html << "    <table>\n";
    html << "        <thead>\n";
    html << "            <tr>\n";
    html << "                <th>Palavra</th>\n";
    html << "                <th>Ocorrências</th>\n";
    html << "            </tr>\n";
    html << "        </thead>\n";
    html << "        <tbody>\n";

    /* Insiro aqui um for auto que lerá o map entre as tags necessárias para o HTML*/

    for(auto [k, v] : teste){
        html << "            <tr>\n";
        html << "                <td>" << k << "</td>\n";
        html << "                <td>" << v << "</td>\n";
        html << "            </tr>\n";
    }



    html << "        </tbody>\n";
    html << "    </table>\n";
    html << "</body>\n";
    html << "</html>\n";

}

