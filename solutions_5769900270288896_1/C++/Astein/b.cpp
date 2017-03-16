#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> a;
int r, c;
int ret;

int sol1(int r, int c, int n)
{
	int mmax = (r * (c - 1)) + ((r - 1) * c);
	int canremove = r * c - n;
	int four = (r - 2) * (c - 2) / 2;
	if (canremove >= four)
	{
		mmax -= 4 * four;
		canremove -= four;
	}
	else
	{
		mmax -= 4 * canremove;
		canremove = 0;
	}

	int three = ((r * c) % 2 == 1) ? (2 * r + 2 * c - 4) / 2 : (2 * r + 2 * c - 8) / 2;
	if (canremove >= three)
	{
		mmax -= 3 * three;
		canremove -= three;
	}
	else
	{
		mmax -= 3 * canremove;
		canremove = 0;
	}

	int two = ((r * c) % 2 == 1) ? 0 : 2;
	if (canremove >= two)
	{
		mmax -= 2 * two;
		canremove -= two;
	}
	else
	{
		mmax -= 2 * canremove;
		canremove = 0;
	}
	return mmax;
}


int sol2(int r, int c, int n)
{
	int mmax = (r * (c - 1)) + ((r - 1) * c);
	int canremove = r * c - n;
	int four = ((r - 2) * (c - 2) + 1) / 2;
	if (canremove >= four)
	{
		mmax -= 4 * four;
		canremove -= four;
	}
	else
	{
		mmax -= 4 * canremove;
		canremove = 0;
	}

	int three = (2 * r + 2 * c - 12) / 2;
	if (canremove >= three)
	{
		mmax -= 3 * three;
		canremove -= three;
	}
	else
	{
		mmax -= 3 * canremove;
		canremove = 0;
	}

	int two = 4;
	if (canremove >= two)
	{
		mmax -= 2 * two;
		canremove -= two;
	}
	else
	{
		mmax -= 2 * canremove;
		canremove = 0;
	}
	return mmax;
}

int go(int n)
{
	bool odd = ((r * c) % 2 == 1);
	if ((r * c + 1) / 2 >= n) return 0;
	int remain = n - (r * c + 1) / 2;

	if (r == 1)
	{
		if (odd)
		{
			return 2 * remain;
		}
		else
		{
			return 2 * remain - 1;
		}
	}
	
	if (odd)
	{
		int s1 = sol1(r, c, n);
		int s2 = sol2(r, c, n);
		return std::min(s1, s2);
	}
	else
	{
		return sol1(r, c, n);
	}
	return -2;
}

int main()
{
	freopen("B-large.in", "r", stdin);
	freopen("B-large.out", "w", stdout);

	int T;
	scanf("%d", &T);
	for (int cn = 1; cn <= T; ++cn)
	{
		int n;
		scanf("%d%d%d", &r, &c, &n);
		if (r > c) swap(r, c);
		printf("Case #%d: %d\n", cn, go(n));
	}
	return 0;
}