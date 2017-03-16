#include <cstdio>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;

#define x first
#define y second

#define D(x...) fprintf(stderr,x)

typedef long long ll;

typedef pair<ll, ll> pii;

const int MAX_N = 16;

int N;
pii points[MAX_N];
int best[MAX_N];

pii fix;

ll det(pii a, pii b, pii c) {
    pii aa = make_pair(a.x-c.x, a.y-c.y);
    pii bb = make_pair(b.x-c.x, b.y-c.y);
    return aa.x*bb.y - aa.y*bb.x;
}

bool comp(pii a, pii b) {
    if(det(a,b,fix) != 0ll) {
        return det(a,b,fix) > 0ll;
    } else {
        pii c = fix;
        pii aa = make_pair(a.x-c.x, a.y-c.y);
        pii bb = make_pair(b.x-c.x, b.y-c.y);
        return (aa.x*aa.x+aa.y*aa.y) < (bb.x*bb.x+bb.y*bb.y);
    }
}

int ch(vector<pii> p) {
    vector<pii> hull;
    // check if it's just a line
    bool isLine = true;
    for(int i=1;i<p.size() && isLine;i++) {
        for(int j=i+1;j<p.size();j++) {
            if(det(p[i], p[j], p[0]) != 0ll) {
                isLine = false;
                break;
            }
        }
    }

    if(isLine) {
        for(int i=0;i<p.size();i++) {
            hull.push_back(p[i]);
        }
    } else {
        for(int i=1;i<p.size();i++) {
            pii a = make_pair(p[0].y, p[0].x);
            pii b = make_pair(p[i].y, p[i].x);
            if(b < a) {
                swap(p[0], p[i]);
            }
        }
        fix = p[0];
        sort(p.begin()+1, p.end(), comp);
        for(int i=0;i<p.size();i++) {
            while(hull.size() >= 2 && det(hull[hull.size()-1], p[i], hull[hull.size()-2]) <= 0) {
                hull.pop_back();
            }
            hull.push_back(p[i]);
        }

        vector<pii> add;
        for(int i=0;i<hull.size();i++) {
            int k = (i+1)%hull.size();
            for(int j=0;j<p.size();j++) {
                if(det(hull[i], hull[k], p[j]) == 0ll &&
                    min(hull[i].x, hull[k].x) <= p[j].x && p[j].x <= max(hull[i].x, hull[k].x) &&
                    min(hull[i].y, hull[k].y) <= p[j].y && p[j].y <= max(hull[i].y, hull[k].y)) {
                    add.push_back(p[j]);
                }
            }
        }

        for(int i=0;i<add.size();i++) {
            hull.push_back(add[i]);
        }
    }

    int mask = 0;
    for(int i=0;i<hull.size();i++) {
        for(int j=0;j<N;j++) {
            if(hull[i] == points[j]) {
                mask |= (1<<j);
                break;
            }
        }
    }

    return mask;
}

int main() {
    int T;
    scanf("%d",&T);

    for(int z=1;z<=T;z++) {
        scanf("%d",&N);
        for(int i=0;i<N;i++) {
            scanf("%lld %lld",&points[i].x,&points[i].y);
            best[i] = 0;
        }

        for(int i=0;i<(1<<N);i++) {
            vector<pii> p;
            for(int j=0;j<N;j++) {
                if(i & (1<<j)) {
                    p.push_back(points[j]);
                }
            }
            int h = ch(p);
            for(int j=0;j<N;j++) {
                if(h & (1<<j)) {
                    best[j] = max(best[j], __builtin_popcount(i));
                }
            }
        }

        printf("Case #%d:\n",z);
        for(int i=0;i<N;i++) {
            printf("%d\n",N-best[i]);
        }
    }

    return 0;
}
