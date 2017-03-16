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
#define x first
#define y second
#define ft first
#define sc second
#define pt pair<int, int>

typedef long long li;
typedef long double ld;


using namespace std;

const int N = 200, INF = 1000*1000*1000;
const ld  eps = 1e-9;

char buf[N];
int sza[N];
pair<char, int> a[N][N];

bool solve(int test) {
	int n;
	scanf("%d", &n);
    printf("Case #%d: ", test + 1);
	forn(i, n) {
		scanf("%s", buf);
		string s = string(buf);
		int m = sz(s);
		sza[i] = 0;
		for(int j = 0; j < m;) {
			int k = j;
			for(; k < m && s[k] == s[j]; k++);
			a[i][sza[i]++] = mp(s[j], k - j);
			j = k;
		}
	}

	string seq = "";
	forn(i, sza[0])
		seq.pb(a[0][i].ft);

	forn(i, n) {
	    if (sza[i] != sz(seq)) {
        	puts("Fegla Won");
        	return true;
	    }
	    bool ok = true;
		forn(j, sza[i]) {
        	if (seq[j] != a[i][j].ft)
        		ok = false;
		}
		if (!ok) {
        	puts("Fegla Won");
        	return true;
        }
	}
	
	int ans = 0;
	forn(i, sz(seq)) {
		int best = INF;
		for(int k = 1; k < N; k++) {
			int cur = 0;
			forn(j, n) {
				cur += abs(k - a[j][i].sc);
			}
			best = min(best, cur);
		}
		ans += best;
	}
	printf("%d\n", ans);
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
	return 0;
}