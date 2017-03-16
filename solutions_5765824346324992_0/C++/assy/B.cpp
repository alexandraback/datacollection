#include <algorithm>
#include <iostream>
#include <cstdio>
#include <map>
#include <numeric>
#include <cmath>
#include <set>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <complex>
#include <string.h>
#include <unordered_set>
#include <unordered_map>
#include <iomanip>
using namespace std;

#define endl '\n'
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define uniq(v) (v).erase(unique((v).begin(), (v).end()), (v).end())

typedef long long ll;
typedef pair<ll, int> P;
typedef unsigned int uint;
typedef unsigned long long ull;
struct pairhash {
public:
    template<typename T, typename U>
    size_t operator()(const pair<T, U> &x) const {
	size_t seed = hash<T>()(x.first);
	return hash<U>()(x.second) + 0x9e3779b9 + (seed<<6) + (seed>>2);
    }
};

const int inf = 1000000009;
const double eps = 1e-8;
const string yes = "YES", no = "NO";

int solve() {
    int n, b;
    cin >> b >> n;
    ll m[b];
    for (int i = 0; i < b; i++)
	cin >> m[i];

    ll lb = 0, ub = 1e18;
    while (ub - lb > 1) {
	ll mid = (lb + ub) / 2;
	ll num = 0;
	for (int i = 0; i < b; i++) {
	    num += mid / m[i] + (mid%m[i]==0?0:1);
	}
	if (num >= n) {
	    ub = mid;
	} else {
	    lb = mid;
	}
    }
    ll num = 0;
    vector<P> vec(b);
    for (int i = 0; i < b; i++) {
	ll cut = lb / m[i];
	num += cut;
	vec[i] = make_pair(m[i] * cut, i);
    }
    sort(all(vec));
    /*
    cerr << lb << " " << num << endl;
    for (int i = 0; i < b; i++)
	cerr << vec[i].second << " " << vec[i].first << endl;
    */
    return vec[n-num-1].second + 1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(15);

    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
	cout << "Case #" << i << ": " << solve() << endl;
    }
}
