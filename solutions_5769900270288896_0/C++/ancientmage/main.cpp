#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <memory.h>
#include <fstream>
#include <map>
#include <sstream>
#include <stack>
#include <queue>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <ctime>

using namespace std;
#define ll long long
#define MOD 1000000007
#define mp(a, b) make_pair(a, b)
#define PI 3.1415926535
#define EPS 0.00000001
#define pii pair<int, int>
#define INF 2000000000

//#define DEBUG 41

#ifndef DEBUG

ifstream in("in.txt");
ofstream out("out.txt");

#define cin in
#define cout out

#endif
template<typename T>
void print(int i, T a)
{
	cout << "Case #" << i << ": " << a << "\n";
}


ll a[1234567];

int bitcount(int a)
{
	int ans = 0;
	while(a)
	{
		ans += (a & 1);
		a >>= 1;
	}
	return ans;
}


int main()
{
	int n;
	cin >> n;



	for(int ii = 1; ii <= n; ++ii)
	{
		int r, c, t;
		cin >> r >> c >> t;
		int ans = 10000;

		for(int iii = 0; iii < (1 << r*c); ++iii)
		{
			if(bitcount(iii) != t)
				continue;
			vector<vector<int> > v;
			v.resize(r);
			for(int i = 0; i < r; ++i)
				v[i].assign(c, 0);
			for(int rr = 0; rr < r; ++rr)
			{
				for(int cc = 0; cc < c; ++cc)
				{
					if(iii & (1<<(rr*c + cc)))
					{
						v[rr][cc] = 1;
					}
				}
			}
			int curans = 0;
			for(int i = 0; i < r-1; ++i)
			{
				for(int j = 0; j < c; ++j)
				{
					if(v[i][j] == v[i+1][j] && v[i][j] == 1)
						++curans;
				}
			}
			for(int i = 0; i < r; ++i)
			{
				for(int j = 0; j < c-1; ++j)
				{
					if(v[i][j] == v[i][j+1] && v[i][j] == 1)
						++curans;
				}
			}
			ans = min(ans, curans);
		}

		print(ii, ans);

	}


}