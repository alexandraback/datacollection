#include <iostream>
#include <algorithm>
#include <deque>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cstring>
#include <cstdio>

using namespace std;

int r,c,n;
int pos(int i, int j) {
	return i*c + j;
}

int score(int mask) {
	int res = 0;
	for(int i=0; i<r; ++i) {
		for(int j=0; j<c;++j) {
			int d1[] = { 1, -1, 0, 0},
				d2[] = { 0,  0, 1, -1};
			for(int k=0;k<4;++k) {
				int i1 = i+d1[k],
					j1 = j+d2[k];
				if (i1 >= 0 && i1 < r && j1 >= 0 && j1 < c) {
					if ((mask & (1 << pos(i1,j1))) &&
							(mask & (1 << pos(i,j)))) res++;
				}
			}
		}
	}
	if (res % 2 == 1) throw -1;
	return res/2;
}

int main() {
	int t;
	cin>>t;
	for(int K=1; K <= t; ++K) {
		cin>>r>>c>>n;
		int res = 1e9;
		int m = r*c;
		int mx = 0;
		for(int mask = 0; mask < (1<<(m)); ++mask) {
			mx = max(mx, __builtin_popcount(mask));
			if (__builtin_popcount(mask) == n) {
				res = min(res, score(mask));
			}
		}
		//cout << mx << endl;
		printf("Case #%d: %d\n", K, res);
	}
	return 0;
}

