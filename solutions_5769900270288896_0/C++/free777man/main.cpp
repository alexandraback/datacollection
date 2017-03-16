#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
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
#include <cstring>
using namespace std;
#define ALL(a) (a).begin(), (a).end()
#define SZ(a) (int)(a).size()
#define FOR(i,s,n) for(int i=(s);i<(n);++i)
#define REP(i,n) FOR(i,0,(n))
#define PB(x) push_back((x))
#define CLR(a,v) memset((a),(v),sizeof((a)))
typedef long long ll;

char b[16][16];
int bc[1<<16];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

void f()
{
    int mx=1<<16;
    REP(i,mx)
    {
        int r = 0, t = i;
        while(t)++r,t&=t-1;
        bc[i]=r;
    }
}

void solve()
{
    int r,c,n;
    scanf("%d %d %d", &r, &c, &n);

    int sz = r*c, res=100500;
    int mx = 1<<sz;

    REP(mask,mx)if(bc[mask]==n)
    {
        CLR(b,0);
        int k = 0;
        REP(i,r)REP(j,c)
        {
            if(mask&(1<<k))b[i][j]=1;
            ++k;
        }

        int rs = 0;
        REP(i,r)REP(j,k)if(b[i][j])REP(d,4)
        {
            int x = i + dx[d], y = j + dy[d];
            if(x<0||y<0||x>=r||y>=c)continue;
            if(b[x][y])++rs;
        }

        rs /= 2;
        if(res>rs)res=rs;
    }

    printf("%d\n", res);
}

int main()
{
    f();
    //freopen("input.txt","r",stdin);
    freopen("B-small-attempt0.in","r",stdin);
    freopen("outputB.txt","w+",stdout);
    int T;
    scanf("%d",&T);
    REP(i,T)printf("Case #%d: ",i+1),solve();
}
