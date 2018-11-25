#ifndef EQUITY_H
#define EQUITY_H
#include "order.h"
#include <queue>

class equity{
    int eid;
    std::priority_queue<order> buyers,sellers;
    public:
        equity(int eid):eid(eid),buyers(),sellers(){}
        void addbuyer(order v){buyers.push(v);}
        void addseller(order v){sellers.push(v);}
        order getbuyer();
        order getseller();
};
#endif