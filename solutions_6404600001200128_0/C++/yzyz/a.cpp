#include <iostream>
#include <cstdlib>
#include <algorithm>
#define MAXN 1010

using namespace std;

int n,m[MAXN];

int ct1() {
    int res = 0;
    for (int i = 1; i < n; i++)
        res += max(m[i-1] - m[i], 0);
    return res;
}

int ct2() {
    int res = 0, mx = 0;
    for (int i = 1; i < n; i++) {
        mx = max(mx, m[i-1] - m[i]);
    }
    for (int i = 1; i < n; i++) {
        res += min(mx, m[i-1]);
    }
    return res;
}

int main() {
    int T;
    cin >> T;
    for (int TC = 1; TC <= T; TC++) {
        cin >> n;
        for (int i = 0; i < n; i++) cin >> m[i];
        cout << "Case #" << TC << ": ";
        cout << ct1() << ' ' << ct2() << '\n';
    }
}
