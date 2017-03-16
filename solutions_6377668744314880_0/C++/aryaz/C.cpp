#include <bits/stdc++.h>
using namespace std;

complex<double> p[3005];
double pp[3005];

int main () {
	int T;
	cin >> T;
	for(int t = 1; t <= T; t++) {
		int n;
		cin >> n;
		cout << "Case #" << t << ":\n";
		if(n <= 3) {
			for(int i = 0; i < n; i++) {
				double x, y;
				cin >> x >> y;
				cout << 0 << endl;
			}
			continue;
		}
		for(int i = 0; i < n; i++) {
			double x, y;
			cin >> x >> y;
			p[i] = complex<double>(x, y);
		}
		for(int i = 0; i < n; i++) {
			int k = 0;
			for(int j = 0; j < n; j++)
				if(j != i) {
					pp[k] = arg(p[j]-p[i]);
					if(pp[k] < -1e-12)
						pp[k] += 2.0*M_PI;
					k++;
				}
			sort(pp, pp+n-1);
//			cerr << "### " << i << endl;
//			for(int j = 0; j < n-1; j++) {
//				cerr << "!!! " << pp[j] << endl;
//			}
			int res = n;
			for(int s = 0; s < n-1; s++) {
				for(int e = 0; e < n-1; e++) {
					if((pp[(s+e)%(n-1)] >= pp[s] && pp[(s+e)%(n-1)] - pp[s] >= M_PI-1e-12) || (pp[(s+e)%(n-1)] < pp[s] && (2.0*M_PI) + pp[(s+e)%(n-1)] - pp[s] >= M_PI-1e-12)) {
//						cerr << "@@@ " << s << " " << e << ": " << pp[(s+e)%(n-1)] << " " << pp[s] << endl;
						res = min(res, e-1);
						break;
					}
				}
			}
			if(res == n)
				res = 0;
			cout << res << endl;
		}
	}
	return 0;
}
