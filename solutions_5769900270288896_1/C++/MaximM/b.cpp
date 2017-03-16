#include <cstdio>

const int M = 1010;

int a[M];
int n, m, k;
int te;

void del(int x, int y)
{
	if (x >= 0 && x < n && y >= 0 && y < m)
		--a[x * m + y];
}

void add(int x, int y)
{
	a[x * m + y] = 0;
	del(x - 1, y);
	del(x + 1, y);
	del(x, y - 1);
	del(x, y + 1);
}

void formarr()
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			int t = i * m + j;
			int c = 4;
			if (i == 0)
				--c;
			if (i == n - 1)
				--c;
			if (j == 0)
				--c;
			if (j == m - 1)
				--c;
			a[t] = c;
		}
}

const int dx[2] = {0, 1}, dy[2] = {1, 0};

bool b[18][18];
int sum;

void go(int t, int k)
{
	if (k == 0)
	{
		int r = 0;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				if (b[i][j])
					for (int k = 0; k < 2; k++)
					{
						int x = i + dx[k], y = j + dy[k];
						if (x >= 0 && x < n && y >= 0 && y < m && b[x][y])
							++r;
					}
		if (r < sum)
			sum = r;
	}
	if (k > 0)
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				if (i * m + j >= t && !b[i][j])
				{
					b[i][j] = true;
					go(i * m + j, k - 1);
					b[i][j] = false;
				}
}

int brute()
{
	sum = 1e9;
	go(0, k);
	return sum;
}

int countsum(int d)
{
	int sum = 0;
	while (d > 0)
	{
		int cur = 0;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				if (a[i * m + j] > a[cur])
					cur = i * m + j;
		sum += a[cur];
		add(cur / m, cur % m);
		--d;
	}
	return sum;
}

int main()
{
	scanf("%d", &te);
	for (int tn = 1; tn <= te; tn++)
	{
		scanf("%d%d%d", &n, &m, &k);
		formarr();
		int all = 2 * (n - 1) * (m - 1) + n + m - 2;
		int sum = countsum(n * m - k);
		int c = all - sum;
		if (k < n * m)
		{
			formarr();
			int cur = 0, cr = 0;
			for (int i = 0; i < n; i++)
				for (int j = 0; j < m; j++)
				{
					if (a[i * m + j] > a[cur])
						cur = i * m + j, cr = 0;
					if (a[i * m + j] == a[cur])
					{
						++cr;
						if (cr == 2)
							cur = i * m + j;
					}
				}
			sum = a[cur];
			add(cur / m, cur % m);
			sum += countsum(n * m - k - 1);
			if (all - sum < c)
				c = all - sum;
			if (n * m <= 16)
			{
				int br = brute();
				if (br < c)
					c = br;
			}
		}
		printf("Case #%d: %d\n", tn, c);
	}

	return 0;
}