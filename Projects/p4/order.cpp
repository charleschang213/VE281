#include "order.h"
bool operator<(const order &a,const order &b){
    if (a.buy){
        if (a.price==b.price) return a.oid>b.oid;
        return a.price<b.price;
    }
    if (a.price==b.price) return a.oid>b.oid;
        return a.price>b.price;
}