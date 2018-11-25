#include "order.h"
bool order::operator<(order &a){
    if (buy){
        if (price==a.price) return oid>a.oid;
        return price<a.price;
    }
    if (price==a.price) return oid>a.oid;
        return price>a.price;
}