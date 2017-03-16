#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <memory.h>
#include <string>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
#include <vector>
#include <set>
#include <assert.h>

#define file_name ""

typedef long long ll;

const int N = 1e3+5;

using namespace std;


char s[111][N];
char str[N];
int a[111][N];
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int countTests;
	scanf("%d",&countTests);

	for(int numTest=1;numTest<=countTests;++numTest)
	{
		int n ;
		scanf("%d",&n);
		for(int i=0;i<n;++i)
			scanf("%s",&s[i]);
		int len  =0;
		int ans = 1e9;
		int h = strlen(s[0]);
		for(int i=0;i<h;++i)
			if (!i || s[0][i] != s[0][i-1])
				str[len++] = s[0][i];
		memset(a, 0 ,sizeof (a));

		bool f = 0;
		for(int i=0;i<n;++i)
		{
			int sn = strlen(s[i]);
			int k =0;
			int j =0;
			while (j<sn && k<len && s[i][j]==str[k])
			{
				while (j<sn && k<len && s[i][j]==str[k])
					a[i][k]++, j++;
				k++;
			}
			if (j<sn || k<len)
			{
				f=1;
				break;
			}
		}

		if (!f)
		{
			ans = 0;
			for(int k=0;k<len;++k)
			{
				int t = 1e9;
				for(int i=0;i<n;++i)
				{
					int d = 0;
					for(int j=0;j<n;++j)
						d += abs(a[i][k]-a[j][k]);
					t = min(t,d);
				}
				ans+=t;
			}
		}
		printf("Case #%d: ", numTest);
		if (f) puts("Fegla Won");
		else printf("%d\n",ans);
	}
	return 0;
}




