#ifndef GRAPH_H
#define GRAPH_H
#include <vector>
class graph{
    int size;
    std::vector<std::vector<std::pair<int,int> > > adj;
    std::vector<int> innode;
    public:
        graph(int size):size(size),adj(size,std::vector<std::pair<int, int> >()),innode(size,0){}  
        void addedge(int s,int t,int w);
        bool dag();
};
#endif