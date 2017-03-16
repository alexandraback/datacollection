#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	
	freopen("d:\\1.in", "r", stdin);
	freopen("d:\\1.txt", "w", stdout);
	
	int T;
	cin>>T;
	for(int kase = 1; kase <= T; ++kase)
	{
		vector<string> str;
		int n;
		cin>>n;
		for(int i = 0; i < n; ++i)
		{
			string tmp;
			cin>>tmp;
			str.push_back(tmp);
		}
		
		vector<char> ch[105];
		vector<int> cnt[105];
		
		for(int i = 0; i < n; ++i)
		{
			string cur = str[i];
			char last = cur[0];
			int lastcnt = 1;
			for(int j = 1; j < cur.size(); ++j)
			{
				if(cur[j] != last)
				{
					ch[i].push_back(last);
					cnt[i].push_back(lastcnt);
					last = cur[j];
					lastcnt = 1;
				}
				else
				{
					lastcnt++;
				}
			}
			ch[i].push_back(last);
			cnt[i].push_back(lastcnt);
		}
		
		bool ok = true;
		for(int i = 1; i < n; ++i)
		{
			if(ch[i].size() != ch[0].size())
			{
				ok = false;
				break;
			}
			for(int j = 0; j < ch[0].size(); ++j)
			{
				if(ch[i][j] != ch[0][j])
				{
					ok = false;
					break;
				}
			}
		}
		
		int ans = 0;
		if(ok)
		{
			for(int i = 0; i < ch[0].size(); ++i)
			{
				vector<int> v;
				for(int j = 0; j < n; ++j)
					v.push_back(cnt[j][i]);
				sort(v.begin(), v.end());
				int mid = v.size() / 2;
				for(int i = 0; i < v.size(); ++i)
					ans += abs(v[i] - v[mid]);
			}
		}
		
		cout<<"Case #"<<kase<<": ";
		if(ok)
			cout<<ans<<endl;
		else
			cout<<"Fegla Won"<<endl;
	}
	
	return 0;
}
