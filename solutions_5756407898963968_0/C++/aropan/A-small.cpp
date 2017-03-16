#include <iostream>
#include <cstdio>
#include <cassert>
#include <ctime>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>

using namespace std;

template <typename T> T sqr(T x) { return x * x; }
template <typename T> T abs(T x) { return x < 0? -x : x; }
template <typename T> T gcd(T a, T b) { return b? gcd(b, a % b) : a; }
#define foreach(a, b) for(typeof((b).begin()) a = (b).begin(); a != (b).end(); ++a)

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

int main(int argc, char **argv)
{
    ios_base::sync_with_stdio(false);
    // #ifdef LOCAL
    // assert(freopen("inp", "r", stdin));
    // assert(freopen("out", "w", stdout));
    // #endif
    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        cout << "Case #" << t << ": ";
        int c[16];
        memset(c, 0, sizeof(c));
        for (int iter = 0; iter < 2; ++iter) {
            int r;
            cin >> r;
            r -= 1;
            for (int i = 0; i < 4; ++i) {
                for (int j = 0; j < 4; ++j) {
                    int x;
                    cin >> x;
                    x -= 1;
                    if (i == r) {
                        c[x] += 1;
                    }
                }
            }
        }
        int ans = -1;
        for (int i = 0; i < 16; ++i) {
            if (c[i] == 2) {
                if (ans != -1) {
                    ans = -2;
                    break;
                }
                ans = i;
            }
        }
        if (ans == -1) {
            cout << "Volunteer cheated!";
        } else {
        if (ans == -2) {
            cout << "Bad magician!";
        } else
            cout << ans + 1;
        }
        cout << endl;
    }
    fprintf(stderr, "Time execute: %.3lf sec\n", clock() / (double)CLOCKS_PER_SEC);
    return 0;
}
