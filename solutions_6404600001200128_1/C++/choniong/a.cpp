#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;

int main () {
    int T;
    cin >> T;
    for (int tt = 1; tt <= T; ++tt) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        int eaten1 = 0;
        int maxdis = 0;
        for (int i = 0; i < n-1; ++i) {
            if (a[i] > a[i+1]) {
                eaten1 += a[i] - a[i+1];
                maxdis = max(maxdis, a[i] - a[i+1]);
            }
        }

        int eaten2 = 0;
        for (int i = 0; i < n-1; ++i) {
            eaten2 += min(maxdis, a[i]);
        }

        printf("Case #%d: %d %d\n", tt, eaten1, eaten2);

    }

    return 0;
}
