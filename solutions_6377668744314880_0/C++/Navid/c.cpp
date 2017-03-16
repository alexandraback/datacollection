#include <iostream>
#include <complex>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

typedef complex<double> point;

const double eps = 1e-6;

double cross(const point &a, const point &b) {
	return imag(conj(a)*b);
}

int comp(const point &a, const point &b) {
	if  (abs(a.real() - b.real())>eps)
		return a.real()<b.real();
	if (abs(a.imag() - b.imag())>eps)
		return a.imag()<b.imag();
	return 0;
}

int isonline(const point &a, const point &b, const point &c) {
	return abs(cross(a-b, c-a)) < eps;
}

inline vector<point> convexhull (vector<point> &pts) {
	sort(pts.begin(), pts.end(), comp);
	vector<point> lower, upper;
	for(int i=0; i<(int)pts.size(); i++) {
		while (lower.size() >= 2 && cross(lower.back()-lower[lower.size()-2], pts[i]-lower.back()) < eps)
			lower.pop_back();
		while (upper.size() >= 2 &&	cross(upper.back()-upper[upper.size()-2], pts[i]-upper.back()) > -eps)
			upper.pop_back();
		lower.push_back(pts[i]);
		upper.push_back(pts[i]);
	}
	lower.insert(lower.end(), upper.rbegin() +1 , upper.rend());
	return lower;
}

int main() {
	int t;
	cin >> t;
	for (int tn=0; tn<t; tn++) {
		int n;
		vector<point> tree;
		cin >> n;
		for (int i=0; i<n; i++) {
			double a, b;
			cin >> a >> b;
			tree.push_back(point(a,b));
		}
		//vector<point> convex = convexhull(tree);
		cout << "Case #"<<tn+1<<":"<<endl;
		for (int i=0; i<n; i++) {
			int ans = n-1;
			for(int j=0; j<(1<<n); j++) {
				vector<point> newtree;
				int bitcnt = 0;
				int tmp = j;
				int isbad = 0;
				for (int h=0; h<n; h++) {
					if (h==i && (tmp&(1<<h))==0){
						isbad = 1;
						break;
					}
					if (tmp&(1<<h)) {
						newtree.push_back(tree[h]);
						bitcnt++;
					}
				}
				if (n-bitcnt < ans && !isbad) {
					vector<point> convex = convexhull(newtree);
					int isgood = 0;
					for (int k=0; k+1<convex.size(); k++) {
						if (isonline(tree[i], convex[k], convex[k+1])) {
							isgood = 1;
							break;
						}
					}
					if (isgood) {
						ans = n-bitcnt;
					}
				}
			}
			cout << ans << endl;
		}
	}
}