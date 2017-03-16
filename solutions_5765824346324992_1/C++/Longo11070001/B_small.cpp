#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#define pb push_back
using namespace std;
typedef long long ll;
const int maxn = 1010;
int B;
ll N;
ll M[maxn];
struct Hair{
    int id;
    ll t;
    bool operator < (const Hair &o) const
    {
        if(t != o.t) return t<o.t;
        return id<o.id;
    }
}hairs[maxn*maxn];
ll gcd(ll a,ll b)
{
    while(a && b)
    {
        if(a >= b) a%= b;
        else b%=a;
    }
    return a+b;
}
int main()
{
    freopen("B-small-attempt0.in","r",stdin);
    freopen("B-small-attempt0.out","w",stdout);
    int T,cas,i,j,x;
    ll g;
    scanf("%d",&T);
    for(cas=1; cas<=T; cas++)
    {
        scanf("%d%lld",&B,&N); N--;
        g = 1;
        for(i=0; i<B; i++)
        {
            scanf("%lld",&M[i]);
            g=g*M[i]/gcd(g,M[i]);
        }
        x = 0;
        for(i=0; i<B; i++)
        {
            for(j=0; j<g/M[i]; j++)
            {
                hairs[x].id = i; hairs[x].t = 1LL*j*M[i];
                x++;
            }
        }
        sort(hairs,hairs+x);
        N %= x;
        printf("Case #%d: %lld\n",cas,hairs[N].id+1);
    }
    return 0;
}
