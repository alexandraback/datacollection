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
		
		auto valid = [&](int x, int y) { return 0 <= x && x < r && 0 <= y && y < c; };
		
		ll ans = 1e18;
		
		for (int it = 0; it < 2; it++)
		{
			ll m = n;
			for (int i = 0; i < r; i++)
				for (int j = 0; j < c; j++)
					if (bool((i + j) & 1) == it)
						m--;
			m = max(m, 0LL);
			
			vector < int > f;
			const int dirs[4][2] = 
			{
				1, 0,
				0, 1,
				-1, 0,
				0, -1, 
			};
			for (int i = 0; i < r; i++)
				for (int j = 0; j < c; j++)
					if (bool((i + j) & 1) != it)
					{
						int p = 0;
						for (int h = 0; h < 4; h++)
						{
							int x = i + dirs[h][0];
							int y = j + dirs[h][1];
							if (valid(x, y))
								p++;
						}
						f.pb(p);
					}
			sort(f.begin(), f.end());
			ll c = 0;
			for (int i = 0; i < m; i++)
				c += f[i];
			ans = min(c, ans);
		}
		
		printf("Case #%d: %lld\n", tt, ans);
		cerr << tt << endl;
	}
	
	return 0;
}





































