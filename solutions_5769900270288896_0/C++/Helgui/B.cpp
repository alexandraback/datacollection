#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <cstdlib>
#include <iomanip>
#include <ctime>
#include <utility>

#define x first
#define y second
#define mp make_pair
#define pb push_back
#define sqr(x) (x)*(x)
#define _with_file
#define TASK ""
#define forn(i, n) for(int i = 0; i < (int)n; ++i)

void quit(); 

using namespace std;

typedef long long i64;
typedef unsigned long long u64;
#ifdef local
typedef double ld;
#else
typedef long double ld;
#endif
typedef pair <int, int> PII;
typedef pair <i64, i64> PII64;
typedef pair <ld, ld> PLL;

const ld PI = acos(-1);
const ld EPS = 1e-10;
double __t;

inline int cnt(int x)
{
	int res = 0;
	while(x)
	{
		if (x & 1)
			++res;
		x >>= 1;
	}
	return res;
}

int r, c, n;
int s;

bool f[32][32];

inline int calc(int mask)
{
	memset(f, 0, sizeof(f));
	int res = 0;
	for(int i = 0; i < s; ++i)
	{
		if (mask & (1 << i))
			f[i/c][i%c] = 1;
	}
	for(int i = 0; i < 30; ++i)
		for(int j = 0; j < 30; ++j)
			if (f[i][j])
			{
				if (f[i+1][j])
					++res;
				if (f[i][j + 1])
					++res;
			}
	 return res;
}


int main()
{
	#ifdef local
		__t = clock();
		#ifndef _with_files
			freopen("z.in", "rt", stdin);
			freopen("z.out", "wt", stdout);
		#endif
	#endif
	#ifdef _with_files
		freopen(TASK".in", "rt", stdin);
		freopen(TASK".out", "wt", stdout);
	#endif
	int T;
	cin >> T;
	for(int test = 1; test <= T; ++test)
	{
		cin >> r >> c >> n;
		s = r*c;
		int ans = 1000000000;	
		for(int i = 0; i < (1 << s); ++i)
		{
			if (cnt(i) == n)
				ans = min(ans, calc(i));	
		}	
		cout << "Case #" << test << ": " << ans << endl;
	} 
	quit();
}

void quit()
{
	#ifdef local
		cerr << "\nTOTAL TIME: "<< (clock() - __t)/1000.0 << " s\n";
	#endif
	exit(0);		
}