#include <bits/stdc++.h>
using namespace std;

#define endl ('\n')

const int
	MAXN = 1 << 10;

int N;
vector< char > T[MAXN];
string S[MAXN];
int cnt[MAXN];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int testCount;
	cin >> testCount;
	for (int test = 1; test <= testCount; ++test)
	{
		cout << "Case #" << test << ": ";
		
		
		cin >> N;
		for (int i = 0; i < N; ++i)
		{
			cin >> S[i];
			
			T[i].clear();
			for (char c : S[i])
			{
				if (T[i].empty() || T[i].back() != c)
					T[i].push_back(c);
			}
		}
		
		int C = unique(T, T + N) - T;
		
		if (C > 1) {
			cout << "Fegla Won" << endl;
			continue ;
		}
		
		int ans = 0;
		while (!S[0].empty())
		{
			char target = S[0][0];
			for (int i = 0; i < N; ++i)
			{
				cnt[i] = 0;
				while (!S[i].empty() && S[i][0] == target)
				{
					cnt[i]++;
					S[i].erase(S[i].begin());
				}
				
				assert(cnt[i] > 0);
			}
			
			sort(cnt, cnt + N);
			
			int t = cnt[N/2];
			for (int i = 0; i < N; ++i)
				ans += abs(cnt[i] - t);
		}
		
		cout << ans << endl;
	}
	
	return 0;
}