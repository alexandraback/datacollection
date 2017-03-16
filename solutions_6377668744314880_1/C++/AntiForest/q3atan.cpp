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

#define EPS 1e-9
#define PI 3.14159265359

/*~~~~TEMPLATE END~~~~*/

int _T;
int N;
int x[3005], y[3005];
int ans[3005];

struct grad {
    double y, x;
    double ang;
    grad (double _y = 1, double _x = 0) {
        y = _y; x = _x;
        ang = atan2 (_y,_x);
        //fprintf (stderr, "%lf %lf\n", _y, _x);
        //fprintf (stderr, "ang: %lf\n", ang);
    }
    bool operator < (const grad &_a) const {
        return ang < _a.ang;
    }
};

bool isEq (long double a, long double b) {
    return (abs (a-b)) < EPS;
}
//NTS: To optimize, I need a sweep around a point
//Kill me >>
//Just pray to all the gods this is accurate enough

vector <grad> topHalf;
vector <grad> botHalf;

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
            topHalf.clear();
            botHalf.clear();
            //fprintf (stderr, "%d\n", i);
            FO (p,0,N) {
                if (i == p) continue;
                double dY = y[p]-y[i];
                double dX = x[p]-x[i];
                if (dY >= 0) {
                    //push to topHalf
                    topHalf.push_back (grad (dY,dX));
                } else {
                    //push to botHalf
                    botHalf.push_back (grad (dY,dX));
                }
            }
            sort (topHalf.begin(), topHalf.end());
            sort (botHalf.begin(), botHalf.end());
            //fprintf (stderr, "HERE: %d %d \n", topHalf.size(), botHalf.size());
            //FO (_x,0,topHalf.size()) fprintf (stderr, "%lf\n", topHalf[_x].ang);
            //FO (_x,0,botHalf.size()) fprintf (stderr, "%lf\n", botHalf[_x].ang);
            int lowerAm = 0;
            int higherAm = 0;
            FO (p,0,N) {
                if (y[p] < y[i]) lowerAm++;
                if (y[p] > y[i]) higherAm++;
            }
            ans[i] = min (lowerAm, higherAm);
            int tSt = 0;
            int tEn = 0;
            int bSt = 0;
            int bEn = 0;
            double cAng = 0;
            double bAng = -PI;
            while (true) {
                while (tSt != topHalf.size() && topHalf[tSt].ang < cAng-EPS) tSt++;
                while (tEn != topHalf.size() && topHalf[tEn].ang < cAng+EPS) tEn++;
                while (bSt != botHalf.size() && botHalf[bSt].ang < bAng-EPS) bSt++;
                while (bEn != botHalf.size() && botHalf[bEn].ang < bAng+EPS) bEn++;
                //fprintf (stderr, "%d %d %d %d\n", tSt, tEn, bSt, bEn);
                //fprintf (stderr, "%.10lf %.10lf\n", cAng, bAng);
                int topAns = topHalf.size() - tEn;
                topAns += max (0, bSt);
                int botAns = botHalf.size() - bEn;
                botAns += max (0, tSt);
                //fprintf (stderr, "topAns: %d botAns: %d\n", topAns, botAns);
                ans[i] = min (ans[i], topAns);
                ans[i] = min (ans[i], botAns);
                if (tEn == topHalf.size() && bEn == botHalf.size()) break;
                if (tEn == topHalf.size()) {
                    cAng = botHalf[bEn].ang + PI;
                } else if (bEn == botHalf.size()) {
                    cAng = topHalf[tEn].ang;
                } else {
                    double secAng = botHalf[bEn].ang + PI;
                    cAng = min (secAng, topHalf[tEn].ang);
                }
                bAng = cAng - PI;
            }
        }
        FO (i,0,N) printf ("%d\n", ans[i]);
    }
    return 0;
}
                
                
                
                
                
                
                
                
                
                
                
                
                
