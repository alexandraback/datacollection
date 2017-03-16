#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int m[100000];

void solve() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> m[i];
    }
    int y = 0, z = 0;
    int speed = 0;
    for (int i = 1; i < n; ++i) {
        y += max(0, m[i - 1] - m[i]);
        speed = max(speed, m[i - 1] - m[i]);
    }
    for (int i = 1; i < n; ++i) {
        z += min(speed, m[i - 1]);
    }
    cout << y << " " << z;
}

int main() {
    cin.tie(NULL);
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        printf("Case #%d: ", i + 1);
        solve();
        printf("\n");
    }
}
