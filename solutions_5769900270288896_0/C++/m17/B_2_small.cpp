/* Man Mohan Mishra aka m17
   IIIT - Allahabad */
#include <cstdio>
#include <cmath>
#include <cstring>
#include <climits>
#include <cstdlib>
#include <cctype>
#include <iostream>
#include <algorithm>
#include <utility>
#include <string>
#include <vector>
#include <map>
#include <list>
#include <stack>
#include <queue>
#include <set>
#include <iterator>

#define MOD 1000000007
#define INF 1000000000000000000
#define PI acos(-1)

using namespace std;

long long GCD (long long a,long long b) {
	if (b == 0) return a;
	return(a % b == 0 ? b : GCD(b,a % b));
}

long long POW (long long base,long long exp) {
	long long val;
	val = 1;
	while (exp > 0) {
		if (exp % 2 == 1) {
			val = (val * base) % MOD;
		}
		base = (base * base) % MOD;
		exp = exp / 2;
	}
	return val;
}

int a[20][20];

int main()
{
//	freopen("input.in","r",stdin);
//	freopen("output.in","w",stdout);
	int t,tc;
	scanf("%d",&t);
	tc = 1;
	while (t --) {
		int r,c,N;
		int n,i,j,k,bit,cnt,ans;
		scanf("%d%d",&r,&c);
		scanf("%d",&N);
		n = r * c;
		ans = INT_MAX;
		for (i = 0; i < (1 << n); i++) {
			bit = 0;
			for (j = 0; j < n; j++) {
				if (((i >> j) & 1) == 1) {
					bit++;
				}
			}
			if (bit == N) {
				for (j = 0; j <= r; j++) {
					for (k = 0; k <= c; k++) {
						a[j][k] = 0;
					}
				}
				for (j = 0; j < n; j++) {
					if (((i >> j) & 1) == 1) {
						a[j / c][j % c] = 1;
					}
				}
				cnt = 0;
				for (j = 0; j < r; j++) {
					for (k = 0; k < c; k++) {
						if (a[j][k] == 1 && a[j + 1][k] == 1) cnt++;
						if (a[j][k] == 1 && a[j][k + 1] == 1) cnt++;
					}
				}
				ans = min(ans,cnt);
			}
		}
		printf("Case #%d: %d\n",tc,ans);
		tc += 1;
	}
	return 0;
}
