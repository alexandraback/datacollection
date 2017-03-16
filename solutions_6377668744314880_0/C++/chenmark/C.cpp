#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <set>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
#include <memory.h>
#include <string>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include <cassert>

#define FF first
#define SS second
#define MP make_pair
#define PB push_back

#define MOD 1000000007
#define INF 2000000000

using namespace std;

typedef long long LL;
typedef pair<int,int> PII;

int T, N;

struct PT { 
    LL x, y; 
    PT() {} PT(LL x, LL y) : x(x), y(y) {}
    bool operator< (const PT &rhs) const { return make_pair(y,x) <  make_pair(rhs.y,rhs.x); }
    bool operator==(const PT &rhs) const { return make_pair(y,x) == make_pair(rhs.y,rhs.x); }
};

vector<PT> pts;

LL cross(PT p, PT q) { return p.x*q.y-p.y*q.x; }
LL area2(PT a, PT b, PT c) { return cross(a,b) + cross(b,c) + cross(c,a); }

void ConvexHull(vector<PT> &pts) {
    sort(pts.begin(), pts.end()); pts.erase(unique(pts.begin(), pts.end()), pts.end());

    vector<PT> up, dn;

    for (int i = 0; i < pts.size(); i++) {
        while (up.size() > 1 && area2(up[up.size()-2], up.back(), pts[i]) > 0) up.pop_back();
        while (dn.size() > 1 && area2(dn[dn.size()-2], dn.back(), pts[i]) < 0) dn.pop_back();
        up.push_back(pts[i]);
        dn.push_back(pts[i]);
    }

    pts = dn;
    for (int i = (int) up.size() - 2; i >= 1; i--) pts.push_back(up[i]);
}

const int MAXN = 20;
int x[MAXN], y[MAXN], res[MAXN];

vector<PT> xy;

int main() {
    scanf("%d", &T);

    for (int test = 0; test < T; test++) {
        // remember to reset structures
        cin >> N; xy.clear();

        for (int i = 0; i < N; i++) {
            cin >> x[i] >> y[i]; xy.PB(PT(x[i],y[i]));
            res[i] = N-1;
        }

        for (int i = 0; i < (1 << N); i++) {
            pts.clear(); int pcnt = 0;

            for (int j = 0; j < N; j++) {
                if (i & (1 << j)) {
                    pts.PB(xy[j]); 
                    pcnt++;
                }
            }

            ConvexHull(pts);

            //cout << "DBG " << (int)((i & 1) > 0) << " " << (int)((i & 2) > 0) << " " << (int)((i & 4) > 0) << " " << (int)((i & 8) > 0) << " " << (int)((i & 16) > 0) << " " << pcnt << " " << pts.size() << endl;

            for (int j = 0; j < N; j++) {
                for (int k = 0; k < pts.size(); k++) {
                    if (xy[j] == pts[k]) res[j] = min(res[j], N-pcnt);
                }
            }
        }

        cout << "Case #" << (test+1) << ":\n";
        for (int i = 0; i < N; i++) {
            cout << res[i] << "\n";
        }
    }
    
    return 0; 
}
