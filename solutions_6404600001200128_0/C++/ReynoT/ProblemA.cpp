
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
    freopen ("A-small-attempt1.in", "r", stdin);
	freopen ("A.out", "w", stdout); 
 	int tt; 
 	cin >> tt; 
 	for (int cases = 1; cases <= tt; cases++)
 	{
 		cout << "Case #" << cases << ": ";
 		int n; 
 		cin >> n; 
 		int plate [n];
 		for (int x = 0; x < n; x++)
 			cin >> plate[x];
 		int m1 = 0;
 		int diff = 0;
		for (int x = 1; x < n; x++)
		{
			if (plate[x-1]-plate[x] > 0)
				m1 += plate[x-1]-plate[x];
			if (plate[x-1]-plate[x] > diff)
				diff = plate[x-1]-plate[x];
		}
		cout << m1 << " ";
		m1 = 0;
		for (int x = 0; x < n - 1; x++)
			m1 += min (plate[x],diff);
		cout << m1 << "\n";
	}
}
