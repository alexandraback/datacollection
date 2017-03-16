#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int T,ans=0x7FFFFFFF;
int m[20005],N;
int MAXN;
int counter=0;
int main()
{
	freopen("xx.in","r",stdin);
	freopen("xx.out","w",stdout);
	int i;
	scanf("%d",&T);
	while(T--)
	{
		counter++;ans=0;MAXN=0;
		scanf("%d",&N);
		for(i=1;i<=N;i++)
			scanf("%d",&m[i]);
		for(i=2;i<=N;i++)
		{
			if(m[i]<m[i-1])
				ans+=(m[i-1]-m[i]);
			if(m[i-1]-m[i]>MAXN)
				MAXN=m[i-1]-m[i];
		}
		printf("Case #%d: %d ",counter,ans);
		ans=0;
		for(i=1;i<N;i++)
		{
			if(m[i]<MAXN)
				ans+=m[i];
			else
				ans+=MAXN;
		}
		printf("%d\n",ans);
	}
	return 0;
}
