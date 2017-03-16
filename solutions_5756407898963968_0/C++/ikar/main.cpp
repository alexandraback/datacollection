#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
#include <string>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <set>
#include <map>
#include <ctime>
#include <cmath>

#define forn(i, n) for(int i=0;i<n;++i)
#define for1(i, n) for(int i=1;i<=n;++i)
#define forv(i, v) for(int i=0;i<v.size();++i)
#define sz(v) int(v.size())
#define all(v) v.begin(), v.end()
#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define ft first
#define sc second
#define pt pair<int, int>

typedef long long li;
typedef long double ld;


using namespace std;

const int n = 4, N = 16 + 3, INF = 1000*1000*1000;
const ld  eps = 1e-9;

int a[n][n];
int u[N];

bool solve(int test) {
	memset(u, 0, sizeof u);
	forn(t, 2) {
    	int r;
    	scanf("%d", &r);
    	r--;
    	forn(i, n) 
    		forn(j, n)
    			scanf("%d", &a[i][j]);
    	forn(j, n)
    		u[ a[r][j] ]++;
	}
	int ans = -1;
	int cnt = 0;
	forn(i, N) {
		if (u[i] == 2) {
			ans = i;
			cnt++;
		}
	}	
	printf("Case #%d: ", test + 1);
	if (cnt == 0) {
		puts("Volunteer cheated!");
	} else if (cnt >= 2) {
		puts("Bad magician!");
	} else {
		printf("%d\n", ans);
	}
	return false;
}

int main () {	
#ifdef IKAR
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n;
	scanf("%d", &n);
	forn(i, n)
		solve(i);
}