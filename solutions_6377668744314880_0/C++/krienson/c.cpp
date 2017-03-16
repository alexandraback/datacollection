#include <algorithm>
#include <cmath>
#include <iostream>
#include <list>
#include <sstream>
#include <string>
#include <utility>
#include <vector>
#include<stdio.h>
#define MP make_pair
#define PB push_back
#define SQ(a) (a)*(a)
#define SZ(a) (int)a.size()
#define X first
#define Y second
#define SL size()
using namespace std;
//const double piF = 2*acos(0);

struct point{
	int x,y, id;
	point(){}
	point(int X, int Y){x = X; y = Y;}
	bool operator<(const point &p)const{
		return (x < p.x || (x == p.x &&y < p.y));
	}
};
inline double dist(const point &a, const point &b){
	return sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y));
}

// 2D cross product.
// Return a positive value, if OAB makes a counter-clockwise turn,
// negative for clockwise turn, and zero if the points are collinear.
long long crossproduct(const point &O, const point &A, const point &B){
	return (A.x - O.x) * (B.y - O.y) - (A.y - O.y) * (B.x - O.x);
}

// Returns a list of points on the convex hull in counter-clockwise order.
// Note: the last point in the returned list is NOT the same as the first one.
vector<point> convexHull(vector<point> &P){
	long long n = P.size(), k = 0;
	vector<point> H(2*n);
	// Sort Points lexicographically
	//sort(P.begin(), P.end());
	// Build lower hull
	for (long long i = 0; i < n; i++) {
		while (k >= 2 && crossproduct(H[k-2], H[k-1], P[i]) < 0) k--;
		H[k++] = P[i];
	}
	// Build upper hull
	for (long long i = n-2, t = k+1; i >= 0; i--) {
		while (k >= t && crossproduct(H[k-2], H[k-1], P[i]) < 0) k--;
		H[k++] = P[i];
	}
	H.resize(k-1);
	return H;
}

int solution(int id, int st, vector<point> p2,vector<point> ch){
	if(int(p2.size()) < 2) return 0;
	for(int i=0;i<int(ch.size());i++) if(ch[i].id == id) return 0;
	int mini = 1000000;
	for(int i=st;i<int(p2.size());i++){
		if(p2[i].id == id) continue;
		vector<point> p = p2;
		p.erase(p.begin()+i);
		vector<point> ch2 = convexHull(p);
		mini = min(mini, 1+solution(id, i+1, p, ch2));
	}
	return mini;
}

int main(){
	int kases; cin>>kases;
	for(int kase = 1; kase <= kases; kase++){
		int N; cin>>N;
		vector<point> p(N);
		for(int i=0;i<N;i++){ cin>>p[i].x>>p[i].y; p[i].id = i;}
		sort(p.begin(), p.end());
		vector<point> ch = convexHull(p);
		vector<int> res(N,-1);
		for(int i=0;i<int(ch.size());i++) 
			res[ch[i].id] = 0;
		for(int i=0;i<N;i++){
			if(res[i] < 0){ 
				//cout<<"DESIRED ID: "<<p[i].id<<endl;
				res[i] = solution(i, 0, p, ch);
				/*vector<point> p2 = p;
				vector<point> ch2 = ch;	
				bool ok = false;
				do{	res[i]++;
					double mindist = 100000000.0, current_dist;
					int id = -1;
					for(int j=0;j<int(ch2.size());j++){
						current_dist = dist(ch2[j], p[i]);
						if(current_dist < mindist){ mindist = current_dist; id = ch2[j].id;}
					}
					for(int j=0;j<int(p2.size());j++) 
						if(p2[j].id == id){ 
							p2.erase(p2.begin()+j); cout<<"Remove ID: "<<p2[j].id<<" ("<<p2[j].x<<","<<p2[j].y<<")"<<endl;
							break; 
						}
					ch2 = convexHull(p2);
					for(int j=0;j<int(ch2.size());j++) cout<<"ID: "<<ch2[j].id<<endl; //cout<<endl;
					for(int j=0;j<int(ch2.size());j++) if(ch2[j].id == p[i].id){ ok = true; break;}
				}while(!ok);*/
			}
		}
		cout<<"Case #"<<kase<<": "<<endl;
		for(int i=0;i<N;i++) cout<<res[i]<<endl;	
	}
}
