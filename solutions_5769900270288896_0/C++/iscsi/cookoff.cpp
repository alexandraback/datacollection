#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <cstring>
#include <ctime>
#include <cassert>
#include <list>
using namespace std;
typedef long long LL;
#define FOR(k,a,b) for(int k(a); k < (b); ++k)
#define FORD(k,a,b) for(int k(b-1); k >= (a); --k)
#define REP(k,a) for(int k=0; k < (a); ++k)
#define ABS(a) ((a)>0?(a):-(a))
#define EPS 1e-9

template <typename T> int sgn(T val) {
	return (T(0) < val) - (val < T(0));
}

int popcount(int a)
{
	int res = 0;
	while(a)
	{
		++res;
		a&=a-1;
	}
	return res;
}

int main( int argc, char* argv[] ) {
#ifdef HOME
	freopen("B-small-attempt0.in","r",stdin);
	freopen("B-small-attempt0.out", "wb", stdout);
#endif

	int T,R,C,N;
	cin>>T;
	FOR(tc,1,T+1)
	{
		cin>>R>>C>>N;
		int Z = R*C;
		int res = 1000;
		REP(i,1<<Z) if(popcount(i)==N)
		{
			int act = 0;
			REP(j,Z) if((1<<j)&i)
			{
				if(j%R)
				{
					if((1<<j-1)&i)
						++act;
				}
				if(j>=R)
				{
					if((1<<j-R)&i)
						++act;
				}
			}
			res = min(act,res);
		}
		cout << "Case #" << tc << ": "  << res << endl;
	}
	return 0;
}

