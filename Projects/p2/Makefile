all: main

main: main.o select.o
	g++ -o main main.o select.o -g -Wall -Wextra -Werror -pedantic

main.o: main.cpp
	g++ -c main.cpp

select.o: select.cpp
	g++ -c select.cpp

clean: 
	rm -f *.o main
