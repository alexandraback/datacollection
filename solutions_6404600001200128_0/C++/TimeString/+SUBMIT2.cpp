#include <stdio.h>

inline int min(int a, int b) {
	if (a < b)
		return a;
	return b;
}

int main(int argc, char *argv[]) {
	int ecase, ecount;
	int caseStart = -1, caseEnd = 9999999;
	scanf("%d", &ecase);

	if (argc > 1) {
		if (sscanf(argv[1], "%d", &caseStart) == 1) {
			if (argc > 2)
				sscanf(argv[2], "%d", &caseEnd);
		}
		if (caseEnd < caseStart)
			caseEnd = caseStart;
		if (caseEnd != 9999999 && caseEnd >= 1 && caseStart <= 0)
			caseStart = 1;
		if (caseStart > 0)
			fprintf(stderr, "....................DEBUG MODE ENABLED (FROM CASE %d to %d)\n", caseStart, caseEnd);
	}

	int en;
	int array[100000];
	for (ecount = 1; ecount <= ecase; ecount++) {
		if (ecount < caseStart || ecount > caseEnd)
			continue;
	
		if (caseStart > 0)
			fprintf(stderr, "....................CASE %d START\n", ecount);

		scanf("%d", &en);
		for (int i = 0; i < en; i++)
			scanf("%d", &array[i]);
		int ans1 = 0;
		int ans2 = 0;
		int rate = 0;

		for (int i = 0; i < en-1; i++) {
			int d = array[i] - array[i+1];
			if (d > 0)
				ans1 += d;
			if (d > rate)
				rate = d;
		}
		for (int i = 0; i < en-1; i++) {
			ans2 += min(rate, array[i]);
		}


		
		printf("Case #%d: %d %d\n", ecount, ans1, ans2);
		

		if (caseStart > 0)
			fprintf(stderr, "....................CASE %d END\n", ecount);
	}

	return 0;
}
