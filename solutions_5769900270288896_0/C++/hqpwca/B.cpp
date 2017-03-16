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

bool black[10005][10005];
int dirx[4]={0,1,0,-1};
int diry[4]={1,0,-1,0};

vector<pair<int,int> > Black;
vector<pair<int,int> > White;
int numb[10005],numw[10005];

int main()
{
freopen("t.in","r",stdin);
freopen("t.out","w",stdout);

	int T;
    cin>>T;
	for(int cas=1;cas<=T;cas++)
	{
		int r,c,n;
		memset(numb,0,sizeof(numb));
		memset(numw,0,sizeof(numw));
		Black.clear();
		White.clear();
		cin>>r>>c>>n;
		for(int i=0;i<r;i++)
			for(int j=0;j<c;j++)
			{
				black[i][j]=(i+j)%2;
				if(black[i][j])Black.push_back(make_pair(i,j));
				else White.push_back(make_pair(i,j));
			}
		int bs=Black.size(),ws=White.size();
		for(int i=0;i<bs;i++)
		{
			int r0=Black[i].first,c0=Black[i].second;
			for(int z=0;z<4;z++)
			{
				int r1=r0+dirx[z],c1=c0+diry[z];
				if(r1>=0&&r1<r&&c1>=0&&c1<c)numb[i]++;
			}
		}
		for(int i=0;i<ws;i++)
		{
			int r0=White[i].first,c0=White[i].second;
			for(int z=0;z<4;z++)
			{
				int r1=r0+dirx[z],c1=c0+diry[z];
				if(r1>=0&&r1<r&&c1>=0&&c1<c)numw[i]++;
			}
		}
		int ans=0;
		sort(numb,numb+bs);
		sort(numw,numw+ws);
		if(n<=max(bs,ws))ans=0;
		else
		{
			int n1=n-bs,n2=n-ws,ans1=0,ans2=0;
			for(int i=0;i<n1;i++)
				ans1+=numw[i];
			for(int i=0;i<n2;i++)
				ans2+=numb[i];
			ans=min(ans1,ans2);
		}
		printf("Case #%d: %d\n",cas,ans);
	}
	
	return 0;
}
