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

int t,r,c,n,tc;
bool mp[100][100];
int solve(int r,int c,int n)
{
	int res=1<<30;
	for (int i=0;i<(1<<(r*c));i++) if (bcnt(i)==n)
	{
		int cnt=0;
		for (int j=0;j<r;j++)
			for (int k=0;k<c;k++)
				mp[j][k]=bit(i,cnt),cnt++;
		int now=0;
		for (int j=0;j<r;j++)
			for (int k=0;k+1<c;k++)
				now+=(mp[j][k] && mp[j][k+1]);
		for (int j=0;j+1<r;j++)
			for (int k=0;k<c;k++)
				now+=(mp[j][k] && mp[j+1][k]);
		smn(res,now);
	}
	return res;
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
