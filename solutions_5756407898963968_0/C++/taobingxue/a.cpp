#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

int main(){
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
	
	int T, ans1, ans2, cards0[4][4], cards1[4][4], finalans;
	scanf("%d", &T);
	for (int T0=1; T0 <= T; T0 ++) {
		printf("Case #%d: ", T0);
		scanf("%d", &ans1);
		for (int i=0; i<4; i++)
			for (int j=0; j<4; j++) scanf("%d", &cards0[i][j]);
		scanf("%d", &ans2);
		for (int i=0; i<4; i++)
			for (int j=0; j<4; j++) scanf("%d", &cards1[i][j]);
		ans1 -= 1; ans2 -= 1;

		finalans = -1;
		for (int i=0; i<4; i++)
			for (int j=0; j<4; j++)
				if (cards0[ans1][i] == cards1[ans2][j]) {
					if (finalans == -1) finalans = cards0[ans1][i];
					else finalans = -10;
					continue;
				}
		if (finalans == -1) printf("Volunteer cheated!\n");
		else if (finalans == -10) printf("Bad magician!\n");
		else printf("%d\n", finalans);
	}
	return 0;
}

