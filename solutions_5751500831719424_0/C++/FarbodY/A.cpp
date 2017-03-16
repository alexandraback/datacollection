#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
const int MAXN = 105;
vector<pair<char, int> > V[MAXN];
int main()
{
	int T;
	cin >> T;
	for(int t = 0;t < T;t ++)
	{
		int n;
		cin >> n;
		for(int i = 0;i < n;i ++)
		{
			V[i].clear();
			string s;
			cin >> s;
			for(int j = 0;j < (int)s.length();j ++)
			{
				int p = j , cnt = 0;
				while(p < (int)s.length() && s[j] == s[p]) p ++ , cnt ++;
				V[i].push_back(pair<char, int>(s[j] , cnt));
				j = p - 1;
			}
		}
		int ans = 0;

		for(int i = 0;i < n;i ++)
			for(int j = i + 1;j < n;j ++)
				if(V[i].size() != V[j].size())
				{
					ans = 1e9;
					break;
				}
		
		if(ans == 1e9)
		{
			cout << "Case #" << t + 1 << ": " << "Fegla Won" << endl;
			continue;
		}
		
		for(int j = 0;j < (int)V[0].size();j ++)
		{
			for(int i = 0;i < n;i ++)
				for(int p = i + 1;p < n;p ++)
					if(V[i][j].first != V[p][j].first)
					{
						ans = 1e9;
						break;
					}

			if(ans == 1e9)
				break;

			int mx = 0;
			for(int i = 0;i < n;i ++)
				mx = max(mx , V[i][j].second);

			int mn = 1e9;
		
			for(int p = 1;p <= mx;p ++)
			{
				int t = 0;
				for(int i = 0;i < n;i ++)
					t += abs(p - V[i][j].second);
				mn = min(mn , t);
			}
		//	if(t == 1)
		//	cout << mn << endl;
			ans += mn;
		}
		if(ans == 1e9)
		{
			cout << "Case #" << t + 1 << ": " << "Fegla Won" << endl;
			continue;
		}

		cout << "Case #" << t + 1 << ": " << ans << endl;
	}

	return 0;
}
