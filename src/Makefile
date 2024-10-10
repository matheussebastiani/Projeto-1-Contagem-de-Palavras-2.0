
CC=g++
FLAGS=-O2

all: processInputs.o processMap.o processOutputs.o palavras 

processInputs.o: classes/processInputs.hpp classes/processInputs.cpp
	${CC} ${FLAGS} -c classes/processInputs.cpp -o bin/processInputs.o

processMap.o: classes/processMap.hpp classes/processMap.cpp
	${CC} ${FLAGS} -c classes/processMap.cpp -o bin/processMap.o

processOutputs.o: classes/processOutputs.hpp classes/processOutputs.cpp
	${CC} ${FLAGS} -c classes/processOutputs.cpp -o bin/processOutputs.o

palavras: main.cpp processInputs.o processMap.o processOutputs.o
	${CC} ${FLAGS} main.cpp bin/processInputs.o bin/processMap.o bin/processOutputs.o -o palavras

clean:
	rm -f *.o *.html *.csv bin/*.o outputs/*.html outputs/*.csv palavras
