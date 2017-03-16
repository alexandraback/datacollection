#include <string>
#include <iostream>
#include <set>
#include <queue>
#include <vector>
#include <map>
#include <stdio.h>
#include <math.h>
#include <algorithm>

#define REP(i, n) for (int i = 0; i < (n); i++) 

using namespace std;

const int N = 4;	

int main() {
	freopen("D:/a.in", "r", stdin);
	freopen("D:/a.out", "w", stdout);
	int T;
	int a[N][N];
	scanf("%d", &T);
	REP(t, T) {
		int n1, n2;
		set<int> target;
		scanf("%d", &n1);
		REP(i, N) REP(j, N) scanf("%d", &a[i][j]);
		REP(i, N) target.insert(a[n1-1][i]);
		scanf("%d", &n2);
		REP(i, N) REP(j, N) scanf("%d", &a[i][j]);
		int cnt = 0, res = 0;
		REP(i, N) if (target.find(a[n2-1][i]) != target.end()) cnt ++, res = a[n2-1][i];
		printf("Case #%d: ", t + 1);
		if (cnt == 1) printf("%d\n", res);
		else if (cnt == 0) puts("Volunteer cheated!");
		else puts("Bad magician!");
	}
	return 0;
}