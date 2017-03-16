#include<iostream>
#include<algorithm>
#include<string>
#include<vector>

using namespace std;

int n, m, a[100000], b[100000], maxi, mini, k, l, ans, cnt;
string s;
vector<string> str;
vector<pair <char, int> > datas[100];
int main()
{
	//freopen("input.txt","r",stdin);
	//freopen("A_big_good.out","w",stdout);
	int test = 0;
	scanf("%d",&test);
	for(int t=0; t<test; t++)
	{
		scanf("%d",&n);
		for(int i=0; i<n; i++)
		{
			cin >> s;
			str.push_back(s);
		}
		
		for(int i=0; i<n; i++)
		{
			cnt = 1;
			for(int j=0; j<str[i].size(); j++)
			{
				if(j == str[i].size() - 1 || str[i][j+1] != str[i][j])
				{
					datas[i].push_back(make_pair(str[i][j], cnt));
					cnt = 1;
				}
				else
					cnt++;
			}
		}
		int ans = 0;
		bool win = true;
		for(int i=0; i<n; i++)
		{
			if(datas[i].size() != datas[0].size())
			{
				win = false;
				break;
			}
		}
		if(win)
			for(int i=0; i<datas[0].size(); i++)
			{
				for(int j=0; j<n; j++)
				{
					if(datas[j][i].first != datas[0][i].first)
					{
						win = false;
						break;
					}
				}
			}
		if(!win)
		{
			printf("Case #%d: Fegla Won\n",t+1);
		}
		else
		{
			for(int i=0; i<datas[0].size(); i++)
			{
				int mini = 100000000;
				for(int better = 1; better <= 100; better++)
				{
					int cur_sum = 0;
					for(int j=0; j<n; j++)
					{
						cur_sum += abs(datas[j][i].second - better);
					}
					mini = min(mini, cur_sum);
				}
				ans += mini;
			}
			printf("Case #%d: %d\n",t+1,ans);
		}
		//clear
		str.clear();
		for(int i=0; i<n; i++)
		{
			datas[i].clear();
		}
	}







return 0;
}