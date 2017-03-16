#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <iostream>
#include <set>
#include <vector>
#include <cstring>
#include <string>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <map>
#include <queue>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef vector<double> vd;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef vector<pii> vii;
typedef vector<string> vs;

int f(int r, int c, int n, int x) {
    int s = x ? (r*c+1)/2 : r*c/2;
    if (x == 0 && n <= s) {
        return 0;
    }
    n -= s;
    vi v;
    for (int i = 0; i < r; ++i) for (int j = 0; j < c; ++j) if ((i+j) % 2 == x) {
        int t = 0;
        if (i) ++t;
        if (j) ++t;
        if (i < r-1) ++t;
        if (j < c-1) ++t;
        v.push_back(t);
    }
    sort(v.begin(), v.end());
    int sum = 0;
    for (int i = 0; i < n; ++i) sum += v[i];
    return sum;
}

int main() {
    int T;
    cin >> T;
    for (int test = 1; test <= T; ++test) {
        printf("Case #%d: ", test);
        int r,c,n;
        cin >> r >> c >> n;
        cout << min(f(r,c,n,0), f(r,c,n,1)) << endl;
    }
    return 0;
}
