#include <bits/stdc++.h>

#define For(i, a, b) for(int i=(a); i<(b); ++i)
#define INF 1000000000
#define MP make_pair

using namespace std;

typedef long long ll;
typedef pair <int, int> ii;

int barb[1005];

int main()
{
	//std::ios_base::sync_with_stdio(false);

	int tt, caso = 1;
	scanf("%d", &tt);

	while (tt--)
	{
		int B;
		ll n;
		scanf("%d %lld", &B, &n);
		For(i, 0, B)
			scanf("%d", &barb[i]);

		ll a = 0, b = 1000000000000000LL, sec;
		while (a <= b)
		{
			ll m = (a + b) >> 1;
			ll p = 0;

			For(i, 0, B)
				p += m/barb[i] + 1;

			if (p >= n)
				sec = m, b = m - 1;
			else
				a = m + 1;
		}

		//cout << sec << endl;
		ll pant = 0;
		For(i, 0, B)
			pant += (sec-1)/barb[i] + 1;

		int ans;
		For(i, 0, B)
		{
			if (sec % barb[i] == 0)
				pant++;

			if (pant == n)
			{
				ans = i+1;
				break;
			}
		}

		printf("Case #%d: %d\n", caso++, ans);
	}

	return 0;
}