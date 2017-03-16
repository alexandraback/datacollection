#include <iostream>
#include <stdio.h>
#include <vector>
#include <math.h>
#include <string>
#include <algorithm>
#include <string.h>
#include <stack>
#include <assert.h>
#include <cstdio>
#include <cstring>
#include <unordered_map>
#include <queue>

using namespace std;

int T;
int n, m, x;

int getCnt(int x) {
    int cnt = 0;
    while (x) {
        cnt += (x & 1);
        x >>= 1;
    }
    return cnt;
}

bool a[18][18];

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        cin >> n >> m >> x;
        int ans = 1e9;
        
        if (n == 1 && m == 1) {
            ans = 0;
        } else if (n == 1 || m == 1) {
            if (n != 1)
                swap(n, m);
            if (m % 2 == 0) {
                int y = x - m / 2;
                if (y > 0)
                    ans = 1 + 2 * max(0, y - 1);
                else
                    ans = 0;
            } else {
                int y = x - m / 2 - 1;
                if (y > 0)
                    ans = 2 * y;
                else
                    ans = 0;
                
                y = x - m / 2;
                if (y > 0)
                    ans = min(ans, min(y, 2) + 2 * max(0, y - 2));
                else
                    ans = 0;
            }
        } else if (n % 2 + m % 2 <= 1) {
            if (n % 2 != 0)
                swap(n, m);
            int y = x - n * (m / 2) - (n / 2) * (m % 2);
            int z = m + n - 4;
            if (y > 0)
                ans = 2 * min(y, 2) + 3 * min(max(0, y - 2), z) + 4 * max(0, y - 2 - z);
            else
                ans = 0;
        } else {
            int y = x - n * (m / 2) - (n + 1) / 2;
            int z = 2 * (n / 2) + 2 * (m / 2);
            if (y > 0)
                ans = 3 * min(y, z) + 4 * max(0, y - z);
            else
                ans = 0;
            
            y = x - n * (m / 2) - n / 2;
            z = 2 * ((n + 1) / 2 - 2) + 2 * ((m + 1) / 2 - 2);
            if (y > 0)
                ans = min(ans, 2 * min(y, 4) + 3 * min(max(0, y - 4), z) + 4 * max(0, y - 4 - z));
            else
                ans = 0;
        }
        cout << "Case #" << t << ": " << ans << endl;
    }
    return 0;
}