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

int a[10005];

int main()
{
freopen("1a-a.in","r",stdin);
freopen("1a-a.out","w",stdout);

	ios::sync_with_stdio(false);
	
	int T;
    cin>>T;
	for(int cas=1;cas<=T;cas++)
	{
		int n;
		cin>>n;
		for(int i=0;i<n;i++)
			cin>>a[i];
		int ans1=0,ans2=0,tmp=0;
		for(int i=1;i<n;i++)
			if(a[i]<a[i-1])
			{
				ans1+=a[i-1]-a[i];
				tmp=max(tmp,a[i-1]-a[i]);
			}
		for(int i=0;i<n-1;i++)
		{
			if(a[i]<=tmp)
				ans2+=a[i];
			else
				ans2+=tmp;
		}
		cout<<"Case #"<<cas<<": "<<ans1<<' '<<ans2<<endl;
	}
	
	return 0;
}
