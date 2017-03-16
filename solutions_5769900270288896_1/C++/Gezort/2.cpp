#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <map>
#include <math.h>
#include <vector>
#include <limits.h>
#include <set>
#include <queue>
#include <stack>
#include <algorithm>
#include <string>
#include <string.h>
#include <time.h>
#define ll long long
#define mp make_pair
#define s second
#define f first
#define pii pair<int,int>
#define vi vector<int>
#define vl vector<ll>
#define vii vector <pii>
#define pll pair<ll,ll>
#define vll vector <pll>
#define pb push_back
#define inf 2000000000
#define MOD 1000000007ll

#define rep(i, n) for (int i = 0, _n = (int)(n); i < _n; i++)
#define fer(i, x, n) for (ll i = (ll)(x), _n = (ll)(n); i < _n; i++)
#define rof(i, n, x) for (int i = (int)(n), _x = (int)(x); i-- > _x; )
#define fch(i, x) for (__typeof(x.begin()) i = x.begin(); i != x.end(); i++)
#define sz(x) (int((x).size()))

#define MAX 3000
using namespace std;

int main()
{
    //ios_base::sync_with_stdio(0);
    //memset(memo,-1,sizeof(memo));
    //memset(di,0,sizeof(di));
    //memset(dj,0,sizeof(dj));
    //memset(h,0,sizeof(h));
    //memset(cnt,-1,sizeof(cnt));
    //memset(vis,0,sizeof(vis));
    freopen("B-large.in","r",stdin);
    freopen("output.txt","w",stdout);
    ll T,R,C,N;    
    cin >> T;
    rep (u,T) {
        cin >> R >> C >> N;
        if (R < C)
           swap (R,C);
        if (C == 1) {
           int res = (N > (R + 1) / 2 ? (N - (R + 1) / 2) * 2 - (1 - (R % 2)) : 0);
           printf ("Case #%d: %d\n",u + 1, res);
           continue;
        }
        int xa = ((R + 1) / 2) * ((C + 1) / 2) + (R / 2) * (C / 2);
        int ya = (R % 2 && C % 2 ? 0 : 2);
        int za = (C % 2 ? 2 * (R / 2) + (R % 2 ? 2 * ((C - 1) / 2) : C - 2) : (R / 2) + (R + 1) / 2 + (C - 2)) - ya;
        int resa = 0;
        //cout << xa << " " << ya << " " << za << endl;
        int M = N;
        if (N > xa) {
              N -= xa;
              if (N > ya) {
                    N -= ya;
                    resa += 2 * ya;
              } else {
                     resa += N * 2;
                     N = 0;
              }
        } else {
               N = 0;
        }
        if (N < za) {
              resa += N * 3;
              N = 0;
        } else {
               resa += za * 3;
               N -= za;
        }
        resa += N * 4;
        int xb = (R / 2) * ((C + 1) / 2) + ((R + 1) / 2) * (C / 2);
        int yb = 4 - ya;
        int zb = (C % 2 ? 2 * ((R + 1)/ 2) + (R % 2 ? 2 * ((C - 2) / 2) : C - 2) : (R / 2) + (R + 1) / 2 + (C - 2)) - yb;
        int resb = 0;
        //cout << xb << " " << yb << " " << zb << endl;
        N = M;
        if (N > xb) {
              N -= xb;
              if (N > yb) {
                    N -= yb;
                    resb += 2 * yb;
              } else {
                     resb += N * 2;
                     N = 0;
              }
        } else {
               N = 0;
        }
        if (N < zb) {
              resb += N * 3;
              N = 0;
        } else {
               resb += zb * 3;
               N -= zb;
        }
        resb += N * 4;
        printf ("Case #%d: %d\n",u + 1, min (resa, resb));
    }
    //system("pause");
    return 0;
}

