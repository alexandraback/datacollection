#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


class Point {
public:
	long long x, y;
	int idx;
	bool operator <(const Point &p) const {
		return x < p.x || (x == p.x && y < p.y);
	}
};

long long cross(const Point &O, const Point &A, const Point &B)
{
	return (A.x - O.x) * (B.y - O.y) - (A.y - O.y) * (B.x - O.x);
}

vector<Point> convex_hull(vector<Point> P)
{
	int n = P.size(), k = 0;
	vector<Point> H(2*n);
 
	// Sort points lexicographically
	sort(P.begin(), P.end());
 
	// Build lower hull
	for (int i = 0; i < n; ++i) {
		while (k >= 2 && cross(H[k-2], H[k-1], P[i]) < 0) k--;
		H[k++] = P[i];
	}
 
	// Build upper hull
	for (int i = n-2, t = k+1; i >= 0; i--) {
		while (k >= t && cross(H[k-2], H[k-1], P[i]) < 0) k--;
		H[k++] = P[i];
	}
 
	H.resize(k);
	return H;
}
	 

Point pt[20];
vector<int> m;

int main() {
	int T;
	cin >> T;
	m.resize(16);
	for (int t=1;t<=T;t++) {
		cout << "Case #" << t << ": " << endl;
		int N;
		cin >> N;
		for (int i=0;i<N;i++) {
			cin >> pt[i].x;
			cin >> pt[i].y;
			pt[i].idx = i;
		}
		fill(m.begin(), m.end(), N);
		int mask = (1 << N) - 1;
		for (int i=1;i<=mask;i++) {
			vector<Point> tr;
			for (int j=0;j<N;j++) {
				if ((i & (1 << j)) != 0) {
					tr.push_back(pt[j]);
				}
			}
			if (tr.size() > 0) {
				vector<Point> h = convex_hull(tr);
				for (int j=0;j<h.size();j++) {
					if (m[h[j].idx] > (N - tr.size())) {
						m[h[j].idx] = N - tr.size();
					}	
				}
			}
		}
		for (int i=0;i<N;i++) {
			cout << m[i] << endl;
		}
	}
	return 0;
}
