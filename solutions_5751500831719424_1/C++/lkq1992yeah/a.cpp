#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

#define INF 2111222333
#define MAXN 120
#define MAXL 120

char dict[MAXN][MAXL];
char wordName[MAXN][MAXL];
int wordLen[MAXN][MAXL];
int dlen[MAXN];

int n;

int preprocess(char str[MAXL], char wn[MAXL], int wl[MAXL])
{
	int i = 0, tmp, cnt = -1, len = strlen(str);
	char last = '#';
	for (i = tmp = 0; i < len; i++)
	{
		if (str[i] == last)
			tmp++;
		else
		{
			if (last != '#')
			{
				wn[cnt] = last;
				wl[cnt] = tmp;
			}
			last = str[i];
			tmp = 1;
			cnt++;
		}
	}
	wn[cnt] = last;
	wl[cnt] = tmp;
	cnt++;
	// for (i = 0; i < cnt; i++)
		// printf("%c:%d ", wn[i], wl[i]);
	// printf("\n");
	return cnt;
}

bool judge()
{
	int i, j;
	for (i = 0; i < n; i++)
		if (dlen[i] != dlen[0]) return false;
	for (i = 0; i < n; i++)
		for (j = 0; j < dlen[0]; j++)
			if (wordName[0][j] != wordName[i][j]) return false;
	return true;
}

int work()
{
	int i, j, k, ans = 0, len = dlen[0];
	int tmp, tmp2, cmp = INF;
	for (j = 0; j < len; j++)
	{
		cmp = INF; 
		for (k = 1; k <= 100; k++)
		{
			tmp = 0;
			for (i = 0; i < n; i++)
			{
				tmp2 = k - wordLen[i][j];
				if (tmp2 < 0) tmp2 = -tmp2;
				tmp += tmp2;
			}
			cmp = min(cmp, tmp);
		}
		ans += cmp;
	}
	return ans;
}

int main()
{
	int t, cas, i, j, ans, tmp, tmp2;
	scanf("%d", &t);
	for (cas = 1; cas <= t; cas++)
	{
		scanf("%d", &n);
		for (i = 0; i < n; i++)	scanf("%s", dict[i]);
		for (i = 0; i < n; i++) dlen[i] = preprocess(dict[i], wordName[i], wordLen[i]);
		printf("Case #%d: ", cas);
		if (judge())
		{
			ans = work();
			printf("%d\n", ans);
		}
		else printf("Fegla Won\n");
	}
	return 0;
}
