#include <bits/stdc++.h>

#define INF 1000000010
#define FO(i,a,b) for (int (i) = (a); (i) < (b); ++(i))

using namespace std;
//PAIRS:
#define mp make_pair
#define fi first
#define se second
typedef pair<int,int> pii;
typedef long long ll;

/*~~~~TEMPLATE END~~~~*/

int _T;
int N;
int x[3005], y[3005];
int ans[3005];

//NTS: To optimize, I need a sweep around a point
//Kill me >>
int main() {
    freopen ("q3.in", "r", stdin);
    freopen ("q3.out", "w", stdout);
    scanf ("%d", &_T);
    FO (_z,0,_T) {
        printf ("Case #%d:\n", _z+1);
        scanf ("%d", &N);
        FO (i,0,N) scanf ("%d %d", &x[i], &y[i]);
        FO (i,0,N) ans[i] = INF;
        if (N == 1) {
            printf ("0\n");
            continue;
        }
        FO (i,0,N) {
            FO (p,0,N) {
                if (i == p) continue;
                int lCoun = 0;
                int rCoun = 0;
                if (x[i] == x[p]) {
                    //Special case:
                    FO (t,0,N) {
                        if (x[t] < x[i]) lCoun++;
                        if (x[t] > x[i]) rCoun++;
                    }
                } else {
                    //Find the line equation:
                    ll dY = y[p] - y[i];
                    ll dX = x[p] - x[i];
                    ll xCo = dY;
                    ll yCo = -dX;
                    long long zCo = dX*y[i] - dY*x[i];
                    FO (t,0,N) {
                        long long v = xCo * x[t] + yCo * y[t] + zCo;
                        if (v < 0) lCoun++;
                        if (v > 0) rCoun++;
                    }
                }
                ans[i] = min (ans[i], lCoun);
                ans[i] = min (ans[i], rCoun);
            }
        }
        FO (i,0,N) printf ("%d\n", ans[i]);
    }
    return 0;
}
