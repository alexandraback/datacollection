
#include <bits/stdc++.h>
using namespace std;

bool compare(pair<long long int, long long int> a, pair<long long int, long long int> b)
{
	return (a.first < b.first || (a.first == b.first && a.second < b.second));
}

int main()
{
	int T;
	long long int m[1005];
	vector <pair<long long int, long long int> > pos;
	cin >> T;
	for (int t = 1; t <= T; ++t)
	{
		pos.clear();
		long long int b, n, mn = 100000;
		cin >> b >> n;
		for(int i = 1; i <= b; ++i)
		{
			cin >> m[i];
			mn = min(mn, m[i]);
		}
		long long int left = n - 1;
		long long int ti = 0;
		while(left >= b)
		{
			int mncut = left / b;
			ti += mn * mncut;
			int cut = 0;
			for(int i = 1; i <= b; ++i)
			{
				cut += (ti / m[i]);
			}
			//cout << cut << " "; return 0;
			left = (n - 1 - cut);
		}
		for(int i = 1; i <= b; ++i)
		{
			pos.push_back(make_pair(m[i] * (ti / m[i]) - ti, i));
		}
		sort(pos.begin(), pos.end(), compare);
		printf("Case #%d: %lld\n", t, pos[left].second);
	}
	return 0;
}

