#ifndef CLIENT_H
#define CLIENT_H
#include <string>
class client{
    int cid;
    int income;
    std::string cname;
    public:
        client(int cid,int income):cid(cid),income(income){}
        int getcid(){return cid;}
        int getincome(){return income;}
        int buy(int val){income-=val;}
        int sell(int val){income+=val;}
};
#endif