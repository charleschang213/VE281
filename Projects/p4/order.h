#ifndef ORDER_H
#define ORDER_H
class order{
    int oid;
    int cid,eid;
    bool buy;
    int share;
    int duration,ts;
    int price;
    public:
        friend bool operator<(const order &a,const order &b);
        order(int oid,int cid,int eid,bool buy,int share,int duration,int ts,int price):
            oid(oid),cid(cid),eid(eid),buy(buy),share(share),duration(duration),ts(ts),price(price){}
        void doneshare(int val){share-=val;}
        int getoid(){return oid;}
        int getcid(){return cid;}
        int geteid(){return cid;}
        int getbuy(){return buy;}
        int getduration(){return duration;}
        int getprice(){return price;}
        int getshare(){return share;}
        int getts(){return ts;}
};

bool operator<(const order &a,const order &b);
#endif