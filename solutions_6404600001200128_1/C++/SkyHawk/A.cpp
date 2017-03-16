#include <cassert>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <iterator>
#include <utility>
#include <algorithm>
#include <list>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <queue>

using namespace std;

#define pb push_back
#define sz(v) ((long long)v.size())
#define mp make_pair
#define FOR(i,n) for(int i = 0;i < (n);++i)

long long MOD = 1000000007;

int T;
long long ar[1010];

int main() {
    cin >> T;
    FOR(itest, T) {
        long long n;
        cin >> n;
        FOR(i, n)
            cin >> ar[i];
        long long ans1 = 0;
        long long ans2 = 0;
        long long ans3 = 0;
        for (long long i = 1; i < n; ++i) {
            if (ar[i] < ar[i-1]) {
                ans1 += ar[i-1] - ar[i];
                ans2 = max(ans2, ar[i-1] - ar[i]);
            }
        }
        FOR(i,n-1) {
            if (ar[i] < ans2)
                ans3 += ans2 - ar[i];
        }
        cout << "Case #" << (itest + 1) << ": " << ans1 << " " << ans2 * (n-1) - ans3 << endl;
    }
}