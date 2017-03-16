#include<bits/stdc++.h>
using namespace std;
int m[1005];
int main()
{
	freopen("A-large.in","r",stdin);
	freopen("A-large.out","w",stdout);
	int T,cse,i,n,f,s,mx;
	scanf("%d",&T);
	for(cse=1;cse<=T;cse++)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++)scanf("%d",&m[i]);
		f=mx=0;
		for(i=2;i<=n;i++)
		{
			if(m[i]<m[i-1]){f+=m[i-1]-m[i];mx=max(mx,m[i-1]-m[i]);}
		}
		s=0;
		for(i=1;i<n;i++)
		{
			if(m[i]>=mx)s+=mx;else s+=m[i];
		}
		printf("Case #%d: %d %d\n",cse,f,s);
	}
	return 0;
}
