#include <iostream>
#include <fstream>
#include <cstring>
#include <set>
#include <map>
#include <list>
#include <queue>
#include <stack>
#include <bitset>
#define _USE_MATH_DEFINES
#include <math.h>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <assert.h>
using namespace std;

void smain();
int main(){
    ios_base::sync_with_stdio(0);
#ifdef TASK
    //freopen(TASK".in","rt",stdin);
    freopen("/Users/ramis/Downloads/B-small-attempt0.in.txt","rt",stdin);
    freopen("output.txt","wt",stdout);
    const clock_t start = clock();
#endif
    smain();
#ifdef TASK
    cerr << "\nTotal Execution Time: " << float( clock () - start ) /  CLOCKS_PER_SEC << endl;
#endif
    return 0;
}

#define forn(i,n) for (int i=0;i<n;i++)
#define rforn(i,n) for (int i=n-1;i>=0;i--)
#define fori(i,a) for(auto i=a.begin(); i!=a.end(); ++i)
#define rfori(i,a) for(auto i=a.rbegin(); i!=a.rend(); ++i)
//#define int long long
#define LL long long
#define mp(a,b) make_pair(a,b)
#define INF 2000000000//2305843009213693951LL
#define MOD 1000000007
#define EPS 1E-9
#define N 200
/* --------- END TEMPLATE CODE --------- */

int r, c, n;
bool mtr[N][N];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int small(){
    int m = (1 << (r * c));
    int res = INF;
    forn(mask, m) if(__builtin_popcount(mask) == n) {
        int k = 0;
        forn(i, r) forn(j, c) {
            mtr[i][j] = (mask >> k) & 1;
            k += 1;
        }
        int v = 0;
        forn(i, r) forn(j, c) if(mtr[i][j]) {
            if(i < r - 1 && mtr[i+1][j]) v += 1;
            if(j < c - 1 && mtr[i][j+1]) v += 1;
        }
        res = min(v, res);
    }
    return res;
}

void smain() {
    int T;
    cin >> T;
    for(int cas = 1; cin >> r >> c >> n; ++cas){
        cout << "Case #" << cas << ": " << small() << '\n';
    }
}
