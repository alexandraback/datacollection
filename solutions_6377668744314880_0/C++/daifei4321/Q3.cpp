#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cmath>
#include <cassert>

typedef long INT;
typedef long long LL;
typedef int BOOL;
#define TRUE 1
#define FALSE 0
#define MAX_N 15

using namespace std;

struct XY {
	INT x;
	INT y;
	XY() : x(0), y(0) {
	}
	XY(INT _x, INT _y) : x(_x), y(_y) {
	}
};
struct Dot : public XY {
};
struct Vec : public XY {
	Vec(Dot &from, Dot &to) : XY(to.x - from.x, to.y - from.y) {
	}
};
INT sign(LL v) {
	return v > 0 ? 1 : (v < 0 ? -1 : 0);
}
LL crossProduct(Vec &a, Vec &b) {
	return a.x * (LL) b.y - b.x * (LL) a.y;
}

BOOL isAtBoundry(Dot *dots, INT N, INT i) {
	assert(N >= 4);
	Dot &dotOri = dots[i];
	for (INT j = 0; j < N; j++) {
		if (i == j) {
			continue;
		}
		Dot &dotCon = dots[j];
		Vec ab(dotOri, dotCon);
		BOOL bothSideHappened = FALSE;
		INT sigHappened = 0;
		for (INT k = 0; k < N; k++) {
			if (i == k || j == k) {
				continue;
			}
			Dot &dotChk = dots[k];
			Vec bc(dotCon, dotChk);
			INT turn = sign(crossProduct(ab, bc));
			if (0 != turn) {
				if (sigHappened == 0) {
					sigHappened = turn;
				} else {
					if (sigHappened != turn) {
						bothSideHappened = TRUE;
						break;
					}
				}
			}
		}
		if (!bothSideHappened) {
			return TRUE;
		}
	}
	return FALSE;
}
INT getNeededToCut(Dot *dots, INT N, INT i, INT removed = 0) {
	if (N <= 3) {
		return 0;
	}
	if (isAtBoundry(dots, N, i)) {
		return 0;
	}
	if (removed >= 5) {
		return 9999;
	}
	INT neededFoundMin = 9999;
	Dot dotsRemain[MAX_N + 1];
	for (INT r = 0; r < N; r++) {
		if (r == i) {
			continue;
		}
		for (INT cFrom = 0, cTo = 0; cFrom < N; cFrom++) {
			if (cFrom == r) {
				continue;
			}
			dotsRemain[cTo++] = dots[cFrom];
		}
		INT iNext = r > i ? i : (i - 1);
		INT neededForR = getNeededToCut(dotsRemain, N - 1, iNext, removed + 1);
		if (neededForR == 0) {
			return 1;
		}
		if (neededFoundMin > neededForR) {
			neededFoundMin = neededForR;
		}
	}
	return 1 + neededFoundMin;
}
int main() {
	INT caseCount;
	cin >> caseCount;
	for (INT caseValue = 1; caseValue <= caseCount; caseValue++) {
		INT N;
		cin >> N;
		Dot dots[MAX_N + 1];
		for (INT i = 0; i < N; i++) {
			cin >> dots[i].x >> dots[i].y;
		}
		cout << "Case #" << caseValue << ":" << endl;
		for (INT i = 0; i < N; i++) {
			cout << getNeededToCut(dots, N, i) << endl;
		}
	}
	return EXIT_SUCCESS;
}
