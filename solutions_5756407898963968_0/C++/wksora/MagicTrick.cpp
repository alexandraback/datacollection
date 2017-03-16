/*
 * Magic Trick  Google code jam
 *
 *  Created on: 2014Äê4ÔÂ12ÈÕ
 *      Author: Bevoid
 */

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

int main() {
	freopen("D:/Downloads/A-small-attempt0.in", "r", stdin);
	freopen("d:/out.out", "w", stdout);
	int T;
	int frows[4][4], srows[4][4];
	while (scanf("%d", &T) != EOF) {
		int cases = 0;
		while (cases++ < T) {
			printf("Case #%d: ", cases);
			
			int fa, sa;
			scanf("%d", &fa);
			for (int i = 0; i < 4; i++) {
				for (int j = 0; j < 4; j++) {
					scanf("%d", &frows[i][j]);
				}
			}
			scanf("%d", &sa);
			for (int i = 0; i < 4; i++) {
				for (int j = 0; j < 4; j++) {
					scanf("%d", &srows[i][j]);
				}
			}

			int flag[17];
			memset(flag,0,sizeof(flag));
			for (int i = 0; i < 4; i++){
				flag[frows[fa - 1][i]]++;
				flag[srows[sa - 1][i]]++;
			}

			int count = 0;
			int target = -1;
			for (int i = 1; i <=16; i++) {
				if (flag[i] >= 2) {
					count++;
					target = i;
				}
			}

			if (count == 0) {
				printf("Volunteer cheated!\n");
			} else if (count == 1) {
				printf("%d\n", target);
			} else if (count > 1) {
				printf("Bad magician!\n");
			}

		}
	}
	return 0;
}
