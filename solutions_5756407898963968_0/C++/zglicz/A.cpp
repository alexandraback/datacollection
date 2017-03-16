#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <list>
#include <ctime>
#include <sstream>
#include <queue>
#include <stack>
#include <bitset>
using namespace std;
typedef vector<int> VI;
typedef pair<int,int> PII;
typedef long long LL;
#define FOR(x, b, e) for(int x=(b); x<=(e); ++x)
#define FORD(x, b, e) for(int x=((int)(b))-1; x>=(e); --x)
#define REP(x, n) for(int x=0; x<(n); ++x)
#define VAR(v,n) typeof(n) v=(n)
#define ALL(c) c.begin(),c.end()
#define SIZE(x) ((int)((x).size()))
#define FOREACH(i,c) for(VAR(i,(c).begin());i!=(c).end();++i)
#define PB push_back
#define ST first
#define ND second
#define mp(x,y) make_pair(x,y)
#define DEBUG 1
#define debug(x) {if (DEBUG)cerr <<#x <<" = " <<x <<endl; }
#define debugv(x) {if (DEBUG) {cerr <<#x <<" = "; FOREACH(it, (x)) cerr <<*it <<", "; cout <<endl; }}
typedef short int sint;

const int N = 2;
const int K = 4;
int t[N][K][K];
int ans[N];

int main() {
	int z;
	scanf("%d", &z);
	REP(q, z) {
		REP(a, N) {
			scanf("%d", &ans[a]);
			--ans[a];
			REP(i, K) REP(j, K) {
				scanf("%d", &t[a][i][j]);
			}
		}
		int odp = -1;
		FOR(i, 1, 16) {
			bool ex[2];
			REP(a, N) {
				ex[a] = false;
				REP(j, K) if (t[a][ans[a]][j] == i) ex[a] = true;
			}
			if (ex[0] && ex[1]) {
				if (odp == -1) {
					odp = i;
				} else {
					odp = -2;
					break;
				}
			}
		}
		printf("Case #%d: ", q+1);
		if (odp == -2) {
			printf("Bad magician!");
		} else if (odp == -1) {
			printf("Volunteer cheated!");
		} else {
			printf("%d", odp);
		}
		printf("\n");
	}
}