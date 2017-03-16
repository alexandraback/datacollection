#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

typedef vector<bool> VB;
typedef vector<VB> MB; 

int h;

int eval(MB& map) {
	int res = 0;
	for (int i = 0; i < map.size(); ++i) {
		for (int j = 0; j < map[i].size(); ++j) {
			if (map[i][j]) {
				if (i+1 < map.size() and map[i+1][j]) {
					++res;
				}
				if (j+1 < map[i].size() and map[i][j+1]) {
					++res;
				}
			}
		}
	}
	return res;
}

void gen(MB& map, int pos, int n) {
	if (pos == (map.size() * map[0].size())) {
		int nh = eval(map);
		if (n == 0) {
			if (h == -1 or h > nh) {
				h = nh;
			}
		}
		return;
	}
	int j = pos/map.size();
	int i = pos%map.size();
	map[i][j] = true;
	gen(map, pos+1, n-1);
	map[i][j] = false;
	gen(map, pos+1, n);
}

int main() {
	int t;
	cin >> t;
	for (int cas = 1; cas < t+1; ++cas) {
		int r,c,n;
		cin >> r >> c >> n;
		MB map = MB(r,VB(c));
		h = -1;
		gen(map, 0, n);
		cout << "Case #" << cas << ": " << h << endl;
	}
}