#include "processOutputs.hpp"
#include <string>
#include <fstream>
#include <iostream>
namespace out{

/*
O escopo da funcao membro export_html,
essa funcao acessa um vector de ponteiros para pair 
e cria um arquvido wide output stream, 
nesse arquivo sao colocados os elementos ordenados do vector 
e sao formatados para o padrao html para a criacao de uma tabela.

*/

void processOutputs::export_html(){
    std::wstring nome_saida = L"HTML OUTPUT";
    std::wofstream html("saida.html");

    html << L"<!DOCTYPE html>\n";
    html << L"<html lang=\"pt-br\">\n";
    html << L"<head>\n";
    html << L"    <meta charset=\"UTF-8\">\n";
    html << L"    <meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\">\n";
    html << L"    <title>" << nome_saida << "</title>\n";
    
    html << L"    <style>\n";
    html << L"        table {\n";
    html << L"            width: 100%;\n";
    html << L"            border-collapse: collapse;\n"; //remove espaços entre bordas de células
    html << L"        }\n";
    html << L"        th, td {\n"; //th -> table header cell. td -> table data cell 
    html << L"            border: 1px solid black;\n"; //coloca borda nas células
    html << L"            padding: 8px;\n"; //coloca espaçamento interno nas células
    html << L"            text-align: left;\n"; //centraliza o texto
    html << L"        }\n";
    html << L"        th {\n";
    html << L"            background-color: #f2f2f2;\n"; //adiciona uma cor de fundo aos cabeçalhos
    html << L"        }\n";
    html << L"    </style>\n";
    html << L"</head>\n";
    html << L"<body>\n";
    html << L"\n";
    html << L"    <table>\n";
    html << L"        <thead>\n";
    html << L"            <tr>\n";
    html << L"                <th>Palavra</th>\n";
    html << L"                <th>Ocorrências</th>\n";
    html << L"            </tr>\n";
    html << L"        </thead>\n";
    html << L"        <tbody>\n";

    

    for(auto loca : vector_saida){
        html << L"            <tr>\n";
        html << L"                <td>" << loca->first << "</td>\n";
        html << L"                <td>" << loca->second << "</td>\n";
        html << L"            </tr>\n";
    }



    html << L"        </tbody>\n";
    html << L"    </table>\n";
    html << L"</body>\n";
    html << L"</html>\n";

    //é necessário utilizar o L para indicar que está sendo enviado uma wstring!
}


/*
O escopo da funcao membro export_csv,
essa funcao acessa um vector de ponteiros para pair 
e cria um arquvido wide output stream, 
nesse arquivo sao colocados os elementos ordenados do vector 
e sao formatados para o padrao csv para a criacao de uma tabela.
*/

void processOutputs::export_csv(){
    std::wofstream csv("saida.csv"); 
    csv << "\"Palavra\";\"N\"\n"; 
    for(auto loca : vector_saida){
        csv << '"' << loca->first << '"' << ';' << loca->second << std::endl; 
    }


}

}


