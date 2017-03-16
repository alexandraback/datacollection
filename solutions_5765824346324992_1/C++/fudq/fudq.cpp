#include<stdio.h>
#include<iostream>
#include<string>
#include<string.h>
#include<algorithm>
#include<iomanip>
#include<vector>
#include<time.h>
#include<queue>
#include<stack>
#include<iterator>
#include<math.h>
#include<stdlib.h>
#include<limits.h>
#include<set>
#include<map>
using namespace std;
typedef long long ll;
const int maxn=1e3+10;
int T,n,m,cas=1;
int a[maxn];
ll calc(ll M)
{
    ll ret=0;
    for (int i=1;i<=n;i++) ret+=M/a[i];
    return ret;
}
int main()
{
    freopen("testin.txt","r",stdin);
    freopen("testout.txt","w",stdout);
    scanf("%d",&T);
    while (T--)
    {
        scanf("%d%d",&n,&m);
        for (int i=1;i<=n;i++) scanf("%d",&a[i]);
        int ans;
        if (m<=n) ans=m;
        else
        {
            m-=n;
            ll L=0,R=1ll<<60,M,p;
            while (L<=R)
            {
                M=(L+R)>>1;
                if (calc(M)>=m) R=M-1,p=M;
                else L=M+1;
            }
            ll tmp=calc(p);
            for (int i=n;i;i--) if (p%a[i]==0)
            {
                if (tmp==m) {ans=i;break;}
                tmp--;
            }
        }
        printf("Case #%d: %d\n",cas++,ans);
    }
    return 0;
}
