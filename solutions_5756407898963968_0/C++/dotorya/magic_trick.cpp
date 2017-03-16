#include <stdio.h>
int d[17];
int main() {
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("output.txt", "w", stdout);
	int case_no, i, j, k, T, tmp, tmp2, cnt;
	scanf("%d", &T);
	for(case_no = 1; case_no <= T; case_no++) {
		for(i = 1; i <= 16; i++) d[i] = 0;
		cnt = 0;
		for(i = 1; i <= 2; i++) {
			scanf("%d", &tmp);
			for(j = 1; j <= 4; j++) {
				for(k = 1; k <= 4; k++) {
					scanf("%d", &tmp2);
					if(j == tmp) d[tmp2]++;
				}
			}
		}
		for(i = 1; i <= 16; i++) {
			if(d[i] == 2) {
				if(cnt == 0) cnt = i;
				else break;
			}
		}
		printf("Case #%d: ", case_no);
		if(i != 17) printf("Bad magician!\n");
		else if(cnt == 0) printf("Volunteer cheated!\n");
		else printf("%d\n", cnt);
	}
	return 0;
}