#ifndef CLIENT_H
#define CLIENT_H
#include <string>
class client{
    int cid;
    int income;
    std::string cname;
    int bought,sold;
    public:
        client(int cid,std::string cname,int income):cid(cid),cname(cname),income(income),bought(0),sold(0){}
        int getcid(){return cid;}
        int getincome(){return income;}
        int buy(int share,int val){bought+=share;income-=val;}
        int sell(int share,int val){sold+=share;income+=val;}
        std::string getname(){return cname;}
};
#endif