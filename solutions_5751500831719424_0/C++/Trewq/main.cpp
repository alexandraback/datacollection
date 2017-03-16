#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<list>
#include<map>
#include<set>
#include<memory.h>
#include<ctime>
#include<unordered_set>
using namespace std;
char cc[100];
int countcc;
int cnt[100][100];
int main()
{
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("output.txt", "w", stdout);
	int tc;
	scanf("%d", &tc);
	for (int cs = 1; cs <= tc; cs++)
	{
		int n;
		string s;
		bool err = 0;
		int cntp;
		scanf("%d", &n);
		countcc = 0;
		memset(cnt, 0, sizeof(cnt));
		for (int i = 0; i < n; i++)
		{
			cin >> s;
			if (i == 0)
			{
				for (int j = 0; j < s.length(); j++)
				{
					if (j == 0 || s[j] != s[j - 1])
						cc[countcc++] = s[j];
					cnt[countcc - 1][i]++;
				}
			}
			else
			{
				cntp = 0;
				for (int j = 0; j < s.length(); j++)
				{
					if (s[j] == cc[cntp])
					{
						cnt[cntp][i]++;
					}
					else if (cnt[cntp][i]>0 && cntp < countcc&&s[j] == cc[cntp + 1])
					{
						cntp++;
						cnt[cntp][i]++;
					}
					else
					{
						err = 1;
					}
				}
				if (cntp != countcc - 1)
				{
					err = 1;
				}
			}
		}
		printf("Case #%d: ", cs);
		if (!err)
		{
			int ss = 0;
			for (int i = 0; i < countcc; i++)
			{
				sort(cnt[i], cnt[i] + n);
				for (int j = 0; j < n; j++)
					ss += abs(cnt[i][j] - cnt[i][n / 2]);
			}
			cout << ss << endl;
		}
		else
			cout << "Fegla Won" << endl;
	}
	return 0;
}