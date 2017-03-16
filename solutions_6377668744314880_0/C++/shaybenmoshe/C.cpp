// Uses a modified version of covex hull from:
// https://en.wikibooks.org/wiki/Algorithm_Implementation/Geometry/Convex_hull/Monotone_chain.

#include <iostream>
#include <fstream>
#include <chrono>
#include <algorithm>
#include <array>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <stdint.h>

using namespace std;

typedef uint32_t uint;
typedef int32_t sint;
typedef uint64_t ulong;
typedef int64_t slong;
typedef uint8_t byte;

#define FOR(var,start,end)		for (sint (var) = (sint)(start); (var) <= (sint)(end); (var)++)
#define SORT(arr, N)			std::sort((arr), &(arr)[(N)])










typedef slong coord_t;
typedef slong coord2_t;

struct Point {
	coord_t x, y;

	uint pos;

	bool operator ==(const Point &p) const {
		return x == p.x && y == p.y;
	}

	bool operator <(const Point &p) const {
		return x < p.x || (x == p.x && y < p.y);
	}

	ulong distSq(const Point &p) const {
		return (p.x - x) * (p.x - x) + (p.y - y) * (p.y - y);
	}
};

// 2D cross product of OA and OB vectors, i.e. z-component of their 3D cross product.
// Returns a positive value, if OAB makes a counter-clockwise turn,
// negative for clockwise turn, and zero if the points are collinear.
coord2_t cross(const Point &O, const Point &A, const Point &B)
{
	return (A.x - O.x) * (B.y - O.y) - (A.y - O.y) * (B.x - O.x);
}

// Returns a list of points on the convex hull in counter-clockwise order.
// Note: the last point in the returned list is the same as the first one.
// 
vector<Point> convex_hull(uint N, vector<Point> P)
{
	int k = 0;
	vector<Point> H(2 * N);

	// Build lower hull
	for (int i = 0; i < N; ++i) {
		while (k >= 2 && cross(H[k - 2], H[k - 1], P[i]) <= 0) k--;
		H[k++] = P[i];
	}

	// Build upper hull
	for (int i = N - 2, t = k + 1; i >= 0; i--) {
		while (k >= t && cross(H[k - 2], H[k - 1], P[i]) <= 0) k--;
		H[k++] = P[i];
	}

	H.resize(k);
	return H;
}










bool tryVec(uint N, vector<Point> P, uint tar, vector<Point> o) {
	Point t = P[tar];
	FOR(i, 0, o.size() - 2) {
		if ((t.y - o[i].y) * (o[i + 1].x - o[i].x) == (o[i + 1].y - o[i].y) * (t.x - o[i].x)) {
			return true;
		}
	}
	return false;
}

uint solveForPos(uint N, vector<Point> P, uint tar) {
	if (N == 1) {
		return 0;
	}

	vector<Point> o = convex_hull(N, P);
	if (tryVec(N, P, tar, o)) {
		return 0;
	}

	Point p = P[tar];

	uint minDistSqInd = 0;
	ulong minDistSq = UINT64_MAX;
	FOR(i, 0, o.size() - 1) {
		ulong d = p.distSq(o[i]);
		if (d < minDistSq) {
			minDistSqInd = i;
		}
	}

	uint realInd = 0;
	FOR(i, 0, N - 1) {
		if (o[minDistSqInd] == P[i]) {
			realInd = i;
		}
	}

	Point remP = P[realInd];
	P.erase(P.begin() + realInd);

	uint m = solveForPos(N - 1, P, realInd < tar ? tar - 1 : tar);

	P.insert(P.begin() + realInd, remP);

	/*uint m = UINT32_MAX;
	FOR(i, 0, N - 1) {
		if (i == tar) continue;
		
		Point remP = P[i];
		P.erase(P.begin() + i);

		uint temp;
		temp = solveForPos(N - 1, P, i < tar ? tar - 1 : tar);
		if (temp < m) {
			m = temp;
		}
		if (m == 0) break;

		P.insert(P.begin() + i, remP);
	}*/

	return m + 1;
}

void solve(uint N, vector<Point> P, vector<uint> &sol) {
	sort(P.begin(), P.end());
	
	FOR(k, 0, N - 1) {
		sol[P[k].pos] = solveForPos(N, P, k);
	}
}


void main() {
	ofstream output;
	ifstream input;
	input.open("D:\\projects\\cpp\\codejam\\2015-round-1A\\2015-round-1A-C\\Release\\input.txt");
	output.open("D:\\projects\\cpp\\codejam\\2015-round-1A\\2015-round-1A-C\\Release\\output.txt");

	uint T;
	input >> T;

	FOR(i, 1, T) {
		cout << "Case #" << i << " out of #" << T;
		chrono::milliseconds timeStart = chrono::duration_cast< chrono::milliseconds >(chrono::high_resolution_clock::now().time_since_epoch());



		uint N;
		input >> N;

		vector<Point> P(N);
		FOR(k, 0, N - 1) {
			input >> P[k].x;
			input >> P[k].y;
			P[k].pos = k;
		}

		vector<uint> sol(N);

		solve(N, P, sol);

		output << "Case #" << i << ":" << endl;
		FOR(k, 0, N - 1) {
			output << sol[k] << endl;
		}



		chrono::milliseconds timeEnd = chrono::duration_cast< chrono::milliseconds >(chrono::high_resolution_clock::now().time_since_epoch());
		cout << ", took " << (timeEnd - timeStart).count() << "ms" << endl;
	}

	input.close();
	output.close();

	cout << "DONE!" << endl;
	system("pause");
}

