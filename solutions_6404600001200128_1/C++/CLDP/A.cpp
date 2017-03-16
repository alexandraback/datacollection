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

int x[MAXN];

int main() {
    int T;
    cin >> T;
    for (int times = 1; times <= T; ++times) {
        int N;
        cin >> N;
        for (int i = 0; i < N; ++i) cin >> x[i];
        int ans1 = 0, ans2 = 0, rate = 0;
        for (int i = 1; i < N; ++i)
         if (x[i] < x[i - 1]) {
             ans1 += x[i - 1] - x[i];
             rate = max(rate, x[i - 1] - x[i]);
         }
        
        for (int i = 0; i < N - 1; ++i) {
            ans2 += min(rate, x[i]);
        }
        cout << "Case #" << times << ": " << ans1 << " " << ans2 << endl;
    }
    return 0;
}
