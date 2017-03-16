#include <bits/stdc++.h>
#define maxn 10009
using namespace std;
int n,m,a[maxn];
int main()
{
	int tt,cot=1;
	freopen("B.in","r",stdin);
	freopen("B.out","w",stdout);
	scanf("%d",&tt);
	while(tt--)
	{
		scanf("%d%d",&m,&n);
		for(int i=1;i<=m;i++)
			scanf("%d",&a[i]);
		long long L=0,R=1e18;
		while(L<R)
		{
			long long M=(L+R)>>1;
			long long cnt=0;
			bool ok=0;
			for(int i=1;i<=m;i++)
			{
				cnt+=M/a[i]+1;
				if(cnt>=n)
				{
					ok=1;
					break;
				}
			}
			if(ok)
				R=M;
			else
				L=M+1;
		}
		int last=0;
		if(R-1>=0)
		{
			for(int i=1;i<=m;i++)
				last+=(R-1)/a[i]+1;
		}
		int ans=1;
		last=n-last;
		for(int i=1;i<=m;i++)
		{
			if(R%a[i]==0)
			{
				last--;
				if(last==0)
				{
					ans=i;
					break;
				}
			}
		}
		printf("Case #%d: %d\n",cot++,ans);
	}
	//system("pause");
	return 0;
}