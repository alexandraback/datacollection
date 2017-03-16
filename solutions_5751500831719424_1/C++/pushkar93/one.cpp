//PUSHKAR SINGH
#include<stdio.h>
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<sstream>
#include<set>
#include<map>
#include<stack>
#include<cmath>
#include<cstdlib>
#include<cstring>
#include<string>
#include <cassert>
using namespace std;
// Input macros
#define s(n) scanf("%d",&n)
#define sc(n) scanf("%c",&n)
#define sl(n) scanf("%lld",&n)
#define sf(n) scanf("%lf",&n)
#define ss(n) scanf("%s",n)
#define ll long long
// Useful constants
#define INF (int)1e9
#define EPS 1e-6
// Useful hardware instructions
#define bitcount __builtin_popcount
#define gcd __gcd
// Useful container manipulation / traversal macros
#define forall(i,a,b) for(int i=a;i<b;i++)
#define foreach(v, c) for( typeof( (c).begin()) v = (c).begin(); v != (c).end(); ++v)
#define all(a) a.begin(), a.end()
#define in(a,b) ( (b).find(a) != (b).end())
#define pb push_back
#define fill(a,v) memset(a, v, sizeof a)
//#define sz(a) ((int)(a.size()))
#define mp make_pair
//#define tr(container, it) for(auto it = container.begin(); it != container.end(); it++)
#define tr(container, it) for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)

#define llu long long unsigned

#define DEBUG 1
#define debug(x) {if (DEBUG)cout <<#x <<" = " <<x <<endl; }
#define debugv(x) {if (DEBUG) {cerr <<#x <<" = "; FORE(it, (x)) cerr <<*it <<", "; cout <<endl; }}
#define mod 1000000007

#define checkbit(n,b) ( (n >> b) & 1)

double pi = 3.14159265359;

void output(int cno,ll num)
{
	printf("Case #%d: %lld\n",cno,num);
}
void output(int cno,string s)
{
	stringstream ss;
	ss << cno;
	string op;
	ss >> op;
	op = "Case #" + op + ": " + s;
	cout<<op<<endl;
}

ll modpow(ll base,ll power)
{
	ll ret = 1;
	while(power > 0)
	{
		if(power%2 == 1)
		{
			ret = (ret * base)%mod;
		}
		power = power>>1;
		base = (base*base)%mod;
	}
	return ret;
}

int n;
vector<int> cc;
vector<string> vs;
int indx[101];
int ans = 0;

void soln()
{
	int mini=INF,sum,maxi=INF,ini = 0;
	while(maxi > 0)
	{

		sort(all(cc));
		maxi = cc[n-1];

		sum = 0;

		for(int i=0;i<n;i++)
		{
			sum += maxi - cc[i];
		}

		mini = min(mini,sum + ini);

		for(int i=n-1;i>=0;i--)
		{
			if(cc[i] == maxi)
			{
				cc[i] -= 1;
				ini++;
			}
			else
				break;
		}
		maxi = cc[n-1];
	}
	ans += mini;
}

void solve()
{


	char cur;
	int in,j,sz,sz0 = vs[0].size();

	while(indx[0] != sz0)
	{
		cc.clear();
		for(int i=0;i<n;i++)
		{
			in = indx[i];
			cur = vs[i][in];
			sz = vs[i].size();
			for(j=in;vs[i][j] == cur && j < sz;j++)
			{

			}
			cc.pb(j - in +1);
			indx[i] = j;
		}
		soln();
	}

}

int check()
{
	string test = "",t;

	int sz = vs[0].size();
	test = vs[0][0];
	for(int i=1;i<sz;i++)
	{
		if(vs[0][i] != vs[0][i-1])
		{
			test = test + vs[0][i];
		}
	}

	for(int i=1;i<n;i++)
	{
		sz = vs[i].size();
		t = vs[i][0];
		for(int j=1;j<sz;j++)
		{
			if(vs[i][j] != vs[i][j-1])
			{
				t = t + vs[i][j];
			}
		}
		if(test != t)
		{
			return 1;
		}
	}
	return 0;
}

int main()
{
	int cno=0,t;
	string s;
	s(t);
	for(cno = 1;cno<=t;cno++)
	{
		ans=  0;
		cin>>n;
		vs.clear();
		for(int i=0;i<n;i++)
		{
			cin>>s;
			vs.pb(s);
		}
		fill(indx,0);
		if(check())
		{
			output(cno,"Fegla Won");

		}
		else
		{
			solve();
			output(cno,ans);
		}
	}

}
