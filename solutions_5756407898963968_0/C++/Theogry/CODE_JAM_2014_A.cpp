#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <queue>
#include <cmath>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <memory.h>

using namespace std;
#define FOR(i,s,e) for (int i=(s); i<(e); i++)
#define FOE(i,s,e) for (int i=(s); i<=(e); i++)
#define FOD(i,s,e) for (int i=(s); i>=(e); i--)
#define CLR(a,x) memset(a, x, sizeof(a))
#define EXP(i,l) for (int i=(l); i; i=qn[i])
#define LL long long
#define eps 1e-6
#define pi acos(-1.0)

LL max(LL a,LL b){if (a>b){return a;} else {return b;}}
LL min(LL a,LL b){if (a<b){return a;} else {return b;}}

struct P{
    double x, y;
    P(){}
    P(double x, double y):x(x) , y(y){}
    P operator+ (const P &a) const {return P(x+a.x, y+a.y);}
    P operator- (const P &a) const {return P(x-a.x, y-a.y);}
    double operator^ (const P &a) const {return x*a.x+y*a.y;}
    void in(){scanf("%lf%lf", &x, &y);}
    void out(){printf("REQUIRED %.7f %.7f\n", x, y);}
    double dist(P a, P b) {return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));}
    double sqdist(P a, P b) {return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);}

};

void solve(int tc){
    int pos[17][2], a1, a2;
    scanf("%d", &a1);
    FOE(i, 1, 4) FOE(j, 1, 4){
        int t;
        scanf("%d", &t);
        pos[t][0] = i;
    }
    scanf("%d", &a2);
    FOE(i, 1, 4) FOE(j, 1, 4){
        int t;
        scanf("%d", &t);
        pos[t][1] = i;
    }
    int ans = 0;
    FOE(i, 1, 16){
        if ((pos[i][0] == a1) && (pos[i][1] == a2)){
            if (ans == 0) ans = i;
            else ans = -1;
        }
    }
    printf("Case #%d: ", tc);
    if (ans == 0) puts("Volunteer cheated!");
    else if (ans == -1) puts("Bad magician!");
    else printf("%d\n", ans);

}


int main(){
    freopen("A-small-attempt0.in", "r", stdin);
    freopen("sol.out", "w", stdout);
    int t; scanf("%d", &t);
    FOE(i, 1, t) solve(i);
    return 0;
}
