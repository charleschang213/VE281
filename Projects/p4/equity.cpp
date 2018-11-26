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

void equity::modify(int ts,int val, bool buy){
    if (!buy){
            if (val<minb){
                mintime = ts;
                minb = val;
            }
    }
    else {
            if (mintime!=-1&&val-minb > maxv){
                btime = mintime;
                stime = ts;
                maxv = val-minb;
            
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