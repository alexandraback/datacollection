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
lld modpow(lld a,lld n,lld temp){lld res=1,y=a;while(n>0){if(n&1)res=(res*y)%temp;y=(y*y)%temp;n/=2;}return res%temp;} 
inline int bits(int x) {
	int res = 0;
	while (x > 0) {
		if (x&1) res++;
		x>>=1;
	}
	return res;
}

int main()
{
	int t;
	cin>>t;
	int T = t;
	while (t--) {
		int r,c,n;
		cin>>r>>c>>n;
		int res = INT_MAX;
		for (int i = 0; i < (1<<(r*c)); i++) {
			if(bits(i) == n) {
				int temp = 0;
				for (int j = 0; j < r; j++) {
					for (int k = 0; k < c - 1; k++) {
						if (((i>>(j*c + k))&1) && ((i>>(j*c + k + 1))&1)) {
							temp ++;
						}
					}
				}
				for (int j = 0; j < r - 1; j++) {
					for (int k = 0; k < c; k++) {
						if (((i>>(j*c + k))&1) && ((i>>((j+1)*c + k))&1)) {
							temp ++;
						}
					}
				}
				res = min (res, temp);
			}
		}
		cout<<"Case #"<<T-t<<": "<<res<<"\n";
	}
	return 0;
}
