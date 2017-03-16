#include <iostream>
#include <fstream>
#include <vector>
#include <complex>
#include <string>
#include <cmath>
#include <sstream>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;

class P2 {
public:
	long long x, y;
	P2(long long x = 0, long long y = 0) : x(x), y(y) {}
	bool operator == (const P2& p) const { return x == p.x && y == p.y; }
	bool operator < (const P2& p) const { return x != p.x ? x < p.x : y < p.y; }
};

long long dot(P2& a, P2& b){ return a.x*b.x + a.y*b.y; }
long long cross(P2& a, P2& b){ return a.x*b.y - a.y*b.x; }
P2 add(P2& a, P2& b){ return P2(a.x + b.x, a.y + b.y); }
P2 sub(P2& a, P2& b){ return P2(a.x - b.x, a.y - b.y); }
int norm(P2& p){ return p.x*p.x + p.y*p.y; }

int ccw(P2 a, P2 b, P2 c) {
	b = sub(b, a);
	c = sub(c, a);
	if (cross(b, c) > 0)   return +1;       // counter clockwise
	if (cross(b, c) < 0)   return -1;       // clockwise
	if (dot(b, c) < 0)     return +2;       // c--a--b on line
	if (norm(b) < norm(c)) return -2;       // a--b--c on line
	return 0;
}

vector<P2> convexHull(const vector<P2>& ps){
	int n = ps.size(), k = 0;
	vector<P2> ch(2 * n);
	for (int i = 0; i<n; ch[k++] = ps[i++]) // lower-hull
		while (k >= 2 && ccw(ch[k - 2], ch[k - 1], ps[i]) == -1) --k;
	for (int i = n - 2, t = k + 1; i >= 0; ch[k++] = ps[i--]) // upper-hull
		while (k >= t && ccw(ch[k - 2], ch[k - 1], ps[i]) == -1) --k;
	ch.resize(k - 1);
	return ch;
}

int main(){
	int T; cin >> T;
	static int mem[1 << 15];
	for(int t=1;t<=T;t++){
		int N; cin >> N;
		vector<int> x(N), y(N);
		for (int i = 0; i < N; i++) cin >> x[i] >> y[i];
		memset(mem, 0, sizeof(mem));
		for (int i = 1; i < (1 << N); i++){
			vector<P2> vp;
			for (int j = 0; j < N; j++){
				if (i&(1 << j)) vp.push_back(P2(x[j], y[j]));
			}
			sort(vp.begin(), vp.end());
			if (vp.size() > 3) vp = convexHull(vp);
			for (int j = 0; j < N; j++){
				for (int k = 0; k < vp.size(); k++){
					if (vp[k].x == x[j] && vp[k].y == y[j]) mem[i] |= (1 << j);
				}
			}
		}
		printf("Case #%d:\n", t);
		for (int i = 0; i < N; i++){
			int res = N;
			for (int j = 0; j < (1 << N); j++){
				if (mem[j] & (1 << i)){
					int cnt = 0;
					for (int k = 0; k < N; k++){
						if (!(j&(1 << k))) cnt++;
					}
					res = min(res, cnt);
				}
			}
			printf("%d\n", res);
		}
	}
}
