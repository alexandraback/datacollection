#include <iostream>
#include <fstream>
#include <string>
#include <vector>



using namespace std;

int t;

struct point {
	int x, y;
};

bool above(point *p1, point *p2, point *p3) {		//above or right
	if(p1->x == p2->x)
		return p3->x > p1->x;
	return p3->y > ( (p2->y - p1->y) * 1.0 / (p2->x - p1->x) * (p3->x - p1->x) + p1->y );
}

bool below(point *p1, point *p2, point *p3) {		//below or left
	if(p1->x == p2->x)
		return p3->x < p1->x;
	return p3->y < ( (p2->y - p1->y) * 1.0 / (p2->x - p1->x) * (p3->x - p1->x) + p1->y );
}


int main() {

	ifstream fin("C-small-attempt0.in", ifstream::in);
	ofstream fout("result.out", ofstream::out);
	fin >> t;
//	cin >> t;
	int n;
	vector<point> ps;
	for(int i = 0; i < t; ++i) {
		fin >> n;
//		cin >> n;
		int nn = n;
		ps.clear();
		int x, y;
		while(nn--) {
			fin >> x >> y;
//			cin >> x >> y;
			point p;
			p.x = x;
			p.y = y;
			ps.push_back(p);
		}
		cout << "Case #" << (i+1) << ": " << endl;
		fout << "Case #" << (i+1) << ": " << endl;
		for(int j = 0; j < n; ++j) {
			int res = n-1;
			for(int k = 0; k < n; ++k) {
				int first = 0, second = 0;
				int temp_res = n-1;
				if(k == j)
					continue;
				for(int l = 0; l < n; ++l) {
					if(l == j || l == k)
						continue;
					if(above(&ps[j], &ps[k], &ps[l]))
						++first;
					else if(below(&ps[j], &ps[k], &ps[l]))
						++second;
				}
				temp_res = min(first, second);
				res = min(temp_res, res);
				if(res == 0)
					break;
			}
			cout << res << endl;
			fout << res << endl;
		}				
	}
	
	return 0;
}
