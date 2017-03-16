#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

class Point {
public:
	long long x, y;
	Point (long long x = 0, long long y = 0) : x(x), y(y) {}
};

long long area(const Point &A, const Point &B) {
	return A.y * B.x - A.x * B.y;
}

bool operator < (const Point &A, const Point &B) {
	return atan2(A.y, A.x) < atan2(B.y, B.x);
}

Point operator - (const Point &A, const Point &B) {
	return Point(A.x - B.x, A.y - B.y);
}

int main() {
	int nTests;
	cin >> nTests;
	for (int test = 1; test <= nTests; ++test) {
		int n;
		cin >> n;
		vector<Point> P(n);
		for (int i = 0; i < n; ++i) {
			cin >> P[i].x >> P[i].y;
		}
		cout << "Case #" << test << ":" << endl;
		if (n == 1) {
			cout << 0 << endl;
		} else {
			for (int i = 0; i < n; ++i) {
				vector<Point> v1, v2;
				for (int j = 0; j < n; ++j) {
					if (j != i) {
						v1.push_back(P[j] - P[i]);
					}
				}
				sort(v1.begin(), v1.end());
				for (int j = 0; j < v1.size(); ++j) {
					//cout << v1[j].x << " " << v1[j].y << endl;
				}
				v2 = v1;
				reverse(v2.begin(), v2.end());
				
				int best = -1;

				int h, t;

				h = 0, t = 0;
				while (h < n - 1) {
					while ((t + 1) % (n - 1) != h && area(v1[h], v1[(t + 1) % (n - 1)]) <= 0) {
						t = (t + 1) % (n - 1);
					}
					int tmp;
					if ((t + 1) % (n - 1) == h) {
						tmp = 0;
					} else {
						tmp = n - 1 - (t - h + 1 + n - 1) % (n - 1);
					}
					if (best == - 1 || best > tmp) {
						best = tmp;
					}
					++h;
				}

				h = 0, t = 0;
				while (h < n - 1) {
					while ((t + 1) % (n - 1) != h && area(v2[h], v2[(t + 1) % (n - 1)]) >= 0) {
						t = (t + 1) % (n - 1);
					}
					int tmp;
					if ((t + 1) % (n - 1) == h) {
						tmp = 0;
					} else {
						tmp = n - 1 - (t - h + 1 + n - 1) % (n - 1);
					}
					if (best == - 1 || best > tmp) {
						best = tmp;
					}
					++h;
				}
				cout << best << endl;
			}
		}
		//return 0;
	}
	return 0;
}
