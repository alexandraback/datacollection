#include <cstdio>
#include <iostream>
using namespace std;
int m[1001],n;
int main()
{
	int T;
	int cnt,ans,ma,cal;
	freopen("A-large.in","r",stdin);
	freopen("A.out","w",stdout);
	scanf("%d",&T);
	for(int j=1;j<=T;j++)
	{
		scanf("%d",&n);
		for(int i=0;i<n;i++)
			scanf("%d",m+i);
		cnt=0;ma=0;ans=0;
		for(int i=1;i<n;i++)
		{
			cal=m[i-1]-m[i];
			if(cal>0) cnt+=cal;
			if(cal>ma) ma=cal;
		}
		for(int i=0;i<n-1;i++)
			ans+=ma>m[i]?m[i]:ma;
		printf("Case #%d: %d %d\n",j,cnt,ans);
	}
	return 0;
}
