#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <assert.h>

using namespace std;

typedef long long ll;

int M[1111];

ll servicedCount(ll t,int B)
{
	ll ans = 0;
	for(int i = 0;i < B;i++) ans += (t+M[i])/M[i];
	return ans;
}

int main(void)
{
	int T = 0;
	int TK = 0;
	scanf("%d",&T);
	while(T--)
	{	
		int B = 0;
		int N = 0;
		scanf("%d %d",&B,&N);
		for(int i = 0;i < B;i++) scanf("%d",&M[i]);

		ll l = 0;
		ll r = 1000000000000000000LL;
		while(l < r)
		{
			ll mid = (l+r)/2;
			if(servicedCount(mid, B) < N) l = mid+1;
			else r = mid;
		}

		int who = -1;
		ll ser = 0;
		ll more = N-servicedCount(l-1, B);
		for(int i = 0;i < B;i++)
		{
			if(l % M[i] == 0)
			{
				if(!--more)
				{
					who = i;
					break;
				}
			}
		}

		printf("Case #%d: ", ++TK);
		printf("%d\n",who+1);
	}
	return 0;
}
