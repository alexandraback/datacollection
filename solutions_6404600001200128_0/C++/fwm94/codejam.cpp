#include <bits/stdc++.h>
#define maxn 10009
using namespace std;
int n,a[maxn];
int main()
{
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
	int tt,cot=1;
	scanf("%d",&tt);
	while(tt--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		int ans1=0,ans2=0,mx=0;
		for(int i=2;i<=n;i++)
		{
			if(a[i]<a[i-1])
			{
				ans1+=a[i-1]-a[i];
				mx=max(mx,a[i-1]-a[i]);
			}
		}
		for(int i=1;i<n;i++)
		{
			ans2+=min(mx,a[i]);
		}
		printf("Case #%d: %d %d\n",cot++,ans1,ans2);
	}
	//system("pause");
	return 0;
}