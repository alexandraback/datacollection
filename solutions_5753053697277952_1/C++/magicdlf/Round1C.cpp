// Round1C.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include "iostream"
#include "vector"
#include "algorithm"
#include "string"
#include "string.h"
#include "stdio.h"
using namespace std;


int g[50]={};

int check(int n)
{
	int total = 0;
	for(int i=0;i<n;i++)
		total+=g[i];
	for(int i=0;i<n;i++)
	{
		if(g[i]>total*0.5)
			return 0;
	}
	return 1;
}
int main()
{
	int T;
	cin>>T;
	for(int tc=0;tc<T;tc++)
	{
		int n;
		cin>>n;
		memset(g,0,sizeof(g));
		for(int i=0;i<n;i++)
		{
			cin>>g[i];
		}
		cout<<"Case #"<<tc+1<<": ";
		string ans;
		int flag=1;
		while(flag)
		{
			flag=0;
			for(int i=0;i<n;i++)
			{
				if(g[i]>0)
				{
					g[i]--;
					if(check(n))
					{
						ans.push_back('A'+i);
						ans.push_back(' ');
						flag=1;
					}
					else
					{
						g[i]++;
					}
				}
			}
			for(int i=0;i<n;i++)
			{
				if(g[i]>0)
				{
					for(int j=i+1;j<n;j++)
					{
						if(g[i]>0 && g[j]>0)
						{
							g[i]--; g[j]--;
							if(check(n))
							{
								ans.push_back('A'+i);
								ans.push_back('A'+j);
								ans.push_back(' ');
								flag=1;
							}
							else
							{
								g[i]++;
								g[j]++;
								flag=1;
							}
						}
					}
				}
			}
		}
		ans.pop_back();
		cout<<ans<<endl;
	}
	return 0;
}

