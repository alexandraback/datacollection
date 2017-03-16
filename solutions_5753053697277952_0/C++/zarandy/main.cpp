#include <cstdio>
#include <iostream>
#include <list>

using namespace std;

int t;
int n;
int p[26];
list<int> l[1001];
int m;
int x;
int s;

int main()
{
	ios_base::sync_with_stdio(false);
	cin >> t;
	for (int tt = 1; tt <= t; tt++)
	{
		cin >> n;
		m = 0;
		for (int i = 0; i < n; i++)
		{
			cin >> p[i];
			l[p[i]].push_back(i);
			m = max(m, p[i]);
			s += p[i];
		}
		cout << "Case #" << tt << ": ";
		while (m > 0)
		{
			x = l[m].back();
			cout << (char) ('A' + x);
			p[x]--;
			s--;
			l[m - 1].push_back(x);
			l[m].pop_back();
			if ((!l[m].empty()) && (s != 2))
			{
				x = l[m].back();
				cout << (char) ('A' + x);
				p[x]--;
				s--;
				l[m - 1].push_back(x);
				l[m].pop_back();
			}
			while (l[m].empty())
			{
				m--;
			}
			if (m > 0) cout << ' ';
		}
		cout << endl;
	}
	return 0;
}


