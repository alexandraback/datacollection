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

typedef long long LL;

LL cnt(vector<int>& barbers, LL time) {
    LL c = 0;
    for (int i = 0; i < barbers.size(); ++i) {
        c += (time + barbers[i] - 1) / barbers[i];
    }
    return c;
}


void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> barbers(n);
    for (int i = 0; i < n; ++i) {
        cin >> barbers[i];
    }
    LL left = 0, right = 100000000000000LL;
    while (left <= right) {
        LL mid = (left + right) / 2;
        if (cnt(barbers, mid) >= m) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    LL low = m - cnt(barbers, right);
    // cout << right << " " << low << endl;
    for (int i = 0; i < barbers.size(); ++i) {
        if (right % barbers[i] == 0) {
            if (low == 1) {
                cout << i + 1 << endl;
                break;
            }
            -- low;
        }
    }
}


int main() {
    int testcase;
    freopen("/Volumes/Data/download/B-small-attempt0.in", "r", stdin);
    freopen("/Volumes/Data/download/out.txt", "w", stdout);

    cin >> testcase;
    for (int i = 1; i <= testcase; ++i) {
        cout << "Case #" << i << ": ";
        solve();
    }
    return 0;
}
