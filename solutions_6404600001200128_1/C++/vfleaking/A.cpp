#include <iostream>
#include <cstdio>
using namespace std;

const int MaxN = 1000;

template <class T>
inline void relax(T &a, const T &b)
{
	if (b > a)
		a = b;
}

int main()
{
	int nT;
	cin >> nT;
	for (int t = 1; t <= nT; t++)
	{
		int n;
		static int a[MaxN + 1];
		
		cin >> n;
		for (int i = 1; i <= n; i++)
			cin >> a[i];

		int resA = 0, resB = 0;
		for (int i = 1; i <= n; i++)
			resA += max(a[i] - a[i - 1], 0);
		resA -= a[n];

		int r = 0;
		for (int i = 2; i <= n; i++)
			if (a[i] <= a[i - 1])
				relax(r, a[i - 1] - a[i]);
		resB = a[1];
		for (int i = 2; i <= n; i++)
			resB += a[i] - max(a[i - 1] - r, 0);
		resB -= a[n];

		printf("Case #%d: %d %d\n", t, resA, resB);
	}
	
	return 0;
}
