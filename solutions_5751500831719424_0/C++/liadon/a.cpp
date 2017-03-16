#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <iostream>
using namespace std;
#define FOR(i,a,b) for(int i=(a); i<(b); ++i)
#define REP(i,n) FOR(i,1,(n)+1)
typedef vector<int> vi;
#define pb push_back
typedef pair<int,int> pii;
#define mp make_pair
#define st first
#define nd second
typedef long long ll;
#define INF 1000000001
#define sz size()
#define VAR(n,v) typeof(v) n=(v)
#define ALL(t) t.begin(),t.end()
#define SC(a) scanf("%d", &a)
#define GET(a) int a; SC(a)
#define ISDEBUG 1
#define dprintf(...) if(ISDEBUG) \
{printf("\033[31m"); printf(__VA_ARGS__); printf("\033[0m");}
template <class It> void dptab(It b, It e, const char* f="%d ") {
	if(ISDEBUG) {
		for(It it=b; it!=e; ++it) dprintf(f, *it); dprintf("\n");
}}

vector<int> get_counter(string &s) {
	vi counter;
	int c = 0;
	FOR(i,0,s.sz) {
		if(i>0 && s[i]!=s[i-1]) {
			counter.pb(c);
			c=1;
		} else ++c;
	}
	counter.pb(c);
	return counter;
}

string shrink(string &s) {
	string shrinked;
	FOR(i,0,s.sz) {
		if(i==0 || s[i]!=s[i-1]) {
			shrinked += s[i];
		}
	}
	return shrinked;
}

int get_moves(vector<vi> &counter, int j) {
	vi v;
	FOR(i, 0, counter.sz)
		v.pb(counter[i][j]);
	sort(ALL(v));
	int m = v[v.sz/2];
	int res = 0;
	FOR(i, 0, v.sz)
		res += abs(m-v[i]);
	return res;
}

int main() {
	GET(t);
	FOR(ti, 0, t) {
		int res = 0;
		GET(n);
		string pattern;
		vector<vi> counter;
		FOR(i, 0, n) {
			string s;
			cin >> s;
			if(i==0) {
				pattern = shrink(s);		
			}
			if(pattern != shrink(s))
				res = -1;
			counter.pb(get_counter(s));
			
		}
		if(-1==res) {
			printf("Case #%d: %s\n", ti+1, "Fegla Won");
			continue;
		}

		FOR(i, 0, pattern.sz) {
			res += get_moves(counter, i);
		}

		printf("Case #%d: %d\n", ti+1, res);
	}
	return 0;
}
