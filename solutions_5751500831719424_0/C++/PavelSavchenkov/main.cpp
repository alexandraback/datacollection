#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <utility>
#include <cstdlib>
#include <memory>
#include <queue>
#include <cassert>
#include <cmath>
#include <ctime>

using namespace std;

#define pb push_back
#define f first
#define s second
#define mp make_pair 
#define sz(C) ((int) (C).size())
#define forn(i, n) for (int i = 0; i < (int) n; ++i)
#define ford(i, n) for (int i = ((int) n) - 1; i >= 0; --i)
#define foran(i, a, n) for (int i = (int) a; i < (int) n; ++i)
#define y1 gftxdtrtfhyjfctrxujkvbhyjice
#define y0 ehfoiuvhefroerferjhfjkehfjke
#define left sdhfsjkshdjkfsdfgkqqweqweh
#define right yytrwtretywretwreytwreytwr
#define all(C) (C).begin(), (C).end()

template <typename T>
inline T sqr( T x ) {
	return x * x;
}

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair <int,int> pii;
typedef pair <ll, ll> pll;
typedef vector <ll> vll;
typedef vector <int> vi;
typedef vector <vector <int> > vvi;
typedef vector <pii> vii;

const double EPS = 1e-9;

char s[110][110];
vi cnt[110];

int main() {
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	int t;
	scanf("%d", &t);
	forn(it, t) {
		int n;
		scanf("%d\n", &n);

		forn(i, n) {
			gets(s[i]);	
		}
			
		string pat;
		for (int i = 0; s[0][i]; ++i)
			if  (pat.empty() || pat[sz(pat) - 1] != s[0][i]) {
				pat += s[0][i];
			}

		bool ok = true;
	   	forn(i, n) {
	   		string cur_pat;

			for (int j = 0; s[i][j]; ++j)
				if  (cur_pat.empty() || cur_pat[sz(cur_pat) - 1] != s[i][j]) {
					cur_pat += s[i][j];
				}	

//			cout << pat << '\n';
//			cout << cur_pat << '\n';
			if  (cur_pat != pat) {
				ok = false;
				break;
			}
	   	}

	   	if  (!ok) {
	   		printf("Case #%d: Fegla Won\n", it + 1);
	   		continue;	
	   	}

	   	forn(i, 105)
	   		cnt[i].clear();

	   	forn(i, n) {
	   		int cur_cnt = 0;
	   		int id = 0;

	   		for (int j = 0; s[i][j]; ++j) {
	   			if  (j && s[i][j - 1] == s[i][j]) {
	   				++cur_cnt;
	   			} else {
	   				cnt[id].pb(cur_cnt);
	   				id++;
	   				cur_cnt = 1;
	   			}

	   			if  (!s[i][j + 1]) {
	   				cnt[id].pb(cur_cnt);
	   			}	
			}	
		}	

		int res = 0;
		forn(i, 105)
			if  (!cnt[i].empty()) {
				sort(all(cnt[i]));

				int best = int(1e9);
				forn(j, sz(cnt[i])) {
					int cur = 0;
					forn(k, sz(cnt[i])) {
						cur += abs(cnt[i][j] - cnt[i][k]);
					}

					best = min(best, cur);
				}

				res += best;
			}	

		printf("Case #%d: %d\n", it + 1, res);
	}

	return 0;
}
