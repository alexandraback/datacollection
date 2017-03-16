#include <iostream>
#include <cstdio>
using namespace std;

typedef long long s64;

const s64 INF = 1000000000000000000;

const int MaxM = 1000;

template <class T>
inline void tension(T &a, const T &b)
{
	if (b < a)
		a = b;
}

int n, m;
int a[MaxM + 1];

int main()
{
	int nT;
	cin >> nT;

	for (int t = 1; t <= nT; t++)
	{

		cin >> m >> n;
		for (int i = 1; i <= m; i++)
			cin >> a[i];

		s64 le = 0, ri = n * 1000000ll;
		while (le != ri)
		{
			s64 mi = (le + ri) / 2;

			s64 al = 0;
			for (int k = 1; k <= m; k++)
				al += mi / a[k] + 1;
			if (al < n)
				le = mi + 1;
			else
				ri = mi;
		}

		int nr = 0;
		for (int k = 1; k <= m; k++)
			nr += le / a[k] + 1 - (le % a[k] == 0);
		for (int k = 1; k <= m; k++)
			if (le % a[k] == 0)
			{
				nr++;
				if (nr == n)
					printf("Case #%d: %d\n", t, k);
			}
	}

	return 0;
}
