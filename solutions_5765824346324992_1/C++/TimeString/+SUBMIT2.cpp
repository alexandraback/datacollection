#include <stdio.h>

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

	int eb, en;
	int array[100000];
	long long nextTime[10000];
	for (ecount = 1; ecount <= ecase; ecount++) {
		if (ecount < caseStart || ecount > caseEnd)
			continue;
	
		if (caseStart > 0)
			fprintf(stderr, "....................CASE %d START\n", ecount);

		scanf("%d%d", &eb, &en);
		for (int i = 0; i < eb; i++) {
			scanf("%d", &array[i]);
		}

		long long lbound = 0;
		long long ubound = 100000000000000000LL;
		long long time = lbound;

		while (lbound <= ubound) {
			long long mid = (lbound + ubound) / 2;
			long long numPeople = 0;
			for (int i = 0; i < eb; i++) {
				numPeople += mid / array[i];
				if (mid % array[i] > 0)
					numPeople++;
			}
			if (numPeople < en) {
				time = lbound;
				lbound = mid + 1;
			}
			else {
				ubound = mid - 1;
			}
		}
	
		int ans;
		long long totalPeople = 0;
		for (int i = 0; i< eb; i++) {
			long long serve = time / array[i];
			if (time % array[i] > 0)
				serve++;
			nextTime[i] = serve * array[i];
			totalPeople += serve;
		}

		do {
			int mno = 0;
			for (int i = 1; i < eb; i++)
				if (nextTime[i] < nextTime[mno])
					mno = i;
			ans = mno;
			nextTime[mno] += array[mno];
			totalPeople++;
		} while ((int)totalPeople < en);

		printf("Case #%d: %d\n", ecount, ans+1);
		

		if (caseStart > 0)
			fprintf(stderr, "....................CASE %d END\n", ecount);
	}

	return 0;
}
