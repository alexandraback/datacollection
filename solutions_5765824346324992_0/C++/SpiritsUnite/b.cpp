#include <bits/stdc++.h>

using namespace std;

int m[1024], b;
long long n;

long long f(long long t)
{
	long long sum = 0;
	for (int i = 0; i < b; i++)
	{
		sum += t / m[i];
		if (t % m[i]) sum++;
		if (sum >= n) return n;
	}
	return sum;
}

int T;

int main()
{
	cin >> T;
	for (int C = 1; C <= T; C++)
	{
		cin >> b >> n;
		for (int i = 0; i < b; i++) cin >> m[i];
		long long lo = 0, hi = 1e15;
		while (hi - lo > 1)
		{
			long long mid = (lo + hi) / 2;
			if (f(mid) >= n) hi = mid;
			else lo = mid;
		}
		int pos = n - f(lo);
		for (int i = 0; i < b; i++)
		{
			if (lo % m[i] == 0)
			{
				if (pos == 1)
				{
					cout << "Case #" << C << ": " << i + 1 << '\n';
					break;
				}
				else pos--;
			}
		}
	}
	return 0;
}

