#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

long long t, n;
long long m[1000];

ifstream fin("C-small-attempt0.in");
ofstream fout("test.out");

struct Point {
	long long x, y;
	Point(long long x, long long y) {
		this->x = x;
		this->y = y;
	}
};

vector<Point> v;

long long get_dir(int p1, int p2, int p) {
	if (p == p1 || p == p2)
		return 0;
	long long vx1 = v[p2].x - v[p1].x;
	long long vy1 = v[p2].y - v[p1].y;
	long long vx2 = v[p].x - v[p1].x;
	long long vy2 = v[p].y - v[p1].y;
	return vx1 * vy2 - vx2 * vy1;
}

int main() {
	fin >> t;
	for (long long case_num = 1; case_num <= t; case_num++) {
		fin >> n;
		v.clear();
		for (long long i = 0; i < n; i++) {
			long long x, y;
			fin >> x >> y;
			Point tmp(x, y);
			v.push_back(tmp);
		}
		vector<long long> res;
		for (int p = 0; p < n; p++) {
			bool flag = false;
			long long opt = 0;
			for (int p1 = 0; p1 < n - 1; p1++)
				for (int p2 = p1 + 1; p2 < n; p2++) {
					long long tmp_opt;
					long long d = get_dir(p1, p2, p);
					long long sum_left = 0, sum_right = 0;
					for (int i = 0; i < n; i++)
						if (i != p && i != p1 && i != p2) {
							if (get_dir(p1, p2, i) > 0)
								sum_left++;
							else if (get_dir(p1, p2, i) < 0)
								sum_right++;
						}
					if (d == 0)
						tmp_opt = min(sum_left, sum_right);
					else if (d < 0)
						tmp_opt = sum_right;
					else
						tmp_opt = sum_left;
					if (!flag || tmp_opt < opt) {
						flag = true;
						opt = tmp_opt;
					}
				}
			res.push_back(opt);
		}		
		fout << "Case #" << case_num << ":" << endl;
		for (int i = 0; i < res.size(); i++)
			fout << res[i] << endl;
	}
	return 0;
}