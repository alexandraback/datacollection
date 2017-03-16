#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define mod 1000000007

using namespace std;
typedef long long LL;
typedef vector<int> VI;
typedef vector< vector<int> > VVI;
typedef pair< int, int > PII;
LL a[100010];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t,Case=0;
	cin>>t;
	while(t--)
	{
		Case++;
		LL n,x=0,y=0,ans=0; cin>>n;
		for(int i=0; i<n; i++) cin>>a[i];
		for(int i=1; i<n; i++) x += max(0LL,a[i-1]-a[i]);
		for(int i=1; i<n; i++) y = max(y,a[i-1]-a[i]);
		for(int i=0; i<n-1; i++) ans += min(a[i],y);
		//if(a[n-1] >= max(0LL,a[n-2]-10*y)) ans -= (a[n-1] - max(0LL,(a[n-2]-10*y)));
		cout<<"Case #"<<Case<<": "<<x<<" "<<ans<<"\n";
	}
	return 0;
}
