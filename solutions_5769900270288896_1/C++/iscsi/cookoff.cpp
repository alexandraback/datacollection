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

int calcedge(int R, int C,const vector<vector<bool> >& w)
{
	int res = 0;
	REP(i,R) REP(j,C) if(w[i][j])
	{
		if(i)
		{
			res +=w[i-1][j];
		}
		if(j)
			res +=w[i][j-1];
	}
	return res;
}


int calc(int R, int C, int N, int version)
{
	vector<vector<bool> > w(R,vector<bool> (C));
	int res = 0;
	int ctr=N;
	REP(i,R)
	{
		REP(j,C)
		{
			if(((i+j)&1)==version)
			{
				w[i][j]=1;
				--ctr;
				if(ctr==0)
					break;
			}
		}
		if(ctr==0) break;
	}
	if(ctr)
	{
		if(!w[0][0])
		{
			w[0][0]=1;
			--ctr;
		}
		if(ctr && !w[0][C-1])
		{
			w[0][C-1]=1;
			--ctr;
		}
		if(ctr && !w[R-1][C-1])
		{
			w[R-1][C-1]=1;
			--ctr;
		}
		if(ctr && !w[R-1][0])
		{
			w[R-1][0]=1;
			--ctr;
		}
		REP(j,C) 
		{
			if(ctr && !w[0][j])
			{
				w[0][j]=1;
				--ctr;
			}
			if(ctr && !w[R-1][j])
			{
				w[R-1][j]=1;
				--ctr;
			}
			if(ctr == 0)
				break;
		}
		REP(i,R) 
		{
			if(ctr && !w[i][0])
			{
				w[i][0]=1;
				--ctr;
			}
			if(ctr && !w[i][C-1])
			{
				w[i][C-1]=1;
				--ctr;
			}
			if(ctr == 0)
				break;
		}
		REP(i,R)
		{
			REP(j,C)
			{

				if(ctr && !w[i][j])
				{
					w[i][j]=1;
					--ctr;
				}
				if(ctr==0)
					break;
			}
			if(ctr==0)
				break;
		}
	}
	return calcedge(R,C,w);
}

int main( int argc, char* argv[] ) {
#ifdef HOME
	freopen("in.txt","r",stdin);
	freopen("out.txt", "wb", stdout);
	freopen("B-large.in","r",stdin);
	freopen("B-large.out", "wb", stdout);
#endif

	int T,R,C,N;
	cin>>T;
	FOR(tc,1,T+1)
	{
		cin>>R>>C>>N;
		if(N==0)
		{
			cout << "Case #" << tc << ": "  << 0<< endl;
			continue;
		}
		int res = calc(R,C,N,0);
		int res2 = calc(R,C,N,1);
		
		cout << "Case #" << tc << ": "  << min(res,res2) << endl;
	}
	return 0;
}

