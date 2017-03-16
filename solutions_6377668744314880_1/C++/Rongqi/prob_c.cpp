#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

const double pi = acos(-1.0);
const double zero = 1e-9;

struct Point {
	double x, y;
	Point() {x = 0.0; y = 0.0;}
	Point(double x1, double y1) : x(x1), y(y1) {}
};

struct Node {
	double angle;
	int index;
	Node() {angle = 0.0; index = 0;}
	Node(double angle1, int index1) : angle(angle1), index(index1) {}
};

vector<Point> a;

void findmove(vector<double> & ang, int & p, int & q) {
	q = (q + 1) % ang.size();
	while (p != q && ((ang[q] >= ang[p] - zero && ang[q] <= ang[p] + pi + zero) || (ang[q] >= ang[p] - 2 * pi - zero && ang[q] <= ang[p] - pi + zero))) {
		q = (q + 1) % ang.size();
	}
	q = (q - 1 + ang.size()) % ang.size();
}

int main() {
	int testcases;
	cin >> testcases;
	for (int testcase = 0; testcase < testcases; testcase ++) {
		int n;
		cin >> n;
		a.clear();
		for (int i = 0; i < n; i ++) {
			Point p;
			cin >> p.x >> p.y;
			a.push_back(p);
		}
		cout << "Case #" << testcase + 1 << ":" << endl;
		if (n == 1) {
			cout << "0" << endl;
		} else {
			for (int i = 0; i < n; i ++) {
				int o = n - 1;
				vector<double> ang;
				for (int j = 0; j < n; j ++) {
					if (i == j) continue;
					ang.push_back(atan2(a[j].y - a[i].y, a[j].x - a[i].x));
				}
				sort(ang.begin(), ang.end());
				int p = 0;
				int q = 0;
				while (p < n - 1) {
					findmove(ang, p, q);
					int t = (q - p + 1 + n - 1) % (n - 1);
					if (t < o) o = t;
					if (n - 1 - t < o) o = n - 1 - t;
					p ++;
				}
				cout << o << endl;
			}
		}
	}
	return 0;
}