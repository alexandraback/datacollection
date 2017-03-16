#include <stdio.h>
#include <math.h>
#include <iostream>
#include <algorithm>
#include <vector>

#define N 3010
#define INF (-1u/2)

using namespace std;

class Point {
	public :
		double X, Y;
}P[N];

int CH[N], ans[N];
int idx[N];
int n;

double isleft(Point P1, Point P2, Point P3) {
	return (P2.X - P1.X) * (P3.Y - P1.Y) - (P2.Y - P1.Y) * (P3.X - P1.X);
}
double dis(Point P1, Point P2) {
	double dx = P1.X - P2.X, dy = P1.Y - P2.Y;
	return sqrt(dx * dx + dy * dy);
}
int cmpAng(int idx1, int idx2) {
	double r = isleft(P[idx[1]], P[idx1], P[idx2]);
	if(r != 0.0) {
		return r > 0;
	}else {
		return dis(P[idx[1]], P[idx1]) < dis(P[idx[1]], P[idx2]);
	}
}
int main() {
	
	freopen("Csmall.in", "r", stdin);
	freopen("Csmall.out", "w", stdout);
	int t;
	cin >> t;
	for(int C = 1;C <= t;C++) {
		cin >> n;
		for(int i = 1;i <= n;i++) {
			cin >> P[i].X >> P[i].Y;
			idx[i] = i;
			CH[i] = 0;
		}
		int bs = 1;
		for(int i = 2;i <= n;i++) {
			if(P[i].X < P[bs].X) { 
				bs = i;
			}
		}
		swap(idx[1], idx[bs]);
		sort(idx+1, idx+n+1, cmpAng);
		vector<int> stk;
		for(int i = 1;i <= n;i++) {
			int tmp = -1;
			while(stk.size() >= 2) {
				int t1 = stk.back();
				stk.pop_back();
				int t2 = stk.back();
				if(isleft(P[t2], P[t1], P[idx[i]]) >= 0.0) {
					stk.push_back(t1);
					break;
				}else if(isleft(P[stk[0]], P[t1], P[idx[i]]) == 0.0) {
					tmp = t1;
					break;
				}
			}
			stk.push_back(idx[i]);
			if(tmp != -1) {
				stk.push_back(tmp);
			}
		}
		for(int id : stk) {
			CH[id] = 1;
		}
		int sz = stk.size();
		for(int i = 1;i <= n;i++) {
			if(CH[i]) {
				ans[i] = 0;
				continue;
			}
			ans[i] = INF;
			for(int j = 0;j < sz;j++) {
				int k = (j + 1) % sz;
				while(k != j) {
					if(isleft(P[stk[j]], P[stk[k]], P[i]) <= 0.0) {
						int len;
						if(j < k) {
							len = k - j - 1;
						}else {
							len = sz - (j - k + 1);
						}
						ans[i] = min(ans[i], len);
					}
					k = (k + 1) % sz;
				}
			}
		}
		printf("Case #%d:\n", C);
		for(int i = 1;i <= n;i++) {
			printf("%d\n", ans[i]);
		}
	}
	return 0;
}
