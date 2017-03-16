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
const int maxn = 1e3 + 10;
int d[maxn];
main(){
	iOS;
	int T;
	cin >> T;

	For(test, 1, T + 1){
		cout << "Case #" << test << ": ";
		int n;
		cin >> n;
		For(i,0,n)
			cin >> d[i];
		int ans = 0;
		For(i,1,n)
			if(d[i] < d[i-1])
				ans += d[i-1] - d[i];
		cout << ans << ' ';
		if(ans == 0){
			cout << ans << endl;
			continue;
		}
		ans = 0;
		bool ok = 1;
		int r = 0;
		For(i,1,n)
			smax(r, d[i-1] - d[i]);
		For(i,1,n)
			ans += min(r, d[i-1]);

		cout << ans << endl;
	}
}

