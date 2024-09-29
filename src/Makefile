
CC=g++
FLAGS=-O2

all: processInputs.o processMap.o processOutputs.o palavras 

processInputs.o: processInputs.hpp processInputs.cpp
	${CC} ${FLAGS} -c processInputs.cpp

processMap.o: processMap.hpp processMap.cpp
	${CC} ${FLAGS} -c processMap.cpp

processOutputs.o: processOutputs.hpp processOutputs.cpp
	${CC} ${FLAGS} -c processOutputs.cpp

palavras: main.cpp processInputs.o processMap.o processOutputs.o
	${CC} ${FLAGS} main.cpp processInputs.o processMap.o processOutputs.o -o palavras

clean:
	rm -f *.o *.html *.csv 
