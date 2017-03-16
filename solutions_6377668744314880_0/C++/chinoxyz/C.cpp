#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <set>
#include <queue>
#include <stack>
#include <string>
#include <sstream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cassert>

using namespace std;

#define ri(X) scanf("%d", &(X))
#define pi(X) printf("%d", (X))
#define mp(X,Y) make_pair(X,Y)
#define pb(X) push_back(X)
#define lint long long
#define pii pair<int,int>
#define inf 1e9
#define linf 1e18
#define X first
#define Y second
#define all(X) (X).begin(),(X).end()
#define uni(X) X.erase(unique(X.begin(), X.end()), X.end());


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
int n;
vector<PT> convex_hull(vector<PT> P){ 
	int n = P.size(), k = 0; 
	vector<PT> H(2*n); 
	// Sort PTs lexicographically 
	//sort(P.begin(), P.end()); 
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
vector<PT> ve;
int solve(int x){
  vector<PT> cv;// = convex_hull(ve);
  /*for(int i = 0; i < cv.size(); i++){
    if(cv[i] == ve[x]) return 0;
  }*/
  int res = inf;
  vector<PT> v1;
  for(int s = 0; s < (1<<n); s++){
    if( ((1<<x)&s) == 0) continue;
    
    v1.clear();
    
    int num = n;
    for(int i = 0; i < n; i++){
      if( ((1<<i)&s) == 0) continue;
      v1.pb(ve[i]);
      num--;
    }
    
    sort(all(v1));
    /*
    printf("%d\n", num);
    
    for(int i = 0; i < v1.size(); i++){
      printf("(%d %d)", v1[i].x, v1[i].y);
    }cout << endl;
    */
    if(v1.size() <= 3){
      res = min(res,num);
      continue;
    }
    cv = convex_hull(v1);
    
    /*
    for(int i = 0; i < cv.size(); i++){
      printf("(%d %d)", cv[i].x, v1[i].y);
    }cout << endl;*/
    for(int i = 0; i < cv.size()-1; i++){
      if(cv[i] == ve[x]){
        res = min(res, num);
      }
    }
  }
  return res;
}
int main(){
  int T;
  
  int x, y;
  
  ri(T);
  for(int t = 0; t < T; t++){
    ri(n);
    ve.clear();
    for(int i = 0; i < n; i++){
      ri(x); ri(y);
      ve.pb(PT(x,y));
    }
    printf("Case #%d:\n", t+1);
    
    for(int i = 0;i < n; i++){
      printf("%d\n", solve(i));
    }
  }
  return 0;
}

