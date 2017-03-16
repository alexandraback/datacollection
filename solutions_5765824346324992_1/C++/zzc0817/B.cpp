#include <stdio.h>
#include <assert.h>

int nums[2000];
int b, n;

// number of service started <= t
long long cnt_before(long long t)
{
	long long ret = 0;
	for(int i = 0; i < b; ++i)
		ret += (t + nums[i] - 1) / nums[i];
	return ret;
}


int main()
{
	int T;
	scanf("%d", &T);
	for(int ca = 1; ca <= T; ++ca)
	{
		scanf("%d %d", &b, &n);
		for(int i = 0; i < b; ++i)
			scanf("%d", nums + i);
		// when n-th get cut
		// first minute that cnt >= n
		long long t1 = 1, t2 = 1000000000000LL;
		//printf("%lld\n", t2);
		while(t1 < t2)
		{
			long long tmid = (t1 + t2) / 2;
			long long cnt = cnt_before(tmid);
			//printf("#%d %d %d->%d\n", t1, t2, tmid, cnt);
			if(cnt < n)
			{
				t1 = tmid + 1;
			}
			else
			{
				t2 = tmid;
			}
		}
		assert(t1 == t2);
		--t1;
		long long c1 = cnt_before(t1);
		//printf("#%d %d %d\n", t1, t2, c1);
		n -= c1;
		int choice = -1;
		//printf("#%d\n", n);
		for(int i = 0; i < b; ++i)
		{
			if(t1 % nums[i] == 0)
			{
				if(--n == 0)
				{
					choice = i + 1;
					break;
				}
			}
		}
		assert(choice != -1);
		printf("Case #%d: %d\n", ca, choice);
	}
}
