#include <bits/stdc++.h>

using namespace std;

#define ERROR 1e-12
#define RAD (PI / 180)

bool equal(double a, double b){ // O(1)
    return fabs(a - b) < ERROR;
}


struct Point{
    double x, y;
    bool operator <(Point cmp) const{
        if(equal(x, cmp.x))
            return y < cmp.y;
        return x < cmp.x;
    }
};

double Cross(Point u, Point v){ // O(1)
    return u.x * v.y - v.x * u.y;
}


Point P(double x, double y){ // O(1)
    Point* p = new Point;
    p->x = x, p->y = y;
    return *p;
}


Point Vector(Point o, Point p){ // O(1)
    return P(p.x - o.x, p.y - o.y);
}


bool CCW(Point p, Point q, Point r){ // O(1)
    return Cross(Vector(p, q), Vector(p, r)) >= 0;
}


vector<Point> ConvexHull(vector<Point> P){
    vector<Point> U, L;
    sort(P.begin(), P.end());
    
    for(int i = 0; i < P.size(); i++){
        while(L.size() > 1){
            Point p = L[L.size() - 2];
            Point q = L[L.size() - 1];
            if(CCW(p, q, P[i])) break;
            else L.pop_back();
        }
        L.push_back(P[i]);
    }
    if(L.size() > 1) L.pop_back();
    
    for(int i = P.size() - 1; i >= 0; i--){
        while(U.size() > 1){
            Point p = U[U.size() - 2];
            Point q = U[U.size() - 1];
            if(CCW(p, q, P[i])) break;
            else U.pop_back();
        }
        U.push_back(P[i]);
    }
    
    for(int i = 0; i < U.size(); i++)
        L.push_back(U[i]);
    return L;
}

Point puntos[1000];
int ans[100];

int main(){
	int T;
	cin >> T;
	for(int caso = 1; caso <= T; caso++){
		printf("Case #%d:\n", caso);
		int N;
		cin >> N;
		fill(ans, ans + N, 10000);
		for(int i = 0; i < N; i++)
			cin >> puntos[i].x >> puntos[i].y;
		vector <Point> now;
		for(int i = 1; i < (1 << N); i++){
			now.clear();
			int n = 0;
			for(int j = 0; j < N; j++){
				if(i & (1 << j)){
					now.push_back(puntos[j]);
					n++;
				}
			}
			vector <Point> convex =  ConvexHull(now);
			for(int j = 0; j < N; j++){
				for(int k = 0; k < convex.size(); k++){
					if(puntos[j].x == convex[k].x && puntos[j].y == convex[k].y){
						ans[j] = min(ans[j], N - n);
					}
				}
			}
		}
		for(int i = 0; i < N; i++)
			cout << ans[i] << endl;
			
	}
	return 0;
}