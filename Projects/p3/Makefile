all: main

main: main.o path.o
	g++ -o main main.o path.o -std=c++11 -O2

main.o: main.cpp
	g++ -c main.cpp -std=c++11 -O2

path.o: path.cpp
	g++ -c path.cpp -std=c++11 -O2

clean:
	rm -f main *.o
