/*
ID:
PROG: spin
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <complex>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <complex>
#include <stdio.h>
#include <cstdlib>
#include <memory.h>
#include <ctime>
#include <stack>
#ifdef SAMMAX
#include <ctime>
clock_t beg;
#endif

const double pi = 3.1415926535897932384626433832795;
double EPS = 10e-4;
const int INF = 2000000000;

#pragma comment(linker, "/stack:1500000000")
#define sz size()
#define mp make_pair
#define pb push_back
#define ALL(a) (a).begin(), (a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define MEMS(a,b) memset(a,b,sizeof(a))
#define sqr(a) ((a)*(a))
#define HAS(a,b) ((a).find(b)!=(a).end())
#define MAX(a,b) ((a>=b)?a:b)
#define MIN(a,b) ((a<=b)?a:b)
#define ABS(a) ((a<0)?-(a):a)
#define FOR(i,a,b) for (int i=(a);i<(b);++i)
#define FORD(i,a,b) for (int i=(a);i>(b);--i)
#define VVI vector < vector <int> >
#define VI vector <int>
#define LL long long    
#define U unsigned
#define pnt pair <int,int>
LL gcd(LL a, LL b){ if (a == 0) return b; return gcd(b%a, a); }
LL lcm(LL a, LL b){ return a / gcd(a, b) * b; }

using namespace std;

void ifd() {
#ifdef SAMMAX
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout); 
	beg = clock();
#else
	//freopen("D.in", "r", stdin);
	//freopen("D.out", "w", stdout);
#endif  
}
void tme() {
#ifdef SAMMAX
	fprintf(stderr, "*** Total time: %.3lf ***\n", 1.0*(clock() - beg) / CLOCKS_PER_SEC);
#endif
}

int number_of_cases;

int n, last;
string a[111], tmp;
VVI g;
VI gmn, gmx;
vector <string> all;

int ans;

int main() {
	ifd();

	scanf("%d", &number_of_cases);

	FOR(cur_case, 1, number_of_cases + 1) {
		scanf("%d", &n);

		g.clear();
		all.clear();
		g.resize(n);
		gmn.clear();
		gmx.clear();
		ans = 0;

		FOR(i, 0, n) {
			cin >> a[i];
			tmp = "";
			last = 0;

			FOR(j, 1, a[i].size()) {
				if (a[i][j] == a[i][last]) {
					continue;
				}
				else {
					g[i].push_back(j - last);
					tmp += a[i][last];
					last = j;
				}
			}

			g[i].push_back(a[i].size() - last);
			tmp += a[i][last];
			all.push_back(tmp);
		}

		sort(ALL(all));
		all.resize(unique(ALL(all)) - all.begin());

		if (all.size() != 1) {
			printf("Case #%d: Fegla Won\n", cur_case);
		}
		else {
			FOR(i, 0, g[0].size()) {
				gmn.push_back(200);
				gmx.push_back(-200);
			}

			FOR(i, 0, n) {
				FOR(j, 0, g[i].size()) {
					gmn[j] = MIN(gmn[j], g[i][j]);
					gmx[j] = MAX(gmx[j], g[i][j]);
				}
			}

			FOR(i, 0, g[0].size()) {
				int best = 1000000000;
				FOR(j, gmn[i], gmx[i] + 1) {
					int tmp = 0;
					FOR(k, 0, n)
						tmp += ABS(g[k][i] - j);
					best = MIN(best, tmp);
				}
				ans += best;
			}

			printf("Case #%d: %d\n", cur_case, ans);
		}
	}
	

	tme();
	return 0;
}