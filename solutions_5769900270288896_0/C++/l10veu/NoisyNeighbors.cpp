#include <cstdio>

int R, C, N;
int ans;

bool check[18][18];

int count()
{
	int cnt = 0;
	
	for (int i=1; i<=R; ++i)
	{
		for (int j=1; j<=C; ++j)
		{
			if (check[i][j] == false)
				continue;

			if (check[i-1][j])
				++cnt;

			if (check[i+1][j])
				++cnt;

			if (check[i][j-1])
				++cnt;

			if (check[i][j+1])
				++cnt;
		}
	}
	
	return cnt / 2;
}

void next(int& y, int& x)
{
	++x;
	if (x>C)
	{
		x=1;
		++y;
	}
}

void go(int y, int x, int c)
{
	if (c == N)
	{
		int newAns = count();
		if (newAns < ans)
			ans = newAns;
	}

	if (y>R)
		return;

	while (y<=R && x<=C)
	{
		check[y][x] = true;

		int py = y;
		int px = x;
		
		next(y, x);
		go(y, x, c+1);
		
		check[py][px] = false;
	}
}

void solve()
{
	for (int y=0; y<R+2; ++y)
		for (int x=0; x<C+2; ++x)
			check[y][x] = false;

	go(1, 1, 0);
}

int main()
{
	int t;
	scanf("%d", &t);
	for (int tc=1; tc<=t; ++tc)
	{
		scanf("%d %d %d", &R, &C, &N);
		ans = R*C*4;

		solve();
		printf("Case #%d: %d\n", tc, ans);
	}
	
	return 0;
}