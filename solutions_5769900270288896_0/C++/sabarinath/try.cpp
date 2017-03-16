#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
vector<long long> sol;

long long grid[20][20],r,c;

long long isadj(long long i,long long j)
{
	if(grid[i][j])
	return grid[i+1][j]+grid[i][j+1];	
	else
	return 0;
}

long long countSetBits(long long  n)
{
  long long  count = 0;
  while(n)
  {
    count += n & 1;
    n >>= 1LL;
  }
  return count;
}

void populate(long long n)
{
	//cout<<n<<endl;
	long long i,j,k=0;
	memset(grid,0,sizeof(grid));
	for(i=1;i<=r;i++)
	{
		for(j=1;j<=c;j++)
		{
			if(n&(1LL<<k))
			grid[i][j]=1;
		//	else if(n==495)
		//	cout<<"K= "<<k<<endl;
			k++;
		}
	}
}

long long fin()
{
	long long i,j,ans=0;
	for(i=1;i<=r;i++)
	for(j=1;j<=c;j++)
	ans+=isadj(i,j);
	//cout<<ans<<endl;
	return ans;
}


int main() 
{
	freopen("input.txt","r",stdin);
	freopen("output2.txt","w",stdout);
	long long t,i,j,n,cnt,T,x,ans,N;
	cin>>T;
	for(t=0;t<T;t++)
	{
		cin>>r>>c>>n;
		ans=INT_MAX;
		for(i=0;i<(1LL<<(r*c));i++)
		{
			if(countSetBits(i)==n)
			{
				populate(i);
				ans=min(ans,fin());
			}
		}
		cout<<"Case #"<<t+1<<": "<<ans<<"\n";
	
	}
	return 0;
}
