#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <utility>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <math.h>
#include <string>
#include <string.h>
#include <vector>
#include <set>
#include <list>
#include <sstream>
#include <time.h>
#include <stdlib.h>
#include <ctype.h>

#define print(Z,a,b) for (int __z = a; __z < b; __z ++) cout << Z[__z] << " ";
#define scan(Z,a,b) for (int __z = a; __z < b; __z ++) cin >> Z[__z];
#define bit(_z) (1ll << (_z))
#define rep(__z,__Z) for(int __z = 0; __z < __Z ; __z++ )
#define all(__z) __z.begin(),__z.end()

#define par pair<int, int>
#define p1 first
#define p2 second

#define eps = 1e-6

using namespace std;

int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};

int t;
int n, M[20100];

int main()
{
	cin >> t;
	int caze = 0;
	while (t --)
	{
		caze ++;
		
		cin >> n;
		scan(M, 0, n);
		
		int ansa = 0, ansb = 0;
		int maxdif = 0;
		
		for (int i = 1; i < n; i ++)
		{
			if (M[i] < M[i-1])
				ansa += M[i-1] - M[i];
			maxdif = max(maxdif, M[i-1] - M[i]);
		}
		
		
		for (int i = 0; i < n-1; i ++)
		{
			ansb += min(maxdif, M[i]);
		}
		
		
		cout << "Case #" << caze << ": " << ansa << " " << ansb << endl;
	}
		
	return 0;
}


