#include "graph.h"
#include <iostream>

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
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
    int minimum = a.mst();
    if (minimum==-1) std::cout << "No MST exists!" << std::endl;
    else std::cout << "The total weight of MST is " << minimum << std::endl;
    return 0;
}