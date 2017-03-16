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

int T,n,R,C;
int a[20][20];
int res = 0;

void attemp(int y, int x, int s) {
	if (y == R) {
		if (s == n) {
		int cnt = 0;
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				if (j + 1 < C && a[i][j] == 1 && a[i][j + 1] == 1) {
					cnt++;
				}
				if (i + 1 < R && a[i][j] == 1 && a[i + 1][j] == 1) {
					cnt++;
				}
			}
		}
		res = min(res, cnt);
		}
		return;
	}
	if (x + 1 < C)
	attemp(y, x + 1, s); else
	attemp(y + 1, 0, s);
	a[y][x] = 1;
	if (x + 1 < C)
	attemp(y, x + 1, s + 1); else
	attemp(y + 1, 0, s + 1);	
	a[y][x] = 0;
}

int main()
{
    freopen("B.inp","r",stdin);
    freopen("B.out","w",stdout);
    scanf("%d",&T);
    for (int st = 1; st <= T; st++) {
    	scanf("%d%d%d", &R,&C,&n);
    	res = 1000000;
    	attemp(0, 0, 0);
    	cout<<"Case #"<<st<<": "<<res<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}