#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#include<utility>
#include<set>
#include<stack>
#include<list>
#include<deque>
#include<bitset>
#include<iomanip>
#include<cstring>
#include<sstream>
#include<cstdio>
#include<cstdlib>
#include<climits>
#include<cmath>
#include<cctype>


#define pb push_back
#define mp make_pair
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define ren(i,a,b) for(int i=a;i>=b;i--)
#define ff first
#define ss second
#define pll pair<long long int,long long int>
#define pii pair<int,int>
#define vll vector<long long int>  
#define vii vector<int>
#define gi(n) scanf("%d",&n)
#define gll(n) scanf("%lld",&n)
#define gstr(n) scanf("%s",n)
#define gl(n) cin >> n
#define oi(n) printf("%d",n)
#define oll(n) printf("%lld",n)
#define ostr(n) printf("%s",n)
#define ol(n) cout << n
#define os cout<<" "
#define on cout<<"\n"
#define o2(a,b) cout<<a<<" "<<b
#define all(n) n.begin(),n.end()
#define present(s,x) (s.find(x) != s.end()) 
#define cpresent(s,x) (find(all(s),x) != s.end()) 
#define tr(container, it) for(__typeof(container.begin()) it = container.begin(); it != container.end(); it++) 
using namespace std;
 
typedef unsigned long long int ull;
typedef long long int ll;
int main()
{ios_base::sync_with_stdio(false);
freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);
int t,t1=0;
gl(t);
while(t--)
{
  t1++;
  ol("Case #");ol(t1);ol(": ");	
  int a[25][25]={0},n,r,c,s=0,ans=0,b[25][25]={0},s1=0;
  cin>>r>>c>>n;
  rep(i,1,r)
  rep(j,1,c)
  {
  	if(a[i-1][j]==0&&a[i][j-1]==0)
  	{
	  a[i][j]=1;s++;
     } 
  	//cout<<a[i][j];
  	//if(j==c)on;
  }
  rep(i,1,r)
  rep(j,1,c)
  {
  	if(!(i==1&&j==1))
  	{
	  
	  if(b[i-1][j]==0&&b[i][j-1]==0)
  	{
	  b[i][j]=1;s1++;
     }} 
  	//cout<<b[i][j];
  	//if(j==c)on;
  }
  if(n<=s)
  ol("0\n");
  else if(r*c==n)
  {
  	cout<<n+1<<"\n";
  }
  else
  {
  	rep(z,s+1,n)
  	{int d1=5,pi,pj;
  		rep(i,1,r)
  		{
  			rep(j,1,c)
  			{
  				int deg=0;
  				if(a[i][j]==0)
  				{
				  
  				deg+=(a[i+1][j]+a[i-1][j]+a[i][j-1]+a[i][j+1]);
  				if(deg<d1)
  				{
  					d1=deg;
  					pi=i;pj=j;
				  }
				  }
			  }
		  }
		  a[pi][pj]=1;
		  ans+=d1;
	  }
	  int ans1=0;
	  rep(z,s1+1,n)
  	{int d1=5,pi,pj;
  		rep(i,1,r)
  		{
  			rep(j,1,c)
  			{
  				int deg=0;
  				if(b[i][j]==0)
  				{
				  
  				deg+=(b[i+1][j]+b[i-1][j]+b[i][j-1]+b[i][j+1]);
  				if(deg<d1)
  				{
  					d1=deg;
  					pi=i;pj=j;
				  }
				  }
			  }
		  }
		  b[pi][pj]=1;
		  ans1+=d1;
	  }
	  ans=min(ans,ans1);
	  ol(ans);on;
  }
}
return 0;
}
