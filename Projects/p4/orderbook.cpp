#include "orderbook.h"
#include <sstream>
#include <iostream>

order orderbook::order_generate(int oid,std::string line){
    std::istringstream sin(line);
    std::string tmp;
    int cid,share,duration,price,eid,duration;
    bool buy;
    sin >> tmp;
    duration = std::stoi(tmp);
    sin >> tmp;
    if (cname.find(tmp)==cname.end()){
        ordered_cname.push(tmp);
        cid = cname.size();
        cname[tmp] = cid;
        clients.emplace_back(cid,0);
    }
    else cid = cname[tmp];
    sin >> tmp;
    buy = (tmp=="BUY");
    sin >> tmp;
    if (ename.find(tmp)==ename.end()){
        ordered_ename.push(tmp);
        eid = ename.size();
        ename[tmp] = eid;
        equities.emplace_back(eid);
    } else eid = ename[tmp];
    sin >> tmp;
    price = std::stoi(tmp.substr(1));
    sin >> tmp;
    share = std::stoi(tmp.substr(1));
    sin >> tmp;
    duration+=std::stoi(tmp);
    sin.clear();
    return order(oid,cid,eid,buy,share,duration,price); 
}