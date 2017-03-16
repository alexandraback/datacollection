#include<iostream>
#include<algorithm>

using namespace std;

int n,m,t,ans,sum;

int main()
{
  int qw;
  cin>>qw;
  for(int q=1;q<=qw;q++)
    {
      cin>>n>>m>>t;
      ans=100000000;
      for(int i=0;i<(1<<n*m);i++)
	{
	  if(__builtin_popcount(i)==t)
	    {
	      sum=0;
	      for(int x=0;x<n;x++)
		for(int y=0;y<m;y++)
		  {
		    if(y<m-1 && (i&(1<<(x*m+y))) && (i&(1<<(x*m+y+1))))
		      sum++;
		    if(x<n-1 && (i&(1<<(x*m+y))) && (i&(1<<(x*m+y+m))))
		      sum++;
		  }
	      ans=min(ans,sum);
	    }
	}
      cout<<"Case #"<<q<<": "<<ans<<endl;
    }
}
