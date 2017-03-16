#include <iostream>
#include <vector>

using namespace std;

struct pt {
    long long x, y;
};

long long cross(const pt& a, const pt& b) {
    return a.x * b.y - a.y * b.x;
}

pt operator-(const pt& a, const pt& b) {
    pt res;
    res.x = a.x - b.x;
    res.y = a.y - b.y;
    return res;
}

int main() {
    int T;
    cin >> T;
    for (int cs = 1; cs <= T; ++cs) {
        int n;
        cin >> n;
        vector<pt> a(n);
        for (int i = 0; i < n; ++i)
            cin >> a[i].x >> a[i].y;
        cout << "Case #" << cs << ":" << endl;
        if (n == 1 || n == 2) {
            for (int i = 0; i < n; ++i)
                cout << 0 << endl;
            continue;
        }
        for (int i = 0; i < n; ++i) {
            int ans = n;
            for (int j = 0; j < n; ++j) {
                if (j == i)
                    continue;
                int neg = 0, pos = 0;
                for (int k = 0; k < n; ++k) {
                    long long t = cross(a[i] - a[j], a[k] - a[j]);
                    if (t < 0)
                        ++neg;
                    if (t > 0)
                        ++pos;
                }
                ans = min(ans, min(neg, pos));
            }
            cout << ans << endl;
        }
    }
    return 0;
}
