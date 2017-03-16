#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <cmath>
#include <map>
#include <algorithm>
#include <cstdio>
#include <set>
#include <queue>
#include <cassert>
#include <climits>
using namespace std;
int A[5][5], B[5][5];
bool ahas[17], bhas[17];
int main() {
	int T, a, b;
	scanf("%d", &T);
	for (int cn = 1; cn <= T; ++cn) {
		scanf("%d", &a);
		for (int i = 1; i <= 4; ++i)
			for (int j = 1; j <= 4; ++j)
				scanf("%d", &A[i][j]);
		scanf("%d", &b);
		for (int i = 1; i <= 4; ++i)
			for (int j = 1; j <= 4; ++j)
				scanf("%d", &B[i][j]);
		memset(ahas, 0, sizeof(ahas));
		memset(bhas, 0, sizeof(bhas));
		for (int i = 1; i <= 4; ++i) {
			ahas[A[a][i]] = bhas[B[b][i]] = true;
		}
		int numboth = 0, ans;
		for (int i = 1; i <= 16; ++i)
			if (ahas[i] && bhas[i]) {
				++numboth;
				ans = i;
			}
		printf("Case #%d: ", cn);
		if (!numboth) printf("Volunteer cheated!\n");
		else if (numboth > 1) printf("Bad magician!\n");
		else printf("%d\n", ans);
	}
}

