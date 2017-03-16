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


  int gcd(int x , int y)
{
    return y == 0 ? x : gcd(y , x%y);
}

struct node
{
    ll t;
    int id;
    bool operator<(const node a)const{
            if(t==a.t)return id>a.id;
            else return  t>a.t;
	}
};
int n,m;
int p[1111];
ll check(ll x)
{
    ll sb=0;
    for(int i=0;i<n;i++)
    {
        sb+=x/p[i];
    }
    return sb;
}
int work()
{
    if(m<=n)
    {
        return m;
    }
    ll l=0,r=100000000000000LL;
    m-=n;
    while(l<r)
    {
        ll mid=(l+r)/2+1;
        if(check(mid)<m)l=mid;
        else r=mid-1;
    }
    ll f=check(l);
  //  fuck(l);
    m-=f;
  //  fuck(m);
    for(int i=0;i<n;i++)
    {
        if((l+1)%p[i]==0)m--;
        if(m==0)return i+1;
    }
}
int main()
{
    int T;
    freopen("B-large.in","r",stdin);
    freopen("BB.out","w",stdout);
    scanf("%d",&T);
    for(int cas=1;cas<=T;cas++)
    {
        scanf("%d%d",&n,&m);
        for(int i=0;i<n;i++)
        {
            scanf("%d",&p[i]);
        }
      //  fuck(check(6250000000001LL));
        printf("Case #%d: %d\n",cas,work());
    }
    return 0;
}
