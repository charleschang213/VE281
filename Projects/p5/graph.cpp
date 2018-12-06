#include "graph.h"
#include <set>

void graph::addedge(int s,int t,int w){
    this->adj[s].emplace_back(t,w);
    this->convadj[t].emplace_back(s,w);
    this->innode[t]++;
}

bool graph::dag(){
    std::queue<int> q1,q2;
    for (int i=0;i<this->size;i++){
        if (this->innode[i]==0) q1.push(i);
    }
    while (!q1.empty()){
        int nownode = q1.front();
        q1.pop();
        q2.push(nownode);
        for (auto t: this->adj[nownode]){
            if (this->innode[t.first]!=0){
                this->innode[t.first]--;
                if (this->innode[t.first]==0) q1.push(t.first);
            }
        }
    }
    if (q2.size()==size) return true;
    return false;
}

struct primcmp{
    bool operator()(const std::pair<int, int> &lhs,const std::pair<int, int> &rhs){
        if (lhs.second==rhs.second) return lhs.first< rhs.first;
        return lhs.second<rhs.second;
    }
};

int graph::prim(){
    std::vector<int> d(this->size,INT_MAX);
    std::set<std::pair<int, int>,primcmp> dset;
    d[rand()%this->size] = 0;
    int total = 0;
    for (int i=0;i<this->size;i++){
        dset.emplace(i,d[i]);
    }
    while (!dset.empty()){
        int dnum = dset.begin()->first;
        //std::cerr << dset.size() << " " << dnum << " " << d[dnum] << std::endl;
        if (d[dnum]==INT_MAX) return -1;
        dset.erase(dset.begin());
        total+=d[dnum];
        for (auto edg:this->adj[dnum]){
            int dst = edg.first;
            int wg = edg.second;
            auto where = dset.find(std::pair<int,int>(dst,d[dst]));
            if ((where!=dset.end())&&(d[dst]>wg)){
                //std::cerr << "Find " << dst << std::endl;
                dset.erase(where);
                d[dst]=wg;
                dset.emplace(dst,d[dst]);
            }
        }
        for (auto edg:this->convadj[dnum]){
            int dst = edg.first;
            int wg = edg.second;
            auto where = dset.find(std::pair<int,int>(dst,d[dst]));
            if ((where!=dset.end())&&(d[dst]>wg)){
                //std::cerr << "Find " << dst << std::endl;
                dset.erase(where);
                d[dst]=wg;
                dset.emplace(dst,d[dst]);
            }
        }
    }
    return total;
}