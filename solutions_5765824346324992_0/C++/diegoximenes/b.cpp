#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define MAX 1005

ll v[MAX];

int main()
{
	int t, n, b;
	
	scanf("%d", &t);
	for(int tc=1; tc<=t; ++tc)
	{
		scanf("%d %d", &b, &n);
		for(int i=0; i<b; ++i) scanf("%lld", &v[i]);
		
		int sol = -1;
			
		if(n <= b) sol = n;
		else
		{
			ll l = 0, r = 1000000000000000LL, mid, last;
			while(l <= r)
			{
				mid = (l+r)/2;
				
				ll cnt = 0;
				for(int i=0; i<b; ++i) cnt += mid/v[i] + 1;

				if(cnt < n-1) l = mid + 1;
				else if(cnt >= n-1) last = mid, r = mid - 1;
			}
					
			ll cnt = 0;
			for(int i=0; i<b; ++i) cnt += last/v[i] + 1;
			
			//printf("last = %lld\n", last);
			//printf("cnt = %lld\n", cnt);

			if(cnt == n-1)
			{
				ll minEnd = INFLL;
				for(int i=0; i<b; ++i)
				{
					ll end = (last/v[i] + 1) * v[i];
					if(end < minEnd)
					{
						minEnd = end;
						sol = i+1;
					}
				}
			}
			else //cnt > n-1
			{
				ll aux = 0;
				for(int i=0; i<b; ++i) aux += 1 + last/v[i] - (last%v[i] == 0);
				for(int i=0; i<b; ++i)
				{
					if(last % v[i] == 0) aux++;
					if(aux == n)
					{
						sol = i+1;
						break;
					}
				}
			}
		}

		printf("Case #%d: %d\n", tc, sol);
	}

	return 0;
}
