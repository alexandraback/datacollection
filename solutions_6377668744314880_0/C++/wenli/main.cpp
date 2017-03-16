#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;

struct Point
{
	long long int x, y;
};

int main()
{
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
    	int N;
    	cin >> N;
    	Point *points = new Point[N];
    	for (int n = 0; n < N; n++) {
    		cin >> points[n].x >> points[n].y;
    		// if (t == 25)
    		// 	cout << points[n].x << ' ' << points[n].y << endl;
    	}
    	cout << "Case #" << t+1 << ":\n";
    	if (N == 1) {
    		cout << "0\n";
    		continue;
    	}
    	for (int i = 0; i < N; i++) { // every point
    		int mleft = 10000;
    		int mright = 10000;
    		for (int j = 0; j < N; j++) { // every other point
    			if (j == i) continue;
    			int nleft = 0;
    			int nright = 0;
    			for (int k = 0; k < N; k++) {
    				if (k == i || k == j) continue;
					long long int turn = (points[j].y - points[i].y) * (points[k].x - points[j].x) - (points[j].x - points[i].x) * (points[k].y - points[j].y);
					if (turn < 0)
						nright++;
					else if (turn > 0)
						nleft++;
    			}
    			mleft = min(mleft, nleft);
    			mright = min(mright, nright);
    		}
    		cout << min(mleft, mright) << endl;
    	}
    	delete[] points;
    }
    
    return 0;
}
