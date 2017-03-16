/*
ID:
PROG: kimbits
LANG: C++
*/

#define _CRT_SECURE_NO_WARNINGS

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
#include <unordered_set>
#include <memory.h>
#include <ctime>
#include <stack>
#include <unordered_map>
#ifdef SAMMAX
#include <ctime>
clock_t beg;
#endif


const double pi = 3.1415926535897932384626433832795;
double EPS = 10e-9;
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
	//freopen("kimbits.in", "r", stdin);
	//freopen("kimbits.out", "w", stdout);
#endif  
}
void tme() {
#ifdef SAMMAX
	fprintf(stderr, "*** Total time: %.3lf ***\n", 1.0*(clock() - beg) / CLOCKS_PER_SEC);
#endif
}

int n, t, ans, r, c;
int d[32][32];

int di[4] = {1, 0, -1, 0};
int dj[4] = { 0, -1, 0, 1 };

int b_count(int k) {
	int res = 0;
	while (k) {
		res += (k & 1);
		k >>= 1;
	}
	return res;
}

int unh_score(int mask) {
	int res = 0;
	FOR(i, 0, r) {
		FOR(j, 0, c) {
			d[i][j] = ((mask >> (i * c + j)) & 1);
		}
	}

	FOR(i, 0, r) {
		FOR(j, 0, c) {
			if (!d[i][j])
				continue;
			FOR(k, 0, 4) {
				if (i + di[k] >= 0 && j + dj[k] >= 0 &&
					i + di[k] < r && j + dj[k] < c &&
					d[i + di[k]][j + dj[k]])
					res++;
			}
		}
	}

	return res / 2;
}

int main() {
	ifd();

	cin >> t;
	
	FOR(tc, 1, t + 1) {
		cin >> r >> c >> n;
		ans = 10000;

		FOR(i, 0, (1 << (r * c))) {
			if (n == b_count(i)) {
				ans = MIN(ans, unh_score(i));
			}
		}
	
		printf("Case #%d: %d\n", tc, ans);
	}

	tme();
	return 0;
}