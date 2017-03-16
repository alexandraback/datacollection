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

int main()
{
	int t;
	cin >> t;
	for (int cs = 1; cs <= t; cs++)
	{
		printf("Case #%d: ", cs);
		int n,x;
		cin >> n >>x;
		vector<int> a;
		while (n--)
		{
			int t;
			scanf("%d", &t);
			a.push_back(t);
		}

		n = a.size();
		int g = 1;
		for (int i = 0; i < n; i++)
			g = lcm(g,a[i]);

		int p = 0;
		for (int i : a) p += g / i;
		x %= p;

		if (x == 0) x = p;
		vector < pair <int, int>> Q;

		for (int i = 0; i < n; i++)
			for (int j = 0; j < g / a[i]; j++)
			{
				Q.push_back(make_pair(a[i]*j, i+1 ));
			}
		sort(Q.begin(), Q.end());
		cout << Q[x - 1].second << endl;
		cerr << Q[x - 1].second << endl;
	}


	return 0;
}