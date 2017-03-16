#include <bitset>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <math.h>
#include <algorithm>
#include <time.h>
#include <map>
#include <set>
#include <iostream>
#include <assert.h>
#include <string>

using namespace std;

#define forn(i,n) for(int i=0;i<(int)n;i++)
#define forab(i,a,b) for(int i=(int)a;i<(int)b;i++) //WARNING!! long long
#define mp make_pair
#define pb push_back
#define all(a,n) a,a+n
#define dprintf if(DEBUG)printf
#define dputs if(DEBUG)puts
#define dassert if(DEBUG)assert
#define fi first
#define se second
#define j0 jqwerty
#define j1 jasdf
#define i0 iqwerty
#define i1 iasdf
#define sq(x) (x)*(x)

typedef long long ll;
typedef double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

int DEBUG=1;

void solve(){
	int n;
	cin >> n;
	vector<pii> p(n);
	int S = 0;
	forn(i, n){
		p[i].se = i;
		cin >> p[i].fi;
		S += p[i].fi;
	}
	set<pair<int, int>, greater<pii> > s;
	forn(i, n)
		s.insert(p[i]);
	while(S > 0){
		pii v = *s.begin();
		s.erase(s.begin());
		
		if(2*s.begin()->first > S  - 1){
			pii u = *s.begin();
			s.erase(u);
			cout << (char)(v.second + 'A') << (char)(u.second + 'A') << " ";
			v.fi--;
			u.fi--;
			S -= 2;
			s.insert(v);
			s.insert(u);
		}
		else{ 
			cout << (char)(v.second + 'A') << " ";
			v.fi--;
			S -= 1;
			s.insert(v);
		}
	}
}
int main()
{
	int t;
	cin >> t;
	forn(i, t){
		printf("Case #%d: ", i + 1);
		solve();
		puts("");
	}
	return 0;
}
