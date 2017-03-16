#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#define maxn 1010
using namespace std;
typedef long long LL;
int n,m,a[maxn];
void read()
{
	scanf("%d %d",&m,&n);
	for(int i=1;i<=m;++i)
		scanf("%d",a+i);
}
LL calc(LL x)
{
	LL ans=0;
	for(int i=1;i<=m;++i)
		ans=min((LL)n,ans+(x-1+a[i])/a[i]);
	return ans;
}
int binary(LL l,LL r)
{
	while(l<r)
	{
		LL mid=(l+r)>>1;
		calc(mid)<n?l=mid+1:r=mid;
	}
	n-=calc(l-1);
	for(int i=1;i<=m;++i)
		if((l-1)%a[i]==0&&--n==0)
			return i;
}
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int T,C=0;
	for(cin>>T;T;--T)
	{
		read();
		printf("Case #%d: %d\n",++C,n<=m?n:binary(1,1000000000000000000LL));
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
