#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>

int main () {
	int T, N;
	int tt = 1;
	scanf("%d", &T);
	char str[110][110];
	int num[110][110];
	memset(num, 0, sizeof(num));
	while (T--) {
		scanf("%d", &N);
		int alc = 0;
		for (int i = 0 ; i < N ; i++) {
			scanf("%s", str[i]);
			char tstr[110];
			char nowc = str[i][0];
			int nown = 1;
			int ct = 0;
			for (int j = 1 ; str[i][j] ; j++) {
				if (str[i][j] != nowc) {
					num[i][ct] = nown;
					nown = 1;
					tstr[ct] = nowc;
					nowc = str[i][j];
					ct++;
				} else {
					nown++;
				}
			}
			tstr[ct] = nowc;
			num[i][ct] = nown;
			alc = ct;
			tstr[ct+1] = '\0';
			strcpy(str[i], tstr);
		}
		printf("Case #%d: ", tt);
		tt++;
		bool over = false;
		for (int i = 1 ; i < N ; i++) {
			if (strcmp(str[i-1], str[i]) != 0) {
				over = true;
				break;
			}
		}	
		if (over == true) {
			printf("Fegla Won\n");
		} else {
			int ans = 0;
			int tn[110];
			for (int i = 0 ; i <= alc ; i++) {
				for (int j = 0 ; j < N ; j++) {
					tn[j] = num[j][i];	
				}
				std::sort(tn, tn+N);
				int mid = tn[N/2];
				for (int j = 0 ; j < N ; j++) {
					ans += abs(num[j][i]-mid);
				}
			}
			printf("%d\n", ans);
		}
	}
	return 0;
}
