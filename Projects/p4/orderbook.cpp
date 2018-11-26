#include "orderbook.h"
#include <sstream>
#include <iostream>

#define MIN(a,b) a<b?a:b

order orderbook::order_generate(int oid,std::string line){
    std::istringstream sin(line);
    std::string tmp;
    int cid,share,duration,price,eid,duration,ts;
    bool buy;
    sin >> tmp;
    ts = std::stoi(tmp);
    sin >> tmp;
    if (cname.find(tmp)==cname.end()){
        ordered_cname.push(tmp);
        cid = cname.size();
        cname[tmp] = cid;
        clients.emplace_back(cid,tmp,0);
    }
    else cid = cname[tmp];
    sin >> tmp;
    buy = (tmp=="BUY");
    sin >> tmp;
    if (ename.find(tmp)==ename.end()){
        ordered_ename.push(tmp);
        eid = ename.size();
        ename[tmp] = eid;
        equities.emplace_back(eid,tmp);
    } else eid = ename[tmp];
    sin >> tmp;
    price = std::stoi(tmp.substr(1));
    sin >> tmp;
    share = std::stoi(tmp.substr(1));
    sin >> tmp;
    duration = ts+std::stoi(tmp);
    sin.clear();
    return order(oid,cid,eid,buy,share,duration,ts,price); 
}

void orderbook::order_execute(order neworder){
    equity &eq = this->equities[neworder.geteid()];
    client &c1 = this->clients[neworder.getcid()];
    if (neworder.getbuy()){
        if (eq.sellercount()==0){
            if (neworder.getduration()>this->timestamp)
                eq.addbuyer(neworder);
            return;
        }
        order seller = eq.getseller();
        while (seller.getduration()!=-1&&seller.getduration()<this->timestamp) {
            if (eq.sellercount()==0){
                if (neworder.getduration()>this->timestamp)
                    eq.addbuyer(neworder);
                return;
            }
            seller = eq.getseller();
        }
        client &c2 = this->clients[seller.getcid()];
        if (seller.getprice()<neworder.getprice()){
            int dshare = MIN(seller.getshare(),neworder.getshare());
            seller.doneshare(dshare);
            neworder.doneshare(dshare);
            int commision = seller.getprice()*dshare/100;
            this->income+=2*commision;
            c2.sell(dshare,seller.getprice()*dshare);
            c1.buy(dshare,seller.getprice()*dshare);
            this->transferred+=seller.getprice()*dshare;
            this->completed++;
            this->cshare+=dshare;
            if (this->verbose)
                std::cout << c1.getname() << " purchased " << dshare << " shares of " << eq.getname() << " from " << c2.getname() << " for $" << seller.getprice() << "/share" << std::endl; 
        }
        if ((neworder.getduration()==-1||neworder.getduration()>=this->timestamp)&&(neworder.getshare()!=0))
            eq.addbuyer(neworder);
        if ((seller.getduration()==-1||seller.getduration()>=this->timestamp)&&(seller.getshare()!=0))
            eq.addseller(seller);
    }
    else {
        if (eq.buyercount()==0){
            if (neworder.getduration()>this->timestamp)
                eq.addseller(neworder);
            return;
        }
        order buyer = eq.getbuyer();
        while (buyer.getduration()!=-1&&buyer.getduration()<=this->timestamp) {
            if (eq.sellercount()==0){
                if (neworder.getduration()>this->timestamp)
                    eq.addseller(neworder);
                return;
            }
            buyer = eq.getbuyer();
        }
        client &c2 = this->clients[buyer.getcid()];
        if (neworder.getprice()<buyer.getprice()){
            int dshare = MIN(buyer.getshare(),neworder.getshare());
            buyer.doneshare(dshare);
            neworder.doneshare(dshare);
            int commision = buyer.getprice()*dshare/100;
            this->income+=2*commision;
            c2.buy(dshare,buyer.getprice()*dshare);
            c1.sell(dshare,buyer.getprice()*dshare);
            this->transferred+=buyer.getprice()*dshare;
            this->completed++;
            this->cshare+=dshare;
            if (this->verbose)
                std::cout << c2.getname() << " purchased " << dshare << " shares of " << eq.getname() << " from " << c1.getname() << " for $" << buyer.getprice() << "/share" << std::endl; 
        }
        if ((neworder.getduration()==-1||neworder.getduration()>this->timestamp)&&(neworder.getshare()!=0))
            eq.addseller(neworder);
        if ((buyer.getduration()==-1||buyer.getduration()>this->timestamp)&&(buyer.getshare()!=0))
            eq.addbuyer(buyer);
    }
}

void orderbook::endofday(){
    std::cout << "---End of Day---\nCommission Earnings: " << this->income << "\nTotal Amount of Money Transferred: " << this->transferred << "\nNumber of Completed Trades: " << this->completed << "\nNumber of Shares Traded: " << this->cshare << std::endl;
}

void orderbook::endoftime(){
    timestamp++;
}