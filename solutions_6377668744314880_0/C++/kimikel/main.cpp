#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;




typedef double T;

struct PT {
    T x, y;

    PT() {
    }

    PT(T x, T y) : x(x), y(y) {
    }

    bool operator<(const PT &rhs) const {
        return make_pair(y, x) < make_pair(rhs.y, rhs.x);
    }

    bool operator==(const PT &rhs) const {
        return make_pair(y, x) == make_pair(rhs.y, rhs.x);
    }
};

T cross(PT p, PT q) {
    return p.x * q.y - p.y * q.x;
}

T area2(PT a, PT b, PT c) {
    return cross(a, b) + cross(b, c) + cross(c, a);
}

void ConvexHull(vector<PT> &pts) {
    sort(pts.begin(), pts.end());
    pts.erase(unique(pts.begin(), pts.end()), pts.end());
    vector<PT> up, dn;
    for (int i = 0; i < pts.size(); i++) {
        while (up.size() > 1 && area2(up[up.size() - 2], up.back(), pts[i]) > 0) up.pop_back();
        while (dn.size() > 1 && area2(dn[dn.size() - 2], dn.back(), pts[i]) < 0) dn.pop_back();
        up.push_back(pts[i]);
        dn.push_back(pts[i]);
    }
    pts = dn;
    for (int i = (int) up.size() - 2; i >= 1; i--) pts.push_back(up[i]);
}






int main() {
    int T, N, X[3010], Y[3010], ans[3010];
    cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        
        cin >> N;
        for (int i = 0; i < N; i++) {
            cin >> X[i] >> Y[i];
            ans[i] = N;
        }
        
        for (int mask = 0; mask < (1<<N); mask++) {
            int cost = 0;
            //for (int i = 0; i < N; i++) if (mask & (1<<i)) cost++;
            vector<PT> points;
            for (int i = 0; i < N; i++) {
                if (mask & (1<<i)) {
                    cost++;
                } else {
                    points.push_back(PT(X[i], Y[i]));
                }
            }
            ConvexHull(points);
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < points.size(); j++) {
                    if (X[i] == points[j].x && Y[i] == points[j].y &&
                            cost < ans[i]) {
                        ans[i] = cost;
                    }
                }
            }
        }
        
        cout << "Case #" << tc << ":" << endl;
        for (int i = 0; i < N; i++) cout << ans[i] << endl;
    }

    return 0;
}

