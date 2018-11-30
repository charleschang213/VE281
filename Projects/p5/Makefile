all: main

main: main.o graph.o ufs.o
	g++ -o main -std=c++11 -O2 main.o graph.o ufs.o

main.o: main.cpp
	g++ -c main.cpp -std=c++11 -O2

graph.o: graph.cpp
	g++ -c graph.cpp -std=c++11 -O2

ufs.o: ufs.cpp
	g++ -c ufs.cpp -std=c++11 -O2

clean:
	rm -f *.o main