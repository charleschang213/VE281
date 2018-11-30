#ifndef GRAPH_H
#define GRAPH_H
#include <vector>
#include <queue>

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
    std::vector<int> innode;
    std::priority_queue<edge,std::vector<edge>,edgecomp> edges;
    public:
        graph(int size):size(size),adj(size,std::vector<std::pair<int, int> >()),innode(size,0){}  
        void addedge(int s,int t,int w);
        bool dag();
        int mst();
};
#endif