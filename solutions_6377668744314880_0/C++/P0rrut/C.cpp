#include<bits/stdc++.h>
#define ri(X) scanf("%d",&X)
#define rii(X,Y) scanf("%d %d",&X,&Y)
#define rf(X) scanf("%lf",&X)
#define rff(X,Y) scanf("%lf %lf",&X,&Y)
#define mp(X,Y) make_pair(X,Y)
#define pii pair<int,int>
#define FOR(i,j) for(int i=0;i<j;i++)
#define FORC(i,j,c) for(int i=0;i<j;i+=c)

using namespace std;
int N;
const int mn = 20;
int xs[mn];
int ys[mn];

//Convex hulll de la guia
typedef int coord_t;         // coordinate type 
typedef long long coord2_t;  // must be big enough to hold 2*max(|coordinate|)^2 
struct PT { 
  public: 
	int x, y; 
  PT (int _x, int _y){ 
    x = _x; 
    y = _y; 
  } 
  PT(){ 
    x = 0; 
    y = 0; 
  } 
	bool operator <(const PT &p) const { 
		return x < p.x || (x == p.x && y < p.y); 
	} 
	bool operator ==(const PT &p) const { 
		return (x == p.x && y == p.y); 
	} 
	 
}; 

// 2D cross product of OA and OB vectors, i.e. z-component of their 3D cross product. 
// Returns a positive value, if OAB makes a counter-clockwise turn, 
// negative for clockwise turn, and zero if the PTs are collinear. 
coord2_t cross(const PT &O, const PT &A, const PT &B){ 
	return (A.x - O.x) * (coord2_t)(B.y - O.y) - (A.y - O.y) * (coord2_t)(B.x - O.x); 
} 


vector<PT> convex_hull(vector<PT> P){ 
	int n = P.size(), k = 0; 
	vector<PT> H(2*n); 
	double dist;
	// Sort PTs lexicographically 
	sort(P.begin(), P.end()); 
	// Build lower hull 
	for (int i = 0; i < n; i++) { 
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

//

int main(){
  int T;
  cin >> T;
  FOR(t,T){
    printf("Case #%d: ",t+1);
    cin >> N;
    FOR(i,N) cin >> xs[i] >> ys[i];
    cout << endl;
    FOR(i,N){
      int mini = N+10;
      FOR(k,(1<<N)){
        if(((1<<i) & k)==0) continue;
        vector<PT> pts;
        if(__builtin_popcount(k)<=2) continue;
        FOR(j,N){
          if(k & (1<<j)){
            pts.push_back(PT(xs[j],ys[j]));
          }
        }
        vector<PT> hull = convex_hull(pts);
        FOR(j,hull.size()){
          if(hull[j].x==xs[i] && hull[j].y==ys[i]){
            mini = min(mini,N-__builtin_popcount(k));
            break;
          }
        }
      }
      cout << mini << endl;
    }
  }

	return 0;
}
