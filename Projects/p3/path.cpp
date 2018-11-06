#include "path.h"
void path(long int m,long int n, point_t **map,long int sx,long int sy,long int ex,long int ey,Modes mode,bool v){
    long int direct[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};
    map[sy][sx].pathcost = map[sy][sx].weight;
    map[sy][sx].reached = true;
    priority_queue<point_t,compare_point> *pq;
    switch (mode){
        case UNSORTED:
            pq = new unsorted_heap<point_t,compare_point>;
            break;
        case BINARY:
            pq = new binary_heap<point_t,compare_point>;
            break;
        default:
            pq = new fib_heap<point_t,compare_point>;
            break;            
    }
    pq->enqueue(map[sy][sx]);
    long int counter = 0;
    while (!pq->empty()){
        if (v) std::cout << "Step " << counter << std::endl;
        counter++;
        point_t c = pq->dequeue_min();
        if (v) std::cout << "Choose cell (" << c.x << ", " << c.y << ") with accumulated length " << c.pathcost << ".\n";
        for (long int i=0;i<4;i++){
            long int x1 = c.x+direct[i][0];
            long int y1 = c.y+direct[i][1];
            if (((x1<0)||(y1<0)||(x1>=n)||(y1>=m))||(map[y1][x1].reached)) continue;
            map[y1][x1].pathcost = map[y1][x1].weight+map[c.y][c.x].pathcost;
            map[y1][x1].reached = true;
            map[y1][x1].pre = &(map[c.y][c.x]);
            if ((x1==ex)&&(y1==ey)){
                if (v) std::cout <<  "Cell (" << x1 << ", " << y1 << ") with accumulated length " << map[y1][x1].pathcost << " is the ending point.\n";
				std::cout << "The shortest path from (" << sx << ", " << sy << ") to (" << ex << ", " << ey << ") is " << map[y1][x1].pathcost << ".\nPath:\n";
				backtrace(map, ex,ey);
                delete pq;
                return; 
            } 
            if (v) std::cout << "Cell (" << x1 << ", " << y1 << ") with accumulated length " << map[y1][x1].pathcost << " is added into the queue.\n";
            pq->enqueue(map[y1][x1]);
        }
    }
}

void backtrace(point_t **map, long int ex,long int ey){
    if (map[ey][ex].pre==NULL){
        std::cout << "(" << ex << ", " << ey << ")\n";
        return;
    }
    backtrace(map,map[ey][ex].pre->x,map[ey][ex].pre->y);
    std::cout << "(" << ex << ", " << ey << ")\n";
}
