#include "graph.h"
#include <iostream>

int main(){
    int size;
    std::cin >> size;
    graph a(size);
    while (!std::cin.eof()){
        int s,t,w;
        std::cin >> s >> t >> w;
        a.addedge(s,t,w);
    }
    if (a.dag()) std::cout << "The graph is a DAG" << std::endl;
    else std::cout << "The graph is not a DAG" << std::endl;
    return 0;
}