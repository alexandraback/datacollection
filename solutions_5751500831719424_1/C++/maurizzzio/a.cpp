#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <string>
#include <bitset>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <list>
#include <stack>
#include <sstream>
#include <utility>
#include <numeric>
#include <functional>
using namespace std;
 
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define F(i,a) FOR(i,0,a)
#define ALL(x) x.begin(),x.end()
#define PB push_back
#define X first
#define Y second
#define MS(a, v) memset(a, v, sizeof a)
#define NL printf("\n")
#define SP system("pause")
#define INF 1e9
#define PI acos(-1)
#define EPS 1e-9
#define TR(ar, it) for ( decltype(ar.begin()) it = ar.begin(); it != ar.end(); it++ )
typedef long long LL;
typedef pair<int, int> pii;
typedef vector<int> vi;

vector<string> vs;
vector<vi> r;
int n;
vi cr(string &s) {
	int i = 0, cnt = 0;
	char last;
	vi v;
	while (i < s.size()) {
		if (!i) last = s[i], cnt = 1;
		else {
			if (last == s[i]) ++cnt;
			else v.push_back(cnt), cnt = 1;
			last = s[i];
		}
		++i;
	}
	if (cnt) v.push_back(cnt);
	return v;
}

int solve(vector<string> &str) {
	int c = 0;
	F(i, n - 1) {
		if(vs[i] != vs[i + 1]) return INF;
	}

	F(i, r[0].size()) {
		int bt = INF;
		for (int z = 1; z <= 100; z += 1) {
			int t = 0;
			F(j, n) t += abs(r[j][i] - z);
			bt = min(t, bt);
		}
		c += bt;
	}
	return c;
}

int main() {
	int cas;
	cin >> cas;
	F(z, cas) {
		cin >> n;
		vector<string> str(n);
		vs.clear();
		r.clear();

		F(i, n) {
			cin >> str[i];

			string s = "";
			char last;
			F(j, str[i].size()) {
				if (!j) { s += str[i][j]; last = str[i][j]; }
				else {
					if(str[i][j] != last) {
						last = str[i][j];
						s += last;
					}
				}
			}
			vs.push_back(s);
			r.push_back(cr(str[i]));
		}

		int best = INF;
		best = min(solve(str), best);
		printf("Case #%d: ", z + 1);
		if (best == INF) puts("Fegla Won");
		else printf("%d\n", best);
	}
	return 0;
}