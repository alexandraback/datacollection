#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <string>
using namespace std;

struct Point {
    Point(long long int x_ = 0, long long int y_ = 0) : x(x_), y(y_) {} 
    long long int x, y;
};

Point operator-(const Point & P1, const Point & P2) {
    return Point(P1.x-P2.x,P1.y-P2.y);
}

inline long long int crossProd(const Point & P1, const Point & P2) {
    return P1.x*P2.y- P1.y*P2.x;
}

int nbGoods(const vector<Point> & v, int i) {
    Point A = v[i];
    int maxi = -1;
    for(int j = 0; j < v.size(); j++) {
	Point B = v[j];
	if(A.x == B.x && A.y == B.y)
	    continue;
	int nbHalf = 0;
	Point AB = B-A;
	for(int k = 0; k < v.size(); k++) {
	    Point C = v[k];
	    if(crossProd(C-A,AB) >= 0)
		nbHalf++;
	}
	maxi = max(maxi,nbHalf);
    }
    return (maxi == -1 ? v.size() : maxi);
}

void result(const vector<Point> & v) {
    for(int i = 0; i < v.size(); i++) {
	cout << v.size() - nbGoods(v,i) << endl;
    }
}

int main() {
    int T;
    cin >> T;
    for(int t = 0; t < T; t++) {
	int N;
	cin >> N;
	vector<Point> v(N);
	for(int i = 0; i < N; i++) {
	    cin >> v[i].x >> v[i].y;
	}
	cout << "Case #" << t+1 << ":" << endl;
	result(v);
    }
    return 0;
}
