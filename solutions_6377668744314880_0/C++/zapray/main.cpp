#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <climits>

using namespace std;
typedef long long ll;


int gcd(int a, int b)
{
	for (;;)
	{
		if (a == 0) return b;
		b %= a;
		if (b == 0) return a;
		a %= b;
	}
}

int lcm(int a, int b)
{
	int temp = gcd(a, b);

	return temp ? (a / temp * b) : 0;
}

ll cross(ll x1, ll y1, ll x2, ll y2)
{
	return x1*y2 - x2*y1;
}


int main()
{
	int t;
	cin >> t;
	for (int cs = 1; cs <= t; cs++)
	{
		printf("Case #%d:\n", cs);
		ll n;
		cin >> n;
		vector<pair<int, int> > p;

		for (int i = 0; i < n; i++)
		{
			int x, y;
			scanf("%d%d",&x,&y);
			p.push_back(make_pair(x,y));
		}

		vector<int> ans(n,n);
		for (int i = 0; i < n; i++)
			for (int j = i + 1; j < n; j++)
			{
				int a=0, b=0;


				for (int k = 0; k < n; k++)
				{
					if (k != i && k != j)
					{
						ll c = cross(p[k].first - p[i].first, p[k].second - p[i].second,
							p[j].first - p[i].first, p[j].second - p[i].second);
						if (c > 0) a++;
						if (c < 0) b++;
					}
				}

				ans[i] = min(ans[i], min(a, b));
				ans[j] = min(ans[j], min(a, b));
			}
		for (int i = 0; i < n; i++)
			cout << ans[i] << endl;
	}


	return 0;
}