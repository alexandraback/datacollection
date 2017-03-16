#include <fstream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

ifstream fin("C-small-attempt0.in");
ofstream fout("out.txt");

struct pt {
	double x, y;
};

bool cmp (pt a, pt b) {
	return a.x < b.x || a.x == b.x && a.y < b.y;
}

bool cw (pt a, pt b, pt c) {
	return a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y) <= 0;
}

bool ccw (pt a, pt b, pt c) {
	return a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x*(a.y - b.y) >= 0;
}

void convex_hull (vector<pt> & a) {
	if (a.size() == 1)  
		return;
	sort (a.begin(), a.end(), &cmp);
	pt p1 = a[0],  p2 = a.back();
	vector<pt> up, down;
	up.push_back (p1);
	down.push_back (p1);
	for (size_t i=1; i<a.size(); ++i) {
		if (i==a.size()-1 || cw (p1, a[i], p2)) {
			while (up.size()>=2 && !cw (up[up.size()-2], up[up.size()-1], a[i]))
				up.pop_back();
			up.push_back (a[i]);
		}
		if (i==a.size()-1 || ccw (p1, a[i], p2)) {
			while (down.size()>=2 && !ccw (down[down.size()-2], down[down.size()-1], a[i]))
				down.pop_back();
			down.push_back (a[i]);
		}
	}
	a.clear();
	for (size_t i=0; i<up.size(); ++i)
		a.push_back (up[i]);
	for (size_t i=down.size()-2; i>0; --i)
		a.push_back (down[i]);
}

int main() {
	int tests;
	fin >> tests;
	int n;
	for(int test = 0; test < tests; ++test) {
		int ans[15];
		vector<pt> a, b, c;
		fin >> n;
		for(int i = 0; i < n; ++i) {
			pt x;
			fin >> x.x >> x.y;
			a.push_back(x);
		}
		b = a;
	    convex_hull(a);
		for(int i = 0; i < n; ++i) {
			for(int j = 0; j < a.size(); ++j) 
				if((b[i].x == a[j].x) && (b[i].y == a[j].y)) ans[i] = 0;
			if(ans[i] != 0) {
				vector<int> two;
				two.resize(n);
				two[n - 1] = 1;
				bool flag = true;
				while(flag) {
					c.clear();
					int twos = 0;
					for(int o = 0; o < n; ++o) {
						if (two[o]) c.push_back(b[o]), twos++;
					}
					convex_hull(c);
					for(int k = 0; k < c.size(); ++k) 
				        if((b[i].x == c[k].x) && (b[i].y == c[k].y)) ans[i] = n - twos;
					int j = n - 1;
					while(j >= 0 && two[j] == 1) {
						two[j] = 0;
						--j;
					}
					if(j == -1) flag=false; else
					    two[j] = 1;
				}
			}
		}

		fout << "Case #" << test + 1 << ": " << endl;
		for(int i = 0; i < n; ++i) {
			fout << ans[i] << endl;
		}
	}
	return 0;
}
