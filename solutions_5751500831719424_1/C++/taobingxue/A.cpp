#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

char s[105][105], ss[105], ans[105];
int sum[105][105];
int main(){
	freopen("A.in", "r", stdin);
	freopen("A.out", "w", stdout);

	int T;
	scanf("%d", &T);
	for (int times=1; times<=T; times++) {
		printf("Case #%d: ", times);
		
		int n;
		scanf("%d", &n);
		gets(ss);
		bool flag = true;
		memset(ans, 0, sizeof(ans));
		memset(sum, 0, sizeof(sum));
		
		for (int i=0; i<n; i++) {
			gets(s[i]);
			if (!flag) continue;
			int l = strlen(s[i]), s0, sseg = 0;
			if (i == 0) {
				s0 = 1;
				for (int j=1; j<=l; j++)
					if (s[i][j] != s[i][j-1]) {
						ans[sseg] = s[i][j-1];
						sum[0][sseg++] = s0;
						s0 = 0;
					} else s0 += 1;
				continue;
			}
			s0 = 1;
			for (int j=1; j<=l; j++)
				if (s[i][j] != s[i][j-1]) {
					if (ans[sseg] != s[i][j-1]) {
						flag = false;
						break;
					}
					sum[i][sseg++] = s0;
					s0 = 0;
				} else s0 += 1;
			if (ans[sseg] != 0) flag = false;
		}
		if (!flag) {
			printf("Fegla Won\n");
			continue;
		}
		
		int answer = 0;
		for (int i=0; ans[i]>0; i++) {
			int num[105];
			for (int j=0; j<n; j++) num[j] = sum[j][i];
			sort(num, num+n);
			int level = num[n >> 1];
			for (int j=0; j<n; j++) answer += sum[j][i] > level? sum[j][i] - level : level - sum[j][i];
		}
		printf("%d\n", answer);
	}
	return 0;
}

