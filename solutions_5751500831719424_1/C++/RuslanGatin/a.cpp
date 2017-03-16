#define _CRT_SECURE_NO_DEPRECATE
#pragma comment (linker, "/stack:256000000")

#include <iostream>
#include <cstdio>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <queue>
#include <deque>
#include <set>
#include <bitset>
#include <map>
#include <memory.h>
#undef NDEBUG
#include <cassert>
#include <ctime>

using namespace std;

#define fo(a,b,c) for (int a = (b); a < (c); a++)
#define fr(a,b) fo(a, 0, (b))
#define fi(n) fr(i, (n))
#define fj(n) fr(j, (n))
#define fk(n) fr(k, (n))
#define fd(a,b,c) for (int a = (b); a >= (c); a--)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define _(a,b) memset((a), (b), sizeof(a))
#define __(a) memset((a), 0, sizeof(a))
#define sz(a) (int)(a).size()
#define mp make_pair
#define pb push_back

typedef long long lint;
typedef unsigned long long ull;
typedef vector<int> VI;
typedef vector<string> VS;
typedef pair<int, int> pii;

const int INF = 1000000000;
const lint LINF = 4000000000000000000LL;
const double eps = 1e-9;

int ni() { int a; scanf("%d", &a); return a; }
double nf() { double a; scanf("%lf", &a); return a; }
char sbuf[100005]; string ns() { scanf("%s", sbuf); return sbuf; }
long long nll() { long long a; scanf("%lld", &a); return a; }

void prepare()
{
	freopen("input.txt", "r", stdin);
	freopen("a-small.in", "r", stdin);
	freopen("a-small.out", "w", stdout);
	freopen("a-large.in", "r", stdin);
	freopen("a-large.out", "w", stdout);
}

const int maxn = 105;

int n;
string s[maxn];
vector<pair<char, int> > w[maxn];

void read()
{
	n = ni();
	fi(n)
		s[i] = ns();
}

int get(int id)
{
	int maxw = 0;
	fi(n)
		maxw = max(maxw, w[i][id].second);
	int res = INF;
	fi(maxw + 1) if (i)
	{
		int cur = 0;
		fj(n)
		{
			cur += abs(i - w[j][id].second);
		}
		res = min(res, cur);
	}
	return res;
}

void solve(int test_num)
{
	//cerr << test_num << endl;
	printf("Case #%d: ", test_num);
	fi(n)
		w[i].clear();
	fi(n)
	{
		int cnt = 1;
		fj(sz(s[i])) if (j)
		{
			if (s[i][j] != s[i][j - 1])
			{
				w[i].push_back(mp(s[i][j - 1], cnt));
				cnt = 1;
			}
			else
				cnt++;
		}
		w[i].push_back(mp(s[i][sz(s[i]) - 1], cnt));
	}
	fi(n) if (i)
	{
		if (sz(w[i - 1]) != sz(w[i]))
		{
			printf("Fegla Won\n");
			return;
		}
		fj(sz(w[i]))
		{
			if (w[i][j].first != w[i - 1][j].first)
			{
				printf("Fegla Won\n");
				return;
			}
		}
	}
	int res = 0;
	fi(sz(w[0]))
		res += get(i);
	printf("%d\n", res);
}

int main()
{
	prepare();
	int number_of_tests;
	scanf("%d\n", &number_of_tests);
	fi(number_of_tests)
	{
		read();
		solve(i + 1);
	}
	return 0;
}