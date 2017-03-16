#include <vector>
#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
using namespace std;

struct Point {
	int x, y;
	bool operator<(const Point &r) const {
		return x == r.x ? y < r.y : x < r.x;
	}
	bool operator==(const Point &r) const {
		return x == r.x && y == r.y;
	}
};

ostream& operator<<(ostream& os, const Point& pt)
{
	os << '(' << pt.x << ", " << pt.y << ')';
	return os;
}

#define cross(A, B, C) ((B.x - A.x) * (C.y - A.y) - (B.y - A.y) * (C.x - A.x))

int convexHull(const vector<Point>& P, int t) {

	cerr << " -- *** MAKING HULL for " << P[t] << '\n';

	int n = P.size(), k = 0;
	vector<Point> H(2 * n); // hull

	int modu = 0, modd = 0, zt, i;

	// up
	for (i = 0; i < n; i++) {
		cerr << " -- [ UP ] consider " << P[i] << "\n";
		while (k >= 2 && cross(H[k - 2], H[k - 1], P[i]) < 0) {
			if (H[k - 1] == P[t]) {
				// removing our square!
				modu++;
				cerr << " -- [ UP ] fail; remove " << H[k - 2] << "\n";
				swap(H[k - 2], H[k - 1]);
			} else {
				cerr << " -- [ UP ] remove " << H[k - 1] << "\n";
			}
			k--;
		}
		H[k++] = P[i];
		cerr << " -- [ UP ] Add " << P[i] << "\n";
	}
	for (i = n - 2, zt = k + 1; i >= 0; i--) {
		cerr << " -- [DOWN] consider " << P[i] << "\n";
		while (k >= zt && cross(H[k - 2], H[k - 1], P[i]) < 0) {
			cerr << " -- [DOWN] remove " << H[k - 1] << "\n";
			k--;
		}
		H[k++] = P[i];
		cerr << " -- [DOWN] Add " << P[i] << "\n";
	}

	int zzz = zt - 3;
	while (cross(H[zzz], H[zt - 2], H[zt - 1]) < 0) {
		zzz--;
		modu++;
	}
	while (cross(H[k - 1], H[0], H[1]) < 0) {
		k--;
		modu++;
	}

	cerr << " -- FINAL HULL - up (mod: " << modu << "):\n";
	for (i = 0; i < k; i++) {
		cerr << "  " << H[i];
	}
	cerr << '\n';

	k = 0;

	// down
	for (i = 0; i < n; i++) {
		cerr << " -- [ UP ] consider " << P[i] << "\n";
		while (k >= 2 && cross(H[k - 2], H[k - 1], P[i]) < 0) {
			cerr << " -- [ UP ] remove " << H[k - 1] << "\n";
			k--;
		}
		H[k++] = P[i];
		cerr << " -- [ UP ] Add " << P[i] << "\n";
	}
	for (i = n - 2, zt = k + 1; i >= 0; i--) {
		cerr << " -- [DOWN] consider " << P[i] << "\n";
		while (k >= zt && cross(H[k - 2], H[k - 1], P[i]) < 0) {
			if (H[k - 1] == P[t]) {
				// removing our square!
				modd++;
				cerr << " -- [DOWN] fail; remove " << H[k - 2] << "\n";
				swap(H[k - 2], H[k - 1]);
			} else {
				cerr << " -- [DOWN] remove " << H[k - 1] << "\n";
			}
			k--;
		}
		H[k++] = P[i];
		cerr << " -- [DOWN] Add " << P[i] << "\n";
	}

	zzz = zt - 3;
	while (cross(H[zzz], H[zt - 2], H[zt - 1]) < 0) {
		zzz--;
		modd++;
	}
	while (cross(H[k - 1], H[0], H[1]) < 0) {
		k--;
		modd++;
	}

	cerr << " -- FINAL HULL - down (mod: " << modd << "):\n";
	for (i = 0; i < k; i++) {
		cerr << "  " << H[i];
	}
	cerr << '\n';

	cerr << " -- *** ANSWER : " << min(modu, modd) << '\n';

	return min(modu, modd);
}

int main() {
	int T;
	scanf("%d", &T);
	for (int t = 0; t++ < T;) {
		int N, x, y, res[3000];
		scanf("%d", &N);

		vector<Point> P(N);
		map<Point, int> trf;
		for (int i = 0; i < N; i++) {
			scanf("%d%d", &P[i].x, &P[i].y);
			trf[P[i]] = i;
		}
		sort(P.begin(), P.end());

		for (int i = 0, j; i < N; i++) {
			//printf("%d\n", convexHull(P, i));
cerr << " --- \n";
/*
			// find upper half cost
			int cost = 0x7fffffff;

			int cul = 0, cur = 0;
			// find cost going left
			for (j = i - 1; j >= 0; j--) {
				if (P[j].y <= P[i].y) break;
			}
			cost = min(cost, i - j - 1);
			for (j = i + 1; j < N; j++) {
				if (P[j].y <= P[i].y) break;
			}
			cost = min(cost, j - i - 1);

			// lower half cost
			for (j = i - 1; j >= 0; j--) {
				if (P[j].y >= P[i].y) break;
			}
			cost = min(cost, i - j - 1);
			for (j = i + 1; j < N; j++) {
				if (P[j].y >= P[i].y) break;
			}
			cost = min(cost, j - i - 1);
*/
			res[trf[P[i]]] = convexHull(P, i);
		}
		printf("Case #%d:\n", t);
		for (int i = 0; i < N; i++) {
			printf("%d\n", res[i]);
		}
	}
	return 0;
}