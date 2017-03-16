#include <stdio.h>
#include <string.h>
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <algorithm>
using namespace std;

int a[200];

void solve() {
    int n;
    cin >> n;
    for (int i=0; i<n; i++) {
        a[i] = 0;
    }

    int sum1 = 0;
    int max_diff = 0;
    for (int i=0; i<n; i++) {
        cin >> a[i];
        if (i>0 && a[i]<a[i-1]) {
            sum1 += a[i-1]-a[i];
        }

        if (i>0 && a[i]<a[i-1]) {
            if (a[i-1]-a[i] > max_diff) {
                max_diff = a[i-1]-a[i];
            }
        }
    }

    int sum2 = 0;
    for (int i=1; i<n; i++) {
        if (a[i-1] < max_diff) {
            sum2 += a[i-1];
        }
        else {
            sum2 += max_diff;
        }

    }

    cout << sum1 << ' ' << sum2 << endl;
}

int main() {
    int T;
    cin >> T;
    for (int t=1; t<=T; t++) {
        cout << "Case #" << t << ": ";
        solve();
    }
    return 0;
}
