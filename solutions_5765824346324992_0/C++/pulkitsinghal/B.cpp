#include <bits/stdc++.h>
using namespace std;

#define MAXN 1010
#define INF 10000000000000000LL
long long A[MAXN];

int main()
{
	int t,n,req;
	scanf("%d",&t);
	for(int test=1;test<=t;++test)
	{
		scanf("%d%d",&n,&req);
		for(int i=0;i<n;++i)
			scanf("%lld",A+i);
		long long lo = 0, hi = INF, m, done;
		while(lo<hi)
		{
			done = 0;
			m = (lo+hi)/2;
			for(int i=0;i<n;++i)
			{
				done += m/A[i];
				if(m%A[i]!=0)
					++done;
			}
			if(done>=req)
				hi = m;
			else
				lo = m+1;
		}
		done = 0;
		vector<int> freeBarbers;
		for(int i=0;i<n;++i)
		{
			if((lo-1)%A[i]==0)
			{
				done += (lo-1)/A[i];
				freeBarbers.push_back(i);
			}
			else
			{
				done += (lo-1)/A[i] + 1;
			}
		}
		req -= done;
		printf("Case #%d: %d\n",test,freeBarbers[req-1]+1);
	}
	return 0;
}
