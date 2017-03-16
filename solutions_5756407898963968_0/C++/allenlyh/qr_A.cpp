
//by allenlyh
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <string>
#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <vector>
#include <list>
#include <complex>

using namespace std;

typedef long long LL;

#define X first
#define Y second
#define MP make_pair
#define PB push_back
#define sqr(x) (x)*(x)
#define sign(x) ((x)<-eps)?-1:(x)>eps;
#define foreach(ite,s) for (__typeof(s.begin()) ite=s.begin();ite!=s.end();ite++)
#define lowbit(x) ((x) & (-(x)))
const double eps=1e-9;
const int INF=0x3f3f3f3f;

const int maxn=5;
int n;
int a[maxn][maxn];
int tot[maxn*maxn];

void work() {
	scanf("%d", &n);
	for (int i=0;i<4;i++) {
		for (int j=0;j<4;j++) {
			scanf("%d", &a[i][j]);
		}
	}
	memset(tot, 0, sizeof(tot));
	n--;
	for (int j=0;j<4;j++) {
		tot[a[n][j]]++;
	}
	scanf("%d", &n);
	for (int i=0;i<4;i++) {
		for (int j=0;j<4;j++) {
			scanf("%d", &a[i][j]);
		}
	}
	n--;
	int ans=-1;
	for (int j=0;j<4;j++) {
		tot[a[n][j]]++;
		if (tot[a[n][j]] == 2) {
			if (ans != -1) ans = -2;
			else ans = a[n][j];
		}
	}
	if (ans == -1) puts("Volunteer cheated!");
	else if (ans == -2) puts("Bad magician!");
	else printf("%d\n", ans);
}

int main() {
	int T;
	int cas=0;
	scanf("%d", &T);
	while (T--) {
		printf("Case #%d: ", ++cas);
		work();
	}
	return 0;
}
