
#include <iostream>
#include <istream>
#include <stdio.h>
#include <string>
#include <vector> 
#include <fstream>
#include <queue>
#include <algorithm>
#define INF 2147483647
#define BIG 1000000007
#define PI 3.14159265358979323846
#define ERROR 0.00000001
using namespace std; 

int main ()
{
    freopen ("C-small-attempt1.in", "r", stdin);
	freopen ("C.out", "w", stdout); 
 	int tt; 
 	cin >> tt; 
 	for (int cases = 1; cases <= tt; cases++)
 	{
 		cout << "Case #" << cases << ":\n";
 		int n;
 		cin >> n; 
 		int px[n], py[n]; 
 		for (int x = 0; x < n; x++)
 			cin >> px[x] >> py[x];
 		int perimeter [n], it = 0;
 		int start, dir;
 		for (start = 0; start < n; start++)
 		{
 			int best = 9999;
 			SEARCH:
 			for (dir = 0; dir < n; dir++)
			{
				if (start == dir)
					continue;
				if (px[start] == px[dir])
				{
					int less = 0, more = 0;
					for (int z = 0; z < n; z++)
					{
						if (px[z] < px[start])
							less++;
						else if (px[z] > px[start])
							more++;
					}
					best = min (less, best); 
					best = min (more, best);
				}
				else
				{
					double m = (py[dir]-py[start])/(double)(px[dir]-px[start]);
					double b = py[dir] - px[dir]*m;
					int less = 0, more = 0;
					for (int z = 0; z < n; z++)
					{
						if (abs(px[z]*m + b - py[z]) < ERROR)
							continue;
						if (px[z]*m + b < py[z])
						{
							//cout << "Less: " << start << " " << dir << " " << z << "\n";
							less++;
						}
						else if (px[z]*m + b > py[z])
						{
							//cout << "More: " << start << " " << dir << " " << z << "\n";
							more++;
						}
					}
					best = min (less, best); 
					best = min (more, best);
				}
			}
			if (n <= 3)
				cout << "0\n";
			else
			cout << best << "\n";	
		}
	}
}
