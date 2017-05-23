/*The Repeater*/

#include<cstdio>
#include<iostream>
#include<string>
#include<vector>
#include<cstdlib>
#include<algorithm>

using namespace std;

struct node
{
	char c;
	int count;
};

vector<int> charcounts;
vector<vector<struct node> > compressed_strings;

int main()
{
	int cost, count, i, j, k, length, mincost, N, t, T, totalcost;
	string str;
	struct node newnode;
	freopen("A-small-attempt1.in", "r", stdin);
	freopen("A.out", "w", stdout);
	cin >> T;
	for (t = 1; t <= T; t++)
	{
		compressed_strings.clear();
		cin >> N;
		compressed_strings.resize(N);
		for (i = 0; i < N; i++)
		{
			cin >> str;
			length = str.length();
			for (j = 0; j < length; j++)
			{
				count = 1;
				while ((j < length - 1) && (str[j] == str[j + 1]))
				{
					count++;
					j++;
				}
				newnode.c = str[j];
				newnode.count = count;
				compressed_strings[i].push_back(newnode);
			}
		}
		length = compressed_strings[0].size();
		for (i = 1; i < N; i++)
		{
			if (compressed_strings[i].size() != compressed_strings[0].size())
				break;
			for (j = 0; j < length; j++)
				if (compressed_strings[i][j].c != compressed_strings[0][j].c)
					break;
			if (j < length)
				break;
		}
		if (i < N)
			printf("Case #%d: Fegla Won\n", t);
		else
		{
			totalcost = 0;
			for (i = 0; i < length; i++)
			{
				charcounts.clear();
				charcounts.resize(N);
				for (j = 0; j < N; j++)
					charcounts[j] = compressed_strings[j][i].count;
				sort(charcounts.begin(), charcounts.end());
				mincost = -1;
				for (j = 0; j < N; j++)
				{
					cost = 0;
					for (k = 0; k < N; k++)
						cost += abs(charcounts[j] - charcounts[k]);
					if ((mincost == -1) || (mincost > cost))
						mincost = cost;
				}
				totalcost += mincost;
			}
			printf("Case #%d: %d\n", t, totalcost);
		}
	}
	return 0;
}