#include <bits/stdc++.h>
#define REP(i,n) for(int i=0; i<int(n); i++)
#define ALL(v) (v).begin(),(v).end()
#define DBG(x) cerr<<__LINE__<<": " #x " = "<<x<<endl
#define endl '\n'
using namespace std;

// from http://en.wikibooks.org/wiki/Algorithm_Implementation/Geometry/Convex_hull/Monotone_chain
typedef long long coord_t;         // coordinate type
typedef long long coord2_t;  // must be big enough to hold 2*max(|coordinate|)^2
 
struct Point {
	coord_t x, y;
 
	bool operator <(const Point &p) const {
		return x < p.x || (x == p.x && y < p.y);
	}
	
	bool operator==(const Point&p) const {
		return x==p.x && y==p.y;
	}
};
 
// 2D cross product of OA and OB vectors, i.e. z-component of their 3D cross product.
// Returns a positive value, if OAB makes a counter-clockwise turn,
// negative for clockwise turn, and zero if the points are collinear.
coord2_t cross(const Point &O, const Point &A, const Point &B)
{
	return (A.x - O.x) * (B.y - O.y) - (A.y - O.y) * (B.x - O.x);
}
 
// Returns a list of points on the convex hull in counter-clockwise order.
// Note: the last point in the returned list is the same as the first one.
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

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T; cin>>T;
    REP(_t, T) {
        cout<<"Case #"<<_t+1<<":"<<endl;
        
        int N; cin>>N;
        vector<Point> points(N);
        REP(i,N) {
        	cin>>points[i].x>>points[i].y;
		}
		
		vector<int> result(N, max(0, N-3));
		for(int mask=1; mask<(1<<N); mask++) {
			int numTrees = __builtin_popcount(mask);
			if(numTrees<=3) continue;
			int cut = N-numTrees;
			
			vector<Point> subset;
			subset.reserve(numTrees);
			for(int bit=0; bit<N; bit++)
				if(mask&(1<<bit))
					subset.push_back(points[bit]);
			
			vector<Point> preserv = convex_hull(subset);
			
			for(int k=0; k<preserv.size(); k++) {
				REP(i,N)
					if(preserv[k]==points[i])
						result[i] = min(result[i], cut);
			}
			
			
		}
		
        for(auto v: result) cout<<v<<endl;
        
    }
}

