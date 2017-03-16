#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <cmath>
#include <set>
#include <map>
#include <string>
#include <iomanip>
#include <sstream>
#include <functional>
#include <bitset>

using namespace std;

long long reversed(long long num) {
    long long res = 0;
    while (num) {
        res *= 10;
        res += num % 10;
        num /= 10;
    }

    return res;
}

void printans(int test, int ans) {
    cout << "Case #" << test << ": " << ans << endl;
}



int main() {
    freopen("input.txt", "r", stdin);
    freopen("output1.txt", "w", stdout);

    int cases;
    cin >> cases;

    for (int test = 1; test <= cases; test++) {
        int r, c, n;
        cin >> r >> c >> n;

        int ans = 1e9;
        for (int i = 0; i < (1 << r * c); i++) {
            bitset<16> mask(i);

            if (mask.count() != n) {
                continue;
            }

            int u = 0;
            for (int p = 0; p < r * c; p++) {
                if (mask[p]) {
                    if (p % c != 0) {
                        if (mask[p - 1]) {
                            u++;
                        }
                    }

                    if (p - c >= 0) {
                        if (mask[p - c]) {
                            u++;
                        }
                    }
                }
            }
            ans = min(ans, u);
        }

        cout << "Case #" << test << ": " << ans << endl;
    }
}
