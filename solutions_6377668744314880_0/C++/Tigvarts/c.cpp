#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

struct pt
{
    int x, y;
    pt(int _x=0, int _y=0): x(_x), y(_y) {}
    friend pt operator - (const pt &a, const pt &b) {
        return pt(a.x - b.x, a.y - b.y);
    }
    friend pt operator - (const pt &a) {
        return pt(-a.x, -a.y);
    }
    friend long long operator * (const pt &a, const pt &b) {
        return (long long)a.x * b.x + (long long)a.y * b.y;
    }
    friend long long operator ^ (const pt &a, const pt &b) {
        return (long long)a.x * b.y - (long long)a.y * b.x;
    }
};

pt p[4000];
int n;
int res[4000];
pt tmp[4000];

int quarter(const pt &a) {
    if (a.y >= 0 && a.x > 0) return 0;
    if (a.y > 0 && a.x <= 0) return 1;
    if (a.y <= 0 & a.x < 0) return 2;
    if (a.y < 0 && a.x >= 0) return 3;
}

bool cmp(const pt &a, const pt &b) {
    if (quarter(a) != quarter(b)) {
        return quarter(a) < quarter(b);
    }
    return (a ^ b) > 0;
}

bool prop(const pt &a, const pt &b) {
    return (a ^ b) == 0 && (a * b) > 0;
}

void solve() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> p[i].x >> p[i].y;
    }
    bool line = true;
    for (int i = 2; i < n; ++i) {
        if (((p[i] - p[0]) ^ (p[1] - p[0])) != 0) {
            line  = false;
            break;
        }
    }
    if (line) {
        for (int i = 0; i < n; ++i) {
            cout << 0 << endl;
        }
        return;
    }
    for (int i = 0; i < n; ++i) {
        res[i] = n - 1;
        for (int j = 0; j < n; ++j) {
            tmp[j - (j > i)] = p[j] - p[i];
        }
        sort(tmp, tmp + n - 1, cmp);
        int r = 1;
        for (int l = 0; l < n - 1; ++l) {
            while (prop(tmp[(r + 1) % (n - 1)], tmp[r])) {
                r = (r + 1) % (n - 1);
            }
            while ((tmp[r] ^ tmp[l]) < 0){
                r = (r + 1) % (n - 1);
            }
            if (prop(tmp[r], tmp[l])) {
                r = (r + 1) % (n - 1);
                while ((tmp[r] ^ tmp[l]) < 0){
                    r = (r + 1) % (n - 1);
                }
            }

            while (prop(tmp[r], tmp[(r + n - 2) % (n - 1)])) {
                r = (r + n - 2) % (n - 1);
            }
            res[i] = min(res[i], (r - l - 1 + 10 * (n - 1)) % (n - 1));
        }
    }
    for (int i = 0; i < n; ++i) {
        cout << res[i] << endl;
    }
}

int main() {
    cin.tie(NULL);
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        printf("Case #%d:\n", i + 1);
        solve();
    }
}
