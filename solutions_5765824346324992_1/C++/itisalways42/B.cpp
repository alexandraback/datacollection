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
typedef pair< LL, LL > PII;

LL gcd(LL x, LL y)
{
	if(y==0) return x;
	return gcd(y,x%y);
}

LL a[1010];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t,Case=0;
	cin>>t;
	while(t--)
	{
		Case++;
		LL n,m,lcm=1,cnt=0,ans,val;
		cin>>m>>n;
		for(int i=0; i<m; i++) {cin>>a[i]; lcm = (a[i]*lcm)/gcd(a[i],lcm);}
		for(int i=0; i<m; i++) cnt += lcm/a[i];
		n %= cnt; if(n==0) n += cnt;
		//cout<<n<<" "<<cnt<<endl;
		LL l=0,r=lcm,mid,x;
		while(l<=r)
		{
			mid = (l+r)/2;
			x = 0;
			for(int i=0; i<m; i++) x += 1+mid/a[i];
			val=0;
			for(int i=0; i<m; i++) val += 1+(mid-1)/a[i];
			if(mid==0) val=0;
			//val = x-val;
			//cout<<l<<" "<<r<<" "<<mid<<" "<<x<<" "<<val<<" "<<n<<" "<<lcm<<" "<<cnt<<endl;
			if(x>=n && val<n) break;
			if(x<n) l = mid+1;
			else if(x>=n) r = mid-1;
		}
		ans=-1;
		//cout<<mid<<endl;
		val = n-val;
		for(int i=0; i<m; i++) if(!(mid%a[i]))
		{
			ans=i+1;
			val--;
			if(!val) break;
		}
		cout<<"Case #"<<Case<<": "<<ans<<"\n";
	}
	return 0;
}
