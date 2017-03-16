#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

long long m[2000];
int b, n;

void solve() {
    cin >> b >> n;
    long long longest = 0;
    for (int i = 0; i < b; ++i) {
        cin >> m[i];
        longest = max(m[i], longest);
    }
    if (n <= b) {
        cout << n;
        return;
    }
    long long r = n * longest, l = 0;
    while (r - l > 1) {
        long long s = (l + r) / 2;
        long long clients = 0;
        for (int i = 0; i < b; ++i) {
            clients += s / m[i] + 1;
        }
        if (clients >= n) {
            r = s;
        } else {
            l = s;
        }
    }
    long long clients = 0;
    for (int i = 0; i < b; ++i) {
        clients += (r - 1) / m[i] + 1;
    }
    for (int i = 0; i < b; ++i) {
        if (r % m[i] == 0) {
            clients++;
            if (clients == n) {
                cout << i + 1;
                return;
            }
        }
    }
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
