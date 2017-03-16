#include <iostream>
#include <fstream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <stdio.h>
#include <cmath>
#include <math.h>
#include <stdlib.h>

#include <algorithm>
#include <cstring>
#include <vector>
#include <string>
#include <sstream>
#include <queue>
using namespace std;
int N;
string simply(string a, vector<int>& num)
{
	string ans = "";
	char last = '0';
	int count = 0;
	for (int i=0;i<a.length();i++)
	{
		if (a[i]!=last)
		{
			ans += a[i];
			last = a[i];
			num.push_back(count);
			count = 0;
		}
		count++;
	}	
	num.push_back(count);
	return ans;
}
int main()
{
	int T;
	scanf("%d",&T);
	for (int i=1;i<=T;i++)
	{
		scanf("%d",&N);
		printf("Case #%d: ",i);
		string tmp, common="111", tmp_common;
		vector<vector<int>> words;
		bool flag = true;
		for (int j=0;j<N;j++)
		{
			cin>>tmp;
			vector<int> tmp_num;
			if (common == "111")
				common = simply(tmp, tmp_num);
			else
			{
				tmp_common = simply(tmp, tmp_num);
				if (tmp_common != common)
				{
					flag = false;
				}
			}
			words.push_back(tmp_num);
		}
		if (!flag)
			printf("Fegla Won\n");
		else
		{
			int pos = N / 2;
			int sum = 0;
			for (int j=1;j<words[0].size();j++)
			{
				vector<int> tmp_num;
				for (int k=0;k<N;k++)
				{
					tmp_num.push_back(words[k][j]);
				}
				sort(tmp_num.begin(), tmp_num.end());
				int mid = tmp_num[pos];
				for (int k=0;k<N;k++)
					sum += abs(tmp_num[k] - mid);

			}
			printf("%d\n", sum);

		}
	}
	return 0;
}