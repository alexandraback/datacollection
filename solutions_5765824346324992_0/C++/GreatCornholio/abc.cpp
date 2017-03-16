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

//EUCLID'S GCD
ll gcd(ll a,ll b){
    if(b==0) return a; else return gcd(b,a%b); }
    
//EUCLID'S GCD
ll lcm(ll a,ll b){
    return a*(b/gcd(a,b));   }     
    
vector<ll> v;    

int main()
{	
	cin.sync_with_stdio(0);
	
	ll t;
	
	cin>>t;
	
	F(T,1,t)
	{
		ll b,m;
		
		cin>>b>>m;
		
		ll a[b+1];
		
		cin>>a[1];
		
		ll l=a[1];
		
		F(i,2,b)
		{
			cin>>a[i];
		
			l=lcm(a[i],l);
		}
		
		F(i,1,b)
		if(l%a[i]!=0)
		cout<<"NO";
		
		v.clear();
		
		F(i,1,l) //time
		{
			F(j,1,b)
			if(i>=a[j] && i%a[j]==0)
			{
				v.pb(j);
			}
			
		}
	
		ll num=0;
		
		F(i,l+1,2*l)
		{
			F(j,1,b)
			if(i>=a[j] && i%a[j]==0)
			{	
				if(j!=v[num++])
				cout<<"NO";
			}	
			
		}
		
		if(num!=v.size())
		cout<<"NO";
		
		ll ans;
		
		if(m<=b)
		ans=m;
		
		else
		ans=v[(m-b-1)%v.size()];
		
		assert(ans>=1 && ans<=b);
	
		cout<<"Case #"<<T<<": "<<ans<<"\n";
	}
	
    return 0;
}
