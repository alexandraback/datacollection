#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<cstdlib>
#include<sstream>
#include<string.h>
#include<set>
#include<map>
#include<assert.h>
#include<fstream>
#include<ctime>
#include<queue>
#include<vector>
#include<stack>
#include<list>
#include<math.h>

using namespace std;
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
typedef vector<int> vi;
typedef vector<string> vs;
typedef pair<int,int> pii;
typedef long long int lli;
typedef unsigned long long ull;

#define MAXN 105
#define INF 2147483647
#define MOD 1000000007
#define pb push_back 
#define sz(a) int((a).size())
#define var(a,b)  __typeof(b) a = b
#define FOR(x,a,b) for(int (x) = (a);(x)<=(b);(x)++)
#define rep(x,n)   for(int (x)=0;(x)<(n);(x)++)
#define tr(c,it)  for(var(it,(c).begin());it!=(c).end();++it)
#define all(c) c.begin(),c.end()
#define mset(a,b) memset(a,b,sizeof(a)) 
#define MAX(a, b) (a) > (b) ? (a) : (b)

int c[MAXN][MAXN];
string delete_dupli(string a,int ind)
{
	string b="";
	for(int i=0;i<a.length();)
	{
		if(i!=0)
		{
		if(a[i]!=a[i-1])
			b+=a[i],c[ind][b.length()-1] = 1;
		else
			c[ind][b.length()-1]++;
		}
		else
			{
				b+=a[i];
				c[ind][b.length()-1]=1;
			}
		i++;
	}
	return b;
}
int main()
{
	int t,n;
	string s[MAXN],b[MAXN];
	#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    scanf("%d",&t);
    rep(q,t)
    {
    	mset(c,0);
    	bool flag = false;
    	scanf("%d",&n);
    	rep(i,n)
    	{
    		cin>>s[i];
    		b[i] = delete_dupli(s[i],i);
    	}

    	// rep(i,n)
    	// cout<<"\n"<<b[i]<<" "<<s[i];
    	
    	string temp = b[0];
    	
    	cout<<"Case #"<<q+1<<": ";
    	rep(i,n)
    	{
    		if(temp!=b[i])
    			flag = true;
    	}
    	vi points;
    	int ans = 0;
    	if(flag==false)
    	{
    		// rep(i,temp.length()){cout<<"\n";
    		// rep(j,n)
    		// cout<<c[i][j]<<" ";}
    		rep(i,temp.length())
    		{
    		 points.clear();
  			 rep(j,n)
    	  	  points.pb(c[j][i]);
    		 sort(all(points));
    		 int  k = n/2;
    		 rep(i,n)
    		 ans+=abs(points[i]-points[k]);
    		}
    	}
    	if(flag)
    		cout<<"Fegla Won\n";
    	else
    		cout<<ans<<"\n";	
     }
	

	return 0;
}
