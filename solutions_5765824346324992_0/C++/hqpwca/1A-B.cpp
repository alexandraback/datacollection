#include<iostream>
#include<fstream>
#include<iomanip>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iomanip>
#include<algorithm>
#include<list>
#include<map>
#include<set>
#include<queue>
#include<deque>
#include<vector>
#include<functional>
#include<string>
#define INF 1000000007
#define ll long long
#define rep(i,k) for(int i=G.start[k];i!=INF;i=G.next[i])

using namespace std;

int b;
ll n;
ll a[10005];
int s[1005]={0},p;

ll solve(ll k)
{
	p=0;
	ll tmp=0;
	for(int i=0;i<b;i++)
	{
		tmp+=(k/a[i]+1);
		if(k%a[i]==0)s[p++]=i;
	}
	return tmp;
}

int main()
{
freopen("1a-b.in","r",stdin);
freopen("1a-b.out","w",stdout);
	
	ios::sync_with_stdio(false);
	
    int T;
    cin>>T;
	for(int cas=1;cas<=T;cas++)
	{
		cin>>b>>n;
		for(int i=0;i<b;i++)
			cin>>a[i];
		ll L=0,R=1000000000000000LL;
		while(R>L)
		{
			ll mid=(L+R)/2;
			ll res=solve(mid);
			if(res>=n)R=mid;
			else L=mid+1;
		}
		ll res=solve(L);
		int ans;
		res-=p;
		for(int i=0;i<p;i++)
		{
			res++;
			if(res==n)
			{
				ans=s[i];
				break;
			}
		}
		
		cout<<"Case #"<<cas<<": "<<ans+1<<endl;
	}
	
	return 0;
}
