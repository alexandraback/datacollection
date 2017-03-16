// /\||/\||
//
//
//////////////////////
// Program: 
// Written By Alireza Farhadi (LGM)
//////////////////////
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cctype>
#include <cassert>
#include <csignal>
#include <cmath>
#include <array>
#include <queue>
#include <stack>
#include <string>
#include <regex>
#include <set>
#include <map>
#include <tuple>
#include <list>
#include <utility>
#include <vector>
#include <bitset>
#include <deque>
#include <iomanip>
#include <complex>
#include <fstream>
#include <sstream>
#include <unordered_set>
#include <unordered_map>

using namespace std;
#ifdef _TEST
#define testdo(x) x
#else
#define testdo(x)
#endif
#define show(x) testdo(cerr<<((#x))<<" = "<<((x))<<" "<<endl)
#define bit(a,b) (((a)>>(b))&1)
#define gt(x,i) (get<((i))>(((x))))
#define ALL(x) ((x)).begin(),((x)).end()
#define Mt make_tuple
#define endl '\n'
#define bcnt(x) ((__builtin_popcount(x)))
#define bcntll(x) ((__builtin_popcountll(x)))
#define sqr(x) ((((x))*((x))))
#define fx(x) fixed<<setprecision(x)
#define list _list

template<class T> inline void smn(T &a,const T &b){if(b<a) a=b;}
template<class T> inline void smx(T &a,const T &b){if(b>a) a=b;}
template<class T> inline T gcd(T x,T y) { return y?gcd(y,x%y):x;}
namespace std{ template<class T,class U> struct hash<pair<T,U>> {
	inline size_t operator() (const pair<T,U> & p) const { return hash<T>()(p.first)*701+hash<U>()(p.second);}
};}

typedef long long ll;
typedef pair<int,int> pie;
typedef tuple<int,int,int> trip;
typedef complex<double> point;

const double eps=1e-8;

int t,tc,r,c,n;
int solve(int r,int c,int n)
{
	int rs=r;
	if (r>c) return solve(c,r,n);
	if (n<=(r*c+1)/2) return 0;
	int uh=(r*c+1)/2;
	if ((r*c)%2==0)
	{
		if (r==1)
		{
			int r=n-uh;
			return 1+(r-1)*2;
		}
		int r=n-uh;
		if (r<=2)
			return 2*r;
		int s=2*(rs+c)-4;
		s/=2; s-=2;
		if (r<=s+2)
			return 4+3*(r-2);
		return 4+s*3+(r-s-2)*4;
	}
	else
	{
		if (r==1)
		{
			int r=n-uh;
			return min(r*2,2+(r-1)*2);
		}
		int r=n-uh;
	//	show(r);
		int temp=2*(rs+c)-4;
		temp/=2;
	//	show(temp);
		int res=(r<=temp?r*3:temp*3+(r-temp)*4);
	//	show(res);
		r++;
	//	show((r<=4?2*r:(r<=temp?8+(r-4)*3:8+(temp-4)*3+(r-temp)*4)));
		smn(res,(r<=4?2*r:(r<=temp?8+(r-4)*3:8+(temp-4)*3+(r-temp)*4)));
		return res;
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin>>t;
	while (t-->0)
	{
		cin>>r>>c>>n;
		cout<<"Case #"<<++tc<<": "<<solve(r,c,n)<<endl;
	}
	return 0;
}
