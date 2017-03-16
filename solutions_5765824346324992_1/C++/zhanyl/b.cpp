#include <vector>
#include <list>
#include <queue>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <tr1/unordered_set>
#include <tr1/unordered_map>

using namespace std;
using namespace tr1;

const int maxn=1005;
const long long inf=(long long)1e18+10;

int n,m;
int f[maxn];
priority_queue<pair<long long,int> > Q;

long long check_cut(long long t){
    long long ans=0;
    for(int i=1;i<=n;i++){
        ans+=t/f[i]+1;
        if(ans>inf)return ans;
    }
    return ans;
}

int main(){
    string str_in,str_out;
    cin>>str_in>>str_out;
    freopen(str_in.c_str(),"r",stdin);
    freopen(str_out.c_str(),"w",stdout);
    int T;
    scanf("%d",&T);
    for(int Cas=1;Cas<=T;Cas++){
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++)
            scanf("%d",&f[i]);
        long long l=0,r=inf,mid;
        while(l<r){
            mid=(l+r)/2;
            if(check_cut(mid)>=m)r=mid;
            else l=mid+1;
        }
        int ans=-1;
        long long now=check_cut(l-1);
        //printf("%I64d(%I64d %I64d)\n",l-1,now,check_cut(l));
        while(!Q.empty())Q.pop();
        for(int i=1;i<=n;i++){
            Q.push(make_pair(-((l-1)/f[i]*f[i]+f[i]),-i));
            //("%I64d,%d\n",(l-1)/f[i]*f[i]+f[i],i);
        }
        pair<long long,int> p;
        while(now<m){
            p=Q.top();
            //printf("(%I64d,%d)\n",-p.first,-p.second);
            Q.pop();
            now++;
            if(now==m)ans=-p.second;
            p.first-=f[-p.second];
            Q.push(p);
        }
        if(m==1)ans=1;
        printf("Case #%d: %d\n",Cas,ans);
    }
    return 0;
}
