#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int solve()
{
	int n, k;
	int m[1001];
	scanf("%d%d", &k, &n);
	for (int i = 0; i < k; i++)
	{
		scanf("%d", &m[i]);
	}
	long long l = 0;
	long long r = (long long)(100000) * 1000000000;
	while (l < r)
	{
		long long mid  = (l + r) / 2;
		long long sum = 0;
		for (int i = 0; i < k; i++)
		{
			if (mid % m[i] == 0) sum += mid / m[i];
			else sum += mid / m[i] + 1;
		}
		if (sum < n) l = mid + 1;
		else r = mid;
	}
	long long sum = 0;
	for (int i = 0; i < k; i++)
	{
		if ((l - 1) % m[i] == 0) sum += (l - 1) / m[i];
		else sum += (l - 1) / m[i] + 1;
	}
	//cout << l <<  ' ' << sum << endl;
	for (int i = 0; i < k; i++)
	{
		if (l % m[i] == 1 || m[i] == 1)
		{
			sum++;
			if (sum == n) return i + 1;
		}
	}
}

int main()
{
	freopen("b-small-attempt2.in", "r", stdin);
    freopen("output.txt", "w", stdout);
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; i++)
	{
		printf("Case #%d: %d\n", i + 1, solve());
	}
}