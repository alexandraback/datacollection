#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

const int N = 105;
const int INF = (int) 1e9;

int n;
string s[N];
vector<pair<char, int> > comp[N];

vector<pair<char, int> > compress(string s)
{
	vector<pair<char, int> > res;
	int pos = 0;
	for (int i = 0; i <= s.length(); i++)
		if (i == s.length() || s[i] != s[pos])
		{
			res.push_back(make_pair(s[pos], i - pos));
			pos = i;
		}
	return res;	
}

void solve()
{
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> s[i];

	for (int i = 0; i < n; i++)
		comp[i] = compress(s[i]);

	int len = comp[0].size();
	for (int i = 0; i < n; i++)
		if (comp[i].size() != len)
		{
			puts("Fegla Won");
			return;
		}

	int answer = 0;

	for (int i = 0; i < len; i++)
	{
		char let = comp[0][i].first;
		vector<int> cnt;
		for (int j = 0; j < n; j++)
		{
			if (comp[j][i].first != let)
			{
				puts("Fegla Won");
				return;
			}
			cnt.push_back(comp[j][i].second);
		}

		sort(cnt.begin(), cnt.end());
		int cur_ans = INF;

		for (int j = cnt[0]; j <= cnt.back(); j++)
		{
			int cand = 0;
			for (int k = 0; k < cnt.size(); k++)
				cand += abs(cnt[k] - j);
			cur_ans = min(cur_ans, cand);	
		}

		answer += cur_ans;
	}

	printf("%d\n", answer);
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int t;
	scanf("%d", &t);

	for (int i = 0; i < t; i++)
	{
		printf("Case #%d: ", i + 1);
		solve();
		cerr << "done " << i + 1 << endl;
	}

	return 0;
}