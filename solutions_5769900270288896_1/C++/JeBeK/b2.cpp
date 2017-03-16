#include<iostream>
#include<algorithm>

using namespace std;

int ans,ans1,a,b,c,n,m,t,t1;

int main()
{
  int qw;
  cin>>qw;
  for(int q=1;q<=qw;q++)
    {
      ans=ans1=0;
      cin>>n>>m>>t;
      if(n>m)
	swap(n,m);
      if(n==1)
	{
	  if(t>(m+1)/2)
	    {
	      if(m%2==0)
		ans=1,m--,t--;
	      ans+=(t-(m+1)/2)*2;
	    }
	  cout<<"Case #"<<q<<": "<<ans<<endl;
	  continue;
	}
      t1=t;
      if(t>(n*m+1)/2)
	{
	  t-=(n*m+1)/2;
	  a=b=c=0;
	  if((n*m)%2==0)
	    a=2;
	  b=(n+m-2)-a;
	  c=n*m/2-a-b;
	  ans+=min(t,a)*2;
	  t-=min(t,a);
	  ans+=min(t,b)*3;
	  t-=min(t,b);
	  ans+=min(t,c)*4;
	  // cout<<a<<" "<<b<<" "<<c<<endl;
	}
      t=t1;
      if(t>n*m/2)
	{
	  t-=n*m/2;
	  a=b=c=0;
	  a=4;
	  if((n*m)%2==0)
	    a=2;
	  b=(n+m-2)-a;
	  c=(n*m+1)/2-a-b;
	  ans1+=min(t,a)*2;
	  t-=min(t,a);
	  ans1+=min(t,b)*3;
	  t-=min(t,b);
	  ans1+=min(t,c)*4;
	  t-=min(t,c);
	}
      cout<<"Case #"<<q<<": "<<min(ans,ans1)<<endl;
    }
}
