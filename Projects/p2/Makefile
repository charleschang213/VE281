all: main

main: main.o select.o
	g++ -o main main.o select.o -g -Wall -Wextra -Werror -pedantic -O2

main.o: main.cpp
	g++ -c main.cpp -O2

select.o: select.cpp
	g++ -c select.cpp -O2

clean: 
	rm -f *.o main
