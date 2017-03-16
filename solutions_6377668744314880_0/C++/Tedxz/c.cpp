#include <cstdio>
#include <iostream>

using namespace std;

const int MAX_N = 3007;

typedef long long ll;

struct v2d {
    ll x;
    ll y;
};

int T;
v2d p[MAX_N];
int n;

ll cross(const v2d & u, const v2d &v) {
    return u.x * v.y - u.y * v.x;
}

int main() {
    freopen("C-small-attempt1.in", "r", stdin);
    freopen("c.out", "w", stdout);

    cin >> T;
    for (int cs = 1; cs <= T; ++cs) {
        cin >> n;
        for (int i = 0; i < n; ++i) {
            cin >> p[i].x >> p[i].y;
        }

        cout << "Case #" << cs << ":\n";

        for (int i = 0; i < n; ++i) {
            int ians = n;
            if (n <= 3) ians = 0;
            for (int j = 0; j < n; ++j) {
                if (i == j) continue;
                int lp = 0, rp = 0;
                v2d v;
                v.x = p[i].x - p[j].x;
                v.y = p[i].y - p[j].y;
                
                for (int k = 0; k < n; ++k) {
                    if (k == i || k == j) continue;
                    v2d w;
                    w.x = p[i].x - p[k].x;
                    w.y = p[i].y - p[k].y;
                    ll crs = cross(v, w);
                    if (crs < 0) ++lp;
                    if (crs > 0) ++rp;
                }
                //cout << lp << " " << rp << endl;
                ians = min(ians, min(lp, rp));


            }
            cout << ians << "\n";
        }

    }

    return 0;
}
