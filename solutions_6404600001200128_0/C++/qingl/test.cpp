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
	freopen("A-small-attempt0.in","r",stdin);
	freopen("out.txt","w",stdout);
	int T,ca=1;
	scanf("%d",&T);
	while(T--)
	{
		printf("Case #%d: ",ca++);
		int n;
		scanf("%d",&n);
		int r1=0,r2=0,mx=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			if(i>1&&a[i]<a[i-1])
			{
				r1+=a[i-1]-a[i];
				if(mx<a[i-1]-a[i])mx=a[i-1]-a[i];
			}
		}
		for(int i=1;i<n;i++)
		{
			if(a[i]>=mx)r2+=mx;
			else r2+=a[i];
		}
		printf("%d %d\n",r1,r2);
	}
   return 0;
}
