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

 ll r,c,n;

ll calc(ll x,ll y){ //whether a non cracked neighbor exists
    
    ll dx[4]={1,0,-1,0};
    ll dy[4]={0,1,0,-1};
    
    ll ans=0;
    
    F(i,0,3)
    {
        ll nx=x+dx[i];
        ll ny=y+dy[i];
        
        if(nx<r && ny<c && nx>=0 && ny>=0)
        {
           ans++;
        }   
    }
    
    return ans;
}

int main(){
    
   cin.sync_with_stdio(0);
   
   ll t;
   
   cin>>t;
   
   F(T,1,t){
	   
	   cin>>r>>c>>n;
	   
	   if((r*c)/2 + (r*c)%2>=n)
	   {
		   
		   
		   cout<<"Case #"<<T<<": "<<"0\n";   
			continue;
	   }
	   
	   ll n1=n-(r*c)/2 - (r*c)%2; 
	   
	   ll n2=n-(r*c)/2;
	   
	   vector<ll> mn1,mn2;
	   
	   for(ll i=0;i<r;i++)
	   for(ll j=0;j<c;j++)
	   if(  (i%2==0 && j%2==1)  || (i%2==1 && j%2==0) )
	   {
		
		    mn1.pb(calc(i,j));
	   
       }
       else
	   if(  (i%2==0 && j%2==0)  || (i%2==1 && j%2==1) )
	   {
			mn2.pb(calc(i,j));
	   
       }
       
       ll ans1=0,ans2=0;

	   sort(mn1.begin(),mn1.end());
		
       sort(mn2.begin(),mn2.end());
       
       for(ll i=0;i<mn1.size() && i<n1;i++)
       ans1+=mn1[i];
       
       for(ll i=0;i<mn2.size() && i<n2;i++)
       ans2+=mn2[i];
       
       cout<<"Case #"<<T<<": "<<min(ans1,ans2)<<"\n";   
       
}
  
    return 0;
  
}
