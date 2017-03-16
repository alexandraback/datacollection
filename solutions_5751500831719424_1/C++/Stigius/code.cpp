#include <stdio.h>
#include <stdarg.h>
#include <cstring>
#include <algorithm>
#include <set>
#include <vector>
#define clr(a) memset(a, 0, sizeof(a))

typedef long long ll;
typedef std::pair<int, int> pii;
#define DEBUG 1

void dbg(const char * fmt, ...)
{
#if DEBUG
	va_list args;
	va_start(args, fmt);
	vfprintf(stdout, fmt, args);
	va_end(args);
#endif
}

const int size = 1000;

char s[size];
std::pair<char, int> in[size][size];
int in_cnt[size];

int ar[size];

int solve_n(int n)
{
	std::sort(ar, ar+n);
	int cur_ans = 0;
	int best_ans = (int) 2e9;
	for(int j = 0; j < n; j++)
	{
		cur_ans = 0;
		for(int i = 0; i < n; i++)
		{
			cur_ans += abs(ar[i] - ar[j]);
		}
		best_ans = std::min(best_ans, cur_ans);
	}
	return best_ans;
}


void solve(int test_case)
{
	printf("Case #%d: ", test_case);
	int n;
	scanf("%d", &n);	
	for(int i = 0 ; i < n; i++)
	{
		char last = -1;
		scanf("%s", s);
		int count = 0;
		int idx = 0;
		for(int j = 0; s[j]; j++)
		{
			if (s[j] != last)
			{
				if (last != -1)
					in[i][idx++] = std::make_pair(last, count);
				last = s[j];
				count = 0;
			}
			count++;
		}
		in[i][idx++] = std::make_pair(last, count);
		in_cnt[i] = idx;
	}
	int last = in_cnt[0];
	for(int i = 0; i < n; i++)
	{
		if (in_cnt[i] != last)
		{
			printf("Fegla Won\n");
			return;
		}
		for(int j = 0; j < in_cnt[i]; j++)
			if (in[0][j].first != in[i][j].first)
			{
				printf("Fegla Won\n");
				return;
			}
	}
	int ans = 0;
	for(int j = 0; j < in_cnt[0]; j++)
	{
		for(int i = 0; i < n; i++)
			ar[i] = in[i][j].second;
		ans += solve_n(n);
	}
	printf("%d\n", ans);
}

int main()
{
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
		solve(i);

	return 0;
}
