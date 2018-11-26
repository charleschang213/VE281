#include "equity.h"
#include <algorithm>
order equity::getbuyer()
{
    order v = buyers.top();
    buyers.pop();
    return v;
}

order equity::getseller()
{
    order v = sellers.top();
    sellers.pop();
    return v;
}

void equity::modify(int ts){
    if (!buyers.empty()){
        order bu = buyers.top();
        if (bu.getprice()<minb){
            mintime = ts;
            minb = bu.getprice();
        }
    }
    if (!sellers.empty()){
        order se = sellers.top();
        if (se.getprice()-minb > maxv){
            btime = mintime;
            stime = ts;
            maxv = se.getprice()-minb;
        }
    }
}
void equity::adddealtprice(int p){
    dealt.push_back(p);
    int a = dealt.size()/2;
    int b = (dealt.size()-1)/2;
    std::nth_element(dealt.begin(),dealt.begin()+a,dealt.end());
    int aa= dealt[a];
    std::nth_element(dealt.begin(),dealt.begin()+b,dealt.end());
    int bb = dealt[b];
    this->median = (aa+bb)/2;
}