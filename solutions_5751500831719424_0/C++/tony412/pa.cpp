#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <utility>

using std::vector;
using std::pair;
using std::make_pair;


int main()
{
	int T, C;
	int n, m, cnt, i, j, k, num[100], sum, min, ans;
	char ch;
	char buf[128];
	bool flag;
	
	scanf("%d", &T);
	for (C = 1; C <= T; C++)
	{
		vector<pair<char, int>> arr[100];
		scanf("%d", &n);

		for (i = 0; i < n; i++)
		{
			scanf("%s", buf);
			cnt = 1;
			for (j = 1; buf[j]; j++)
			{
				if (buf[j] != buf[j-1])
				{
					arr[i].push_back(make_pair(buf[j-1], cnt));
					cnt = 1;
				}
				else
					cnt++;
			}
			arr[i].push_back(make_pair(buf[j-1], cnt));
		}

		m = arr[0].size();
		ans = 0;
		for (j = 0; j < m; j++)
		{
			flag = true;
			ch = arr[0][j].first;
			min = 1000000;
			for (k = 1; k <= 100; k++)
			{
				sum = 0;
				for (i = 0; i < n; i++)
				{
					if (arr[i].size() != m || arr[i][j].first != ch)
					{
						flag = false;
						break;
					}
					sum += abs(arr[i][j].second - k);
				}
				if (sum < min) min = sum;
				if (!flag) break;
			}
			ans += min;
			if (!flag) break;
		} 
		
		printf("Case #%d: ", C);
		if (flag) printf("%d\n", ans);
		else puts("Fegla Won");
	}
	return 0;
}
