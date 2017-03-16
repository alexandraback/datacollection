#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cmath>
#define ll long long
#define maxn 1020
using namespace std;
int n,T;
int X[maxn],Y[maxn];
int ans[maxn];
int main()
{
	int T;
//	freopen("D.in","r",stdin);
//	freopen("D.out","w",stdout);
	
	scanf("%d",&T);
	
	for(int ii=1;ii<=T;++ii)
	{
        scanf("%d",&n);
        for(int i=1;i<=n;++i)
        {
            scanf("%d%d",&X[i],&Y[i]);
            ans[i]=n;
        }
        for(int i=1;i<=n;++i)
        {
            for(int j=1;j<=n;++j)
            {
                if(i!=j)
                {
                    int p1,p2;
                    p1=p2=0;
                    for(int k=1;k<=n;++k)
                    {
                        ll x1=X[i]-X[j];
                        ll x2=X[k]-X[j];
                        ll y1=Y[i]-Y[j];
                        ll y2=Y[k]-Y[j];
                        ll si=x1*y2-x2*y1;
                        if(si<0)++p1;
                        if(si>0)++p2;
                    }
                    ans[i]=min(ans[i],min(p1,p2));
                }
            }
        }
        if(n==1)ans[1]=0;
        printf("Case #%d:\n",ii);
        for(int i=1;i<=n;++i)
        {
            printf("%d\n",ans[i]);
        }
	}
	
	return 0;
}
