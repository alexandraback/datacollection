#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <queue>
using namespace std;

#define FOR(i,a,b) for(int i=a;i<b;++i)
#define REP(i,n) FOR(i,0,n)
#define RFOR(i,a,b) for(int i=a;i>=b;i--)
#define RREP(i,n) RFOR(i,n-1,0)
#define ECH(it, v) for(typeof(v.begin()) it=v.begin();it!=v.end();++it)
#define ALL(x) (x).begin(),(x).end()
#define CLR(x) memset(x,0,sizeof(x))
#define SET(x) memset(x,-1,sizeof(x))
#define MKP make_pair
#define MOD 1000000007
typedef long long LL;
typedef unsigned long long uLL;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;

int main() {
    #ifdef raaja
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int zz, qq = 0;
    scanf("%d ", &zz);
    int a[4][4], b[4][4], c1, c2, c, ans;
    while(qq++ < zz) {
        scanf("%d ", &c1);
        REP(i, 4) REP(j, 4) scanf("%d ", &a[i][j]);
        scanf("%d ", &c2);
        REP(i, 4) REP(j, 4) scanf("%d ", &b[i][j]);
        c = 0;
        c1--, c2--;
        REP(i, 4) REP(j, 4) if(a[c1][i] == b[c2][j]) c++, ans = a[c1][i];
        printf("Case #%d: ", qq);
        if(c == 0) printf("Volunteer cheated!\n");
        else if(c > 1) printf("Bad magician!\n");
        else printf("%d\n", ans);
    }
}
