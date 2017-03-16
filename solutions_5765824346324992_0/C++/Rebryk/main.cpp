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

int T, b, n, ans;
int a[MAXN];

int gcd(int a, int b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

set < int > f;
set < pair < int, int > > q;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        cin >> b >> n;
        for (int i = 0; i < b; ++i)
            cin >> a[i];
        
        f.clear();
        q.clear();
        
        int g = a[0];
        for (int i = 1; i < b; ++i)
            g = (g / gcd(g, a[i])) * a[i];
        
        long long cnt = 0;
        for (int i = 0; i < b; ++i)
            cnt += g / a[i];
        
        if (cnt < n) {
            n %= cnt;
            if (n == 0)
                n = (int)cnt;
        }
        
        for (int i = 0; i < b; ++i)
            f.insert(i);
        
        int tm = 0;
        for (int i = 0; i < n - 1; ++i) {
            int x;
            if (f.size() > 0) {
                x = *f.begin();
                f.erase(f.begin());
            } else {
                tm = (*q.begin()).first;
                x = (*q.begin()).second;
                q.erase(q.begin());
            }
            q.insert(make_pair(tm + a[x], x));
        }
        if (f.size() > 0)
            ans = *f.begin();
        else
            ans = (*q.begin()).second;
        
        cout << "Case #" << t << ": " << ans + 1 << endl;
    }
}