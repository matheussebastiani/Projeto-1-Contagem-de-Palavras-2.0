#!/bin/sh

#Meu primeiro shell scrpit para a faculdade!
#Apenas para gerar os arquivos de saída automaticamente!
#Matheus Sebastiani, rev 1

echo "Digite o nome do arquivo a ser lido: "

read ARQUIVO

mkdir outputs

./palavras ${ARQUIVO} #-ac

mv saida.csv outputs/saida_1.csv

./palavras ${ARQUIVO} -ad

mv saida.csv outputs/saida_2.csv

./palavras ${ARQUIVO} -nc

mv saida.csv outputs/saida_3.csv

./palavras ${ARQUIVO} -nd

mv saida.csv outputs/saida_4.csv

#com -csv

./palavras ${ARQUIVO} -ac -csv

mv saida.csv outputs/saida_5.csv

./palavras ${ARQUIVO} -ad -csv

mv saida.csv outputs/saida_6.csv

./palavras ${ARQUIVO} -nc -csv

mv saida.csv outputs/saida_7.csv

./palavras ${ARQUIVO} -nd -csv

mv saida.csv outputs/saida_8.csv

#com HTML

./palavras ${ARQUIVO} -ac -html

mv saida.html outputs/saida_8.html

./palavras ${ARQUIVO} -ad -html

mv saida.html outputs/saida_9.html

./palavras ${ARQUIVO} -nc -html

mv saida.html outputs/saida_10.html

./palavras ${ARQUIVO} -nd -html

mv saida.html outputs/saida_11.html