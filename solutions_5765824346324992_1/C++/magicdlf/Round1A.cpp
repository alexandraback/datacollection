// Round1A.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include "queue"
#include "vector"
#include "algorithm"
#include "string"
#include "string.h"
#include "iostream"
using namespace std;

struct cmp{
	bool operator()(pair<long long, int> a, pair<long long, int> b)
	{
		if(a.first!=b.first) return a.first>b.first;
		return a.second>b.second;
	}
};

int main()
{
	int T;
	cin>>T;
	for(int tc=0;tc<T;tc++)
	{
		int B,N;
		cin>>B>>N;
		vector<int> g(B);
		priority_queue<pair<long long,int> , vector<pair<long long,int> > , cmp > queue;
		for(int i=0;i<B;i++)
		{
			cin>>g[i];
		}

		long long l=1,r=1e16;
		long long t=0;
		while(l<=r)
		{
			long long mid=(l+r)/2;
			//test
			long long x=0;
			for(int i=0;i<g.size();i++)
			{
				long long cur=mid/g[i]+1;
				x+=cur;
			}
			if(x>N-100)
			{
				r=mid-1;
			}
			else if(x<N-100)
			{
				l=mid+1;
				t=max(mid,t);
			}
			else
			{
				break;
			}
		}
		for(int i=0;i<B;i++)
		{
			long long cur=t/g[i];
			N-=cur;
			long long tt=g[i]*cur;
			queue.push(make_pair(tt,i));
		}
		for(int i=0;i<N-1;i++)
		{
			long long t=queue.top().first;
			int x=queue.top().second;
			//cout<<"---"<<x<<endl;
			queue.pop();
			queue.push(make_pair(t+g[x],x));
		}
		int ans=queue.top().second+1;
		cout<<"Case #"<<tc+1<<": "<<ans<<endl;
	}
	return 0;
}

