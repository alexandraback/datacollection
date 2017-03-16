#include <stdio.h>
#include <algorithm>
using namespace std;

typedef long long ll;

#define MAXN 1005

int cas, tc;
int n, k, a[MAXN];

struct node{
	ll x, y;
	bool operator<(const node&b) const{
		return x > b.x || x == b.x && y > b.y;
	}
}b[MAXN];

ll l, r, mid, sum, t, cnt;

int main()
{
	freopen("B.in", "r", stdin); freopen("B.out", "w", stdout);
	scanf("%d", &cas);
	for (tc = 1; tc <= cas; tc ++)
	{
		scanf("%d%d", &n, &k);
		for (int i = 1; i <= n; i ++) scanf("%d", &a[i]);
		l = 1, r = 1ll << 60;
		while (l <= r)
		{
			mid = (l + r) >> 1;
			sum = 0;
			for (int i = 1; i <= n; i ++)
				if (mid % a[i] == 0)
					sum += mid / a[i];
				else
					sum += mid / a[i] + 1;
			if (sum >= k)
			{
				t = mid;
				cnt = sum;
				r = mid - 1;
			} else
				l = mid + 1;
		}
		cnt = cnt - k + 1; //printf("%lld\n", cnt);
		for (int i = 1; i <= n; i ++)
			if (t % a[i] == 0)
				b[i] = (node){(t / a[i] - 1) * a[i] + 1, i};
			else
				b[i] = (node){(t / a[i]) * a[i] + 1, i};
		sort(b + 1, b + n + 1);
		printf("Case #%d: %d\n", tc, b[cnt].y);
	}
	return 0;	
}
