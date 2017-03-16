#include<cstdio>
#include<cstring>
#include<cmath>
#include<string>
#include<algorithm>
#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<stack>

#define msn(x) (memset((x),0,sizeof((x))))
#define msx(x) (memset((x),0x7f,sizeof((x))))
#define fuck(x) cerr << #x << " <- " << x << endl
#define acer cout<<"sb"<<endl
typedef long long ll;
using namespace std;
#define inf 0x3f3f3f3f
#define eps 1e-8
#define pi acos(-1.0)
const int maxn=1e3+7;
int n;
ll p[maxn];

ll sol1()
{
    ll d=0;
    for(int i=1;i<n;i++)
    {
        if(p[i-1]>p[i])d+=p[i-1]-p[i];
    }
    return d;
}

ll sol2()
{
    ll d=0;
    for(int i=1; i<n; i++)
    {
        d=max(p[i-1]-p[i],d);
    }
    ll re=0;
    for(int i=1;i<n;i++)
    {
        re+=min(p[i-1],d);
    }
    return re;
}
int main()
{
    int T;
    freopen("A-small-attempt0.in","r",stdin);
    freopen("A.out","w",stdout);
    scanf("%d",&T);
    for(int cas=1; cas<=T; cas++)
    {
        scanf("%d",&n);
        for(int i=0; i<n; i++)
        {
            scanf("%d",&p[i]);
        }
        printf("Case #%d: %lld %lld\n",cas,sol1(),sol2());
    }
    return 0;
}
