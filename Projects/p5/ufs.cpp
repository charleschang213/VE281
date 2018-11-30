#include "ufs.h"

int ufset::ufset_find(int n){
    if (this->parent[n]==-1) return n;
    this->parent[n] = this->ufset_find(this->parent[n]);
    return this->parent[n];
}

void ufset::ufset_union(int x,int y){
    int a = this->ufset_find(x);
    int b = this->ufset_find(y);
    if (this->rank[a]>this->rank[b]){
        this->parent[b] = a;
    }
    else {
        this->parent[a] = b;
        if (this->rank[a]==this->rank[b]) this->rank[b]++;
    }
}