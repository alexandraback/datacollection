#include <iostream>
#include <cstdio>
#include <string>
#include <string.h>
#include <queue>
#include <math.h>
#include <cmath>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
#include <bitset>
#include <ctype.h>
#include <cassert>
#include <stack>
#include <fstream>
#include <unordered_map>
#include <ctime>
#include <functional>

using namespace std;

#define snd second
#define fst first
#define mp make_pair
#define ll long long
#define ull unsigned long long
#define ld long double
#define pb push_back
#define left _left
#define right _right

const ld pi = 3.14159265359;

template < typename T > T abs(T x)
{
    return x > 0 ? x : -x;
}

template < typename T > T sqr(T x)
{
	return x * x;
}

int a[32][32];


int main()
{
	srand(time(NULL));
	//gen();
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
	
	int t;
	cin >> t;
	//t = 1000;
	for (int tt = 1; tt <= t; tt++)
	{
		int r, c, n;
		cin >> r >> c >> n;
		//n = 9, r = 4, c = 4;
		int m = r * c;
		
		int ans = 1e9;
		const int dirs[4][2] = 
		{
			1, 0,
			0, 1,
			-1, 0,
			0, -1, 
		};
		auto valid = [&](int x, int y) { return 0 <= x && x < r && 0 <= y && y < c; };
		for (int i = 0; i < (1 << m); i++)
		{
			int cnt = 0;
			for (int j = 0; j < m; j++)
				cnt += bool(i & (1 << j));
				
			if (cnt != n)
				continue;
				
			for (int j = 0; j < m; j++)
				a[j / c][j % c] = bool(i & (1 << j));
				
			int cu = 0;
			for (int j = 0; j < r; j++)
				for (int h = 0; h < c; h++)
					for (int k = 0; k < 4; k++)
					{
						int x = j + dirs[k][0];
						int y = h + dirs[k][1];
						if (!valid(x, y))
							continue;
						cu += a[x][y] && a[j][h];
					}
					
			ans = min(ans, cu / 2);
		}
		
		
		printf("Case #%d: %d\n", tt, ans);
		cerr << tt << endl;
	}
	
	return 0;
}




































