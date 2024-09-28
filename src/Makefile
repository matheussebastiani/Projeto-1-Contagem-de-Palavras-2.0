
CC=g++
FLAGS=-O2

all: processInputs.o osvaldo

processInputs.o: processInputs.hpp processInputs.cpp
	${CC} ${FLAGS} -c processInputs.cpp

osvaldo: main.cpp processInputs.o
	${CC} ${FLAGS} main.cpp processInputs.o -o osvaldo

clean:
	rm -f *.o osvaldo
