#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#include<set>
#include<map>
#include<cmath>
#include<cstdlib>
#include<complex>
#include<sstream>
#include<iomanip>

using namespace std;

#define rep(i,n) for(int i=0;i<n;i++)
#define For(i,a,b) for(int i=a;i<b;i++)
#define pb(x) push_back(x)
#define ll long long
#define VI vector<int>

//typedef pair<int,int> pi;

const int maxn = 30;

int p[maxn];

struct pi{
	int c;
	int ind;
	pi(int ii, int cc){
		ind = ii;
		c = cc;
	}
	inline bool operator <(const pi &x)const{
		if(c != x.c)
			return c > x.c;
		return ind < x.ind;
	}
};

void solve(){
	int n;
	cin >> n;
	set<pi> h;
	int rem = 0;
	rep(i,n){
		cin >> p[i];
		h.insert(pi(i, p[i]));
		rem += p[i];
	}
	while(h.size() > 1){
		if(rem == 3 && h.size() == 3){
			pi x = *h.begin();
			h.erase(x);
			cout << (char)('A'+x.ind) << " ";
		}
		pi x = *h.begin();
		h.erase(x);
		pi y = *h.begin();
		h.erase(y);
		cout << (char)('A'+x.ind) << (char)('A'+y.ind) << " ";
		x.c--;
		y.c--;
		rem -=2;
		if(x.c > 0)
			h.insert(x);
		if(y.c > 0)
			h.insert(y);
	}
	cout << endl;
}

int main(){
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	rep(g,t){
		cout << "Case #" << g+1 << ": ";
		solve();
	}
	return 0;
}
