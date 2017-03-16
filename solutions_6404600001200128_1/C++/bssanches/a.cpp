#include <bits/stdc++.h>

using namespace std;
#define MAX 1010

int t,n;
int v[MAX];

int main(void)
{
	cin >> t;
	int cases = 1;

	while (t--)
	{
		cin >> n;

		for (int i = 0; i < n; ++i)
		{
			cin >> v[i];
		}

		int v1 = 0;
		for (int i = 1; i < n; ++i)
		{
			if (v[i-1] > v[i])
			{
				v1 += v[i-1] - v[i];
			}
		}

		double rate = 0;
		for (int i = 1; i < n; ++i)
		{
			if (v[i-1] > v[i])
			{
				rate = max(rate, (double)(v[i-1] - v[i])/10.0);
			}
		}

		int v2 = 0;
		for (int i = 0; i < n - 1; ++i)
		{
			v2 += min(rate * 10, (double)v[i]);
		}

		// v2 += min(rate * 10, v[n-1]);

		cout << "Case #" << cases++ << ": " << v1 << " " << v2 << "\n";
	}

	return 0;
}