#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <sstream>
#include <complex>
#include <ctime>
#include <cassert>
#include <functional>

using namespace std;

typedef long long ll;
typedef vector<int> VI;
typedef pair<int, int> PII;

#define REP(i,s,t) for(int i=(s);i<(t);i++)
#define FILL(x,v) memset(x,v,sizeof(x))

const int INF = (int)1E9;
#define MAXN 3005

int N;
int sign(ll x){
	if (x == 0) return 0;
	return x > 0 ? 1 : -1;
}
struct pt{
	ll x, y;
	pt(){}
	pt(ll _x, ll _y){ x = _x; y = _y; }
	pt operator - (pt p){
		return pt(x - p.x, y - p.y);
	}
	ll cross(pt p) {
		return x * p.y - y * p.x;
	}
} p[MAXN];

ll gcd(ll x, ll y) {
	return !y ? x : gcd(y, x%y);
}
struct frac{
	int reg;
	ll y, x;
	frac(){}
	frac(ll _y, ll _x){
		y = _y; x = _x;
		reg = -1;
		if (x > 0 && y >= 0) reg = 0;
		else if (x <= 0 && y > 0) reg = 1;
		else if (x < 0 && y <= 0) reg = 2;
		else if (x >= 0 && y < 0) reg = 3;
		if (reg == -1){
			cerr << "";
		}
		assert(reg != -1);
		x = abs(x);
		y = abs(y);
		if (x == 0) y = 1;
		else if (y == 0) x = 1;
		else {
			ll g = gcd(x, y);
			x /= g; y /= g;
		}
	}
	bool operator < (const frac &f) const {
		if (reg != f.reg) return reg < f.reg;
		if (reg % 2 == 0) return y * f.x < x * f.y;
		else return y * f.x > x * f.y;
	}
} fs[MAXN];
frac mirror(frac f) {
	frac nf = f;
	nf.reg = (nf.reg + 2) % 4;
	return nf;
}
int main(){
	int cs;
	cin >> cs;
	REP(csn, 1, cs + 1){
		printf("Case #%d:\n", csn);
		cin >> N;
		REP(i, 0, N){
			cin >> p[i].x >> p[i].y;
		}
		if (N == 1){
			puts("0");
			continue;
		}
		REP(i, 0, N){
			int ans = N - 1, sol;
			int F = 0;
			REP(j, 0, N){
				if (j == i) continue;
				pt v = p[j] - p[i];
				fs[F++] = frac(v.y, v.x);
			}
			sort(fs, fs + F);
			REP(j, 0, N){
				if (j == i) continue;
				pt v = p[j] - p[i];
				frac f = frac(v.y, v.x);
				frac mf = mirror(f);
				int p1, p2, p3, p4;
				if (f.reg <= 1){
					p1 = upper_bound(fs, fs + F, f) - fs;
					p2 = lower_bound(fs, fs + F, mf) - fs - 1;
					p3 = lower_bound(fs, fs + F, f) - fs - 1;
					p4 = upper_bound(fs, fs + F, mf) - fs;
					sol = min(p2 - p1 + 1, p3 + 1 + F - p4);
				}
				else {
					p1 = upper_bound(fs, fs + F, f) - fs;
					p2 = lower_bound(fs, fs + F, mf) - fs - 1;
					p3 = lower_bound(fs, fs + F, f) - fs - 1;
					p4 = upper_bound(fs, fs + F, mf) - fs;
					sol = min(p3 - p4 + 1, p2 + 1 + F - p1);
				}
				ans = min(ans, sol);
			}
			printf("%d\n", ans);
		}
	}
	return 0;
}