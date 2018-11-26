#ifndef EQUITY_H
#define EQUITY_H
#include "order.h"
#include <queue>
#include <string>
#include <iostream>
#include <limits>
class equity{
    int eid;
    std::string ename;
    std::priority_queue<order> buyers,sellers;
    std::vector<int> dealt;
    int median;
    int btime,stime,maxv,mintime,minb;
    public:
        equity(int eid,std::string ename):eid(eid),ename(ename),buyers(),sellers(),dealt(),median(-1),btime(-1),stime(-1),mintime(-1),minb(INT32_MAX),maxv(INT32_MIN){}
        void addbuyer(order v){buyers.push(v);}
        void addseller(order v){sellers.push(v);}
        order getbuyer();
        order getseller();
        int sellercount(){return sellers.size();}
        int buyercount(){return buyers.size();}
        void adddealtprice(int p);
        int getmedian(){return median;}
        void modify(int ts,int val,bool buy);
        void strategyout(){
            std::cout << "Time travelers would buy " << ename<< " at time: "<< btime <<" and sell it at time: "<< stime << std::endl;
        }
        std::string getname(){return ename;}
};
#endif