#include <stdio.h>
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
struct charNum
{
	char c;
	int num;
};

int solve(vector<vector<charNum>> pairCharNum)
{
	int ans = 0;
	for (int j = 0; j < pairCharNum[0].size(); ++j) {
		vector<int> totalnum;
		for (int i = 0; i < pairCharNum.size(); ++i) {
			totalnum.push_back(pairCharNum[i][j].num);
		}
		sort(totalnum.begin(), totalnum.end());
		int min_ans = 1000000;
		for (int mid = totalnum[0]; mid <= *(totalnum.end()-1); ++mid) {
			int ans = 0;
			for (int i = 0; i < pairCharNum.size(); ++i) {
				ans += abs(pairCharNum[i][j].num - mid);
			}
			min_ans = min(min_ans, ans);
		}
		ans += min_ans;
	}
	return ans;
}

int main()
{
	int point[200];
	char current[200];
	freopen("A-small-attempt0.in","r",stdin);
	freopen("A-small-attempt0.out","w",stdout);
	int T,N;
	scanf("%d",&T);
	for (int t = 1; t <= T; ++t)
	{
		string str[200];
		string prin[200];
		vector<vector<charNum>> pairCharNum;
		scanf("%d",&N);
		pairCharNum.resize(N);
		for (int i = 0; i < N; ++i)
		{
			cin >> str[i];
		}
		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < str[i].length(); ++j)
			{
				if (j == 0 || str[i][j] != str[i][j-1])
				{
					prin[i].push_back(str[i][j]);
				}
			}
		}
		bool flag = true;
		for (int i = 1; i < N; ++i)
		{
			if (prin[i] != prin[0])
			{
				flag = false;
			}
		}
		if (!flag)
		{
			printf("Case #%d: Fegla Won\n",t);
		}
		else
		{
			for (int i = 0; i < N; ++i)
			{
				int num = 0;
				char current = 0;
				for (int j = 0; j < str[i].length(); ++j) {
					if (str[i][j] != current) {
						if (num > 0) {
							charNum s;
							s.c = current;
							s.num = num;
							pairCharNum[i].push_back(s);
						}
						num = 1;
						current = str[i][j];
					} else {
						++num;
					}
				}
				if (num > 0) {
					charNum s;
					s.c = current;
					s.num = num;
					pairCharNum[i].push_back(s);
				}
			}
			int ans = solve(pairCharNum);
			printf("Case #%d: %d\n",t,ans);
		}
	}
	return 0;
}