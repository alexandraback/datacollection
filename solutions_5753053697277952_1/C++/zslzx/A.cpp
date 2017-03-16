#include<cstdio>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<iostream>
#include<queue>
using namespace std;
typedef pair<int,int>pii;
priority_queue<pii>q;
int n;
int main()
{
	freopen("data.in","r",stdin);
	freopen("data.out","w",stdout);
	int t;
	scanf("%d",&t);
	for(int cas=1;cas<=t;cas++)
	{
		scanf("%d",&n);
		while(!q.empty())q.pop();
		for(int i=0;i<n;i++)
		{
			int x;
			scanf("%d",&x);
			q.push(make_pair(x,i));
		}
		printf("Case #%d:",cas);
		while(!q.empty())
		{
			if(q.size()==2)
			{
				pii x=q.top();q.pop();
				pii y=q.top();q.pop();
				if(x.first>y.first)
				{
					if(x.first>y.first+1)
					{
						printf(" %c%c",x.second+'A',x.second+'A');
						x.first-=2;
						if(x.first>0)q.push(x);
						q.push(y);
					}
					else
					{
						printf(" %c",x.second+'A');
						x.first--;
						if(x.first>0)q.push(x);
						q.push(y);
					}
				}
				else
				{
					printf(" %c%c",x.second+'A',y.second+'A');
					x.first--;y.first--;
					if(x.first>0)q.push(x);
					if(y.first>0)q.push(y);
				}
			}
			else if(q.size()==3&&q.top().first==1)
			{
				pii x=q.top();q.pop();
				if(x.first==1)
				{
					printf(" %c",x.second+'A');
					x.first--;
					if(x.first>0)q.push(x);
				}
			}
			else
			{
				pii x=q.top();q.pop();
				pii y=q.top();q.pop();
				if(x.first>y.first&&x.first>1)
				{
					printf(" %c%c",x.second+'A',x.second+'A');
					x.first-=2;
					if(x.first>0)q.push(x);
					q.push(y);
				}
				else if(x.first==y.first)
				{
					printf(" %c%c",x.second+'A',y.second+'A');
					x.first--;y.first--;
					if(x.first>0)q.push(x);
					if(y.first>0)q.push(y);
				}
			}
		}
		printf("\n");
	}
	return 0;
}
