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

int n, t;
int l[101][101], pp[101];
string y[1001];
void solve(){
    int n;
    scanf("%d", &n);
    FOE(i, 1, n) cin>>y[i];
    char g[1001], nxt = 0;
    string delta = y[1];
    char c;
    FOE(i, 0, delta.length()-1){
        if (i == 0) c = delta[0];
        else if (delta[i] != c){
            g[++nxt] = c;
            c = delta[i];
        }
    }
    g[++nxt] = c;
    FOE(i, 2, n){
        int beta = 1;
        string test = y[i];
        FOE(j, 0, test.length() - 1){
            if (j == 0) c = test[0];
            else if (test[j] != c){
                if ((beta == nxt) || (g[beta] != c)){printf("Fegla Won\n"); return;}
                beta++;
                c = test[j];
            }

        }
        if ((beta != nxt) || (g[beta] != c)){printf("Fegla Won\n"); return;}
    }
    FOE(i, 1, n) pp[i] = 0;
    FOE(i, 1, n){
        int cnt = 0;
        string test = y[i];
        FOE(j, 0, test.length()-1){
            if (j == 0) {cnt = 1; c = test[0];}
            else if (test[j] != c){
                l[i][++pp[i]] = cnt;
                c = test[j];
                cnt = 1;
                } else cnt++;
        }
        l[i][++pp[i]] = cnt;
    }
    int res = 0;
    FOE(i, 1, nxt){
        int par = 9999999;
        FOE(j, 1, 100){
            int ans = 0;
            FOE(k, 1, n) ans = ans + abs(j - l[k][i]);
            par = min(ans, par);
        }
        res += par;
    }
    printf("%d\n", res);
}

int main(){
    freopen("A-small-attempt0 (1).in", "r", stdin);
    freopen("out.out", "w", stdout);
    int x;
    scanf("%d", &x);
    FOE(i, 1, x) {
        printf("Case #%d: ", i);
        solve();
    }
    return 0;
}
