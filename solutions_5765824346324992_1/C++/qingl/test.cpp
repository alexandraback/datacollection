#include<cstdio>
#include<cstring>
#include<string>
#include<map>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
const int N = 2005;
const int MOD = 100007;
int a[N];
int main()
{
	freopen("B-large.in","r",stdin);
	freopen("out.txt","w",stdout);
	int T,ca=1;
	scanf("%d",&T);
	while(T--)
	{
		printf("Case #%d: ",ca++);
		int m,n;
		scanf("%d%d",&m,&n);
		for(int i=0;i<m;i++)scanf("%d",&a[i]);
		if(n<=m)
		{
			printf("%d\n",n);
			continue;
		}
		ll low=0,high=1e15,mid;
	//	printf("high:%I64d \n",high);
		while(low<high-1)
		{
			mid=(low+high)/2;
			ll tot=0;
			for(int i=0;i<m;i++)
			{
				tot+=mid/a[i]+1;
			}
			if(tot>=n)high=mid;
			else low=mid;
		}
		ll tot=0;
		for(int i=0;i<m;i++)tot+=(high-1)/a[i]+1;
	//	printf("high:%I64d \n",high);
		int ret;
		for(int i=0;i<m;i++)if(high%a[i]==0)
		{
			tot++;
			if(tot>=n)
			{
				ret=i+1;
				break;
			}
		}
		printf("%d\n",ret);
	}
   return 0;
}
