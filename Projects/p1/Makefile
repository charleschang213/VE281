all: main

main: main.o sorting.o clocking.o
	g++ -o main main.o sorting.o clocking.o -O2

main.o: main.cpp
	g++ -c -O2 main.cpp

sorting.o: sorting.cpp
	g++ -c -O2 sorting.cpp

clocking.o: clocking.cpp
	g++ -c -O2 clocking.cpp

clean:
	rm -f *.o main
