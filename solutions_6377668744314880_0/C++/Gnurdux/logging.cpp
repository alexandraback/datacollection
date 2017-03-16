#include <iostream>
#include <algorithm>
using namespace std;

struct vec {
	long long x;
	long long y;
};

bool operator<(vec a, vec b) {
	/*if (a.y < 0) {
		a.x = -a.x;
		a.y = -a.y;
	}
	if (b.y < 0) {
		b.x = -b.x;
		b.y = -b.y;
	}*/
	return a.x * b.y < b.x * a.y;
}

vec operator-(vec a, vec b) {
	return { a.x - b.x, a.y - b.y };
}

int N;
vec points[3000];
vec npoints[3000];
int ans[3000];

void compute() {
	for (int i = 0; i < N; i++) {
		int M = 0;
		int leftpoints = 0;
		/*for (int j = 0; j < N; j++) {
			if (points[j].y != points[i].y) npoints[M++] = points[j]-points[i];
			if (points[j].y < points[i].y || (points[j].y == points[i].y && points[j].x < points[i].x)) leftpoints++;
		}
		sort(npoints, npoints+M);

		for (int j = 0; j < M; j++) {
			int k = j, nowleft = 0, nowright = 0;
			while (k < M && !(npoints[j] < npoints[k])) {
				if (npoints[k].y > 0) nowleft++;
				else nowright++;
				k++;
			}
			if (leftpoints-nowright < ans[i]) ans[i] = leftpoints-nowright;

			leftpoints += nowleft-nowright;
			j = k-1;
		}*/
		for (int j = 0; j < N; j++) {
			if (j == i) continue;
			vec jpoint = points[j]-points[i];
			int lposs = 0, rposs = 0;
			for (int k = 0; k < N; k++) {
				vec kpoint = points[k]-points[i];
				if (kpoint < jpoint) lposs++;
				if (jpoint < kpoint) rposs++;
			}
			if (lposs < ans[i]) ans[i] = lposs;
			if (rposs < ans[i]) ans[i] = rposs;
		}
	}
}

void rotate() {
	for (int i = 0; i < N; i++) {
		long long a = points[i].x;
		points[i].x = -points[i].y;
		points[i].y = a;
	}
}

int main() {
	int T;
	cin >> T;

	for (int t = 1; t <= T; t++) {
		cin >> N;

		for (int i = 0; i < N; i++) {
			cin >> points[i].x >> points[i].y;
			ans[i] = N;
		}

		for (int r = 0; r < 4; r++) {
			compute();
			rotate();
		}

		cout << "Case #" << t << ":\n";
		for (int i = 0; i < N; i++) cout << ans[i] << '\n';
	}

	return 0;
}
