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

int B;
int N;
ll data[1000000];

int wynik = -1;

bool can(ll b) {
    ll bef = 0;
    rep (i, B) {
        bef += (b + data[i] - 1) / data[i];
        if (bef > N) return true;
    }
    db(b<<" "<<bef);
    rep (i, B) {
        if (b % data[i] == 0) {
            bef++;
            if (bef == N) {
                db("MM");
                wynik = i;
            }
        }
    }
    db(b<<" "<<bef);
    if (bef >= N) return true;
    return false;
}

void solve() {
    scanf("%d%d", &B, &N);
    rep (i, B)
        scanf("%lld", &data[i]);

    ll minb = 0, maxb = (ll)1e18;
    while (minb < maxb) {
        ll cur_b = (minb + maxb) / 2;
        if (can(cur_b)) {
            maxb = cur_b;
        }
        else
            minb = cur_b + 1;
    }
    can(minb);
    db(minb<<" "<<maxb<<" "<<wynik)
    printf("%d\n", wynik + 1);
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
