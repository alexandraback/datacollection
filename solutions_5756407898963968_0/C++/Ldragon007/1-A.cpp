#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int t, n, m, a[4][4], b[4][4];

int main() {
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("A-small-attempt0.out", "w", stdout);
	scanf("%d", &t);
	for (int ca = 1; ca <= t; ca ++ ) {
		scanf("%d", &n);
		for (int i = 0; i < 4; i ++ )
			for (int j = 0; j < 4; j ++ ) {
				scanf("%d", &a[i][j]);
			}
		scanf("%d", &m);
		for (int i = 0; i < 4; i ++ )
			for (int j = 0; j < 4; j ++ ) {
				scanf("%d", &b[i][j]);
			}
		int cnt = 0, ans = 0;
		for (int i = 0; i < 4; i ++ )
			for (int j = 0; j < 4; j ++ )
				if (a[n - 1][i] == b[m - 1][j]) {
  				   cnt ++ , ans = a[n - 1][i];
  				  // cout<<ans<<endl;
				}
		printf("Case #%d: ", ca);
		if (cnt == 0) printf("Volunteer cheated!\n");
		else if (cnt != 1) printf("Bad magician!\n");
		else printf("%d\n", ans);
	} 
	//system("pause");
	return 0;	
} 