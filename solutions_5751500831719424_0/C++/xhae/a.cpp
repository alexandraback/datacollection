#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main(void)
{
	int T;
	cin >> T;
	for(int kase = 1; kase <= T; kase++)
	{
		cout << "Case #" << kase << ": ";
		int n;
		string inp[100], uniqued;
		cin >> n;
		bool isAble = true;
		for(int i = 0; i < n; i++) 
		{
			cin >> inp[i];
			if(i == 0)
			{
				uniqued = inp[i];
				uniqued.erase(unique(uniqued.begin(), uniqued.end()), uniqued.end());
			}
			else
			{
				string cur = inp[i];
				cur.erase(unique(cur.begin(), cur.end()), cur.end());
				if(uniqued != cur)
					isAble = false;
			}
		}

		if(isAble == false) cout <<"Fegla Won" << endl;
		else
		{
			vector <int> cnt[100];
			for(int i = 0; i < n; i++)
			{
				int ind = 0;
				for(int j = 0; j < inp[i].size(); )
				{
					int ind = j;
					while(ind < inp[i].size() && inp[i][ind] == inp[i][j]) ind++;
					cnt[i].push_back(ind - j);
					j = ind;
				}
			}

			int ans = 0;
			for(int i = 0; i < cnt[0].size(); i++)
			{
				int curAns = 9999999;
				for(int j = 1; j <= 100; j++)
				{
					int curCnt = 0;
					for(int k = 0; k < n; k++)
						curCnt += abs(j - cnt[k][i]);						
					curAns = min(curAns, curCnt);
				}

				ans += curAns;
			}

			cout << ans << endl;
		}
	}

	return 0;
}
