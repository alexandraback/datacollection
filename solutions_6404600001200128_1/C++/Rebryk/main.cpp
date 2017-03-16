#include <iostream>
#include <stdio.h>
#include <math.h>
#include <vector>
#include <string.h>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <algorithm>

using namespace std;

const int MAXN = 1010;

int T, n;
int a[MAXN];
int cnt1, cnt2;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        cin >> n;
        for (int i = 0; i < n; ++i)
            cin >> a[i];
        
        cnt1 = cnt2 = 0;
        
        int _max = 0;
        for (int i = 0; i < n - 1; ++i)
            if (a[i] > a[i + 1]) {
                cnt1 += a[i] - a[i + 1];
                _max = max(_max, a[i] - a[i + 1]);
            }
        
        for (int i = 0; i < n - 1; ++i)
            cnt2 += min(_max, a[i]);
        
        cout << "Case #" << t << ": " << cnt1 << " " << cnt2 << endl;
    }
}