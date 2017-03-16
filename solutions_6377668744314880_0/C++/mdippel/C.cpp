#include <iostream>
#include <vector>

using namespace std;

typedef long long LD;
struct Point{
	LD x;
	LD y;
};

//LD EPSILON = 0.00000001;

bool ccw(Point a, Point b, Point c){
	LD v1 = (b.x - a.x)*(c.y - a.y);
	LD v2 = (b.y - a.y)*(c.x - a.x);
	return v1 - v2 > 0;
}

int minCut(vector<Point> &points, Point &P){
	if (points.size() <= 3)
		return 0;
	int min_to_cut = points.size();
	for(int i = 0; i < points.size(); i++){
		Point P2 = points[i];
		if (P2.x == P.x and P2.y == P.y)
			continue;
		int curr_cut = 0;
		for(int j = 0; j < points.size(); j++){
			Point P3 = points[j];
			if (P3.x == P.x and P3.y == P.y)
				continue;
			if (j == i)
				continue;
			// do we need to cut down P3 if P1 and P are on the convex hull?
			if (ccw(P, P2, P3)){
				curr_cut++;
			}
		}
		if(curr_cut < min_to_cut)
			min_to_cut = curr_cut;
	}
	return min_to_cut;
}
int main()
{
	
	int T;
	cin >> T;
	for(int i = 1; i <= T; i++){
		int N;
		cin >> N;
		vector<Point> trees;
		for(int j = 1; j <= N; j++){
			LD x, y;
			cin >> x >> y;
			Point P;
			P.x = x;
			P.y = y;
			trees.push_back(P);
		}

		cout << "Case #" << i << ":" << endl;
		for(int i = 0; i < trees.size(); i++){
			Point P = trees[i];
			int min_cut = minCut(trees, P);
			cout << min_cut << endl;
		}
	}
	return 0;
}