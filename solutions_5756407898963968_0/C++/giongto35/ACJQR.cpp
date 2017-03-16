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
#include <sstream>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <queue>
#include <iomanip>

using namespace std ;

#define FOREACH(it,c) for( __typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
#define FOR(i,a,b) for( int i=(a),_b=(b);i<=_b;i++)
#define DOW(i,b,a) for( int i=(b),_a=(a);i>=_a;i--)
#define REP(i,n) FOR(i,0,(n)-1)
#define DEP(i,n) DOW(i,(n)-1,0)
#define all(a) (a).begin() , (a).end()
#define mp(a,b) make_pair((a),(b))
#define RESET(c,x) memset (c, x, sizeof (c))
#define oo 1000111000
#define PI acos(-1.0)
#define fi first
#define se second
#define SIZE(c) (c).size()

typedef vector<int> VI ;
typedef vector<string> VS ;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;

template<class T> inline int size(const T&c) { return c.size(); }

using namespace std;
int fastMax(int x, int y) { return (((y-x)>>(32-1))&(x^y))^y; }
int fastMin(int x, int y) { return (((y-x)>>(32-1))&(x^y))^x; }

const int maxn = 20;
bool ok[maxn];
int u,r1,r2,T;
int main()
{
    freopen("ACJQR.in","r",stdin);
    freopen("ACJQR.out","w",stdout);
    scanf("%d",&T);
    for (int st = 1; st <= T; st++)
    {
        memset(ok,false,sizeof(ok));
        scanf("%d",&r1);
        for (int i = 1; i<= 4; i++)
        for (int j = 1; j <= 4; j++)
        {
            scanf("%d",&u);
            if (i == r1)
                ok[u] = true;
        }
        scanf("%d",&r2);
        int cnt = 0;
        int res;
        for (int i = 1; i<= 4; i++)
        for (int j = 1; j <= 4; j++)
        {
            scanf("%d",&u);
            if (i == r2)
            if (ok[u])
            {
                res = u;
                cnt++;
            }
        }
        printf("Case #%d: ",st);
        if (cnt == 1)
            printf("%d\n",res);
        else
        if (cnt == 0)
            printf("Volunteer cheated!\n");
        else
            printf("Bad magician!\n");
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

