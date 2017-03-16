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
LL dp[110][110];
char s1[110], s2[110];
int len1, len2;

LL F(int a1, int a2)
{
	if (a1 == len1 && a2 == len2)
		return 0;
	LL & res = dp[a1][a2];
	if (res != -1)
		return res;
	res = INF;
	if (a1 < len1 && a2 < len2 && s1[a1] == s2[a2])
	{
		res = min(res, F(a1 + 1, a2 + 1));
		res = min(res, F(a1 + 1, a2) + 1);
		res = min(res, F(a1, a2 + 1) + 1);
	}
	if (a1 < len1 - 1 && s1[a1] == s1[a1 + 1])
	{
		res = min(res, F(a1 + 1, a2) + 1);
	}
	if (a2 < len2 - 1 && s2[a2] == s2[a2 + 1])
	{
		res = min(res, F(a1, a2 + 1) + 1);
	}
	return res;
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	scanf("%d", &t);
	for (int k = 0; k < t; k++)
	{
		memset(dp, -1, sizeof(dp));
		scanf("%d", &n);
		getchar();
		gets(s1);
		gets(s2);
		len1 = strlen(s1);
		len2 = strlen(s2);
		LL res = F(0, 0);
		printf("Case #%d: ", k + 1);
		if (res >= INF)
			printf("Fegla Won\n");
		else
			printf("%I64d\n", res);
	}
	return 0;
}