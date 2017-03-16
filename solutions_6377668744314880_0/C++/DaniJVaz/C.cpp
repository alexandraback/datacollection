#include <cstdio>
#include <algorithm>
#include <vector>

typedef long long ll;

using namespace std;

struct point {
	ll x, y;
	int i;
	int minV;
};

ll ccw(point p1, point p2, point p3) {
    return (p2.x - p1.x)*(p3.y - p1.y) - (p2.y - p1.y)*(p3.x - p1.x);
}

bool less (const point & pi,const point & pj) { 
	ll t = ccw (point{0,0}, pi, pj);
	if (t != 0)
		return t >= 0;
	return pi.x*pi.x + pi.y*pi.y < pj.x*pj.x + pj.y*pj.y;
}

bool lessInd (const point & pi,const point & pj) { 
	return pi.i < pj.i;
}

int main() {
	int iC=0, nC;
	scanf("%d", &nC);
	for (iC=1; iC<=nC; iC++) {
		int N;
		scanf("%d", &N);

		point pArr[N];
		for (int i=0; i<N; i++) {
			scanf("%I64d %I64d", &pArr[i].x, &pArr[i].y);
			pArr[i].i = i;
		}

		printf("Case #%d:\n", iC);
		for (int i=0; i<N; i++) {
			point p = pArr[i];
			swap(pArr[0], pArr[i]);

			for (int j=0; j<N; j++) {
				pArr[j].x -= p.x;
				pArr[j].y -= p.y;
			}

			sort(pArr+1, pArr+N, less);

			int minV = N;
			for (int j=1; j<N; j++) {
				int countPos = 0, countNeg = 0;

				for (int l=0; l < N; l++) {
					if (ccw(pArr[0], pArr[j], pArr[l]) > 0)
						countPos++;
					else if (ccw(pArr[0], pArr[j], pArr[l]) < 0)
						countNeg++;
				}
				minV = min(minV, min(countPos, countNeg));
			}
			pArr[0].minV = minV;

			sort(pArr, pArr+N, lessInd);

			for (int j=0; j<N; j++) {
				pArr[j].x += p.x;
				pArr[j].y += p.y;
			}
		}

		if (N == 1)
			pArr[0].minV = 0;

		sort(pArr, pArr+N, lessInd);
		for (int i=0; i<N; i++)
			printf("%d\n", pArr[i].minV);

	}
	return 0;
}