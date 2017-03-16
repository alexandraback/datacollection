/*
 * codejam-Round1B-Blarge.cpp
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
int solve2(int h, int w, int n, int add){
	vector<vector<bool> > v(h,vector<bool>(w,false));
	rep(r,h){
		rep(c,w){
			v[r][c]=(r+c+add)%2;
		}
	}
	priority_queue<int> pq;
	int dr[] = {1,-1,0,0};
	int dc[] = {0,0,1,-1};
	rep(r,h){
		rep(c,w){
			if(v[r][c]) continue;
			int cnt = 0;
			rep(i,4){
				int nr = r+dr[i], nc = c+dc[i];
				if(nr >= h || nr < 0 || nc >= w || nc < 0) continue;
				cnt--;
			}
			pq.push(cnt);
		}
	}
	n -=(h*w)/2+add;
	int ret = 0;
	while(n){
		ret -= pq.top(); pq.pop();
		n--;
	}
	return ret;

}
int solve(int h, int w, int n){
	if(n <= (h*w+1)/2) return 0;
	if(h*w%2) return min(solve2(h,w,n,1),solve2(h,w,n,0));
	return solve2(h,w,n,0);
}
int main(){
	ios_base::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	int t;
	int w, h, n;
	cin >> t;
	int tst = 1;
	while(t--){
		cin >> h >> w >> n;
		cout << "Case #" << tst++ << ": " << solve(h,w,n) << endl;
	}

	return 0;
}
