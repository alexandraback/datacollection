#include <iostream>
#include <fstream>
#include <stdio.h>
#include <utility>
#include <algorithm>
#include <cstring>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <math.h>
#include <cstdio>
#include <assert.h>

#define mset(x,y) memset(x,y,sizeof(x))
#define INF 1000000000
#define MOD 1000000007
#define pb(X) push_back(X) 
#define ff first
#define ss second
#define all(c) c.begin(), c.end()
#define FOR(i,n) for (int i=0; i<(n); i++)
#define foreach(it, c) for(__typeof(c.begin()) it = c.begin(); it != c.end(); ++it)
#define sz(v) ((int) v.size())
#define mp(a, b) make_pair(a, b)
 
using namespace std;
 
typedef long long int lli;
typedef pair<int,int> pii;

int main()
{
	int t;
	scanf("%d", &t);

	for(int tt=1; tt<=t; tt++)
	{
		int r, c, n;
		scanf("%d%d%d",&r,&c,&n);

		int lim = 1<<(r*c);
		int mi = INF;
		for(int m=0; m<lim; m++) if(__builtin_popcount(m) == n)
		{
			int cnt = 0;
			for(int i=0; i<r; i++)
				for(int j=0; j<c-1; j++)
				{
					int a = i*c+j;
					int b = a+1;

					if((m & (1<<a)) and (m & (1<<b))) cnt++;
				}

			for(int i=0; i<r-1; i++)
				for(int j=0; j<c; j++)
				{
					int a = i*c+j;
					int b = a+c;

					if((m & (1<<a)) and (m & (1<<b))) cnt++;
				}

			mi = min(mi, cnt);
		}

		printf("Case #%d: %d\n", tt, mi);
	}
    return 0;
}