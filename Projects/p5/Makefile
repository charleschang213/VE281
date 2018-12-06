all: main

main: main.o graph.o
	g++ -o main -std=c++11 -O2 main.o graph.o

main.o: main.cpp
	g++ -c main.cpp -std=c++11 -O2

graph.o: graph.cpp
	g++ -c graph.cpp -std=c++11 -O2

clean:
	rm -f *.o main