#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define F(i,a,b) for(ll i=a;i<=b;i++)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define mp make_pair
#define pb push_back 
#define X first
#define Y second
#define pi 3.14159265
#define MOD 1000000007  

int main()
{	
	cin.sync_with_stdio(0);
	
	ll t;
	
	cin>>t;
	
	F(T,1,t)
	{
		ll ans1=0,ans2=0;
		
		ll n;
		
		cin>>n;
		
		ll a[n+10];
		
		F(i,1,n)
		{
				cin>>a[i];
			
		} 	
		
		ll mx=0;
		
		F(i,1,n-1)
		{
				if(a[i]>a[i+1])
				ans1+=a[i]-a[i+1];
				
				if(a[i]-a[i+1]>mx)
				mx=a[i]-a[i+1];
		} 
		
		F(i,1,n-1)
		{
				ans2+=min(mx,a[i]);
		} 
		
		cout<<"Case #"<<T<<": "<<ans1<<" "<<ans2<<"\n";
	}
	
    return 0;
}
