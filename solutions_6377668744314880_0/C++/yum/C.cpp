#include <bits/stdc++.h>
using namespace std;

const double EP = 1e-9;
typedef complex<double> PX;
vector<PX> pts;
double cp(PX a, PX b) {return (conj(a)*b).imag();}
int ccw(PX a, PX b, PX c) { 
	double r = cp(b-a, c-a);
	if (fabs(r) < EP) return 0;
	return r > 0 ? 1 : -1;
}
void convexHull() {
	if (pts.empty()) return;
	int fi = 0;
	for (int i = 1; i < (int)pts.size(); i++)
		if (pts[i].imag() + EP < pts[fi].imag() || 
		   (fabs(pts[i].imag() - pts[fi].imag())<EP &&
		   pts[i].real() + EP < pts[fi].real())) fi = i;
	swap(pts[0], pts[fi]);
	sort(++pts.begin(), pts.end(), [](PX a, PX b) {
		PX v1 = a - pts[0], v2 = b - pts[0];
		double a1 = arg(v1), a2 = arg(v2);
		if (fabs(a1 - a2) > 1e-14) return a1 < a2;
		return abs(v1) < abs(v2);
	});
	int M = 2;
	for (int i = 2; i < (int)pts.size(); i++) {
		while (M > 1 && ccw(pts[M-2], pts[M-1], pts[i]) <= 0) M--;
		swap(pts[i], pts[M++]);
	}
	if (M < (int)pts.size()) pts.resize(M);
}
bool onSeg(PX p1, PX p2, PX x) { 
	return fabs(abs(p2-p1)-abs(x-p1)-abs(x-p2))<EP;
}

int main() {
	int TC, N;
	cin >> TC;
	for (int tc=1; tc<=TC; tc++) {
		cin >> N;
		vector<PX> mypx;
		for (int n = 0; n < N; n++) {
			double x, y;
			cin >> x >> y;
			mypx.emplace_back(x, y);
		}
		vector<int> minTrees(N, N);
		for (int bs = 0; bs < (1<<N); bs++) {
			pts.clear();
			for (int n = 0; n < N; n++) if (!(bs & (1<<n))) pts.push_back(mypx[n]);
			convexHull();
			for (int n = 0; n < (int)pts.size(); n++) {
				for (int m = 0; m < N; m++) {
					if (onSeg(pts[n], pts[(n+1)%pts.size()], mypx[m])) {
						minTrees[m] = min(minTrees[m], __builtin_popcount(bs));
					}
				}
			}
		}
		cout << "Case #" << tc << ":" << endl;
		for (int n = 0; n < N; n++) cout << minTrees[n] << endl;
	}
}
