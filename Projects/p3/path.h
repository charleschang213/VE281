#ifndef PATH_H
#define PATH_H
//#define P3_CLOCK
#include "priority_queue.h"
#include "binary_heap.h"
#include "fib_heap.h"
#include "unsorted_heap.h"
#include <iostream>

enum Modes{UNSORTED,BINARY,FIBONACCI,MODES_NUM};

typedef struct __point__{
    long int x,y;
    long int weight;
    long int pathcost;
    bool reached;
    struct __point__ *pre;
}point_t;

struct compare_point{
    bool operator()(const point_t &a,const point_t &b) const{
        if (a.pathcost!=b.pathcost) return a.pathcost<b.pathcost;
        if (a.x!=b.x) return a.x<b.x;
        return a.y<b.y;
    }
};

void path(long int m,long int n, point_t **map,long int sx,long int sy,long int ex,long int ey,Modes mode,bool v);

void backtrace(point_t **map, long int ex,long int ey);
#endif
