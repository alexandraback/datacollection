//Author: net12k44
#include <bits/stdc++.h>
using namespace std;

struct Point{
	long long x, y;
	Point(long long x=0, long long y=0) {
		this->x = x;
		this->y = y;
	}	
	Point(const Point& x, const Point& y){		
		this->x = y.x-x.x;
		this->y = y.y-x.y;
		//Point(y.x - x.x, y.y-x.y);
	}
	
	bool operator == (const Point &X) const {
		return x==X.x && y==X.y;
	}
	
	bool operator < (const Point &X) const {
		if (x != X.x) return x < X.x;
		return y < X.y;
	}
};

#define Vector Point


long long cross(const Vector& a, const Vector& b){	
	//cout << "cross" << a.x << endl;
	return a.x*b.y - a.y*b.x;	
}

long long ccw(const Point& a, const Point& b, const Point& c){	
	return cross( Vector(a,b), Vector(a,c) );
}

long long ccg(const Point& a, const Point& b, const Point& c){
	return cross( Vector(a,b), Vector(c,b) );
}

vector<Point> calConvex(vector<Point> pointList){
	int n = pointList.size();
	for(int i = 1; i < n; ++i)
		if (pointList[i] < pointList[0])
			swap(pointList[0], pointList[i]);
	
	Point p = pointList[0];
	for(int i = 1; i < n; ++i){
		for(int j = i+1; j < n; ++j){
			long long value = ccw(p, pointList[i], pointList[j]);
			if (value > 0 || (value==0 && pointList[j] < pointList[i]))
				swap(pointList[i], pointList[j]);
		}
		//cout << pointList[i].x << " " << pointList[i].y << endl;		
	}
		
				
	//for(auto p:  pointList) cout << p.x << " " << p.y << endl;
	//cout << ccw(p, pointList[1], pointList[2]);
	
	int nn = 1;
	for(int i = 1; i < n; ++i){
		while (nn>=2 && ccg(pointList[nn-2], pointList[nn-1], pointList[i]) <= 0)
			nn--;
		//cout << nn << endl;
		pointList[nn++] = pointList[i];
	}
		
	return vector<Point>(pointList.begin(), pointList.begin()+nn);
}

void solve(){
	int n; scanf("%d",&n);
	vector<Point> a;
	for(int i = 0; i < n; ++i){
		int x, y; scanf("%d%d",&x,&y);
		a.emplace_back(x,y);		
	}
	
	vector<int> res(n,n);
	
	for(int state = 1; state < (1 << n); ++state){
		vector<Point> pointList;
		
		int remove = n;
		for(int i = 0; i < n; ++i)
			if ( ((1 << i) & state) != 0){
				pointList.push_back(a[i]);
				remove--;
			}
					
		
		vector<Point> convex = calConvex(pointList);
		for(int i = 0; i < n; ++i)
		for(int k = 0; k < (int)convex.size(); ++k){
			if (a[i] == convex[k])
				res[i] = min(res[i], remove);
			
			int next = (k+1) % convex.size();
			if ( ccw(a[i], convex[k], convex[next]) == 0) 
				res[i] = min(res[i], remove);
			
		}
	}
	for(int i = 0; i < n; ++i) printf("%d\n",res[i]);
}	

int main(){
	freopen("file.inp","r",stdin);
	int test; scanf("%d",&test);
	for(int i = 1; i <= test; ++i){
		printf("Case #%d:\n", i);
		solve();
	}

}