#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdio>
#include <cstring>
#include <map>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;


void solve() {
    int n, r1 = 0, r2 = 0;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i < n; ++i) {
        r1 += (a[i] < a[i - 1]? a[i - 1] - a[i]: 0);
    }
    int rate = 0;
    for (int i = 1; i < n; ++i) {
        rate = max(rate, a[i - 1] - a[i]);
    }
    for (int i = 0; i < n - 1; ++i) {
        r2 += min(rate, a[i]);
    }
    cout << r1 << " " << r2 << endl;
}

int main() {
    int testcase;
    freopen("/Volumes/Data/download/A-small-attempt0.in", "r", stdin);
    freopen("/Volumes/Data/download/out.txt", "w", stdout);

    cin >> testcase;
    for (int i = 1; i <= testcase; ++i) {
        cout << "Case #" << i << ": ";
        solve();
    }
    return 0;
}
