//By myf
//#pragma comment(linker, "/STACK:16777216")  //C++
#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
#include <map>
#include <set>
#include <bitset>
#include <stack>
#include <complex>
#include <list>
#include <iomanip>

#define rep(i, n) for(int i = 0; i < (n); i++)
#define REP(i, l, r) for(int i = (l) ; i < (r); i++)
#define MP make_pair
#define PB push_back
#define Cls(x) memset(x,0,sizeof x)
#define Print(n,x) for(int i=0;i<(n);i++) cout<<x<<" ";cout<<endl;
#define foreach(i,n) for(__typeof(n.begin()) i=n.begin();i!=n.end();i++) //G++
#define F first
#define S second
#define X real()
#define Y imag()
#define Sqr(x) (x)*(x)
#define sign(x) ((x < -EPS) ? -1 : x > EPS)

using namespace std;

typedef long long LL;
typedef complex<double> Point;
typedef Point Vec;
typedef pair<Point, Point> Line;
//typedef complex<double> Comp;

const int N = 4;
const int MD = 1000000007;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
const double EPS = 1E-6;

int n;
int v[N][N];
bool vis[N * N];

int main(){
	int T;
	scanf("%d", &T);
	rep(cas, T){
		memset(vis, 0, sizeof vis);
		int pos;
		scanf("%d", &pos);
		pos--;
		rep(i, N){
			rep(j, N){
				scanf("%d", &v[i][j]);
				v[i][j]--;
				if (i == pos) vis[v[i][j]] = true;
			}
		}
		int cnt = 0, ans;
		scanf("%d", &pos);
		pos--;
		rep(i, N){
			rep(j, N){
				scanf("%d", &v[i][j]);
				v[i][j]--;
				if (i == pos){
					if (vis[v[i][j]]){
						ans = v[i][j];
						cnt++;
					}
				}
			}
		}
		printf("Case #%d: ", cas + 1);
		if (cnt == 0){
			puts("Volunteer cheated!");
		}
		else if (cnt == 1){
			printf("%d\n", ans + 1);
		}
		else if (cnt > 1){
			puts("Bad magician!");
		}
	}
	return 0;
}
