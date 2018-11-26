#ifndef EQUITY_H
#define EQUITY_H
#include "order.h"
#include <queue>
#include <string>
class equity{
    int eid;
    std::string ename;
    std::priority_queue<order> buyers,sellers;
    std::vector<int> dealt;
    int median;
    public:
        equity(int eid,std::string ename):eid(eid),ename(ename),buyers(),sellers(),dealt(),median(-1){}
        void addbuyer(order v){buyers.push(v);}
        void addseller(order v){sellers.push(v);}
        order getbuyer();
        order getseller();
        int sellercount(){return sellers.size();}
        int buyercount(){return buyers.size();}
        void adddealtprice(int p);
        int getmedian(){return median;}
        std::string getname(){return ename;}
};
#endif