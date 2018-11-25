#ifndef ORDER_H
#define ORDER_H
class order{
    int oid;
    int cid,eid;
    bool buy;
    int share;
    int duration;
    int price;
    public:
        order(int oid,int cid,int eid,bool buy,int share,int duration,int price):
            oid(oid),cid(cid),eid(eid),buy(buy),share(share),duration(duration),price(price){}
        void doneshare(int val){share-=val;}
        bool operator<(order &a);
};
#endif