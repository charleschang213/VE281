all: main

main: main.o equity.o order.o orderbook.o
	g++ -o main -std=c++11 main.o order.o orderbook.o equity.o -O2

main.o: main.cpp
	g++ -c main.cpp -std=c++11 -O2

equity.o: equity.cpp
	g++ -c equity.cpp -std=c++11 -O2

order.o: order.cpp
	g++ -c order.cpp -std=c++11 -O2

orderbook.o: orderbook.cpp
	g++ -c orderbook.cpp -std=c++11 -O2 

clean:
	rm -f *.o main