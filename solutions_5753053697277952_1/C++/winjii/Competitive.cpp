#include <bits/stdc++.h>
using namespace std;

#define int long long

vector< vector<char> > Solve(int N, int P[26])
{
	vector< vector<char> > ans;
	ans.reserve(1000);
	while (true)
	{
		int ma = 0;
		for (int i = 0; i < N; i++) ma = max(ma, P[i]);
		if (ma == 0) break;
		int cntMax = 0;
		for (int i = 0; i < N; i++) cntMax += (P[i] == ma);
		int lim = (cntMax == 2) ? 2 : 1, latte = 0;
		ans.push_back(vector<char>());
		for (int i = 0; i < N; i++)
		{
			if (P[i] != ma) continue;
			if (++latte > lim) break;
			P[i]--;
			ans.back().push_back('A' + i);
		}
	}
	return ans;
}

void Output(int t, vector< vector<char> > &ans)
{
	printf("Case #%lld:", t);
	for (int i = 0; i < ans.size(); i++)
	{
		printf(" ");
		for (int j = 0; j < ans[i].size(); j++)
		{
			printf("%c", ans[i][j]);
		}
	}
	puts("");
}

signed main()
{
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++)
	{
		int N, P[26];
		cin >> N;
		for (int i = 0; i < N; i++) cin >> P[i];
		Output(t, Solve(N, P));
	}
	return 0;
}