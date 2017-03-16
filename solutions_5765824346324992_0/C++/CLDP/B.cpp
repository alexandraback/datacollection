#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <cstdio>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

const int MAXN = 1010;
const int INF = 1000000000;

long long x[MAXN];

int main() {
    int T;
    cin >> T;
    for (int times = 1; times <= T; ++times) {
        int B, N;
        cin >> B >> N;
        for (int i = 0; i < B; ++i) cin >> x[i];
        long long L = -1, R = 1LL * 1000000000 * 1000000000;
        
        while (L + 1 < R) {
            long long mid = (L + R) / 2;
            long long temp = 0, avail = 0;
            for (int i = 0; i < B; ++i) {
                temp += (mid + x[i] - 1) / x[i];
                if (mid % x[i] == 0) ++avail;
            }
            if (avail + temp >= N) R = mid; else L = mid;
        }
        int ans = 0;
        long long temp = 0, avail = 0;
        for (int i = 0; i < B; ++i) {
            temp += (R + x[i] - 1) / x[i];
            if (R % x[i] == 0) ++avail;
        }
        temp = N - temp;
        for (int i = 0; i < B; ++i) {
            if (R % x[i] == 0) {
                --temp;
                if (temp == 0) {
                    ans = i + 1;
                    break;
                }
            }
        }
        
        cout << "Case #" << times << ": " << ans << endl;
    }
    return 0;
}
