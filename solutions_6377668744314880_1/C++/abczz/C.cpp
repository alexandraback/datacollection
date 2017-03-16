#include <functional>
#include <algorithm>
#include <stdexcept>
#include <iostream>
#include <sstream>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <utility>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <cctype>
#include <cstdio>
#include <vector>
#include <string>
#include <bitset>
#include <cmath>
#include <queue>
#include <stack>
#include <ctime>
#include <list>
#include <map>
#include <set>

#define REP(i,n) for(int i=0;i<(n);i++)
#define TR(i,x) for(__typeof(x.begin()) i=x.begin();i!=x.end();i++)
#define ALL(x) x.begin(),x.end()
#define SORT(x) sort(ALL(x))
#define CLEAR(x) memset(x,0,sizeof(x))
#define FILL(x,c) memset(x,c,sizeof(x))
#define SIZE(x) (int)(x).size()

#define MP make_pair
#define PB push_back

using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<int,int> PII;

const int MAXN = 3010;
const LD eps = (LD)1e-15;
const LD pi = acos((LD)-1.0);

struct pt {
    int x, y;
    LD d;
    pt() {}
    pt(int x, int y):x(x), y(y) {d = atan2((LD)y, (LD)x);}

    pt operator - (const pt& p) const {return pt(x - p.x, y - p.y);}

    bool operator < (const pt& p) const {return d + eps < p.d;}

    void rd() {scanf("%d%d", &x, &y); d = atan2((LD)y, (LD)x);}
} pts[MAXN], tp[MAXN];

int N;

int Calc(LD x, bool flag) {
    int st = 0, ed = N - 2;
    if (!flag) {
        while (st <= ed) {
            int mid = st + ed >> 1;
            if (tp[mid].d < x - eps) {
                st = mid + 1;
            } else {
                ed = mid - 1;
            }
        }
    } else {
        while (st <= ed) {
            int mid = st + ed >> 1;
            if (tp[mid].d < x + eps) {
                st = mid + 1;
            } else {
                ed = mid - 1;
            }
        }
    }
    return st;
}

int Gao(LD L, LD R) {
    int ret = 0;
    while (L > pi) L -= pi + pi;
    while (R > pi) R -= pi + pi;
    if (L < R) {
        ret += Calc(R, false) - Calc(L, true);
    } else {
        assert(L > R);
        ret += Calc(pi, true) - Calc(L, true);
//        cerr << "first:" << ret << endl;
        ret += Calc(R, false) - Calc(-pi, true);
//        cerr << "second:" << R << "," << Calc(R,false) << endl;
    }
    return ret;
}

void Solve() {
    cin >> N;
    REP(i, N) pts[i].rd();
    REP(i, N) {
        int m = 0;
        REP(j, N) if (j != i) {
            tp[m++] = pts[j] - pts[i];
        }
        sort(tp, tp + m);
        int ans = N - 1;
//        cerr << "i = " << i << endl;
 //       REP(j, m) 
  //          cerr << fixed << setprecision(15) << tp[j].d << endl; 
        REP(j, m) {
            LD d = tp[j].d;
    //        cerr << fixed << setprecision(15) << d << endl; 
   //         if (i == 3) cerr << Gao(d, d + pi) << ", " << Gao(d + pi, d + pi + pi) << endl;
            ans = min(ans, Gao(d, d + pi));
            ans = min(ans, Gao(d + pi, d + pi + pi));
        }
        printf("%d\n", ans);
    }
}

int main() {
    //	freopen("C.in","r",stdin);
//    	freopen("C-small-attempt0.in","r",stdin);freopen("C-small-attempt0.out","w",stdout);
  //  	freopen("C-small-attempt1.in","r",stdin);freopen("C-small-attempt1.out","w",stdout);
    //	freopen("C-small-attempt2.in","r",stdin);freopen("C-small-attempt2.out","w",stdout);
    	freopen("C-large.in","r",stdin);freopen("C-large.out","w",stdout);
    //    cerr << fixed << setprecision(30) << atan2(1e6,1e6) << ", " << atan2(1e6 + 1, 1e6 - 1) << endl;
    int cas;
    cin >> cas;
    for (int T = 1; T <= cas; ++T) {
        printf("Case #%d:\n", T);
        Solve();
        cerr << "case " << T <<endl;
    }
    return 0;
}

