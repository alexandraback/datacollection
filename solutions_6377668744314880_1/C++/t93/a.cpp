#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

#define loop(i, n) for(int i=0;i<n;i++)

struct Point {
	long x, y;
};

struct Vect {
	long x, y;
};

Vect sub(Point const &point, Point const &origin) {
	Vect v = {point.x - origin.x, point.y - origin.y};
	return v;
}

long cross(Vect const &v1, Vect const &v2) {
	return v1.x * v2.y - v1.y * v2.x;
}

int cmp(long a, long b) {
	return a>b ? 1 : a<b ? -1 : 0;
}

int half(Vect const &v) {
	if (v.y == 0) return v.x > 0 ? 0 : 2;
	return v.y > 0 ? 1 : 3;
}

bool vect_less(Vect const &v1, Vect const &v2) {
	int h1 = half(v1);
	int h2 = half(v2);
	return h1 != h2 ? h1 < h2 : cross(v1, v2) > 0;
}

bool same_dir(Vect const &v1, Vect const &v2) {
	return !vect_less(v1, v2) && !vect_less(v2, v1);
}

bool less_than_half_turn(Vect const &v1, Vect const &v2) {
	return cross(v1, v2) > 0;
}

const int MAX = 3000;
int n;
Point points[MAX];
Vect vects[MAX];

int solve(int p) {
	int k = n-1;
	int j = 0;
	loop(i, n) {
		if (i != p) {
			vects[j++] = sub(points[i], points[p]);
		}
	}
	sort(vects, vects + k, vect_less);
	//printf("sorted:");
	//loop(i, k) printf(" (%d,%d)", vects[i].x, vects[i].y);
	//printf("\n");
	int best = k;
	int count = 0;
	j = 0;
	loop(i, k) {
		if (j==i) {
			j++;
			count++;
			if (j == k) j = 0;
		}
		while (i < k-1 && same_dir(vects[i], vects[i+1])) {
			i++;
			count--;
			if (j==i) {
				j++;
				count++;
				if (j == k) j = 0;
			}
		}
		while (less_than_half_turn(vects[i], vects[j])) {
			j++;
			count++;
			if (j == k) j = 0;
		}
		//printf("(%d, %d) .. (%d, %d) = %d\n", vects[i].x, vects[i].y, vects[j].x, vects[j].y, count);
		count--;
		best = min(best, count);
	}
	return best;
}

int main() {
	int ts;
	cin >> ts;
	loop(ti, ts) {
		printf("Case #%d:\n", ti+1);
		cin >> n;
		loop(i, n) {
			cin >> points[i].x >> points[i].y;
		}
		loop(i, n) {
			printf("%d\n", solve(i));
		}
	}
}
