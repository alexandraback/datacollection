#include <iostream>
#include <string>
#include <array>
#include <cstring>
#include <queue>
#include <cstdlib>
#include <cmath>
#include <algorithm>

using namespace std;
int t, n;
int m[1005];
int main() {
    cin >> t;
    for (int test = 1; test <= t; test++) {
        cin >> n;
        for (int i = 0; i < n; i++) {
            int tmp;
            cin >> tmp;
            m[i] = tmp;
            // cout << m[i] << " ";
        }
        // cout << endl;
        // cout << n << endl;

        int case1 = 0;
        for (int i = 0; i < n-1; i++) {
            if (m[i + 1] < m[i]) {
                // cout << i << endl;
                case1 += m[i] - m[i + 1];
            }
        }
        // number eaten per 10 seconds
        int case2 = 0;
        for (int i = 0; i < n-1; i++) {
            if (m[i] - m[i + 1] > case2) {
                case2 = m[i] - m[i + 1];
            }
        }
        int case2Consumed = 0;
        for (int i = 0; i < n - 1; i++) {
            // if (i == n-1) {
            //     if (case2 > 0)
            //         case2Consumed += m[i];
            //     break;
            // }
            case2Consumed += min(case2, m[i]);
        }
        cout << "Case #" << test << ": " << case1 << " " << case2Consumed << endl;
    }
}
