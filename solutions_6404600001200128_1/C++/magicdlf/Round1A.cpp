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

int main()
{
	int T;
	cin>>T;
	for(int tc=0;tc<T;tc++)
	{
		int N;
		cin>>N;
		vector<int> g(N);
		for(int i=0;i<N;i++)
			cin>>g[i];
		int gap=0;
		int ans1=0;
		for(int i=1;i<N;i++)
		{
			gap=max(gap,g[i-1]-g[i]);
			ans1+=max(0,g[i-1]-g[i]);
		}
		int ans2=0;
		int cur=0;
		for(int i=0;i<N-1;i++)
		{
			cur=max(cur,g[i]);
			ans2+=min(gap,cur);
			cur-=min(gap,cur);
		}
		cout<<"Case #"<<tc+1<<": "<<ans1<<" "<<ans2<<endl;
	}
	return 0;
}