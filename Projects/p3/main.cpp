#include "path.h"
#include "string"
#include<cstdlib>
#ifdef P3_CLOCK
#include <ctime>
#include <sys/time.h>
#endif

#ifndef P3_CLOCK
int main(int argc, char *argv[]){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    long int m,n;
    long int sx,sy,ex,ey;
    Modes mode;
    bool v = false;
    std::string ms[3] = {"UNSORTED","BINARY","FIBONACCI"};
    for (long int i=0;i<argc;i++){
        if ((std::string(argv[i])=="-i")||(std::string(argv[i])=="--implementation")){
            for (long int j=0;i<3;j++){
                if (std::string(argv[i+1])==ms[j]){
                    mode = Modes(j);
                    break;
                }
            }
        }
        v = v||(std::string(argv[i])=="-v")||(std::string(argv[i])=="--verbose");
    }
    std::cin >> n >> m >> sx >> sy >> ex >> ey;
    point_t **map = new point_t*[m];
    for (long int i=0;i<m;i++){
        map[i] = new point_t[n];
        for (long int j=0;j<n;j++){
            map[i][j].pathcost=0;
            map[i][j].x=j;
            map[i][j].y=i;
            map[i][j].pre=NULL;
            map[i][j].reached=false;
            std::cin >> map[i][j].weight;
        }
    }
    path(m,n,map,sx,sy,ex,ey,mode,v);
    for (long int i=0;i<m;i++) delete []map[i];
    delete []map;
    return 0;
}
#else
int main(){
    srand(time(NULL));
	struct timeval t1,t2;
	long int sizes[10];
    long int ts[3][10];
    for (long int i=0;i<10;i++) {
        sizes[i] = 50*(i+1);
        for (long int j=0;j<3;j++) ts[j][i]=0;
    }
    for (long int i=0;i<10;i++){
        std::cerr << "Size: " << sizes[i]<< std::endl;
        point_t **map = new point_t*[sizes[i]];
        for (long int j=0;j<sizes[i];j++){
            map[j] = new point_t[sizes[i]];
        }
        for (long int j=0;j<5;j++){
            for (long int k=0;k<sizes[i];k++)
                for (long int m=0;m<sizes[i];m++) {
                    map[k][m].weight=rand()%1000;
                    map[k][m].pathcost=0;
                    map[k][m].pre=NULL;
                    map[k][m].x=m;
                    map[k][m].y=k;
					map[k][m].reached=false;
                }
			gettimeofday(&t1,NULL);
			path(sizes[i],sizes[i],map,0,0,sizes[i]-1,sizes[i]-1,UNSORTED,false);
            gettimeofday(&t2,NULL);
			ts[0][i]+=(t2.tv_usec-t1.tv_usec)+1000000*(t2.tv_sec-t1.tv_sec);
            for (long int k=0;k<sizes[i];k++)
                for (long int m=0;m<sizes[i];m++) {
                    map[k][m].pathcost=0;
					map[k][m].reached=false;
                    map[k][m].pre=NULL;
                }
			gettimeofday(&t1,NULL);
            path(sizes[i],sizes[i],map,0,0,sizes[i]-1,sizes[i]-1,BINARY,false);
            gettimeofday(&t2,NULL);
			ts[1][i]+=(t2.tv_usec-t1.tv_usec)+1000000*(t2.tv_sec-t1.tv_sec);
			for (long int k=0;k<sizes[i];k++)
                for (long int m=0;m<sizes[i];m++) {
                    map[k][m].pathcost=0;
					map[k][m].reached=false;
                    map[k][m].pre=NULL;
                }
			gettimeofday(&t1,NULL);
			path(sizes[i],sizes[i],map,0,0,sizes[i]-1,sizes[i]-1,FIBONACCI,false);
       	    gettimeofday(&t2,NULL);
			ts[2][i]+=(t2.tv_usec-t1.tv_usec)+1000000*(t2.tv_sec-t1.tv_sec);
        }
		for (long int k=0;k<sizes[i];k++) delete []map[k];
		delete []map;
    }
    for (int i=0;i<3;i++){
        for (int j=0;j<10;j++) std::cout << ts[i][j] <<" ";
        std::cout << std::endl;
    }
    return 0;
}
#endif
