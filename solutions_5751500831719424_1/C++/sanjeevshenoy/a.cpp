#include <cstdio>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <functional>
#include <limits>
#include <cassert>
#include <sstream>
#include <cmath>
#include <string>
#include <fstream>

using namespace std;
typedef long long ll;

const int max_n=110;

int n,T;
string a[max_n],s[max_n];
int cnt[max_n][max_n];

int main()
{
	scanf("%d",&T);

	for(int z=0; z<T; z++)
	{

		scanf("%d",&n);
		for(int i=0; i<n; i++)
			cin>>a[i];

		for(int i=0; i<n; i++)
		{
			char p='1';
			int c=0,nc=0;
			s[i].resize(0);
			for(int j=0; j<(int)a[i].size(); j++)
				if(a[i][j]!=p)
				{
					s[i]+=a[i][j];
					p=a[i][j];
					if(c>0)
					{
						cnt[i][nc]=c;
						nc++;
					}
					c=1;
				}
				else
					c++;

			cnt[i][nc]=c;
		}

		bool res=1;

		for(int i=0; i<n; i++)
			for(int j=0; j<n; j++)
				if(s[i]!=s[j])
					res=0;

		printf("Case #%d: ",z+1);

		if(!res)
			printf("Fegla Won\n");
		else
		{
			int r=0;
			for(int i=0; i<(int)s[0].size(); i++)
			{
				int mn=1e9;

				int x=0;
				for(int j=0; j<n; j++)
					x=max(x,cnt[j][i]);

				for(int k=0; k<=x; k++)
				{
					int rs=0;
					for(int j=0; j<n; j++)
						rs+=abs(cnt[j][i]-k);
					mn=min(mn,rs);
				}

				r+=mn;
			}
			printf("%d\n",r);
		}
	}

	return 0;
}