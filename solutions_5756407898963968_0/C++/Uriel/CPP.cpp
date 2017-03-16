//GCJ Qualification 2014-04-12 A
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
using namespace std;

FILE* fw;

int main() {
//	freopen("B-small-attempt0.in", "r", stdin);
	freopen("A-small-attempt0.in", "r", stdin);
	fw = fopen("A-s.txt", "w");
	int i, j, cse, r1, r2, map1[4][4], map2[4][4], cnt, res, g = 1;
	scanf("%d", &cse);
	while(cse--) {
		scanf("%d", &r1);
		for(i = 0; i < 4; ++i) {
			for(j = 0; j < 4; ++j) {
				scanf("%d", &map1[i][j]);
			}
		}
		scanf("%d", &r2);
		for(i = 0; i < 4; ++i) {
			for(j = 0; j < 4; ++j) {
				scanf("%d", &map2[i][j]);
			}
		}
		cnt = 0;
		for(i = 0; i < 4; ++i) {
			for(j = 0; j < 4; ++j) {
				if(map1[r1 - 1][i] == map2[r2 - 1][j]) {
					cnt++;
					res = map1[r1 - 1][i];
					break;
				}
			}
		}
		if(!cnt) fprintf(fw, "Case #%d: Volunteer cheated!\n", g++);
		else if(cnt == 1) fprintf(fw, "Case #%d: %d\n", g++, res);
		else
			fprintf(fw, "Case #%d: Bad magician!\n", g++);
	}
	fclose(fw);
	return 0;
}
