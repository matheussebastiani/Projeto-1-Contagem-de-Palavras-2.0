#include "processOutputs.hpp"
#include <string>
#include <fstream>

namespace out{

void processOutputs::export_html(){
    std::wstring nome_saida = L"HTML OUTPUT";
    std::wofstream html("saida.html");

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

    for(auto gustavo : vector_saida){
        html << "            <tr>\n";
        html << "                <td>" << gustavo->first << "</td>\n";
        html << "                <td>" << gustavo->second << "</td>\n";
        html << "            </tr>\n";
    }



    html << "        </tbody>\n";
    html << "    </table>\n";
    html << "</body>\n";
    html << "</html>\n";

}

void processOutputs::export_csv(){

}

}


