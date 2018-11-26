#include <iostream>
#include <getopt.h>
#include "orderbook.h"

static const struct option long_options[] = {
    {"verbose",no_argument,NULL,'v'},
    {"median",no_argument,NULL,'m'},
    {"midpoint",no_argument,NULL,'p'},
    {"transfers",no_argument,NULL,'t'},
    {"ttt",required_argument,NULL,'g'}
};
int main(int argc, char *argv[]){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int opt;
    bool median=false,midpoint=false,transfer=false,verbose=false;
    std::vector<std::string> tttnames;
    while ((opt=getopt_long(argc,argv,"vmptg:",long_options,NULL))!=EOF){
        switch(opt){
            case 'v':
                verbose = true;
                break;
            case 'm':
                median = true;
                break;
            case 'p':
                midpoint = true;
                break;
            case 't':
                transfer = true;
                break;
            case 'g':
                tttnames.emplace_back(optarg);
                break;
            default:
                std::cout << "Invalid argument" << std::endl;
        }
    }
    orderbook ob(midpoint,median,transfer,verbose,tttnames);
    int ts = 0;
    int oid = 0;
    while (std::cin){
        std::cerr << oid << std::endl;
        std::string tmp;
        std::getline(std::cin,tmp);
        if (tmp.empty()) break;
        order curr_order = ob.order_generate(oid,tmp);
        oid++;
        ob.order_execute(curr_order);
    }
    ob.endoftime();
    ob.endofday();
    return 0;
}