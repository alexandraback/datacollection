#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <climits>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <list>
#include <ctime>
#include <iostream>
#include <sstream>
#include <cctype>

#define PI 3.14159265358979
#define EPS 1e-9

using namespace std;

#define REP(i, n) for (int i=0; i<n; i++)
#define FOR(i, m, n) for (int i=m; i<=n; i++)
#define ABS(a) (((a)>0)?(a):(-(a)))
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int,int> ii;

int r,s,n;

void solve() {
	scanf("%d%d%d", &r, &s, &n);
	if (n==0) { printf("0\n"); return ; }
	if (r==1 || s==1) {
		if (r*s%2==0) {
			if (n<=r*s/2) { printf("0\n"); return ; }
			if (n-1<=r*s/2) { printf("1\n"); return ; }
			n -= r*s/2 + 1;
			printf("%d\n", (1 + n*2));
			return ;
		}
		else {
			if (n<=r*s/2 + 1) { printf("0\n"); return ; }
			n -= r*s/2 + 1;
			printf("%d\n", n*2);
			return ;
		}
	}
	if (r*s%2==0) {
		if (n<=r*s/2) { printf("0\n"); return;}
		n -= r*s/2;
		int ans = 0;
		if (n<=2) { printf("%d\n", 2*n); return; }
		n -= 2; ans += 4;
		if (n<=r+s-4) { printf("%d\n", ans+3*n); return;}
		n -= r+s-4; ans += 3*(r+s-4);
		printf("%d\n", ans+n*4);
	}
	else {
		if (n<=r*s/2 + 1) { printf("0\n"); return;}
		int n1 = n - r*s/2 - 1;
		int res1 = 0;
		int ans1 = 0;
		if (n1 <= 2*(r/2 + s/2)) {
			res1 = 3*n1;
			goto sol2;
		}
		ans1 += 3 * 2*(r/2 + s/2);
		n1 -= 2*(r/2 + s/2);
		res1 = ans1 + 4*n1;
sol2:
		int n2 = n - r*s/2;
		int ans2=0; int res2=0;
		if (n2 <= 4) {
			res2 = 2*n2;
			goto fin;
		}
		ans2 = 8;
		n2 -= 4;
		if (n2<=2*((r-3)/2 + (s-3)/2)) {
			res2 = ans2 + n2*3;
			goto fin;
		}
		ans2 += 3* 2*((r-3)/2 + (s-3)/2);
		n2 -= 2*((r-3)/2 + (s-3)/2);
		res2 = ans2 + 4*n2;
fin:
		printf("%d\n", min(res1, res2));
	}
}

int main() {
	int t; scanf("%d", &t);
	REP(i, t) {
		printf("Case #%d: ", i+1);
		solve();
	}
	return 0;
}
