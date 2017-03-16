#include <cstdio>
#include <cstring>
#include <algorithm>

int M[1100];

int main()
{
	int T;
	scanf("%d", &T);
	for(int cas = 1; cas <= T; ++cas)
	{
		int b, n;
		scanf("%d%d", &b, &n);
		for(int i = 1; i <= b; ++i)
			scanf("%d", M + i);
		long long l = 0, r = 1LL << 60;
		while(l <= r)
		{
			long long mid = (l + r) / 2;
			long long cnt = 0;
			for(int i = 1; i <= b; ++i)
			{
				cnt += mid / M[i];
				if(mid % M[i]) cnt++;
			}
			if(cnt >= n)
				r = mid - 1;
			else
				l = mid + 1;
		}
		int ans = 0;
		long long cnt = 0;
		for(int i = 1; i <= b; ++i)
		{
			cnt += r / M[i];
			if(r % M[i]) cnt++;
		}
		for(int i = 1; i <= b; ++i)
		{
			if((r) % M[i] == 0)
			{
				cnt++;
				if(cnt == n)
				{
					ans = i;
					break;
				}
			}
		}
		printf("Case #%d: %d\n", cas, ans);
	}
	return 0;
}
