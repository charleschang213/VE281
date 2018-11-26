#ifndef ORDERBOOK_H
#define ORDERBOOK_H
#include <vector>
#include <unordered_map>
#include <string>
#include "equity.h"
#include "client.h"
class orderbook{
    std::unordered_map<std::string,int> ename,cname;
    std::priority_queue<std::string,std::vector<std::string>,std::greater<std::string> > ordered_ename,ordered_cname;
    std::vector<equity> equities;
    std::vector<client> clients;
    std::vector<std::string> tttnames;
    bool midpoint,median,transfer,verbose;
    int timestamp,income,transferred,completed,cshare;
    public:
        order order_generate(int oid,std::string line);
        orderbook(bool midpoint,bool median,bool transfer,bool verbose,std::vector<std::string> tttnames):
            midpoint(midpoint),median(median),transfer(transfer),verbose(verbose),tttnames(tttnames),
            ename(),cname(),ordered_ename(),ordered_cname(),equities(),clients(),timestamp(0),income(0),transferred(0),completed(0),cshare(0){}
        void order_execute(order neworder);
        void endofday();
        void endoftime(int ts);
        int getts(){return timestamp;}
};
#endif