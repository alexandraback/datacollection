#include <stdio.h>
#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

int n;

#define eps 1e-7

struct vec {
	double x, y;
	vec (){}
	vec (double a, double b) { x = a; y = b; }
	vec operator - (vec a) {
		return vec(x-a.x, y-a.y);
	}
	vec operator + (vec a) {
		return vec(x+a.x, y+a.y);
	}
	vec operator * (double k) {
		return vec(k*x, k*y);
	}
	vec operator / (double k) {
		return vec(x/k, y/k);
	}
	vec operator += (vec a) {
		x += a.x; y += a.y;
		return vec(x, y);
	}
	vec operator -= (vec a) {
		x -= a.x; y -= a.y;
		return vec(x, y);
	}
	bool operator != (vec a) {
		return fabs(x-a.x) > eps || fabs(y-a.y) > eps;
	}
	bool operator == (vec a) {
		return !(fabs(x-a.x) > eps || fabs(y-a.y) > eps);
	}
	double length2 (void) {
		return x*x+y*y;
	}
	double length (void) {
		return sqrt(x*x+y*y);
	}
	vec normalize (void) {
		return vec(x/length(), y/length());
	}
	double cross (vec a) {
		return x*a.y-y*a.x;
	}
	double dot (vec a) {
		return x*a.x+y*a.y;
	}
	vec project (vec a) {
		return a*(dot(a)/a.dot(a));
	}
	vec rotate (double rad) {
		double s = sin(rad), c = cos(rad);
		vec n (c*x-s*y, s*x+c*y);
		x = n.x; y = n.y;
		return vec(x, y);
	}
	vec rotate (double c, double s) {
		vec n (c*x-s*y, s*x+c*y);
		x = n.x; y = n.y;
		return vec(x, y);
	}
	void print (void) {
		printf ("(%lf, %lf)\n", x, y);
	}
};

int sgn (double x) {
	if (fabs(x) < eps)	return 0;
	if (x < 0)	return -1;
	return 1;
}

bool eq (double a, double b) {
	return fabs(a-b) < eps;
}

vec pt;

bool gscmp (pair<vec, int> a, pair<vec, int> b) {
	double cosa = (a.first-pt).normalize().x, cosb = (b.first-pt).normalize().x;
	if (eq(cosa, cosb))	return (a.first-pt).length() < (b.first-pt).length();
	return	cosa > cosb;
}

bool eqcos(pair<vec, int> a, pair<vec, int> b) {
	double cosa = (a.first-pt).normalize().x, cosb = (b.first-pt).normalize().x;
	return eq(cosa, cosb);
}

bool lcmp(pair<vec, int> a, pair<vec, int> b) {
	return (a.first-pt).length() > (b.first-pt).length();
}

void grahamScan (vector<vec> & vv, int & ans) {
	if (vv.size() <= 2) {
		ans = (vv.size() == 1 ? 1 : 3);
		return;
	}
	vector<pair<vec, int> > v(vv.size());
	int size, i;
	int ch[v.size()+1];
	vec curr, prev;

	ans = 0;
	for (i = 0; i < vv.size(); i++)	v[i] = make_pair(vv[i], i);
	for (i = 1; i < v.size(); i++) {
		if (v[i].first.y < v[0].first.y) {
			swap(v[i], v[0]);
		}
	}
	pt = v[0].first;
	sort (v.begin()+1, v.end(), gscmp);
	for (i = v.size()-2; eqcos(v[i], v[i+1]); i--);
	i++;
	if (i-1)
		sort (v.begin()+i, v.end(), lcmp);
	// if (v.size() == n) {
	// 	for (i = 0; i < n; i++)	printf ("%d ", v[i].second);
	// 	printf ("\n");
	// }
	ch[0] = 0;
	ch[1] = 1;
	size = 2;
	for (i = 2; i != 1; i = (i+1)%v.size()) {
		size++;
		do {
			size--;
			curr = v[i].first-v[ch[size-1]].first;
			prev = v[ch[size-1]].first-v[ch[size-2]].first;
		} while (size > 1 && sgn(prev.cross(curr)) < 0);
		ch[size++] = i;
	}
	for (i = 0; i < size-1; i++)
		ans |= (1<<v[ch[i]].second);
}
int main (void) {
	int t, c, i;
	vec pts[15];
	int mn[15];

	scanf ("%d", &t);
	for (c = 1; c <= t; c++) {
		scanf ("%d", &n);
		for (i = 0; i < n; i++) {
			mn[i] = n;
			scanf ("%lf%lf", &pts[i].x, &pts[i].y);
		}
		int mx = 1<<n;
		vector<vec> v;
		for (int mask = 1; mask < mx; mask++) {
			v.clear();
			for (i = 0; i < n; i++) {
				if ((mask>>i) & 1) {
					v.push_back(pts[i]);
				}
			}
			int ans;
			grahamScan(v, ans);
			int cnt = 0;
			for (i = 0; i < n; i++) {
				if ((mask>>i)&1)	cnt++;
			}
			//if (mask == mx-1)	printf ("le ans %d le count %d\n", ans, cnt);
			int pos = 0;
			for (i = 0; i < n; i++) {
				if ((mask>>i) & 1) {
					if ((ans>>pos) & 1) {
						mn[i] = min(mn[i], n-cnt);
					}
					pos++;
				}
			}
		}
		printf ("Case #%d:\n", c);
		for (i = 0; i < n; i++)	printf ("%d\n", mn[i]);
	}
}
