
CC=g++
FLAGS=-O2

all: processInputs.o processMap.o osvaldo

processInputs.o: processInputs.hpp processInputs.cpp
	${CC} ${FLAGS} -c processInputs.cpp

processMap.o: processMap.hpp processMap.cpp
	${CC} ${FLAGS} -c processMap.cpp

osvaldo: main.cpp processInputs.o processMap.o
	${CC} ${FLAGS} main.cpp processInputs.o processMap.o -o osvaldo

clean:
	rm -f *.o osvaldo
