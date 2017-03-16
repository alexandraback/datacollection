using namespace std;
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cctype>
#include <climits>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <string>

typedef long long L;
typedef unsigned long long U;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;

main()
{
	int tc;
	cin>>tc;
	for(int t = 1;t<=tc;t++)
	{
		bool flag = 1;
		int n;
		cin>>n;
		string str;
		cin>>str;
		char seq[105];
		int k = 0,c = 1;
		seq[0] = str[0];
		int arr[n][110];
		arr[0][0] = 1;
		for(int i = 1;i<str.length();i++)
		{
			if(str[i] != seq[k])
			{
				k++;
				seq[k] = str[i];
				arr[0][k] = 1;
			}
			else
				arr[0][k]++;
		}
		int l = k;
		for(int i = 1;i<n;i++)
		{
			cin>>str;
			arr[i][0] = 1;
			if(str[0] != seq[0])
				flag = 0;
			k = 0;
			for(int j = 1;j<str.length();j++)
			{
				if(str[j] != seq[k])
				{
					k++;
					if(seq[k] != str[j])
						flag = 0;
					arr[i][k] = 1;
				}
				else
					arr[i][k]++;
			}
			if(k != l)
				flag = 0;
		}
		if(!flag)
		{
			printf("Case #%d: Fegla Won\n",t);
			continue;
		}
		l++;
		int sum = 0;
		for(int i = 0;i<l;i++)
		{
			int m = 100000000;
			for(int j = 0;j<n;j++)
			{
				int s = 0;
				for(int k = 0;k<n;k++)
				{
					s += abs(arr[j][i]-arr[k][i]);
				}
				m = min(m,s);
			}
			sum += m;
		}
		printf("Case #%d: %d\n",t,sum);
	}
}
