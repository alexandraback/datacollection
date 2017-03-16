#include <bits/stdc++.h>
//#include "testlib.h"
using namespace std;
#define Foreach(i, c) for(__typeof((c).begin()) i = (c).begin(); i != (c).end(); ++i)
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define rof(i,a,b) for(int (i)=(a);(i) > (b); --(i))
#define rep(i, c) for(auto &(i) : (c))
#define x first
#define y second
#define pb push_back
#define PB pop_back()
#define iOS ios_base::sync_with_stdio(false)
#define sqr(a) (((a) * (a)))
#define all(a) a.begin() , a.end()
#define error(x) cerr << #x << " = " << (x) <<endl
#define Error(a,b) cerr<<"( "<<#a<<" , "<<#b<<" ) = ( "<<(a)<<" , "<<(b)<<" )\n";
#define errop(a) cerr<<#a<<" = ( "<<((a).x)<<" , "<<((a).y)<<" )\n";
#define coud(a,b) cout<<fixed << setprecision((b)) << (a)
#define L(x) ((x)<<1)
#define R(x) (((x)<<1)+1)
#define umap unordered_map
#define smax(x, y) x = max((x), (y))
#define smin(x, y) x = min((x), (y))
#define double long double
typedef long long ll;
#define int ll
typedef pair<int,int>pii;
typedef vector<int> vi;
const int maxn = 1e5 + 10;
int m[maxn], n, x;
inline bool check(int t){
	int cnt = 0;
	For(i,0,n){
		cnt += t/m[i];
		++ cnt;
	}
	return cnt < x;
}
vi v;
main(){
	iOS;
	int T;
	cin >> T;
	For(test, 1, T + 1){
		cout << "Case #" << test << ": ";
		cin >> n >> x;
		For(i,0,n)
			cin >> m[i];
		if(x <= n){
			cout << x << endl;
			continue;
		}
		int l = 0, r = 1e15;
		while(l < r){
			int mid = (l+r)/2;
			if(check(mid))
				l = mid;
			else
				r = mid - 1;
			if(l + 1 == r){
				if(check(r))
					l = r;
				else
					r = l;
			}
		}
		int t = l;
		v.clear();
		For(i,0,n){
			x -= t/m[i];
			-- x;
		}
		++ t;
		-- x;
		For(i,0,n)
			if(t % m[i] == 0)
				v.pb(i + 1);
		cout << v[x] << endl;
	}
}

