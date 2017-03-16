#include <cassert>
#include <cstring>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <set>
#include <string>
using namespace std;
#define db(v) cout << #v << " = " << (v) << endl;
typedef long long ll;

int T, N;

vector< vector<int> > A;
string processStr(const string& s)
{
	vector<int> vec;
	
	char prev = 'Z';
	string ns;
	for (int i = 0; i < s.length(); ++i)
	{
		if (s[i] == prev)
			++vec.back();
		else
		{
			prev = s[i];
			ns += s[i];
			vec.push_back(1);
		}
	}
	A.push_back(vec);
	return ns;
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	cin >> T;
	for (int i = 0; i < T; ++i)
	{
		A.clear();
		bool ans = true;

		cin >> N;
		string oldPattern; cin >> oldPattern;
		string newPattern = processStr(oldPattern);
		for (int j = 1; j < N; ++j)
		{
			string s; cin >> s;
			string ns = processStr(s);
			if (ns != newPattern) ans = false;
		}

		int cnt = 0;
		for (size_t id = 0; id < newPattern.length(); ++id)
		{
			int best = 1e9;
			for (size_t k = 0; k < N; ++k)
			{
				int pos = A[k][id];
				int cur = 0;
				for (int j = 0; j < N; ++j)
					cur += abs(A[j][id] - pos);
				best = min(best, cur);
			}
			cnt += best;
		}

		if (ans)
			printf("Case #%d: %d\n", i + 1, cnt);
		else
			printf("Case #%d: Fegla won\n", i + 1);
	}

	return 0;
}
