#include <omp.h>
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
    	int *mleft = new int[N];
    	int *mright = new int[N];
    	for (int i = 0; i < N; i++)
    		mleft[i] = mright[i] = 10000;
    	#pragma omp parallel for
    	for (int i = 0; i < N-1; i++) { // every point
    		for (int j = i+1; j < N; j++) { // every other point
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
    			#pragma omp critical
    			{
					mleft[i] = min(mleft[i], nleft);
					mright[i] = min(mright[i], nright);
					mleft[j] = min(mleft[j], nright);
					mright[j] = min(mright[j], nleft);
    			}
    		}
    	}
    	for (int i = 0; i < N; i++)
    		cout << min(mleft[i], mright[i]) << endl;
    	delete[] mleft;
    	delete[] mright;
    	delete[] points;
    }
    
    return 0;
}
