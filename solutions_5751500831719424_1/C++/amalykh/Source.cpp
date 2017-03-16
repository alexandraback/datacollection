#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <cmath>
#include <map>
#include <set>
#include <assert.h>
#include <queue>
#include <unordered_map>

using namespace std;

typedef long long ll;
#define mp make_pair

char s[110][110];

int l[110];
int cur[110];
int len[110];

int allsum = 0;
int cursum = 0;

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int tests;
	scanf("%d", &tests);
	for (int q = 0; q < tests; q++)
	{
		int n;
		scanf("%d", &n);
		fill(cur, cur + n, 0);
		for (int i = 0; i < n; i++)
			fill(s[i], s[i] + 110, 0);
		gets(s[0]);
		ll ans = 0;
		printf("Case #%d: ", q + 1);
		for (int i = 0; i < n; i++)
			gets(s[i]);

		allsum = cursum = 0;

		for (int i = 0; i < n; i++)
			len[i] = strlen(s[i]);
		for (int i = 0; i < n; i++)
			allsum += len[i];
		
		while (cursum < allsum)
		{
			fill(l, l + 101, 0);
			for (int i = 1; i < n; i++)
			{
				if (s[i][cur[i]] != s[i - 1][cur[i - 1]])
				{
					printf("Fegla Won\n");
					goto end;
				}
			}
			for (int i = 0; i < n; i++)
			{
				int t = 1;
				while (s[i][cur[i]] == s[i][cur[i] + 1])
				{
					if (cur[i] >= len[i])
						break;
					t++, cur[i]++;
				}
				if (cur[i] < len[i])
					cur[i]++;
				l[t]++;
			}

			int cur_ans = 1e9;

			for (int i = 1; i < 101; i++)
			{
				int w = 0;
				for (int j = 0; j < 101; j++)
					w += l[j] * (abs(j - i));
				cur_ans = min(w, cur_ans);
			}
			ans += cur_ans;

			cursum = 0;
			for (int i = 0; i < n; i++)
				cursum += cur[i];
		}
		printf("%lld\n", ans);
	end:;
	}
	return 0;
}