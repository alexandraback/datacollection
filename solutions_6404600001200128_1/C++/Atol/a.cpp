#include <iostream>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <vector>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <sstream>
using namespace std;
typedef vector<string> vs;
typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> pii;
#define sz(A) (int)(A).size()
#define FOR(A,B) for(int A=0; A < (int) (B);A++)
#define FOREACH(I,C) for(__typeof(C.begin()) I = (C).begin(); I != (C).end(); I++)
#define pb push_back
#define all(x) x.begin() , x.end()
#define mp make_pair

int n;
vector<int> v;
long long inf = 100000000000ll;

long long calc_min_all() {
	long long ans = 0;
	for(int i = 1; i < n; i++) {
		int comeu = v[i-1] - v[i];
		ans += max(0, comeu);
	}
	return ans;
}

long long calcx(long long val) {
	long long ans = 0;
	for(int i = 1; i < n; i++) {
		int comeu = v[i-1] - v[i];
		if (val < comeu) {
			return inf;
		}
		ans += min(val, (ll) v[i-1]);
	}
	return ans;
}

long long calc_min_const() {
	long long ans = inf;
	FOR(val, 1000000) {
		long long tmp = calcx(val);
		ans = min(ans, tmp);
	}
	return ans;
}

void solve() {
	cin >> n;
	v.clear();
	FOR(i,n) {
		int aux;
		cin >> aux;
		v.pb(aux);
	}

	long long ans1 = calc_min_all();
	long long ans2 = calc_min_const();
	cout << ans1 << " " << ans2 << endl;
}

int main() {
  int num_testes;
  scanf("%d", &num_testes);
  for(int t = 1; t <= num_testes; t++) {
    printf("Case #%d: ", t);
    solve();
  }
  return 0;
}
