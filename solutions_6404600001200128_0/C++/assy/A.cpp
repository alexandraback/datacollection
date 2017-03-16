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
typedef pair<int, int> P;
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

P solve() {
    int n;
    cin >> n;
    int m[n];
    for (int i = 0; i < n; i++) {
	cin >> m[i];
    }
    int res1 = 0;
    int diffmax = 0;
    for (int i = 0; i < n-1; i++) {
	res1 += max(0, m[i] - m[i+1]);
	diffmax = max(diffmax, m[i] - m[i+1]);
    }

    int res2 = 0;
    for (int i = 0; i < n-1; i++) {
	res2 += min(diffmax, m[i]);
    }

    return make_pair(res1, res2);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(15);

    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
	P res = solve();
	cout << "Case #" << i << ": " << res.first << " " << res.second << endl;
    }
}
