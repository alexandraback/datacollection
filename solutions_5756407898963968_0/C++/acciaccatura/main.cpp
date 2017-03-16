#include <cstdio>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <queue>
#include <list>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <cstring>
#include <cassert>
#include <limits.h>

using namespace std;

#define ST first
#define ND second
#define MP make_pair
#define PB push_back

typedef long long LL;
typedef long double LD;

typedef vector<int> VI;
typedef pair<int,int> PII;
#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(VAR(i,a);i<=(b);++i)
#define FORD(i,a,b) for(VAR(i,a);i>=(b);--i)
#define FORE(a,b) for(VAR(a,(b).begin());a!=(b).end();++a)
#define VAR(a,b) __typeof(b) a=(b)
#define SIZE(a) ((int)((a).size()))
#define ALL(x) (x).begin(),(x).end()
#define CLR(x,a) memset(x,a,sizeof(x))
#define ZERO(x) memset(x,0,sizeof(x))
#define S(t,i) scanf("%" ## t, &i)
#define SI(i) scanf("%d", &i)

const int INF=INT_MAX;
const int MAXN=1000+5;

int t, m;
int num[2][17];
int a1, a2, tmp;
int ans;

int main() {
    //ios_base::sync_with_stdio(0);
    
    SI(t);
    
    FOR(i,1, t) {
        SI(a1);
        REP(rowi,4) {
            REP(coli,4) {
                SI(tmp);
                num[0][tmp]=rowi+1;
            }
        }
        SI(a2);
        REP(rowi,4) {
            REP(coli,4) {
                SI(tmp);
                num[1][tmp]=rowi+1;
            }
        }
        ans=0;

        FOR(ni, 1,16){
            if (num[0][ni]==a1 && num[1][ni]==a2) {
                if (ans>0) {
                    printf("Case #%d: Bad magician!\n",i);
                    ans=-1;
                    break;
                }
                ans=ni;
            }
        }
            if (ans==0) {
                printf("Case #%d: Volunteer cheated!\n",i);
                continue;
            }
            else if (ans>0){
                printf("Case #%d: %d\n",i,ans);
            }

    }
    
    
    
	return 0;
}
