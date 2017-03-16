#include <bits/stdc++.h>
using namespace std;

int n, f[26];

bool done() {
    for (int i = 0; i < n; i++) {
        if (f[i] > 0) {
            return false;
        }
    }
    return true;
}

string evacuate() {
    int mx = 0, idx = -1;
    for (int i = 0; i < n; i++) {
        if (f[i] > mx) {
            mx = f[i];
            idx = i;
        }
    }

    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (f[i] == mx) {
            ++cnt;
        }
    }

    string ret = "";
    if (cnt == 2) {
        for (int i = 0; i < n; i++) {
            if (f[i] == mx) {
                ret += 'A' + i;
                --f[i];
            }
        }
    } else {
        ret += char('A' + idx);
        --f[idx];
    }
    return ret;
}

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> f[i];
    }

    while(!done()) {
        cout << ' ' << evacuate();
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int numCases;
    cin >> numCases;
    for (int i = 1; i <= numCases; i++) {
        cout << "Case #" << i << ":";
        solve();
        cout << '\n';
    }
    return 0;
}
