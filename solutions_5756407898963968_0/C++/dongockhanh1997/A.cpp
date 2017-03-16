#include <algorithm>
#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	int nTest; cin >> nTest;
	for(int test = 0; test < nTest; ++test) {
		vector<int> a, b, c;
		int p; cin >> p; --p;
		for(int i = 0; i < 4; ++i) {
			for(int j = 0; j < 4; ++j) {
				int x; cin >> x;
				if(i == p) a.push_back(x);
			}
		}
		cin >> p; --p;
		for(int i = 0; i < 4; ++i) {
			for(int j = 0; j < 4; ++j) {
				int x; cin >> x;
				if(i == p) b.push_back(x);
			}
		}
		sort(a.begin(), a.end());
		sort(b.begin(), b.end());
		c.resize(4);
		c.erase(set_intersection(a.begin(), a.end(), b.begin(), b.end(), c.begin()), c.end());
		printf("Case #%d: ", test + 1);
		if(c.size() == 1) printf("%d\n", c[0]);
		else if(c.size() == 0) puts("Volunteer cheated!");
		else puts("Bad magician!");
	}
	return 0;
}
