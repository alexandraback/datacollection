#include<cstdio>
#include<cstring>
#include<algorithm>
#include<string>
#include<queue>
using namespace std;

int n;
priority_queue<pair<int, int> > q;
int num[26];

int main()
{
	freopen("A-large.in", "r", stdin);
	freopen("A-large.out", "w", stdout);
	int t;
	scanf("%d", &t);
	for (int ii = 1; ii <= t; ii++)
	{
		scanf("%d", &n);
		pair<int, int> temp;
		int sum = 0;
		for (int i = 0; i < n; i++)
		{
			int x;
			scanf("%d", &x);
			temp.first = x;
			temp.second = i;
			sum += x;
			q.push(temp);
			num[i] = x;
		}
		printf("Case #%d:", ii);
		while (!q.empty())
		{
			temp = q.top();
			q.pop();
			if (temp.first * 2 > sum) printf("%d\n", ii);
			int x = temp.second + 'A';
			int y = 'a';
			temp.first--;
			num[temp.second] --;
			sum--;
			pair<int, int> newd;
			if (!q.empty() && sum != 2)
			{
				newd = q.top();
				q.pop();
				if (temp.first <= newd.first)
				{
					y = newd.second + 'A';
					newd.first--;
					num[newd.second] --;
					sum--;
					
				}
				else if (temp.first)
				{
					y = temp.second + 'A';
					temp.first--;
					num[temp.second] --;
					sum--;
				}
				if (newd.first)
				{
					q.push(newd);
				}
			}
			else if (temp.first && sum != 2)
			{
				y = newd.second + 'A';
				temp.first--;
				num[temp.second] --;
				sum--;
			}
			if (temp.first)
			{
				q.push(temp);
			}
			printf(" %c", x);
			if (y != 'a') printf("%c", y);
		}
		for (int i = 0; i < n; i++)
		{
			if (num[i]) printf(" %d\n", ii);
		}
		printf("\n");
	}
	return 0;
}