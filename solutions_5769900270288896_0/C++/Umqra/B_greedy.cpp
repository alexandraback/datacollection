#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <cmath>

using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

const int DX[] = {1, 0, -1, 0};
const int DY[] = {0, 1, 0, -1};
const int N = (int)1e4 + 10;

vector<int> used[N];
vector <int> color[N];
vector <int> deg[N];

bool cmp(pair<int, int> a, pair<int, int> b)
{
	if (deg[a.first][a.second] != deg[b.first][b.second])
		return deg[a.first][a.second] < deg[b.first][b.second];
	return a < b;
}

set <pair<int, int>, bool(*)(pair<int, int>, pair<int, int>)> setCells(cmp);
int r, c;

void putCell(int i, int s)
{
	used[i][s] = 1;
	for (int dir = 0; dir < 4; dir++)
	{
		int nx = i + DX[dir];
		int ny = s + DY[dir];
		if (nx >= 0 && ny >= 0 && nx < r && ny < c)
		{
			setCells.erase(make_pair(nx, ny));
			deg[nx][ny]++;
		}
	}
	for (int dir = 0; dir < 4; dir++)
	{
		int nx = i + DX[dir];
		int ny = s + DY[dir];
		if (nx >= 0 && ny >= 0 && nx < r && ny < c && !used[nx][ny])
			setCells.insert(make_pair(nx, ny));
	}
}

void addCells(int type)
{
	for (int i = 0; i < r; i++)
		for (int s = 0; s < c; s++)
			if (color[i][s] == type)
				putCell(i, s);
}

int solve(int n, int type)
{
	setCells.clear();
	for (int i = 0; i < r; i++)
	{
		color[i].resize(c);
		used[i].resize(c);
		deg[i].resize(c);
		for (int s = 0; s < c; s++)
			color[i][s] = used[i][s] = deg[i][s] = 0;
	}
	int cnt1 = 0, cnt0 = 0;
	for (int i = 0; i < r; i++)
		for (int s = 0; s < c; s++)
		{
			if ((i + s) % 2 == 0)
				color[i][s] = 1, cnt1++;
			else
				color[i][s] = 0, cnt0++;
		}

	if (n <= max(cnt1, cnt0))
		return 0;
	if (type == 0)
	{
		addCells(0);
		n -= cnt0;
	}
	else
	{
		addCells(1);
		n -= cnt1;
	}
	for (int i = 0; i < r; i++)
		for (int s = 0; s < c; s++)
		{
			if (!used[i][s])
				setCells.insert(make_pair(i, s));
		}
	int answer = 0;
	while (n > 0)
	{
		auto p = *setCells.begin();
		setCells.erase(p);
		n--;
		answer += deg[p.first][p.second];
		putCell(p.first, p.second);
	}
	return answer;
}

int main()
{
	int T;
	scanf("%d", &T);
	for (int i = 1; i <= T; i++)
	{
		printf("Case #%d: ", i);
		int n;
		scanf("%d%d%d", &r, &c, &n);
		printf("%d\n", min(solve(n, 0), solve(n, 1)));
	}
	return 0;
}
