all: main

main: main.o sorting.o clocking.o
	g++ -o main main.o sorting.o clocking.o

main.o: main.cpp
	g++ -c main.cpp

sorting.o: sorting.cpp
	g++ -c sorting.cpp

clocking.o: clocking.cpp
	g++ -c clocking.cpp

clean:
	rm -f *.o
