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

#define MAX 15000
using namespace std;
int T;
int a[20][20];
int main()
{
    //ios_base::sync_with_stdio(0);
    //memset(memo,-1,sizeof(memo));
    //memset(di,0,sizeof(di));
    //memset(dj,0,sizeof(dj));
    //memset(h,0,sizeof(h));
    //memset(cnt,-1,sizeof(cnt));
    //memset(vis,0,sizeof(vis));
    freopen("B-small-attempt1.in","r",stdin);
    freopen("output2.txt","w",stdout);
    cin >> T;
    rep (u,T) {
        int R,C,N;
        cin >> R >> C >> N;
        int r = MAX;
        rep (mask, (1 << (R * C))) {
            rep (i,R + 2)
                rep (j,C + 2)
                    a[i][j] = 0;
            int k = 0;
            rep (i,16)
                if (mask & (1 << i))
                   k++;
            if (k != N)
               continue;
            int res = 0;
            k = 0;
            fer (i,1,R + 1)
                fer (j,1, C + 1) {
                    if (mask & (1 << k))
                       a[i][j] = 1;
                    k++;
                }
            fer (i,1,R + 1)
                fer (j,1, C + 1)
                    if (a[i][j] == 1)
                       res += a[i - 1][j] + a[i][j - 1] + a[i][j + 1] + a[i + 1][j];
            res /= 2;
            r = min(res,r);
        }
        printf ("Case #%d: %d\n",u + 1, r);
    }
    //system("pause");
    return 0;
}

