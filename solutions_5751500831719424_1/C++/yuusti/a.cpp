#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <numeric>
#include <cctype>
#include <tuple>
#include <iterator>
#include <bitset>

#ifdef _MSC_VER
#include <agents.h>
#endif

#define FOR(i, a, b) for(int i = (a); i < (int)(b); ++i)
#define rep(i, n) FOR(i, 0, n)
#define ALL(v) v.begin(), v.end()
#define REV(v) v.rbegin(), v.rend()
#define MEMSET(v, s) memset(v, s, sizeof(v))
#define X first
#define Y second
#define MP make_pair

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> P;

int get_dist(vector<int> v){
	int n = v.size();
	sort(ALL(v));
	int med = v[n / 2];
	int res = 0;
	rep(i, n) res += abs(v[i] - med);
	return res;
}

int main(){
	int T;
	cin >> T;
	FOR(t, 1, T + 1){
		printf("Case #%d: ", t);

		int n;
		cin >> n;
		vector<string> vs(n);
		rep(i, n) cin >> vs[i];
		set<string> s;
		rep(i, n){
			string t = vs[i];
			t.erase(unique(ALL(t)), t.end());
			s.insert(t);
		}
		if (s.size() > 1){
			cout << "Fegla Won" << endl;
			continue;
		}

		int m = s.begin()->size();

		vector<vector<int>> v(m);
		for (auto &t : vs){
			char prv = '.';
			int idx = 0, cnt = 0;
			rep(i, t.size()+1){
				if (i == t.size() || t[i] != prv){
					if(cnt) v[idx++].push_back(cnt);
					if(i < t.size()) prv = t[i];
					cnt = 1;
				}
				else{
					++cnt;
				}
			}
		}
		int ans = 0;
		rep(i, m) ans += get_dist(v[i]);
		cout << ans << endl;
	}

	return 0;
}