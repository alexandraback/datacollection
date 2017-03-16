#include<bits/stdc++.h>
#define mp make_pair
#define X first
#define Y second
using namespace std;
main()
{
	freopen("B-small-attempt1.in","r",stdin);
	freopen("out-B-small.txt","w",stdout);
	long long a,b,c,d,e,f,g,m[1100],st,ed,mid;
	set<pair<long long,long long> > x;
	scanf("%I64d",&a);
	for(b=0;b<a;b++)
	{
		scanf("%I64d %I64d",&c,&d);
		for(e=0;e<c;e++)
		{
			scanf("%I64d",&m[e]);
		}
		st=0;
		ed=100000000000010;
		while(st!=ed)
		{
			mid=(st+ed)/2+1;
			e=0;
			for(f=0;f<c;f++)
			{
				e+=mid/m[f];
				if(mid%m[f]!=0)e++;
			}
			if(e>=d)ed=mid-1;
			else st=mid;
		}
		f=0;
		for(e=0;e<c;e++)
		{
			if(st%m[e]!=0)x.insert(mp(m[e]-(st%m[e]),e));
			else x.insert(mp(0,e));
			f+=st/m[e];
			if(st%m[e]!=0)f++;
		}
		d-=f;
		//printf("[%I64d %I64d %I64d]",st,d,f);
		while(d--)
		{
			g=(*x.begin()).Y;
			x.erase(x.begin());
			x.insert(mp(m[g],g));
		}
		x.clear();
		printf("Case #%I64d: %I64d\n",b+1,g+1);
	}
}
