#include <algorithm>
#include <array>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

#define rep(i,b) for(auto i=(0);i<(b);++i)
#define fo(i,a,b) for(auto i=(a);i<=(b);++i)
#define ford(i,a,b) for(auto i=(a);i>=(b);--i)
#define fore(a,b) for(auto a = (b).begin();a!=(b).end();++a)
#define vv vector
#define pb push_back
#define ll long long
#define ld long double
#define ss(a) (int)(a).size()
#define all(x) (x).begin(),(x).end()
#define clr(x,a) memset(x,a,sizeof(x))
#define vi vv<int>
#define vs vv<string>

int cond = (ll)1;
#define db(x) { if (cond > 0) { cond--; rep (xxx, 1) cerr << __LINE__ << " " << #x << " " << x << endl; cerr.flush(); } }

int N;

class pkt {
    public:
    ll x, y;

    pkt(ld _x, ld _y) {
        x = _x;
        y = _y;
    };
    pkt () {}
    bool operator < (const  pkt&p2) const {
        ld a1 = atan2l(x, y);
        ld a2 = atan2l(p2.x, p2.y);
        return a1 < a2;
    }
};

pkt p[11111];

ld pi = 2 * acosl(0);

int check(int p_i) {
    vector<pkt>other;
    rep (i, N) {
        if (i != p_i) {
            ld x = p[p_i].x - p[i].x;
            ld y = p[p_i].y - p[i].y;
            other.push_back(pkt(x, y));
        }
    }
    sort(all(other));
    if (other.size() <= 2) return 0;

    int nj = 0;
    int s = other.size();
    int maxdiff = 0;
    db(p_i<<" "<<s);
    for (int j = 0; j < other.size(); j++) {
        while (true) {
            nj = max(nj, j);
            int nn = nj;
            if (nn >= s + j) break;
            bool ok = ((other[nn % s].x * other[j % s].y -
                        other[j % s].x * other[nn % s].y) >= 0);
            if (ok) {
                nj = nn + 1;
            }
            else
                break;
        }
        maxdiff = max(maxdiff, nj - j);
    }
    db(maxdiff);

    return s - maxdiff;
}

void solve() {
    scanf("%d", &N);
    rep (i, N) {
        int x, y;
        scanf("%d%d", &x, &y);
        p[i] = pkt(x, y);
    }
    printf("\n");
    rep (i, N) {
        printf("%d\n", check(i));
    }
}

int main(int argc, char ** argv) {
    ios::sync_with_stdio(false);

    //  freopen("../1.in","r",stdin);
    //  freopen("../2.in","r",stdin);
    //  freopen("../3.in","r",stdin);
    //  freopen("../A-small.in","r",stdin); freopen("../A-small.out","w",stdout);
    //  freopen("../A-small-attempt0.in","r",stdin);freopen("../A-small-attempt0.out","w",stdout);
    //  freopen("../A-small-attempt1.in","r",stdin);freopen("../A-small-attempt1.out","w",stdout);
    //  freopen("../A-small-attempt2.in","r",stdin);freopen("../A-small-attempt2.out","w",stdout);
    //  freopen("../A-large.in","r",stdin); freopen("../A-large.out","w",stdout);

    cond = argc >= 2 && argv[1][0] == 'q' ? 1 << 30 : 0;
    int t;
    scanf("%d", &t);
    fo (i, 1, t) {
        printf("Case #%d: ", i);
        solve();
        fflush(stdout);
        cerr.flush();
    }
	return 0;
}
