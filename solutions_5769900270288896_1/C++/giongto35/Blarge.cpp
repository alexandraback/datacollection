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
int a[10000][10000];
int cnt;
int res;

int calc() {
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
	return cnt;
}
int main()
{
    freopen("B.inp","r",stdin);
    freopen("B.out","w",stdout);
    scanf("%d",&T);
    for (int st = 1; st <= T; st++) {
        cerr<<st<<endl;
    	scanf("%d%d%d", &R,&C,&n);
    	for (int i = 0; i < R; i++){
    		for (int j = 0; j < C; j++) {
    			if (n > 0)
    			{
    				a[i][j] = 1;
    				n--;
    			}
    			else
    			a[i][j] = 0;
    		}
    	}
    	res = calc();
    	while(true) {
    		bool ok = true;
    		for (int i = 0; i < R; i++){
    			for (int j = 0; j < C; j++) {
    				if (j + 1 < C && a[i][j] != a[i][j + 1]) {
    					swap(a[i][j], a[i][j + 1]);
    					int temp = calc();
    					if (res <= temp) {
    						swap(a[i][j], a[i][j + 1]);   
    					} else {
    						ok = false;
    						res = temp;
    					}
    				}
    				if (i + 1 < R && a[i][j] != a[i + 1][j]) {
    					swap(a[i][j], a[i + 1][j]);
    					int temp = calc();
    					if (res <= temp) {
    						swap(a[i][j], a[i + 1][j]);    	
    					} else {
    						ok = false;
    						res = temp;
    					}
    				}
    			}
    		}
 			if (ok == true) {
 				break;
 			}
    	}
    	cout<<"Case #"<<st<<": "<<calc()<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}