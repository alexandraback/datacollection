#include "bits/stdc++.h"
using namespace std;
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int, int> pii;
typedef unsigned long long ull;
typedef double dbl;
typedef long double ldb;


int popcnt[1 << 20], n, r, c;

inline bool get_bit(int mask, int p) {
    return (mask >> p) & 1;
}
inline int f(int m) {
    int sum = 0;
    for (int i = 0; i < r; i++) 
        for (int j = 0; j < c; j++)
            if (get_bit(m, i * c + j)) {
                if (j + 1 < c && get_bit(m, i * c + j + 1)) sum++;
                if (i + 1 < r && get_bit(m, i * c + c + j)) sum++;
            }
    return sum;
}
int main() {
//    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    for (int i = 0; i < (1 << 20); i++)
        popcnt[i] = __builtin_popcount(i);
    int T;
    cin >> T;
    

    for (int tc = 1; tc <= T; tc++) {
        cin >>  r >> c >> n;
        int answer = INT_MAX;
        for (int mask = 0; mask < (1 << r * c); mask++) {
            if (popcnt[mask] == n) answer = min(answer, f(mask));
        }

        printf("Case #%d: %d\n", tc, answer);
    }

    return 0;
}
