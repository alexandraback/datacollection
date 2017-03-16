#include <iostream>
#include <fstream>
#include <cstdio>
#include <iomanip>
#include <sstream>
#include <cstring>
#include <string>
#include <cmath>
#include <stack>
#include <list>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <numeric>
#include <utility>
#include <functional>
#include <limits>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef pair<int,int> pii;
typedef vector<vector<int> > graph;

const double pi = acos(-1.0);

#define oned(a, x1, x2) { cout << #a << ":"; for(int _i = (x1); _i < (x2); _i++){ cout << " " << a[_i]; } cout << endl; }
#define twod(a, x1, x2, y1, y2) { cout << #a << ":" << endl; for(int _i = (x1); _i < (x2); _i++){ for(int _j = (y1); _j < (y2); _j++){ cout << (_j > y1 ? " " : "") << a[_i][_j]; } cout << endl; } }

#define mp make_pair
#define pb push_back
#define fst first
#define snd second

int TESTS, CASE;

const int MAXN = 105;

int n;
string s[MAXN];
vector<int> cnt[MAXN];

void solve() {
	cout << "Case #" << CASE << ": ";
	
	string t;
	int m = s[0].size();
	char last = -1;
	for(int i = 0; i < m; i++) {
		if(s[0][i]!=last) {
			t += s[0][i];
			last = s[0][i];
		}
	}
	m = t.size();
	for(int i = 0; i < MAXN; i++) {
		cnt[i].clear();
	}
	for(int i = 0; i < n; i++) {
		int sz = s[i].size();
		int j, k;
		for(j = 0, k = 0; j < sz && k < m; ) {
			if(s[i][j]!=t[k]) {
				break;
			}
			int curr = 0;
			while(j < sz && s[i][j]==t[k]) {
				curr++;
				j++;
			}
			cnt[k].pb(curr);
			k++;
		}
		if(j<sz || k<m) {
			cout << "Fegla Won" << '\n';
			return;
		}
	}
	
	int ans = 0;
	for(int i = 0; i < m; i++) {
		sort(cnt[i].begin(),cnt[i].end());
		int sz = cnt[i].size();
		int mid = cnt[i][sz/2];
		for(int j = 0; j < sz; j++) {
//			cout << i << ' ' << cnt[i][j] << endl;
			ans += abs(cnt[i][j]-mid);
		}
	}
	cout << ans << '\n';
}

int main() {
	freopen("input.in", "r", stdin);
	freopen("small-output.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin >> TESTS;
	for(CASE = 1; CASE <= TESTS; CASE++) {
		cin >> n;
		for(int i = 0; i < n; i++) {
			cin >> s[i];
		}
		solve();
	}
}
