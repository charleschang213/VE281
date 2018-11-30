#include "graph.h"
#include <queue>
void graph::addedge(int s,int t,int w){
    this->adj[s].emplace_back(t,w);
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