#include<bits/stdc++.h>
using namespace std;
int m[10005];
main()
{
	freopen("A-small-attempt0.in","r",stdin);
	freopen("out-A-small.txt","w",stdout);
	int a,b,c,d,e,ans1,ans2;
	scanf("%d",&a);
	for(b=0;b<a;b++)
	{
		scanf("%d",&c);
		ans1=0;
		ans2=0;
		e=0;
		for(d=0;d<c;d++)
		{
			scanf("%d",&m[d]);
		}
		for(d=0;d<c-1;d++)
		{
			if(m[d]>m[d+1])
			{
				ans1+=m[d]-m[d+1];
				e=max(e,m[d]-m[d+1]);
			}
		}
		for(d=0;d<c-1;d++)
		{
			if(m[d]<e)ans2+=m[d];
			else ans2+=e;
		}
		printf("Case #%d: %d %d\n",b+1,ans1,ans2);
	}
}
