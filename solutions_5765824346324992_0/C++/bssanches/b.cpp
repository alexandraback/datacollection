#include <bits/stdc++.h>

using namespace std;
#define MAX 1010

int t,b,n;
long long v[MAX];


bool test(long long x)
{
	long long qnt = 0;
	for (int i = 0; i < b; ++i)
	{
		if (x%v[i] == 0)
		{
			qnt++;
		}
		qnt += (long long)(x + v[i] - 1)/v[i];
	}

	return qnt >= n;
}

long long bs(long long lo, long long hi)
{
	while (hi - lo > 1)
	{
		long long mid = (hi + lo) / 2;
		if (test(mid))
		{
			hi = mid;
		}
		else
		{
			lo = mid;
		}
	}

	if (test(lo))
		return lo;
	return hi;
}

int main(void)
{
	cin >> t;

	int cases = 1;
	while (t--)
	{
		cin >> b >> n;

		for (int i = 0; i < b; ++i)
			cin >> v[i];

		long long tempo = bs(1LL, 100000000000LL);

		long long menor = 100000000000000LL;
		int who = -1;
		long long qnt = 0;

		for (int i = 0; i < b; ++i)
		{
			if (tempo%v[i] < menor)
			{
				qnt = 1;
				menor = tempo%v[i];
				who = i;
			}
			else if (tempo%v[i] == menor)
			{
				qnt++;
			}
		}

		long long total = 0;
		if (qnt > 1)
		{
			for (int i = 0; i < b; ++i)
			{
				total += (tempo + v[i] - 1)/v[i];
			}

			n -= total;
			bool ok = false;
			while (n > 0)
			{
				for (int i = 0; i < b; ++i)
				{
					if (tempo%v[i] == menor)
					{
						n--;
						if (n <= 0)
						{
							ok = true;
							who = i;
							break;
						}
					}
				}
			}
			if (!ok)
			{
				for (int i = 0; i < b; ++i)
				{
					if (tempo%v[i] == menor)
					{
						who = i;
					}
				}
			}
		}

		// cout << tempo << "\n";
		cout << "Case #" << cases++ << ": " << who + 1 << "\n";
	}
	return 0;
}