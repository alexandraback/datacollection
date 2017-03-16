#include <iostream>
#include <cstring>
#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int i,j,k,l[1005],m[1005],n, ans, cur , test,t, mx, a,d, ii,x,r,c,b;
string str;
int log[100];

typedef long long coord_t;         // coordinate type
typedef long long coord2_t;  // must be big enough to hold 2*max(|coordinate|)^2
 
struct Point {
	coord_t x, y;
 
	bool operator <(const Point &p) const {
		return x < p.x || (x == p.x && y < p.y);
	}
};
 
// 2D cross product of OA and OB vectors, i.e. z-component of their 3D cross product.
// Returns a positive value, if OAB makes a counter-clockwise turn,
// negative for clockwise turn, and zero if the points are collinear.
coord2_t cross(const Point &O, const Point &A, const Point &B)
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
		while (k >= 2 && cross(H[k-2], H[k-1], P[i]) <= 0) k--;
		H[k++] = P[i];
	}
 
	// Build upper hull
	for (int i = n-2, t = k+1; i >= 0; i--) {
		while (k >= t && cross(H[k-2], H[k-1], P[i]) <= 0) k--;
		H[k++] = P[i];
	}
 
	H.resize(k);
	return H;
}

int main(){
    freopen("input.txt","r",stdin);
    freopen("output1.txt","w", stdout);
    cin>>t;
    while(t--){
        for (i=0;i<100;i++) log[i] = 100;
        cin>>n;
        vector <Point> v;
        test++;
        for (i=0;i<n;i++){
            Point p;
            cin>>p.x>>p.y;
            v.push_back(p);
        }
        for (int mask=1;mask<(1<<n);mask++){
            vector <Point> vec;
            int bits = 0;
            for (j=0;j<n;j++){
                if ((mask&(1<<j))>0){
                    vec.push_back(v[j]);
                    bits++;
                }
            }
            vector <Point> answer  = convex_hull(vec);
            for (j=0;j<answer.size();j++){
                for (i=0;i<n;i++){
                int jj = (j+1)%answer.size();                
                    if (answer[j].x==v[i].x && answer[j].y==v[i].y){
                        log[i] = min(log[i], n-bits);
                    } else
                    if ( ((v[i].x-answer[j].x)*(answer[jj].y-v[i].y) == (v[i].y-answer[j].y)*(answer[jj].x-v[i].x)) && 
                    ((v[i].x-answer[j].x)*(answer[jj].x-v[i].x)>=0) && ((v[i].y-answer[j].y)*(answer[jj].y-v[i].y)>=0))
                    
                    {
                        log[i] = min(log[i], n-bits);                       
                    }
                }
            }
        }
        cout<<"Case #"<<test<<": \n";
        for (i=0;i<n;i++){
            cout<<log[i]<<"\n";
        }
        
    } 
    return 0;
}
