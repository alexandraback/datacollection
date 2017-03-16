#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <iomanip>
using namespace std;
#define F first
#define S second
#define mp make_pair
#define pb push_back
#define fname ""
typedef long long ll;

const int maxn = 101;

struct Letter
{
	int x;
	char c;
	bool operator < (Letter b) const
	{
		return x < b.x;
	}
}p[maxn];

vector <string> ans;

inline void solve()
{
	int n, cnt = 0;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &p[i].x);
		cnt += p[i].x;
		p[i].c = char(i + 'A' - 1);
	}
	while (cnt)
	{
		sort (p + 1, p + n + 1);
		if (cnt == 3 || p[n].x == p[n - 1].x + 1)
		{
			cout << " " << p[n].c;
			p[n].x--;
			cnt--;
			continue;
		}
		if (p[n].x == p[n - 1].x)
		{
			p[n].x--;
			p[n - 1].x--;
			cout << " " << p[n - 1].c << p[n].c;
			cnt -= 2;
			continue;
		}
		if (p[n].x - p[n - 1].x > 1)
		{
			p[n].x -= 2;
			cout << " " << p[n].c << p[n].c;
			cnt -= 2;
			continue;
		}	
	}
	puts("");
}

int main()
{
	freopen (fname"input.txt", "r", stdin);
	freopen (fname"output.txt", "w", stdout);
	int T;
	cin >> T;
	for (int Case = 1; Case <= T; Case++)
	{
		printf("Case #%d:", Case);
		solve();
	}

	return 0;
}
