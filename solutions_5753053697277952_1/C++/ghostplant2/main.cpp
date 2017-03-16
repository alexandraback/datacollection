#include <stdio.h>
#include <string.h>

int main() {
	int T, n, tot, type;
	static int p[30];
	scanf("%d", &T);
	for (int C=1;C<=T;++C) {
		scanf("%d", &n);
		tot=0;
		type=0;
		for (int i=0; i<n; ++i) {
			scanf("%d", p+i), tot+=p[i];
			if (p[i]>0)
				++type;
		}
		printf("Case #%d:", C);
		while (type>2) {
			int t=0;
			for (int t2=1;t2<n;++t2)
				if (p[t2]>p[t])
					t=t2;
			printf(" %c", 'A'+t);
			--p[t];
			if (!p[t])
				--type;
		}
		int acc[2], len=0;
		for (int i=0;i<n;++i)
			if (p[i])
				acc[len++]=i;
		while (p[acc[0]]<p[acc[1]])
			printf(" %c", 'A'+acc[1]), --p[acc[1]];
		while (p[acc[0]]>p[acc[1]])
			printf(" %c", 'A'+acc[0]), --p[acc[0]];
		while (p[acc[0]]!=0)
			printf(" %c%c", 'A'+acc[0], 'A'+acc[1]), --p[acc[0]], --p[acc[1]];
		putchar('\n');
	}
	return 0;
}

