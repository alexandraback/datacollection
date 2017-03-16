#include <cstdio>
#include <cstring>
#include <iostream>
#include <cmath>
#include <algorithm>
#define LL long long
using namespace std;
int cas;
LL b,n,a[1005];
LL cnt(LL m){
    LL res = b;
    for(int i=1;i<=b;i++){
        res += m / a[i];
    }
    return res;
}
bool jud(LL m){
    LL res = cnt(m);
    return res<n;
}
LL solve(LL l,LL r){
    LL m;
    while(l+1<r){
    m = (l+r)/2;
    jud(m) ? l = m : r = m;
    }
    return l;
}
int main(){
    freopen("B.in","r",stdin);
    freopen("B.out","w",stdout);
//    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);
    int T;
    long long amx,ti,c,ans;
    scanf("%d",&T);
    while(T--){
        cin>>b>>n;
        amx=0;
        for(int i=1;i<=b;i++){
            cin>>a[i];
            amx=max(amx,a[i]);
        }
        if(n <= b)
            ans = n;
        else{
            c=0;
            ti = solve(0,n*amx+1);
            LL c = cnt(ti);
            for(int i=1;i<=b;i++){
                if((ti+1)%a[i]==0) c++;
                if(c==n){
                    ans=i;
                    break;
                }
            }
        }
        cout<<"Case #"<<++cas<<": "<<ans<<endl;
    }
    return 0;
}

