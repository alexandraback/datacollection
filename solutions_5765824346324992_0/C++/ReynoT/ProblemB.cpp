
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

using namespace std; 


int main ()
{
    freopen ("B-small-attempt2.in", "r", stdin);
	freopen ("B.out", "w", stdout); 
 	int tt; 
 	cin >> tt; 
 	for (int cases = 1; cases <= tt; cases++)
 	{
 		cout << "Case #" << cases << ": ";
 		int b, n;
 		cin >> b >> n;
 		int barb [b];
 		for (int x = 0; x < b; x++)
 			cin >> barb [x];
 		long long top = pow (2, 55), bot = 0, mid = top/2;
 		for (int z = 0; z < 65; z++)
 		{
 			mid = (bot + top)/2;
 			//cout << z << " " << bot << " " << mid << " " << top << " ";
 			long long sum = 0; 
			int next [b];
			for (int x = 0; x < b; x++)
				next[x] = -1;
			int it = 0;
			for (int x = 0; x < b; x++)
			{
				sum += mid/barb[x];
				if (mid % barb[x] != 0)
					sum++;
				else
				{
					next[it] = x+1;
					it++;
				}
			}
			//cout << sum << " " << it << " " << (n-1)-sum << "\n";
			if (sum <= n-1 && sum+it >= n && next[(n-1)-sum] != -1)
			{
				cout << next[(n-1)-sum] << "\n"; 
				break;	
			}
			else if (sum > n-1)
				top = mid;
			else
				bot = mid;
		}
	}
}
