#include <string>
#include <vector>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <algorithm>
#include <map>
#include <iostream>
#include <sstream>
#include <queue>
#include <cstring>
#include <ctime>
#include <cfloat>

using namespace std;

char ss[105][105];
char sngl[105];
vector<pair<char, int> >infs[105];

bool posble(int n)
{
	int i, j;
	for(i = 1; i < n; i++)
	{
		if(infs[i].size() != infs[0].size())
		{
			return false;
		}
		for(j = 0;  j < infs[0].size(); j++)
		{
			if(infs[i][j].first != infs[0][j].first)
				return false;
		}
	}
	return true;
}

int main()
{
	//freopen("A-small-attempt0.in", "rt", stdin);
	//freopen("A-small-attempt0.out", "wt", stdout);


	freopen("A-large.in", "rt", stdin);
	freopen("A-large.out", "wt", stdout);

	int inp, kase, i, j, k, a, n;
	scanf("%d", &inp);
	for(kase = 1; kase <= inp; kase++)
	{
		scanf("%d", &n);
		for(i = 0; i < n; i++)
		{
			scanf("%s", &ss[i]);
			int len = strlen(ss[i]);
			infs[i].clear();
			infs[i].push_back(make_pair(ss[i][0], 1));
			int cnt = 0;
			for(j = 1; j < len; j++)
			{
				if(ss[i][j] == infs[i][cnt].first)
				{
					infs[i][cnt].second++;
				}
				else
				{
					infs[i].push_back(make_pair(ss[i][j], 1));
					cnt++;
				}
			}
		}
		
		printf("Case #%d: ", kase);
		
		if(!posble(n))
		{
			printf("Fegla Won\n");
		}
		else
		{
			int tot = 0;
			for(j = 0; j < infs[0].size(); j++)
			{
				int mn = 1000000000;
				for(k = 1; k < 102; k++)
				{
					int sum = 0;
					for(i = 0; i < n; i++)
					{
						sum += abs(k - infs[i][j].second);
					}
					if(sum < mn)
						mn = sum;
				}
				tot += mn;
			}
			printf("%d\n", tot);
		}

	}

	return 0;
}

