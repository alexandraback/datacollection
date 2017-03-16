#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;
typedef long long ll;
const int maxn=1e3+10;
int T,n,m,cas=1;
int save[maxn];
ll f(ll x)
{
    ll ret=0;
    for (int i=1;i<=n;i++) ret+=x/save[i];
    return ret;
}
int main()
{
    freopen("bbbbb.in","r",stdin);
    freopen("out.txt","w",stdout);
    scanf("%d",&T);
    while (T--)
    {
        scanf("%d%d",&n,&m);
        for (int i=1;i<=n;i++) scanf("%d",&save[i]);
        int ans=0;
        if (m<=n) ans=m;
        else
        {
            m-=n;
            ll L=0,R=1ll<<60,M,p;
            while (L<=R)
            {
                M=(L+R)>>1;
                if (f(M)>=m) R=M-1,p=M;
                else L=M+1;
            }
            ll tmp=f(p);
            for (int i=n;i;i--) if (p%save[i]==0)
            {
                if (tmp==m) {ans=i;break;}
                tmp--;
            }
        }
        printf("Case #%d: %d\n",cas++,ans);
    }
    return 0;
}
