#define _CRT_SECURE_NO_WARNINGS

#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <queue>
#include <cstring>
#include <string>
#include <complex>

#define vi vector<int>
#define vpii vector< pair<int,int> >
#define pii pair<int,int>
#define mp(x,y) make_pair(x,y)
#define all(x) (x).begin(),(x).end()
#define FOREACH(it,x) for (auto it = (x).begin(); it!=(x).end(); ++it) 
#define sz(x) (int)(x).size()
#define FOR(i,n) for (ll i = 0; i < ll(n); i++)
#define REP(i,a,b) for (ll i = a; i < ll(b); i++)
#define READ(a) int a; scanf("%d", &a);
#define READV(v,n) vi v(n);FOR(i,n){scanf("%d", &v[i]);}
#define WRITE(v) "";FOR(i,sz(v))cout<<v[i]<<" ";cout
#define gmin(a,b) { if (b < a) a = b; }
#define gmax(a,b) { if (b > a) a = b; }
#define pb push_back
#define ff first
#define ss second
#define X first
#define Y second
#define oo 2140000000ll

typedef long long ll;
typedef unsigned long long ull;
using namespace std;

vector<ll> m; 
ll n;
ll B;

ll taken(ll tick){
	ll sum = 0;
	FOR(i,B){
		sum+=(tick+m[i]-1)/m[i];
	}
	return sum;
}

ll bin(ll a, ll b){
	if(a + 1 >= b ) return a;
	ll c = (a+b)/2;
	ll x = taken(c);
	if(x >= n){return bin(a, c); }
	if(x < n){return bin(c, b); }
}

int main(){
	READ(T);
	FOR(t,T){
		cin>>B;
		cin>>n;
		m.clear();
		FOR(i,B){
			ll x;
			cin>>x;
			m.pb(x);
		}
		ll s = bin(0,110000000000000ll);
		ll rem = n - taken(s);
		FOR(i,B){
			if( s%m[i]==0 ){
				rem--;
				if(rem==0){
					cout<<"Case #"<<(t+1)<<": "<< i+1 <<endl;
					rem = 0;
					break;
				}
			}
		}
		


//		cout<<"Case #"<<(t+1)<<": "<< sum<<" "<<sum2 <<endl;
	}

	return 0;
}