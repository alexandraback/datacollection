#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <queue>
#include <vector>
#include <map>
#include <cmath>
#include <string>
#include <cstring>
#include <utility>
#include <stack>
#include <set>
#include <algorithm>
#include <bitset>
#include <functional>
#include <ctime>
#include <cassert>
#include <valarray>
#include <unordered_map>
#include <unordered_set>
#pragma comment(linker, "/STACK:167772160")

using namespace std;
#pragma region TypeDefs

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair<int, int> pii;
typedef vector< vector<int> > vvint;

#pragma endregion

const int INF = 1e9 + 10;
const ll LINF = (ll) 2e18 + 10;
const ld PI = acos(-1);
const ld eps = 1e-8;
const ld EPS = 1e-12;

const int N = 30;
int n;
int cnt[N];
int sum_cnt;

void evacuate()
{
	int maxp = 0;
	for (int i = 0; i < n; ++i)
		if (cnt[i] > cnt[maxp])
			maxp = i;
	--sum_cnt;
	--cnt[maxp];
	printf("%c", 'A' + maxp);
}

void solve()
{
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &cnt[i]);
		sum_cnt += cnt[i];
	}
	while (sum_cnt > 0)
	{
		evacuate();
		if (sum_cnt % 2 == 1)
			evacuate();
		printf(" ");
	}
	printf("\n");
}

int main()
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#else
	//freopen("chocolate.in", "r", stdin);
	//freopen("chocolate.out", "w", stdout);
#endif

	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; ++i)
	{
		printf("Case #%d: ", i + 1);
		solve();
	}

#ifdef LOCAL
	fprintf(stderr, "\n\nTime: %.3f", (double) clock() / CLOCKS_PER_SEC);
#endif
	return 0;
}