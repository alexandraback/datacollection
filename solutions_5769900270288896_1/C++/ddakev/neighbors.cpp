#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
long long t,n,m,k;
int main()
{
	freopen("B-large.in","r",stdin);
	freopen("output.txt","w",stdout);
	scanf("%lld",&t);
	for(int o=1; o<=t; o++)
	{
		scanf("%lld%lld%lld",&n,&m,&k);
		if(n==1||m==1)
        {
            if(m==1) swap(n,m);
            if(m%2==1)
            {
                if(k<=m/2+1) {printf("Case #%d: 0\n",o); continue;}
                else
                {
                    int k1=k-m/2-1;
                    int k2=k-m/2;
                    int p1=0,p2=0;
                    if(k2<=2)
                    {
                        p2=k2;
                    }
                    else
                    {
                        p2=2+(k2-2)*2;
                    }
                    p1=k1*2;
                    printf("Case #%d: %d\n",o,min(p1,p2));
                    continue;
                }
            }
            else
            {
                if(k<=m/2) {printf("Case #%d: 0\n",o); continue;}
                else if(k-m/2<=1) {printf("Case #%d: %d\n",o,k-m/2); continue;}
                else {printf("Case #%d: %d\n",o,1+(k-m/2-1)*2); continue;}
            }
        }
        if(n%2!=0&&m%2!=0)
        {
            if(k<=n*m/2+1) {printf("Case #%d: 0\n",o); continue;}
            else
            {
                int k1=k-n*m/2-1;
                int k2=k-n*m/2;
                int p1=0,p2=0;
                if(k2<=4) p2=k2*2;
                else if(k2<=n+m-2)
                {
                    k2-=4;
                    p2=4*2+k2*3;
                }
                else
                {
                    k2-=(n+m-2);
                    p2=4*2+(n+m-6)*3+k2*4;
                }
                if(k1<=n+m-2)
                {
                    p1=k1*3;
                }
                else
                {
                    k1-=(n+m-2);
                    p1=(n+m-2)*3+k1*4;
                }
                printf("Case #%d: %d\n",o,min(p1,p2));
                continue;
            }
        }
        else
        {
            if(k<=n*m/2)
            {
                printf("Case #%d: 0\n",o);
                continue;
            }
            else
            {
                int ans=0;
                k-=n*m/2;
                if(k<=2)
                {
                    ans+=k*2;
                    printf("Case #%d: %d\n",o,ans);
                    continue;
                }
                ans+=2*2;
                k-=2;
                if(k<=n+m-4)
                {
                    ans+=k*3;
                    printf("Case #%d: %d\n",o,ans);
                    continue;
                }
                ans+=(n+m-4)*3;
                k-=n+m-4;
                ans+=k*4;
                printf("Case #%d: %d\n",o,ans);
            }
        }
	}
	return 0;
}
