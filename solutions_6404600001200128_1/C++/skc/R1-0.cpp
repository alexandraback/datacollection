#include "stdio.h"

#if 1

#define F	"A-large"
#ifndef F
#define TEST	1
#define F	"A"
#endif

#define P	printf

#define N	1000

int s[N+1];

int main(void)
{
	freopen("IO/"F".in","r",stdin);
#ifndef TEST
	freopen("IO/"F".out.txt","w",stdout);
#endif
	int t,tst;
	scanf("%d", &tst);
	for(t=1 ; t<=tst ; ++t)
	{
		long long n,i,j,c,m,sum;
		scanf("%d", &n);

		for(i=0 ; i<n ; ++i)
			scanf("%d", &s[i]);

		m = 0;
		j = 0;
		for(i=1 ; i<n ; ++i)
		{
			if(s[i-1] > s[i])
			{
				c = s[i-1] - s[i];
				j += c;
				if(c > m)
					m = c;
			}
		}
#if 1
		c = 0;
		sum = 0;
		for(i=0 ; i<n-1 ; ++i)
		{
			if(sum < s[i])
				sum = s[i];
			long long v = (sum < m) ? sum : m;
			sum -= v;
			c += v;
		}
#endif
		//c -= s[n-1];
#ifdef TEST
		P("Case #%d: %lld %d --> %d\n",t,j,c, m);
#else
		P("Case #%d: %lld %lld\n",t,j,c);
#endif
	}
	return 0;
}
#endif
