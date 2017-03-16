#include "problem3.h"

#include <fstream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iostream>
#include <array>
using namespace std;

class diff {
public:
	long long dot;
	double len;
	int point;

	diff(long long dot, double len, int point) : dot(dot), len(len), point(point) {}

	bool operator<(const diff &other) const {
		double u = dot * other.len;
		double v = len * other.dot;
		if(abs(u - v) < 1e-45)
			return len < other.len;
		return u < v;
	}

	bool same(const diff &other) const {
		return abs(dot*other.len - len*other.dot) < 1e-45;
	}
};

void problem3(string filename) {
	ifstream infile(filename + ".in");
	ofstream outfile(filename + ".out");

	int t;
	infile >> t;

	for(int z = 1; z <= t; ++z) {
		int n;
		vector<int> x, y, r;

		int start = 0;

		infile >> n;
		for(int i = 0; i < n; ++i) {
			int tx, ty;
			infile >> tx >> ty;
			x.push_back(tx);
			y.push_back(ty);
			r.push_back(99999);

			if(tx < x[start] || (tx == x[start] && ty < y[start]))
				start = i;
		}

		int point = start;
		int prev = -1;
		while(true) {
			long long px, py;

			if(prev == -1) {
				px = 0;
				py = 1;
			} else {
				px = x[point] - x[prev];
				py = y[point] - y[prev];
			}

			vector<diff> angles;
			for(int i = 0; i < n; ++i) {
				if(i == point) {
					angles.push_back(diff(-999, 1, point));
					continue;
				}

				long long dx = x[i] - x[point];
				long long dy = y[i] - y[point];

				double len = sqrt(dx*dx + dy*dy) * sqrt(px*px + py*py);
				angles.push_back(diff(dx*px + dy*py, len, i));
			}

			sort(angles.rbegin(), angles.rend());

			for(int i = 0, pos = 0; i < n - 1; ++i) {
				if(i > 0 && !angles[i].same(angles[i - 1]))
					pos = i;

				r[angles[i].point] = min(pos, r[angles[i].point]);
			}

			prev = point;
			point = angles[0].point;
			if(point == start)
				break;
		}

		outfile << "Case #" << z << ":" << endl;
		for(int i = 0; i < n; ++i)
			outfile << r[i] << endl;
	}
}