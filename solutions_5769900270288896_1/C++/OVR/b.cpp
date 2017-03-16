#include <iostream>
#include <cstdio>

using namespace std;

int solve(int r, int c, int n)
{
	int result;

	if (r > c)
	{
		swap(r, c);
	}

	if (n <= (r * c + 1) / 2)
	{
		result = 0;
	}
	else if (r == 1)
	{
		if (c % 2 == 1)
		{
			n -= (c + 1) / 2;
			result = n * 2;
		}
		else
		{
			n -= c / 2 + 1;
			result = 1 + n * 2;
		}
	}
	else if (r == 2)
	{
		result = 0;
		n -= c;
		
		if (n > 0)
		{
			n -= 1;
			result += 2;
		}		

		if (n > 0)
		{
			n -= 1;
			result += 2;
		}

		result += n * 3;
	}
	else
	{
		int a[2][4];
		int p[4] = {4, 3, 2, 0};

		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				a[i][j] = 1000000009 * (j / 3);
			}
		}

		int mp = 2 * r * c - r - c;

		if (r * c % 2 == 0)
		{
			a[0][0] = (r - 2) * (c - 2) / 2;
			a[0][1] = r + c - 4;
			a[0][2] = 2;
		}
		else
		{
			a[0][0] = ((r - 2) * (c - 2) + 1) / 2;
			a[0][1] = ((r - 2) / 2) * 2 + ((c - 2) / 2) * 2;
			a[0][2] = 4;

			a[1][0] = ((r - 2) * (c - 2)) / 2;
			a[1][1] = ((r - 1) / 2) * 2 + ((c - 1) / 2) * 2;
			a[1][2] = 0;
		}

		int b = 1000000009;

		for (int i = 0; i < 2; i++)
		{
			int t = r * c - n;
			int s = 0;

			for (int j = 0; j < 4; j++)
			{
				int x = min(a[i][j], t);
				t -= x;
				s += p[j] * x;
			}

			b = min(b, mp - s);
		}

		result = b;
	}

	return result;
}

int main()
{
	int testCount;

	scanf("%d", &testCount);

	for (int test = 1; test <= testCount; test++)
	{
		int r, c, n;

		scanf("%d %d %d", &r, &c, &n);

		printf("Case #%d: %d\n", test, solve(r, c, n));
	}

	return 0;
}