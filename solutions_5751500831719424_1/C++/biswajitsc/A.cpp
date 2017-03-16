#include <iostream>
#include <stdio.h>
#include <utility>
#include <algorithm>
#include <cstring>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <math.h>
#include <cstdio>
#include <assert.h>
 
#define FOR(i,x,y) for(int i=(x);i<(y);i++)
#define RFOR(i,x,y) for(int i=(x);i>=(y);i--)
#define ABS(x) ((x)>0?(x):-(x))
#define SQ(x) ((x)*(x))
#define mset(x,y) memset(x,y,sizeof(x))
#define INF 1000000000
#define MOD 1000000007
#define pb(X) push_back(X) 
 
using namespace std;
 
typedef long long int lli;
typedef long double ld;
typedef pair<int,int> pi;
typedef vector<int> vi;
typedef vector<double> vd;

string arr[110];
vector<char> chars[110];
vector<int> cnts[110];

bool chk(int k)
{
	if(chars[0].size()!=chars[k].size()) return 0;
	for(int i=0;i<chars[0].size();i++) if(chars[0][i]!=chars[k][i]) return 0;

	return 1;
}

int main()
{
	#ifndef ONLINE_JUDGE
    freopen("A-large.in","r",stdin);
    #endif

    int t;
    scanf("%d",&t);
    for(int tt=1;tt<=t;tt++)
    {
    	int n;
    	scanf("%d",&n);
    	for(int i=0;i<n;i++) cin>>arr[i];

    	for(int i=0;i<n;i++)
    	{
    		chars[i].clear();
    		cnts[i].clear();
    		for(int j=0;j<arr[i].length();j++)
    		{
    			if(j==0)
    			{
    				chars[i].pb(arr[i][j]);
    				cnts[i].pb(1);
    			}
    			else
    			{
    				if(arr[i][j]==arr[i][j-1])
    				{
    					cnts[i][cnts[i].size()-1]++;
    				}
    				else
    				{
    					chars[i].pb(arr[i][j]);
    					cnts[i].pb(1);
    				}
    			}
    		}
    	}

    	// for(int i=0;i<n;i++)
    	// {
    	// 	for(int j=0;j<cnts[i].size();j++) cout<<cnts[i][j];
    	// 	cout<<endl;
    	// }
    	bool flag=true;
    	for(int i=0;i<n;i++)
    	{
    		if(!chk(i)) flag=false;
    	}

    	int cnt=0;
    	if(flag)
    	{
    		for(int i=0;i<cnts[0].size();i++)
    		{
    			vector<int> v;
    			for(int j=0;j<n;j++) v.pb(cnts[j][i]);
    			sort(v.begin(),v.end());
    			for(int i=0;i<n;i++) cnt+=ABS(v[i]-v[n/2]);
    		}
    		printf("Case #%d: %d\n",tt,cnt);
    	}

    	else
    	{
    		printf("Case #%d: Fegla Won\n",tt);
    	}

    }

    return 0;
}