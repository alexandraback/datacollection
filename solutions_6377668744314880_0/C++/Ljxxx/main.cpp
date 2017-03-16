#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <set>
#include <map>

using namespace std;
 
struct Point {
	long long x, y;
	int id;
	bool operator <(const Point &p) const {
		return x < p.x || (x == p.x && y < p.y);
	}
};

int x[16], y[16], n;

long long cross(const Point &O, const Point &A, const Point &B)
{
	return (A.x - O.x) * (B.y - O.y) - (A.y - O.y) * (B.x - O.x);
}

vector<int> convex_hull(vector<Point> P) {
	int n = P.size(), k = 0;
	vector<int> H(2*n);
 
	sort(P.begin(), P.end());
 
	for (int i = 0; i < n; ++i) {
		while (k >= 2 && cross(P[H[k-2]], P[H[k-1]], P[i]) < 0) k--;
		H[k ++] = i;
	}
 
	for (int i = n-2, t = k+1; i >= 0; i--) {
		while (k >= t && cross(P[H[k-2]], P[H[k-1]], P[i]) < 0) k--;
		H[k++] = i;
	}
 
	H.resize(k);
	for(int i = 0;i < k;i ++) H[i] = P[H[i]].id;

	return H;
}

void input() {
	scanf("%d", &n);
	for(int i = 0;i < n;i ++) scanf("%d%d", &x[i], &y[i]);
}

void solve() {
	int sol[16];
	for(int i = 0;i < n;i ++) sol[i] = 1;

	for(int s = 1;s < (1<<n);s ++) {
		vector<Point> P;
		for(int i = 0;i < n;i ++) if(s&(1<<i)) {
			Point tt;
			tt.x = x[i];
			tt.y = y[i];
			tt.id = i;
			P.push_back(tt);
		}

		vector<int> res = convex_hull(P);
		sort(res.begin(), res.end());
		int cnt = P.size();
		for(int i = 0;i < (int)res.size();i ++) if(cnt > sol[res[i]]) sol[res[i]] = cnt;
	}

	for(int i = 0;i < n;i ++) printf("%d\n", n - sol[i]);
}

int main() {
	freopen("C-small-attempt0.in", "r", stdin);
	freopen("output.txt", "w", stdout);
	int Case;
	scanf("%d", &Case);
	for(int cas = 1;cas <= Case;cas ++) {
		input();
		printf("Case #%d:\n", cas);
		solve();
	}
}