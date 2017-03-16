#include <cstdio>
#include <iostream>
#include <cassert>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <set>
#include <map>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
#include <bitset>
#include <functional>
#define MAX(a,b) (((a)>(b))?(a):(b))
#define MIN(a,b) (((a)<(b))?(a):(b))
#define REPE(i,x,y) for (int i=(x);i<(y);i++)
#define REP(i,x,y) for (int i=(x);i<=(y);i++)
#define DREP(i,x,y) for (int i=(x);i>=(y);i--)
#define mp make_pair
#define pb push_back
#define MAXN 100100

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

ll B[MAXN];

void solve(int tc) {
	int b; cin>>b;
	ll n; cin>>n;
	REP(i,1,b) {
		cin>>B[i];
	}
	ll l=0,r=1e16;
	while (l<r) {
		ll mid=(l+r-1)/2;
		ll v = 0;
		REP(i,1,b) {
			v += (mid/B[i])+1;
		}
		if (v >= n) {
			r=mid;
		} else {
			l = mid + 1;
		}
	}
	ll prev = 0; 
	REP(i,1,b) {
		prev += ((l-1)/B[i])+1;
	}
	n -= prev; int cp = 0;
	REP(i,1,b) {
		if (l%B[i] == 0) {
			cp++;
			if (cp==n) {
				cout<<"Case #"<<tc<<": "<<i<<endl;
				return;	
			}
		}
	}

	
}

	

int main() {
	ios::sync_with_stdio(false);
	int t; cin>>t; REP(i,1,t) solve(i);
}
