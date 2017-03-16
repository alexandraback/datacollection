#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <algorithm>
typedef long long LL;
using namespace std;

class node{
public:
    LL tim,barber;
    node(LL x1,LL x2){
        tim=x1,barber=x2;
    }
    bool operator < (const node Nd) const {
        if (tim<Nd.tim) return true;
        if (tim>Nd.tim) return false;
        return barber<Nd.barber;
    }
};

LL b,n,T;
LL m[1111];
int cas=0;
vector<node> V;

LL getint(LL mid){
    LL tmp=0;
    for (int i=1; i<=b; i++){
        tmp+=(mid+m[i]-1)/m[i];
        //if (mid%m[i]==0) tmp++;
    }
    return tmp;
}

int main(){
    freopen("B-small-attempt0.in","rb",stdin);
    freopen("data.out","wb",stdout);
    scanf("%I64d",&T);
    while (T--){
        scanf("%I64d%I64d",&b,&n);
        for (int i=1; i<=b; i++)
            scanf("%I64d",&m[i]);
        LL L=0,R=1LL<<45,mid;
        while (L<R){
            mid=(L+R)>>1;
            if (getint(mid)>=n) R=mid;
                else L=mid+1;
        }

        //cout<<" here L = "<<L<<endl;

        V.clear();
        for (int i=1; i<=n; i++){
            n-=(L-1)/m[i];
            V.push_back(node((L-1)/m[i]*m[i]+1,i));
        }
        sort(V.begin(),V.end());
        printf("Case #%d: %I64d\n",++cas,V[n-1].barber);
    }
    return 0;
}
