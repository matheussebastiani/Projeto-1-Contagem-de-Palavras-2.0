
CC=g++
FLAGS=-O2

all: processInputs.o palavras

processInputs.o: processInputs.hpp processInputs.cpp
	${CC} ${FLAGS} -c processInputs.cpp

palavras: main.cpp processInputs.o
	${CC} ${FLAGS} main.cpp processInputs.o -o palavras

clean:
	rm -f *.o palavras