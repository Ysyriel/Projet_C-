CFLAGS=-std=c++11 -Wall -Wextra -g

all: main

main: main.o Individu.o CellA.o CellB.o Case.o Environnement.o
	g++ $(CFLAGS) main.o Individu.o CellA.o CellB.o Case.o Environnement.o -o main

main.o: main.cpp Individu.h CellA.h CellB.h Case.h Environnement.h
	g++ $(CFLAGS) -c main.cpp -o main.o

Individu.o: Individu.cpp Individu.h
	g++ $(CFLAGS) -c Individu.cpp -o Individu.o
	
CellA.o: CellA.cpp CellA.h 
	g++ $(CFLAGS) -c CellA.cpp -o CellA.o
	
CellB.o: CellB.cpp CellB.h 
	g++ $(CFLAGS) -c CellB.cpp -o CellB.o

Case.o: Case.cpp Case.h 
	g++ $(CFLAGS) -c Case.cpp -o Case.o	
	
Environnement.o: Environnement.cpp Environnement.h couleurs.h
	g++ $(CFLAGS) -c Environnement.cpp -o Environnement.o 
		
clean:
	rm -f *.o
