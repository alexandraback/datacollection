#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>

using namespace std;

struct Point
{
     int x;
     int y;
};

Point p;

long long ccw(Point p1, Point p2, Point p3) {
    return (p2.x - p1.x) * (p3.y - p1.y) - (p2.y - p1.y) * (p3.x - p1.x);
}

long long dist(Point p1, Point p2)
{
    return (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y);
}

bool compare(Point p1, Point p2) {
	long long x = ccw(p, p1, p2);
	if (x == 0) {
		return (dist(p, p1) <= dist(p, p2));
	}
	if (x > 0) //counterclockwise
		return true;
    else  //clockwise
    	return false;
}

int main() {
	int tests;
	int n;
	int top;
	Point a[3000];
	Point b[3000];
	Point s[3000];
	cin >> tests;
	for (int t = 1; t <= tests; ++t) {
		cin >> n;
		for (int i = 0; i < n; ++i) {
			cin >> a[i].x >> a[i].y;
		}
		cout << "Case #" << t << ":" << endl;
		if (n <= 3) {
			for (int i = 0; i < n; ++i)
				cout << 0 << endl;
			continue;
		}

		for (int i = 0; i < n; ++i) { // every squirrel

			swap(a[0].x, a[i].x);
			swap(a[0].y, a[i].y);
			for (int j = 0; j < n; ++j) {
				b[j].x = a[j].x;
				b[j].y = a[j].y;
			}
			int ans = 10000000;

			for (int j = 1; j < n; ++j) {
				//if (j != i) {
					int count = 0;
					swap(b[1].x, b[j].x);
					swap(b[1].y, b[j].y);
					p.x = b[1].x; p.y = b[1].y;
					sort(b + 2, b + n, compare);
					top = 1;
					s[0] = b[0];
					s[1] = b[1];
					for (int k = 2; k < n; ++k) {
						if (ccw(b[0], b[1], b[k]) < 0) {
							//while (ccw(s[top - 1], s[top], b[k]) < 0) {
							//	--top;
								//++count;
							//}
							//++top;
							//s[top] = b[k];
						//} else {
							++count;
						}
					}
					if (count < ans) ans = count;
					count = 0;
					for (int k = 2; k < n; ++k) {
						if (ccw(b[0], b[1], b[k]) > 0)
							++count;
					}
					if (count < ans) ans = count;	

					//swap(b[1].x, b[j].x);
					//swap(b[1].y, b[j].y);
					for (int k = 1; k < n; ++k) {
						b[k].x = a[k].x;
						b[k].y = a[k].y;
					}

			}
			cout << ans << endl;
			swap(a[0].x, a[i].x);
			swap(a[0].y, a[i].y);
			//for (int j = 0; j <= top; ++j) {
			//	cout << s[j].x << " " << s[j].y << endl;
			//}
		}
	}
	return 0;
}