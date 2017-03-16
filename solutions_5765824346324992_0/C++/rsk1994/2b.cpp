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
lld gcd(lld a,lld b){if(a==0)return(b);else return(gcd(b%a,a));}

int main()
{
	int t,n;
	cin>>t;
	int T = t;
	while (t--) {
		int n,b,i;
		cin>>b>>n;
		scan (a,b);
		lld lcm = a[0];
		vector<int> A(b, 0);
		for (i = 1; i < b; i++) 
			lcm = (lcm*a[i])/gcd (lcm, a[i]);
		lld fact = 0;
		for (i = 0; i < b; i++)
			fact += lcm/a[i];
		n %= fact;
		int res = b-1;
		for (i = 0; i < n; i++) {
			int min1 = INT_MAX, minid = 0;
			for (int j = 0; j < b; j++) {
				if (A[j] < min1) {min1 = A[j]; minid = j;}
			}
			A[minid] += a[minid];
			res = minid;
		}
		cout<<"Case #"<<T-t<<": "<<res+1<<"\n";
	}

	return 0;
}
