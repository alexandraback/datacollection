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
	freopen("a-small.in", "r", stdin);
	freopen("a-small.out", "w", stdout);
	//freopen("-large.in", "r", stdin);
	//freopen("-large.out", "w", stdout);
}

int row[2];
int a[2][4][4];

void read()
{
	fo(k, 0, 2)
	{
		row[k] = ni() - 1;
		fi(4)
		{
			fj(4)
				a[k][i][j] = ni() - 1;
		}
	}
}

void solve(int test_num)
{
	//cerr << test_num << endl;
	printf("Case #%d: ", test_num);
	set<int> v, w;
	fi(4)
	{
		v.insert(a[0][row[0]][i]);
		w.insert(a[1][row[1]][i]);
	}
	VI res;
	fi(16)
	{
		if (v.find(i) != v.end() && w.find(i) != w.end())
			res.pb(i);
	}
	if (sz(res) == 0)
		printf("Volunteer cheated!");
	else if (sz(res) == 1)
		printf("%d", res[0] + 1);
	else
		printf("Bad magician!");
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