#include "path.h"
#include "string"

int main(int argc, char *argv[]){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int m,n;
    int sx,sy,ex,ey;
    Modes mode;
    bool v = false;
    std::string ms[3] = {"UNSORTED","BINARY","FIBONACCI"};
    for (int i=0;i<argc;i++){
        if ((std::string(argv[i])=="-i")||(std::string(argv[i])=="--implementation")){
            for (int j=0;i<3;j++){
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
    for (int i=0;i<m;i++){
        map[i] = new point_t[n];
        for (int j=0;j<n;j++){
            map[i][j].pathcost=0;
            map[i][j].x=j;
            map[i][j].y=i;
            map[i][j].pre=NULL;
            map[i][j].reached=false;
            std::cin >> map[i][j].weight;
        }
    }
    path(m,n,map,sx,sy,ex,ey,mode,v);
    for (int i=0;i<m;i++) delete []map[i];
    delete []map;
    return 0;
}