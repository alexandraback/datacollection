#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

#define fi first
#define se second
#define pb push_back
#define mp make_pair

#define N 3010

const double eps = 1e-6;

struct P {
	int x, y;
	P(){}
	P(int _x, int _y):x(_x),y(_y) {}
	P operator + (const P&a) const {return P(x+a.x, y+a.y);}
	P operator - (const P&a) const {return P(x-a.x, y-a.y);}
	ll crs (const P&a) const {return (ll)x*a.y-(ll)y*a.x;}
	ll dot (const P&a) const {return (ll)x*a.x+(ll)y*a.y;}
	double ang () const {return atan2(y, x);}
	void get () {cin >> x >> y;} 
	void out () {printf ("%d %d\n", x, y);}
};

int n; P a[N], b[N*2];

bool cmp(P x, P y) {
	return x.ang() < y.ang();
}

bool in(double a, double b) {
	while (b > a+2*M_PI-eps) b -= 2*M_PI;
	while (b < a-eps) b += 2*M_PI;
	return b < a+M_PI+eps;
}

void ff() {
	for (int i = 1; i < n; i ++) 
		b[i-1] = a[i]-a[0];
	n --;
	sort(b, b+n, cmp);
	//cout << b[0].ang() << " " << b[2].ang() << endl;
	//in(b[0].ang(), b[2].ang());
	for (int i = 0; i < n; i ++) 
		b[i+n] = b[i];
	int S = 0;
	for (int i = 0, j = 0; i < n; ) {
		while (j < i+n && b[i].crs(b[j]) >= 0) j ++;
		S = max(S, j-i);
		//cout << i << " " << j << endl;
		int k = i;
		while (k < i+n && b[i].dot(b[k]) >= 0 && b[i].crs(b[k]) == 0) k ++;
		i = k;
	}
	printf ("%d\n", n-S);
	//puts ("W");
	n ++;
}

int main() {
	int _; cin >> _;
	for (int __ = 1; __ <= _; __ ++) {
		cin >> n;
		for (int i = 0; i < n; i ++) a[i].get();
		printf ("Case #%d:\n", __);
		for (int i = 0; i < n; i ++) {
			swap(a[0], a[i]);
			ff();
			swap(a[0], a[i]);
		}
	}
	return 0;
}
