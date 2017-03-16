#include <bits/stdc++.h>
using namespace std;

#define MAXN 1010
int A[MAXN];

int main()
{
	int t,n;
	scanf("%d",&t);
	for(int test=1;test<=t;++test)
	{
		scanf("%d",&n);
		for(int i=0;i<n;++i)
			scanf("%d",A+i);
		int first = 0;
		for(int i=0;i<n-1;++i)
			if(A[i+1]>=A[i])
				continue;
			else
				first += A[i]-A[i+1];
		int lo = 0, hi = MAXN*MAXN, m;
		while(lo<hi)
		{
			m = (lo+hi)/2;
			int cur = 0 , i;
			for(i=0;i<n;++i)
			{
				if(cur>A[i])
					break;
				cur = A[i];
				if(cur<m)
					cur = 0;
				else
					cur -= m;
			}
			if(i==n)
				hi = m;
			else
				lo = m+1; 
		}
		int second = 0, cur;
		for(int i=0;i<n-1;++i)
			{
				cur = A[i];
				if(cur<lo)
					second += A[i];
				else
					second += lo;
			}
		printf("Case #%d: %d %d\n",test,first,second);
	}
	return 0;
}
