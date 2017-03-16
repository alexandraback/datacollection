#include <stdio.h>

#include <algorithm>

using namespace std;

struct A {
	long long x, y;
	int dir;
	A(long long _x = 0, long long _y = 0) : x(_x), y(_y) {
		if (x > 0 && y == 0)
			dir =  1;
		else if (x > 0 && y > 0)
			dir =  2;
		else if (x == 0 && y > 0)
			dir =  3;
		else if (x < 0 && y > 0)
			dir =  4;
		else if (x < 0 && y == 0)
			dir =  5;
		else if (x < 0 && y < 0)
			dir =  6;
		else if (x == 0 && y < 0)
			dir =  7;
		else
			dir =  8;
	}
	bool operator < (const A &r) const {
		if (dir != r.dir)
			return dir < r.dir;
		else
			return (x * r.y - y * r.x > 0);
	}

	bool sameSide(const A &r) const {
		return (x * r.y - y * r.x >= 0);
	}
};

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
	int ex[10010], ey[10010];
	A points[10010];
	for (ecount = 1; ecount <= ecase; ecount++) {
		if (ecount < caseStart || ecount > caseEnd)
			continue;
	
		if (caseStart > 0)
			fprintf(stderr, "....................CASE %d START\n", ecount);

		scanf("%d", &en);
		for (int i = 0; i < en; i++) 
			scanf("%d%d", &ex[i], &ey[i]);
		

		printf("Case #%d:\n", ecount);
		for (int i = 0; i < en; i++) {
			int tidx = 0;
			for (int j = 0; j < en; j++) {
				if (j != i)
					points[tidx++] = A(ex[j] - ex[i], ey[j] - ey[i]);
			}
			sort(points, points + en - 1);
			int fp = 0;
			int ans = en-1;
			for (int j = 0; j < en-1; j++) {
				while (fp - j < en-1 && points[j].sameSide( points[ fp%(en-1) ] )) {
					fp++;
				}
				int td = en - 1 - (fp - j);
				if (td < ans)
					ans = td;
			}
			printf("%d\n", ans);
		}



		

		if (caseStart > 0)
			fprintf(stderr, "....................CASE %d END\n", ecount);
	}

	return 0;
}
