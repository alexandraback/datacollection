#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

struct point { long long x, y; };

int turn(const point& a, const point& b, const point& c) {
	long long cross = (b.x - a.x)*(c.y - a.y) - (b.y - a.y)*(c.x - a.x);
	return cross ? (cross > 0 ? 1 : -1) : 0;
}

int main() {
	ifstream in("input.txt");
	ofstream out("output.txt");
	int T;
	in >> T;
	for (int test = 1; test <= T; test++) {
		int N;
		in >> N;
		vector<point> points(N);
		for (int i = 0; i < N; i++) {
			in >> points[i].x >> points[i].y;
		}
		out << "Case #" << test << ":" << endl;
		if (N == 1) {
			out << 0 << endl;
			continue;
		}
		for (int i = 0; i < N; i++) {
			int min_cut = 9999;
			for (int j = 0; j < N; j++) {
				if (j == i) { continue; }
				int left_sum = 0, right_sum = 0;
				for (int k = 0; k < N; k++) {
					int tmp = turn(points[i], points[j], points[k]);
					left_sum += (tmp > 0);
					right_sum += (tmp < 0);
				}
				min_cut = min(min_cut, min(left_sum, right_sum));
			}
			out << min_cut << endl;
		}
	}
	return 0;
}