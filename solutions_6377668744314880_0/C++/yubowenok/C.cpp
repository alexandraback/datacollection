#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <sstream>
#include <complex>
#include <ctime>
#include <cassert>
#include <functional>

using namespace std;

typedef long long ll;
typedef vector<int> VI;
typedef pair<int, int> PII;

#define REP(i,s,t) for(int i=(s);i<(t);i++)
#define FILL(x,v) memset(x,v,sizeof(x))

const int INF = (int)1E9;
#define MAXN 3005

int N;
int sign(ll x){
	if (x == 0) return 0;
	return x > 0 ? 1 : -1;
}
struct pt{
	ll x, y;
	pt(){}
	pt(ll _x, ll _y){ x = _x; y = _y; }
	pt operator - (pt p){
		return pt(x - p.x, y - p.y);
	}
	ll cross(pt p) {
		return x * p.y - y * p.x;
	}
} p[MAXN];
int main(){
	int cs;
	cin >> cs;
	REP(csn, 1, cs + 1){
		printf("Case #%d:\n", csn);
		cin >> N;
		REP(i, 0, N){
			cin >> p[i].x >> p[i].y;
		}
		if (N == 1){
			puts("0");
			continue;
		}
		REP(i, 0, N){
			int ans = N - 1;
			REP(j, 0, N){
				if (j == i) continue;
				pt v1 = p[j] - p[i];
				int s1 = 0, s2 = 0;
				REP(k, 0, N){
					if (k == i || k == j) continue;
					pt v2 = p[k] - p[i];
					ll c = v2.cross(v1);
					int sn = sign(c);
					if (sn > 0) s1++;
					else if (sn < 0) s2++;
				}
				int sol = min(s1, s2);
				ans = min(ans, sol);
			}
			printf("%d\n", ans);
		}
	}
	return 0;
}