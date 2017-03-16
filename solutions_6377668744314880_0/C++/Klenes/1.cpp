#include <iostream>
#include <vector>
using namespace std;

struct Point
{
	long long int x;
	long long int y;
};
#define lli long long int
bool isOnRight(Point a, Point b, Point c){
	//if (a.x == b.x && a.x == b.y || a.x == c.x && a.x == c.y || b.x == c.x && b.x == c.y)
	//	return false;
	lli x1 = b.x - a.x;
	lli y1 = b.y - a.y;
	lli x2 = c.x - a.x;
	lli y2 = c.y - a.y;
	lli  res = x1 * y2 - x2 * y1;
	return res > 0;
}

bool isOnLeft(Point a, Point b, Point c){
	//if (a.x == b.x && a.x == b.y || a.x == c.x && a.x == c.y || b.x == c.x && b.x == c.y)
	//	return false;
	lli x1 = b.x - a.x;
	lli y1 = b.y - a.y;
	lli x2 = c.x - a.x;
	lli y2 = c.y - a.y;
	lli  res = x1 * y2 - x2 * y1;
	return res < 0;
}

// Driver program to test above functions
int main()
{
	int T;
	cin >> T;
	int n;
	for (int ti = 1; ti <= T; ti++){
		printf("Case #%d:\n", ti);
		vector<Point> points;
		cin >> n;
		int min = 50000;
		int min1, min2;
		points.resize(n);
		for (int i = 0; i < n; i++)
			cin >> points[i].x >> points[i].y;
		for (int i = 0; i < n; i++){  // 1 cislo
			min = 500000;
			for (int j = 0; j < n; j++){ // dvojica
				min1 = 0;
				min2 = 0;
				if (i != j){
					for (int f = 0; f < n; f++) // zbytok
					{
						if (f != i && f != j){
							if (isOnRight(points[i], points[j], points[f]))
								min1++;
							if (isOnLeft(points[i], points[j], points[f]))
								min2++;
						}
					}
					if (min1 < min)
						min = min1;
					if (min2 < min)
						min = min2;
				}
			}
			if (n>1)
				cout << min << endl;
			else
				cout << 0 << endl;
		}
	}
	return 0;
}