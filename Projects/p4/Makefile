all: main

main: main.o equity.o order.o orderbook.o
	g++ -o main -std=c++11 -O2 main.o order.o orderbook.o equity.o

main.o: main.cpp
	g++ -c main.cpp -O2 -std=c++11

equity.o: equity.cpp
	g++ -c equity.cpp -O2 -std=c++11

order.o: order.cpp
	g++ -c order.cpp -O2 -std=c++11

orderbook.o: orderbook.cpp
	g++ -c orderbook.cpp -O2 std=c++11

clean:
	rm -f *.o main