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
map<int,int>m;
int main()
{ios_base::sync_with_stdio(false);
freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);
int t,t1=0;
gl(t);
while(t--)
{
  int b,n,a[20005],d[20005],used[20005]={0},x;
  m.clear();
  cin>>b>>n;
  x=b+1;
  rep(i,0,b-1)
  {
   gl(a[i]);
   d[i]=a[i];
   used[i]=1;
  }
  rep(i,1,b)
  m[i]=i;
  //ol(m[0]);os;
  //int f=0;
  //ol(b);on;
  while(1)
  {int c=0;//f++;
  	rep(i,0,b-1)
  	{
	  d[i]--;
	  //ol(d[i]);os;
	  
    }
    //os;
    //ol(x);
  	rep(i,0,b-1)
  	{
  		if(d[i]==0)
  		{
		  used[i]=0;
		  c++;
		  
		  //ol(x);
	    }
  		else
  		used[i]=1;
	}
	//on;
	if(c==b)
	break;
	rep(i,0,b-1)
	{
	     if(d[i]==0)
 		{
		 d[i]+=a[i];
		  m[x]=i+1;
		  x++;}
	}
  }
  
  x--;
  /*ol(x);on;
  
  rep(i,1,x)
  {
  	ol(m[x]);os;
  }*/
  t1++;
  ol("Case #");ol(t1);ol(": ");
  int t=n%x;
  if(t==0)
  t+=x;	
  ol(m[t]);on;
}
return 0;
}
