#ifndef UFS_H
#define UFS_H
#include <vector>
class ufset{
    int size;
    std::vector<int> parent;
    std::vector<int> rank;
    public:
        ufset(int n):size(n),parent(n,-1),rank(n,0){}
        int ufset_find(int n);
        void ufset_union(int x,int y); 
};
#endif