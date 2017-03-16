#include <stdio.h>
#include <algorithm>
#include <vector>
typedef long long ll;
using namespace std;
struct data {
	data() {
		data(0,0);
	}
	data(ll a, ll b) {
		x = a, y = b;
	}
	ll x, y;
	bool operator < (const data & l) const {
		if(y<0 && l.y >= 0) return false;
		if(y>0 && l.y < 0) return true;
		if(l.y == 0) {
			if(l.x > 0) return false;
			if(y > 0) return true;
			if(y == 0 && x > 0) return true;
			if(y == 0 && x < 0) return false;
		}
		if(y == 0) {
			if(x > 0) return true;
			if(l.y > 0) return false;
			if(l.y < 0) return true;
			if(l.y == 0) return false;
		}
		if(x == 0) {
			if(l.x * l.y > 0) return false;
			if(l.x == 0) return false;
			else return true;
		}
		if(l.x == 0) {
			if(x*y>0) return true;
			else return false;
		}
		if(x*y > 0) {
			if(l.x*l.y < 0) return true;
			return l.x*y < l.y*x;
		}
		if(x*y < 0) {
			if(l.x*l.y > 0) return false;
			return l.x*y < l.y*x;
		}
	}
};
vector <data> V;
ll d[3050][2];
int ans[3050];
bool Inside(int x, int y) {
	if(V[x].y == 0) {
		if(V[x].x > 0) {
			if(V[y].y < 0) return false;
			else return true;
		}
		if(V[y].y > 0) return false;
		return true;
	}
	if(V[x].y > 0) {
		data tmp = data(-V[x].x, -V[x].y);
		if(V[y] < V[x] || tmp < V[y]) return false;
		else return true;
	}
	if(V[x].y < 0) {
		data tmp = data(-V[x].x, -V[x].y);
		if(V[y] < V[x] && tmp < V[y]) return false;
		else return true;
	}
}
int main() {
	freopen("C-small-attempt0.in", "r", stdin);
	freopen("output.txt", "w", stdout);
	int T, N, i, j, mx;
	ll t1, t2;
	scanf("%d", &T);
	for(int t = 1; t <= T; t++) {
		scanf("%d", &N);
		for(i = 1; i <= N; i++) scanf("%lld %lld", &d[i][0], &d[i][1]);
		printf("Case #%d:\n", t);
		if(N == 1) {
			printf("0\n");
			continue;
		}
		for(i = 1; i <= N; i++) {
			for(j = 1; j <= N; j++) {
				if(i == j) continue;
				V.push_back(data(d[j][0]-d[i][0], d[j][1]-d[i][1]));
			}
			mx = 0;
			int p = 0;
			sort(V.begin(), V.end());
			while(Inside(0, p%V.size()) && p < V.size()) {
				p++;
			}
			mx = p;
			if(mx == V.size()) {
				printf("0\n");
				V.clear();
				continue;
			}
			for(j = 1; j < V.size(); j++) {
				data tmp = V[j];
				while(Inside(j,p%V.size())&&p<V.size()+j) p++;
				if(mx < p-j) mx = p-j;
			}
			printf("%d\n", N-mx-1);
			V.clear();
		}
	}
	return 0;
}