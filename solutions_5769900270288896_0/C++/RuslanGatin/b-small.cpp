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

int ni() { int a; scanf( "%d", &a ); return a; }
double nf() { double a; scanf( "%lf", &a ); return a; }
char sbuf[100005]; string ns() { scanf( "%s", sbuf ); return sbuf; }
long long nll() { long long a; scanf( "%lld", &a ); return a; }

void prepare()
{
	freopen("input.txt", "r", stdin);
	freopen("b-small.in", "r", stdin);
	freopen("b-small.out", "w", stdout);
	//freopen("-large.in", "r", stdin);
	//freopen("-large.out", "w", stdout);
}

const int maxn = 20;

int r, c, n;
int a[maxn][maxn];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

void read()
{
	r = ni();
	c = ni();
	n = ni();
}

int bitCount(int x)
{
	int ret = 0;
	while (x)
	{
		x &= x - 1;
		ret++;
	}
	return ret;
}

int bit(int mask, int k)
{
	return (mask >> k) & 1;
}

void solve(int test_num)
{
	cerr << test_num << endl;
	printf("Case #%d: ", test_num);
	int rc = r * c;
	int _2rc = 1 << rc;
	int ans = INF;
	fo(mask, 0, _2rc)
	{
		if (bitCount(mask) != n)
			continue;
		fi(rc)
		{
			a[i / c][i % c] = bit(mask, i);
		}
		int cc = 0;
		fi(r)
		{
			fj(c)
			{
				if (!a[i][j])
					continue;
				fk(4)
				{
					int nx = i + dx[k];
					int ny = j + dy[k];
					if (nx >= 0 && nx < r && ny >= 0 && ny < c)
						cc += a[nx][ny];
				}
			}
		}
		ans = min(ans, cc);
	}
	assert(ans % 2 == 0);
	printf("%d", ans / 2);
	printf("\n");
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