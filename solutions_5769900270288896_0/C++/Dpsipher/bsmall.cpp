
/**
 * author : dpsipher
 */
#include <cstdio>
#include <numeric>
#include <iostream>
#include <vector>
#include <set>
#include <cstring>
#include <string>
#include <map>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <bitset>
#include <queue>
#include <sstream>
#include <deque>
#include <cassert>

using namespace std;

#define mp make_pair
#define pb push_back
#define rep(i,n) for(int i = 0; i < (n); i++)
#define re return
#define fi first
#define se second
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define fill(x,y) memset(x,y,sizeof(x))
#define FOREACH(it,v)   for(typeof((v).begin()) it=(v).begin();it != (v).end();it++)
#define i(x) scanf("%d",&x)
#define u(x) scanf("%u",&x)
#define l(x) scanf("%l64d",&x)
#define ul(x) scanf("%l64u",&x)

typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef long double ld;                         
typedef vector<int> vi;

typedef pair<int, int> pii;
typedef vector<pii> vpii;
typedef vector<string> vs;
typedef vector<vi> vvi;

using namespace std;
int cal(int mask, int r, int c) {
    bool grid[16][16];
    memset(grid, 0, sizeof grid);
    for (int i = 0; i < r*c; i++) {
        if (mask&(1<<i)) {
            grid[i/c][i%c] = 1;
        }
    }
    int res = 0;
    //cout << mask << endl;
    //rep(i,r){ rep(j,c) cout << grid[i][j]; cout << endl;}
    rep(i,r) rep(j,c) {
        if (grid[i][j]) {
            if (i-1 >= 0 && grid[i-1][j]) res++;
            if (j - 1>=0 && grid[i][j-1]) res++;
        }
        //else if (i+1 < r && grid[i+1][j]) res++;
        //else if (j+1 < c && grid[i][j+1]) res++;
    }
    //cout << "res " << res << endl;
    return res;
}
int main()
{
    int tests;
    i(tests);
    rep(testno, tests) {
        printf("Case #%d: ", testno+1);
        int r, c, n;
        cin >> r >> c >> n;
        int res = 1<<30;
        for (int mask = 0; mask <= 1<<(r*c); mask++) {
            int filled =  __builtin_popcount(mask);
            //cout << mask << " " << filled << endl;
            if (filled == n) {
                res = min(res, cal(mask, r, c));
            }
        }
        cout << res << endl;
    }
    return 0;
}
