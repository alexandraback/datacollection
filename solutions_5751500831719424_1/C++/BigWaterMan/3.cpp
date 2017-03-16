#pragma warning(disable:4996)
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<time.h>
#include<iostream>
#include<string>
using namespace std;
int c[200][200];
string s[200];
int main()
{
	freopen("A-large (1).in", "r", stdin);
	freopen("output.txt", "w", stdout);
	int T;
	scanf("%d", &T);
	for (int z = 0; z < T; ++z)
	{
		printf("Case #%d: ", z + 1);
		string st;
		int n;
		cin >> n;
		cin >> st;
		memset(c, 0, sizeof(c));
		memset(s, 0, sizeof(s));
		int cnt = 0;
		bool flag = true;
		for (int i = 0; i < st.length(); ++i)
		{
		
			if (i == 0 || st[i] != st[i - 1])
			{
				s[0] += st[i];
				c[++cnt][0] = 1;
			}
			else c[cnt][0]++;
		}
		for (int j = 1; j < n; ++j)
		{
			cin >> st;
			cnt = 0;
			for (int i = 0; i < st.length(); ++i)
			{

				if (i == 0 || st[i] != st[i - 1])
				{
					s[j] += st[i];
					c[++cnt][j] = 1;
				}
				else c[cnt][j]++;
			}
			if (s[j] != s[0]) flag = false;
		}
		if (flag == false)
		{
			cout << "Fegla Won"<<endl;
			continue;
		}
		int sum = 0;
		for (int i = 1; i <= cnt; ++i)
		{
			sort(c[i], c[i] + n);
			for (int j = 0; j < n; ++j)
				sum += abs(c[i][j] - c[i][n / 2]);
		}
		printf("%d\n",sum);
	}
}