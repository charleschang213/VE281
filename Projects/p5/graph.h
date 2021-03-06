#ifndef GRAPH_H
#define GRAPH_H
#include <vector>
#include <queue>
#include <utility>
#include <climits>
#include <cstdlib>
#include <iostream>

typedef struct _edge_{
    int s,t,w;
}edge;

struct edgecomp{
    bool operator()(const edge &lhs,const edge &rhs){
        return lhs.w>rhs.w;
    }
};

class graph{
    int size;
    std::vector<std::vector<std::pair<int,int> > > adj;
    std::vector<std::vector<std::pair<int,int> > > convadj;
    std::vector<int> innode;
    public:
        graph(int size):size(size),adj(size,std::vector<std::pair<int, int> >()),convadj(size,std::vector<std::pair<int, int> >()),innode(size,0){}  
        void addedge(int s,int t,int w);
        bool dag();
        int prim();
};
#endif