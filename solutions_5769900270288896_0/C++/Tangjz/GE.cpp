#include <set>
#include <map>
#include <list>
#include <stack>
#include <queue>
#include <deque>
#include <ctime>
#include <cmath>
#include <cstdio>
#include <vector>
#include <string>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 10010, dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};
int t, r, c, n, ans;
bool vis[maxn];
int idx(int x, int y)
{
	if(x < 0 || x >= r || y < 0 || y >= c)
		return -1;
	return x * c + y;
}
void rdx(int id, int &x, int &y)
{
	x = id / c;
	y = id % c;
}
void solve(int x1, int y1, int rr, int cc)
{
	if(rr == 1)
	{
		for(int i = 0; i < n / 2; ++i)
			vis[idx(x1 + i, y1)] = 1;
		for(int i = 0; i < n - n / 2; ++i)
			vis[idx(x1 + rr - 1 - i, y1)] = 1;
		n = 0;
	}
	else if(cc == 1)
	{
		for(int i = 0; i < n / 2; ++i)
			vis[idx(x1, y1 + i)] = 1;
		for(int i = 0; i < n - n / 2; ++i)
			vis[idx(x1, y1 + cc - 1 - i)] = 1;
		n = 0;
	}
	else
	{
		for(int i = 1; i < rr - 1 && n; ++i, --n)
			vis[idx(x1 + i, y1)] = 1;
		for(int i = 1; i < rr - 1 && n; ++i, --n)
			vis[idx(x1 + i, y1 + cc - 1)] = 1;
		for(int i = 1; i < cc - 1 && n; ++i, --n)
			vis[idx(x1, y1 + i)] = 1;
		for(int i = 1; i < cc - 1 && n; ++i, --n)
			vis[idx(x1 + rr - 1, y1 + i)] = 1;
		if(n)
		{
			vis[idx(x1, y1)] = 1;
			--n;
		}
		if(n)
		{
			vis[idx(x1 + rr - 1, y1)] = 1;
			--n;
		}
		if(n)
		{
			vis[idx(x1, y1 + cc - 1)] = 1;
			--n;
		}
		if(n)
		{
			vis[idx(x1 + rr - 1, y1 + cc - 1)] = 1;
			--n;
		}
	}
	if(n)
		solve(x1 + 1, y1 + 1, rr - 2, cc - 2);
}
int cnt()
{
	int ret = 0;
	for(int x = 0; x < r; ++x)
		for(int y = 0; y < c; ++y)
		{
			int id1 = idx(x, y);
			if(!vis[id1])
				continue;
			for(int i = 0; i < 4; ++i)
			{
				int id2 = idx(x + dx[i], y + dy[i]);
				if(id2 != -1 && vis[id2])
					++ret;
			}
		}
	return ret >> 1;
}
void dfs(int dep, int sum)
{
	if(dep == r * c)
	{
		if(sum == n)
			ans = min(ans, cnt());
		return;
	}
	vis[dep] = 0;
	dfs(dep + 1, sum);
	vis[dep] = 1;
	dfs(dep + 1, sum + 1);
}
int main()
{
	scanf("%d", &t);
	for(int Case = 1; Case <= t; ++Case)
	{
		memset(vis, 0, sizeof vis);
		scanf("%d%d%d", &r, &c, &n);
		ans = ~0u >> 1;
		dfs(0, 0);//solve(0, 0, r, c);
		printf("Case #%d: %d\n", Case, ans);
		//printf("Case #%d: %d\n", Case, cnt());
	}
	return 0;
}
