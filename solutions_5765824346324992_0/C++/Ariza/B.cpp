#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define EPS (1e-10)
#define lef(x) (x<<1)
#define rig(x) (x<<1)+1
#define PI (2*acos(0.0))
int barber[1005];
long long gcd(long long x, long long y){
     if (y==0LL) return x;
     return gcd(y,x%y);
}
void solve(){
     printf(" ");
     long long b,n;
     scanf("%I64d %I64d",&b,&n);
     for (int i=0;i<b;++i){
         scanf("%d",&barber[i]);
     }
     long long kpk = barber[0];
     long long fpb = barber[0];
     for (int i=1;i<b;++i){
         fpb = gcd(fpb,1LL*barber[i]);
         kpk = kpk * barber[i];
         if (kpk>fpb)
            kpk /= fpb;
     }
     
     long long tot = 0LL;
     for (int i=0;i<b;++i){
         tot += (kpk/barber[i]);
     }
     
     n%=tot;
     if (n==0) n=tot;
     
     priority_queue<pair<long long, int >, vector<pair<long long, int> > , greater<pair<long long, int> >  > pq;
     for (int i=0;i<b;++i){
         pq.push(mp(0, i));
     }
     
     while (n>0){
           n--;
           pair<long long,int> top = pq.top();
           pq.pop();
           //cout << "INQ " << top.second << endl;
           if (n==0){
              printf("%d\n",top.second+1);
              return;
           }
           top.first+=barber[top.second];
           pq.push(top);
     }
}
int main(){
    int ntest;
    scanf("%d",&ntest);
    for (int test=1;test<=ntest;++test){
        printf("Case #%d:",test);
        solve();
    }
    return 0;
}
