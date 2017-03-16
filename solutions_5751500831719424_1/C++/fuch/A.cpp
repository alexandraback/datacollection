#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

int n;
char strs[1024][1024];

std::vector< std::pair<char, int> > rle(char *str)
{
	std::vector< std::pair<char, int> > ret;
	char ch;
	int cnt = 0;
	for (int i = 0; str[i]; ++i)
	{
		if (cnt == 0 || ch != str[i])
		{
			if (cnt > 0) ret.push_back(std::make_pair(ch, cnt));
			ch = str[i];
			cnt = 1;
		}
		else
		{
			++cnt;
		}
	}
	if (cnt > 0) ret.push_back(std::make_pair(ch, cnt));
	return ret;
}

void solve()
{
	std::vector< std::vector< std::pair<char, int> > > rles;
	for (int i = 0; i < n; ++i)
	{
		rles.push_back(rle(strs[i]));
	}
//	for (int i = 0; i < n; ++i)
//	{
//		printf("%d:", i);
//		for (int j = 0; j < (int)rles[i].size(); ++j) printf(" %c%d", rles[i][j].first, rles[i][j].second);
//		puts("");
//	}

//printf("n=%d\n", n);

	bool valid = true;

	int m = (int)rles[0].size();

	for (int i = 1; i < n && valid; ++i)
	{
		//printf("i=%d\n", i);
		if ((int)rles[i].size() != m)
		{
			valid = false;
			break;
		}
		for (int j = 0; j < (int)rles[i].size(); ++j)
		{
			if (rles[i - 1][j].first != rles[i][j].first) valid = false;
		}
	}
//puts("AA");
	if (!valid)
	{
		puts("Fegla Won");
		return;
	}

	int ans = 0;
	for (int i = 0; i < m; ++i)
	{
		std::vector<int> ns;
		for (int j = 0; j < n; ++j)
		{
			ns.push_back(rles[j][i].second);
		}
		std::sort(ns.begin(), ns.end());
		for (int j = 0; j < n; ++j) ans += abs(ns[j] - ns[n / 2]);
	}

	printf("%d\n", ans);
}

int main()
{
	int t;
	scanf("%d", &t);
	for (int cs = 1; cs <= t; ++cs)
	{
		scanf("%d", &n);
		for (int i = 0; i < n; ++i)
		{
			scanf("%s", strs[i]);
		}
		printf("Case #%d: ", cs);
		solve();
	}
}
