#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <string>
#include <string.h>
#include <stdlib.h>
#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <ctime>
#include <functional>

using namespace std;

#define CLR(a,x) memset(a,x,sizeof a)
#define LL long long
#define ALL(v) v.begin(),v.end()
#define FR(i,n) for(LL i=0;i<(LL)n;i++)
#define FAB(i,a,b) for(LL i=(LL)a;i<(LL)b;i++)
#define FBA(i,b,a) for(LL i=(LL)b;i>=(LL)a;i--)
#define IIN(x) scanf("%d",&x)
#define IIN2(x,y) scanf("%d%d",&x,&y)
#define LIN(x) scanf("%I64d",&x)
#define LIN2(x,y) scanf("%I64d%I64d",&x,&y)
#define EXIT(n) {cout<<n<<endl;return 0;}
#define PII pair<int,int>
#define PPI pair<PII,int>
#define PLL pair<LL,LL>
#define PDD pair<double,double>
#define PDI pair<double,int>
#define PIS pair<int,string>
#define PSI pair<string,int>
#define PI 3.141592653589793238
#define VI vector<int>
#define VLL vector<long>
#define VPL vector<PLL>
#define VS vector<string>
#define SI set<int>
#define SLL set<LL>
#define SPL set<PLL>
#define SS set<string>
#define MII map<int,int>
#define MLL map<LL,LL>
#define MPL map<PLL,LL>
#define MSI map<string,int>
#define MSL map<string,LL>
#define MIS map<int,string>
#define INF 10000000000000
#define MOD 1000000007
#define MAX 101

int q,tc;
int n,res;
string s[MAX];
vector<PII> v[MAX];

void input()
{
	cin>>n;
	FR(i,n) 
	{
		cin>>s[i];
		v[i].clear();
	}
}

void solve()
{
	FR(i,n)
	{
		int j=1,ch=s[i][0];
		v[i].push_back(PII(ch,1));
		while(j<s[i].size())
		{
			while(j<s[i].size() && s[i][j]==ch)
			{
				v[i][v[i].size()-1].second++;
				j++;
			}
			if(j<s[i].size())
			{
				ch=s[i][j];
				v[i].push_back(PII(ch,1));
				j++;
			}
		}
	}

	FAB(i,1,n)if(v[i].size()!=v[0].size())
	{
		res=-1;
		return;
	}

	res=0;
	FR(i,v[0].size())
	{
		int mn=10000000;
		FR(j,n)
		{
			int sum=0;
			FR(k,n)
			{
				if(v[j][i].first!=v[k][i].first)
				{
					res=-1;
					return;
				}
				sum+=(int)abs((double)v[j][i].second-(double)v[k][i].second);
			}
			mn=min(mn,sum);
		}
		res+=mn;
	}
}

void output()
{
	if(res==-1) printf("Case #%d: Fegla Won\n",q);
	else printf("Case #%d: %d\n",q,res);	
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	cin>>tc;
	for(q=1;q<=tc;q++)
	{
		input();
		solve();
		output();
	}

	return 0;
}