/*******************
    D Rupinder
***********************/


#include<bits/stdc++.h>

#define lld long long int
#define FOR(i,a,b) for(i= a ; i < b ; ++i)
#define rep(i,n) FOR(i,0,n)
#define all(x) x.begin(),x.end()
#define LET(x,a) __typeof(a) x(a)
#define IFOR(i,a,b) for(LET(i,a);i!=(b);++i)
#define EACH(it,v) IFOR(it,v.begin(),v.end())
#define pb push_back
#define sz size()
#define pii pair<int, int>
#define pll pair <lld ,lld>
#define mp make_pair
#define fill(x,v) memset(x,v,sizeof(x))
#define scan(v,n) vector<int> v(n);rep(i,n)cin>>v[i];
#define vi vector<int>
#define MOD 1e9 + 7

using namespace std;

int main()
{
	int t;
	cin>>t;
	int T = t;
	while (t--) {
		int n, i;
		cin>>n;
		scan(a, n);
		lld res1 = 0;
		for (int i = 0; i <n-1; i++)
			if (a[i] - a[i + 1] > 0) res1 = res1 + a[i] - a[i + 1];
		lld maxdiff = 0;
		for (int i = 0; i < n-1; i++) if (a[i] - a[i + 1] > maxdiff) maxdiff = a[i] - a[i + 1];
		lld res2 = 0;
		for (int i = 0; i < n-1; i++) {
			if (a[i] >= maxdiff) res2 = res2 + maxdiff;
			else res2 = res2 + a[i];
		}
		cout << "Case #"<<T-t<<": ";
		cout<<res1<<" "<<res2<<"\n";
	}
	return 0;
}
