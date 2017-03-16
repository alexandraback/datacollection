#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

#define MAXN 4096
#define EPS 1E-12

const double pi = 2.0*acos(0.0);

struct pt {
	double x, y;
	pt(double _x=0.0, double _y=0.0) {
		x=_x; y=_y;
	}
} n[MAXN];

pt operator-(const pt &p1, const pt &p2) {
	return pt(p1.x-p2.x, p1.y-p2.y);
}

double angle(const pt &p) {
	return atan2(p.y, p.x);
}

double alpha[MAXN][MAXN], o[2*MAXN];

int count(int cur, int N) {
	int i, j, RES;
	
	for (i=j=0; i<N; i++) if (i != cur) o[j++] = alpha[cur][i];
	sort(o, o+N-1);
	for (i=0; i<N-1; i++) o[i+N-1] = o[i]+2.0*pi;
	
	RES = N-1;
	for (i=j=0; i<N-1; i++) {
		while (o[j] < o[i]+pi+EPS) j++;
		RES = min(RES, N-1-(j-i));
	}
	return RES;
}

int main() {
	int T, t, N, i, j;

	cin >> T;
	for (t=1; t<=T; t++) {
		cin >> N;
		for (i=0; i<N; i++) cin >> n[i].x >> n[i].y;
		
		for (i=0; i<N; i++) for (j=0; j<N; j++) if (i != j) alpha[i][j] = angle(n[j]-n[i]);
		
		cout << "Case #" << t << ":" << endl;
		for (i=0; i<N; i++) cout << count(i, N) << endl;
	}

	return 0;
}
