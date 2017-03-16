#pragma comment(linker, "/STACK:255000000")
#include <cstdio>
#include <cstring>
#include <cctype>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <functional>
#include <stack>
#include <memory.h>
#include <algorithm>
#include <math.h>
#include <valarray>
#include <complex>
#include <bitset>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef vector<int> vint;
typedef vector<vint> vvint;
typedef complex<double> comp;

long double eps = 1e-7;
const int BASE = (int) 1e9;
const long double PI = 3.1415926535897932384626433832795;
const int MOD = (int) 1e9 + 7;
const int HMOD = (1 << 18) - 1;
const int INF = 1 << 30;
const LL LLINF = 1ll << 60;

int t;
int n;
char s[110][110];
int len[110];

struct st
{
	int c, len;
	st(int c, int len) : c(c), len(len) {}
	st() {}
};

vector<vector<st> > v;

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	scanf("%d", &t);
	for (int k = 0; k < t; k++)
	{
		scanf("%d", &n);
		v.clear();
		v.resize(n);
		getchar();
		for (int i = 0; i < n; i++)
		{
			gets(s[i]);
			len[i] = strlen(s[i]);
			int prevc = -1, curlen = 0;
			for (int j = 0; j < len[i]; j++)
			{
				if (prevc != s[i][j])
				{
					if (prevc != -1)
						v[i].push_back(st(prevc, curlen));
					curlen = 0;
					prevc = s[i][j];
				}
				curlen++;
			}
			v[i].push_back(st(prevc, curlen));
		}
		LL res = 0;
		bool flag = false;
		for (int j = 1; j < n; j++)
				if (v[j].size () != v[0].size())
					flag = true;
		if (!flag)
		{
			for (int i = 0; i < v[0].size(); i++)
			{
				LL Min = LLINF;
				for (int j = 1; j <= 100; j++)
				{
					LL testres = 0;
					for (int cur = 0; cur < n; cur++)
					{
						if (v[0][i].c != v[cur][i].c)
							flag = true;
						testres += abs(j - v[cur][i].len);
					}
					Min = min(Min, testres);
				}
				res += Min;
			}
		}
		printf("Case #%d: ", k + 1);
		if (flag)
			printf("Fegla Won\n");
		else
			printf("%I64d\n", res);
	}
	return 0;
}