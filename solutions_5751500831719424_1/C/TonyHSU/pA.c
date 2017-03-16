#include<stdio.h>
#include<stdlib.h>

char input[105][105];

int cmp(const void *a, const void *b) {
	if (*((int *)a) > *(int *)b) return 1;
	else if (*((int *)a) < *(int *)b) return -1;
	return 0;
}

int my_abs(int a) {
	return a>0 ? a : (-1)*a;
}

int main() {
	int T, nm= 1;
	scanf("%d", &T);
	int i, j, k;
	while (T--) {
		int pt[105]= {0};
		int n;
		scanf("%d", &n);
		for (i=0;i<n;i++) {
			scanf("%s", input[i]);
		}
		int cur= 0, pass= 1, ans= 0;
		while (1) {
			int num[105]= {0};
			char save= input[0][cur];
			//printf("save= %c, cur= %d\n", save, cur);
			for (i=0;i<n;i++) {
				int ct= 0;
				while (input[i][pt[i]]!='\0' && input[i][pt[i]]==save) {
					//printf("ch= %c, pt= %d\n", input[i][pt[i]], pt[i]);
					num[i]++;
					pt[i]++;
				}
				//printf("i= %d, num= %d, pt= %d\n", i, num[i], pt[i]);
				if (num[i]==0) {
					pass= 0;
					break;
				}
			}
			cur= pt[0];
			//printf("cur= %d\n", cur);
			if (!pass) break;
			qsort(num, n, sizeof(int), cmp);
			int mid= n/2;
			//printf("mid= %d\n", mid);
			for (i=0;i<n;i++) {
				//printf("ans= %d, num-mid= %d\n", ans, my_abs(num[i]-num[mid]));
				ans+= my_abs(num[i]-num[mid]);
				//printf("ans= %d, num-mid= %d\n", ans, my_abs(num[i]-num[mid]));
			}
			int end= 1;
			for (i=0;i<n;i++) {
				if (input[i][pt[i]]!='\0') end= 0;
			}
			//printf("end= %d\n", end);
			if (end) break;
		}
		if (pass) printf("Case #%d: %d\n", nm, ans);
		else printf("Case #%d: Fegla Won\n", nm);
		nm++;
	}
	return 0;
}
