/*
 * codejam-Round1B-b.cpp
 *
 *  Created on: May 2, 2015
 *      Author: ghooo
 */

#include <cstring>
#include <map>
#include <deque>
#include <queue>
#include <stack>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <vector>
#include <set>
#include <complex>
#include <list>
#include <climits>
#include <cctype>
#include <bitset>
//#include <windows.h>

using namespace std;

#define pb push_back
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define sz(v) ((int)v.size())
#define rep(i,m) for(int i=0;i<(int)(m);++i)
#define repe(i,n,m) for(int i=n;i<=(int)(m);++i)
#define rep2(i,n,m) for(int i=n;i<(int)(m);i++)
#define For(it,c) for(__typeof(c.begin()) it=c.begin();it!=c.end();++it)
#define reset(a,b) memset(a,b,sizeof(a))
#define mp make_pair
#define dot(a,b) ((conj(a)*(b)).X)
#define X real()
#define Y imag()
#define length(V) (hypot((V).X,(V).Y))
#define vect(a,b) ((b)-(a))
#define cross(a,b) ((conj(a)*(b)).imag())
#define normalize(v) ((v)/length(v))
#define rotate(p,about,theta) ((p-about)*exp(point(0,theta))+about)
#define pointEqu(a,b) (comp(a.X,b.X)==0 && comp(a.Y,b.Y)==0)
#define clrq(x) while(!x.empty()) x.pop();
#define clrvv(v) rep(i,sz(v))v[i].clear();
#define debug(x) cerr << #x << ": " << x << endl;
#define debugv(v) cerr << #v << ": ";For(it,v)cerr <<(*it)<<", "; cerr<<endl;

typedef stringstream ss;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<pii> vpii;
typedef vector<string> vs;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<vector<int> > vii;
typedef long double ld;
typedef complex<double> point;
typedef pair<point, point> segment;
typedef pair<double, point> circle;
typedef vector<point> polygon;
typedef unsigned long long ull;
typedef long long ll;

//==============================================================
// handling triples
typedef pair<ll,pair<ll,ll> > triple;
#define tfirst first
#define tsecond second.first
#define tthird second.second
#define mt(x,y,z) mp(x,mp(y,z))
//---------------------------------------------------------------

const int oo = (int) 1e9;
const double PI = 2 * acos(0.0);
const double eps = 1e-9;
map<pair<int,pair<int,pair<int,int> > >, int> mem;
int h, w, n;
int rec(int rem, int r, int c, int msk){
	if(r == h) {
		if(rem == 0) return 0;
		return oo;
	}
	if(mem.count(mp(rem,mp(r,mp(c,msk)))))
		return mem[mp(rem,mp(r,mp(c,msk)))];

	int &ret = mem[mp(rem,mp(r,mp(c,msk)))];

	if(c == w-1) ret = rec(rem,r+1,0,msk&(~(1<<c)));
	else ret = rec(rem,r,c+1,msk&(~(1<<c)));

	// take
	int cost = 0;
	if((msk>>c)&1) cost++;
	if(c-1>=0&&((msk>>(c-1))&1)) cost++;

	if(c==w-1)
		ret = min(ret,cost+rec(rem-1,r+1,0,msk|(1<<c)));
	else
		ret = min(ret,cost+rec(rem-1,r,c+1,msk|(1<<c)));
	return ret;
}
int main(){
	ios_base::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	int t;
	int tst = 1;
	cin >> t;
	while(t--){
		mem.clear();
		cin >> h >> w >> n;
		cout << "Case #" << tst++ << ": " << rec(n,0,0,0) << endl;
	}

	return 0;
}
