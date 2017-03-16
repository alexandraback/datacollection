#pragma comment(linker,"/STACK:64000000")
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <cmath>
#include <map>
#include <set>
#include <ctime>
#include <algorithm>
#include <memory.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

#define WR printf
#define RE scanf
#define PB push_back
#define SE second
#define FI first
#define MP make_pair

#define FOR(i,k,n) for(int i=(k); i<=(n); i++)
#define DFOR(i,k,n) for(int i=(k); i>=(n); i--)
#define SZ(a) (int)((a).size())
#define FA(i,v) FOR(i,0,SZ(v)-1)
#define RFA(i,v) DFOR(i,SZ(v)-1,0)
#define CLR(a) memset(a, 0, sizeof(a))

#define LL long long
#define VI  vector<int>
#define PAR pair<int ,int>
#define o_O 1000000000

void __never(int a){printf("\nOPS %d", a);}
#define ass(s) {if (!(s)) {__never(__LINE__);cout.flush();cerr.flush();abort();}}

int R, C, K;

int sol()
{
	int ans = 100500;
	int n = R*C;
	FOR(a,0,(1<<n)-1)
	{
		int ones = 0;
		FOR(b,0,n-1) if ((a>>b)&1) ones++;
		if (K == ones)
		{
			int tmp = 0;
			FOR(b,0,R-2) FOR(c,0,C-1)
				if ( ((a>>(b*C+c))&1) && ((a>>((b+1)*C+c))&1) )
					tmp++;
			FOR(b,0,R-1) FOR(c,0,C-2)
				if ( ((a>>(b*C+c))&1) && ((a>>(b*C+c+1))&1) )
					tmp++;
			ans = min( ans, tmp );
		}
	}

	return ans;
}

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);

	int t=0;
	cin >> t;
	FOR(a,1,t)
	{
		cerr << a << "\n";
		cin >> R >> C >> K;
		cout << "Case #" << a << ": ";
		cout << sol();
		cout << "\n";
	}
	return 0;
}
