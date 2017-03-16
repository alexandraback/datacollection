#include <sstream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <string>
#include <cassert>
#include <ctime>
#include <map>
#include <math.h>
#include <cstdio>
#include <set>
#include <deque>
#include <memory.h>
#include <queue>

#pragma comment(linker, "/STACK:50000000")
typedef long long ll;

using namespace std;

const int maxn = -1;
const int inf = 1e9;

struct pt {
    int x, y;

    pt() {}
    pt(int x, int y) : x(x), y(y) {}

    void read() {
        cin >> x >> y;
    }

    pt operator- (const pt &p) const {
        return pt(x - p.x, y - p.y);
    }

    pt operator+ (const pt &p) const {
        return pt(x + p.x, y + p.y);
    }

    ll operator* (const pt &p) const {
        return 1LL * x * p.y - 1LL * y * p.x;
    }

    ll operator% (const pt &p) const {
        return 1LL * x * p.x + 1LL * y * p.y;
    }

    int up() const {
        if (y > 0 || y == 0 && x > 0) return 1;
        if (y < 0 || y == 0 && x < 0) return -1;
        return 0;
    }

    bool operator< (const pt &p) const {
        if (up() != p.up()) return up() > p.up();
        return ((*this) * p) > 0;
    }
};

int main() {
	freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

	//ios_base::sync_with_stdio(0);
    int tests;
    cin >> tests;
    for (int test = 1; test <= tests; test++) {
        cout << "Case #" << test << ":" << endl;
        cerr << "Case #" << test << ":" << endl;

        int n;
        cin >> n;
        vector<pt> a(n);
        for (int i = 0; i < n; i++) a[i].read();
        if (n == 1) {
            cout << 0 << endl;
            continue;
        }

        for (int i = 0; i < n; i++) {
            int mmn = 1e9;
            for (int j = 0; j < n; j++) if (i != j) {
                int cnt1 = 0, cnt2 = 0;
                for (int k = 0; k < n; k++) {
                    cnt1 += ((a[k] - a[i]) * (a[j] - a[i])) > 0;
                    cnt2 += ((a[k] - a[i]) * (a[j] - a[i])) < 0;
                }
                mmn = min(mmn, cnt1);
                mmn = min(mmn, cnt2);
            }

            vector<pt> b;
            for (int j = 0; j < n; j++) if (i != j) b.push_back(a[j] - a[i]);
            sort(b.begin(), b.end());
            int o = b.size();
            for (int j = 0; j < o; j++) b.push_back(b[j]);

            int mn = 1e9;
            int k = 0;
            for (int j = 0; j < o; j++) {
                int j2 = j;
                while (j2 + 1 < j + o && (b[j] * b[j2 + 1]) == 0 && b[j].up() == b[j2 + 1].up()) j2++;
                k = max(k, j2 + 1);
                while (k != j + o && ((b[j] * b[k]) > 0 || (b[j] * b[k]) == 0 && b[k].up() == b[j].up())) {
                    k++;
                }
                mn = min(mn, k - j2 - 1);
                j = j2;
            }

            cout << mmn << endl;
            assert(mn == mmn);
        }
    }


	return 0;
}
