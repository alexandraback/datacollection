/*
 * Round2B-Q1.cpp
 *
 *  Created on: May 3, 2014
 *      Author: Ghoooo
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
#define sz(v) ((ll)v.size())
#define rep(i,m) for(int i=0;i<(int)(m);++i)
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

int t, n;
string arr[110];
bool isValid(){
	string tmp[110];
	rep(i,n){
		tmp[i]="";
		tmp[i]+=arr[i][0];
		rep2(k,1,sz(arr[i])){
			if(arr[i][k] != tmp[i][sz(tmp[i])-1]){
				tmp[i]+=arr[i][k];
			}
		}
	}
	rep2(i,1,n){
		if(tmp[i]!=tmp[i-1]) return false;
	}
	return true;
}
int solve(){
	vector<int> tmp[110];
	rep(i,n){
		int cnt = 1;
		rep2(k,1,sz(arr[i])){
			if(arr[i][k] != arr[i][k-1]){
				tmp[i].pb(cnt);
				cnt = 0;
			}
			cnt++;
		}
		tmp[i].pb(cnt);
	}
	int ans = 0;
	rep(i,sz(tmp[0])){
		int mn = oo;
		rep2(k,1,110){
			int t = 0;
			rep(j,n){
				t += abs(tmp[j][i]-k);
			}
			mn = min(mn,t);
		}
		ans += mn;
	}
	return ans;

}

int main(){
	ios_base::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	cin >> t;
	rep2(casenum,1,t+1){
		cin >> n;
		rep(i,n) cin>>arr[i];
		cout << "Case #" << casenum << ": ";
		if(!isValid()){
			cout << "Fegla Won" << endl;
			continue;
		}
		cout << solve() << endl;

	}
	return 0;
}
