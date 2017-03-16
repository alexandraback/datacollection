#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

int N;

struct Point {
	long long x, y;
	
	Point() {}
	
	Point(long long x, long long y): x(x), y(y) {}
	
	Point operator - (const Point &t) {
		return Point(x - t.x, y - t.y);
	}
} a[4000], b[7000];

long long cross(Point p1, Point p2) {
	return (p1.x * p2.y - p2.x * p1.y);
}

int region(long long x, long long y) {
	if (x > 0 && y >= 0) return 1;
	if (x <= 0 && y > 0) return 2;
	if (x < 0 && y <= 0) return 3;
	return 4;
}

bool cmp(const Point &t1, const Point &t2) {
	Point x(t1.x - b[0].x, t1.y - b[0].y);
	Point y(t2.x - b[0].x, t2.y - b[0].y);
	
	int c1 = region(x.x, x.y);
	int c2 = region(y.x, y.y);
	
	if (c1 > c2) return false;
	if (c1 < c2) return true;
	
	if (cross(x, y) < 0) return false;
	return true;
}

void work() {
	scanf("%d", &N);
	for (int i = 0; i < N; ++i) {
		cin >> a[i].x >> a[i].y;
	}
	
	for (int i = 0; i < N; ++i) {
		int ans = N - 1;
	
		for (int j = 0; j < N; ++j) {
			b[j].x = a[j].x;
			b[j].y = a[j].y;
		}
		swap(b[0], b[i]);
		sort(b + 1, b + N, cmp);
		
		/*
		for (int j = 0; j < N; ++j) {
			cerr << b[j].x << ','<< b[j].y << "   ";
		}
		cerr << endl;
		*/
		
		for (int j = 1; j < N; ++j)
			b[j + N - 1] = b[j];
		
		ans = N - 1;
		for (int j = 1; j < N; ++j) {
			int cnt = 0;
			for (int k = j + 1; k < N * 2 - 1; ++k) {
				long long c = cross(b[j] - b[0], b[k] - b[0]);
				if (c > 0) ++cnt;
				if (c < 0) break;
			}
			ans = min(ans, cnt);
		}
		printf("%d\n", ans);
	}
}

int main() {
	int T;
	scanf("%d", &T);
	for (int i = 0; i < T; ++i) {
		printf("Case #%d:\n", i + 1);
		work();
	}
}
