#include "order.h"
bool order::operator<(const order a){
    if (buy){
        if (price==a.price) return oid>a.oid;
        return price<a.price;
    }
    if (price==a.price) return oid>a.oid;
        return price>a.price;
}