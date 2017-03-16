#include <iostream>
#include <vector>
#include <cstdio>
#include <sstream>
#include <map>
#include <string>
#include <algorithm>
#include <queue>
#include <cmath>
#include <set>
using namespace std;

#define EPS 1e-6

class xy{
	
public:
	double x;
	double y;

	xy(){

	}
	
	xy(double xx, double yy){
		x = xx;
		y = yy;
	}

	xy(const xy &v){
		x = v.x;
		y = v.y;
	}

	xy& operator=(const xy &v){
		x = v.x;
		y = v.y;
		return *this;
	}

	xy operator+(const xy &v) const{
		return xy(this->x+v.x, this->y+v.y);
		
	}
	
	xy operator-(const xy &v) const{
		return xy(this->x-v.x, this->y-v.y);
	}
	
	void operator+=(const xy &v){
		x+=v.x;
		y+=v.y;
	}
	void operator-=(const xy &v){
		x-=v.x;
		y-=v.y;
	}
};

//u,v : vector O = (0,0)
double cross(const xy &u, const xy &v){
	return u.x*v.y - u.y*v.x;
}

//u,v : vector O = (0,0)
double dot(const xy &u, const xy &v){
	return u.x*v.x + u.y*v.y;
}

//distance between two points
double dist_p_p(const xy &a, const xy &b){
	return sqrt( fabs(dot(a-b, a-b)) );
}

//distance between a point and a line segment
double dist_p_ls(const xy &p, const xy &s1, const xy &s2){
	xy vl = s2 - s1;
	xy vp = p - s1;

	return fabs( cross(vl, vp) / sqrt( dot(vl, vl) ) );
}

//zero -> p1
int ccw(xy p1, xy p2, xy p3){
	p2 -= p1;
	p3 -= p1;
	double c = cross(p2,p3);
	if( c > EPS /* c > 0 */) return +1;			//counter-clockwise
	if( c < -EPS /* c < 0 */) return -1;		//clock-wise
	if( dot(p2,p3) < -EPS) return +2;			//on segment : p3-p1-p2
	if( dot(p3,p3) < dot(p2,p2) +EPS ) return -2;	//on segment : p1-p3-p2
	return 0;
}

//segment p1-p2, p3-p4
bool inter_ss(xy p1, xy p2, xy p3, xy p4){
	return ( (ccw(p1,p2, p3) * ccw(p1,p2, p4) <= 0) && (ccw(p3,p4, p1) * ccw(p3,p4, p2) <= 0 ) ) ;
}

//for sorting
bool comp_xy(const pair<xy, int> &a, const pair<xy, int> &b){
	if(a.first.x != b.first.x) return a.first.x < b.first.x;
	return a.first.y < b.first.y;
}

//convex_hull
vector<pair<xy,int>> convex_hull(vector<pair<xy,int>>& v){
	sort( v.begin(), v.end(), comp_xy );
	int k = 0;	//nums of vertex
	vector<pair<xy,int>> tmp(v.size()*2);

	//conect i from k
	for(int i=0; i<v.size(); i++){
		while(k>1 && cross (tmp[k-1].first - tmp[k-2].first, v[i].first - tmp[k-1].first) < -EPS ) k--;
		tmp[k] = v[i];
		k++;
	}
	
	for(int i=v.size()-2, t=k; i>=0; i--){
		while(k>t && cross(tmp[k-1].first - tmp[k-2].first, v[i].first - tmp[k-1].first) < -EPS ) k--;
		tmp[k] = v[i];
		k++;
	}

	tmp.resize(k-1);
	return tmp;
}

int bit_count(int bits){
	int ret = 0;
	while(bits){
		bits -= bits&-bits;
		ret++;
	}
	return ret;
}

void solve(){
	int N;
	cin >> N;
	vector<double> x(N),y(N);
	for(int i=0; i<N; i++){
		cin >> x[i] >> y[i];
	}

	vector<int> ans(N, N);
	for(int i=1; i<(1<<N); i++){
		int cut = N - bit_count(i);
		vector<pair<xy,int>> p;
		for(int j=0; j<N; j++){
			if((i>>j)&1) p.push_back( {xy(x[j],y[j]), j} );
		}

		auto v = convex_hull(p);
		for(int j=0; j<v.size(); j++){
			int pos = v[j].second;
			ans[pos] = min(ans[pos], cut);
		}
	}

	if(N<=3){
		for(int i=0; i<N; i++){
			ans[i] = 0;
		}
	}

	for(int i=0; i<N; i++){
		cout << ans[i] << endl;
	}

}

int main(){
	int T;
	cin >> T;
	for(int t=1; t<=T; t++){
		cerr << "case : " << t << endl;
		cout << "Case #" << t << ":" << endl;
		solve();
	}
	return 0;
}