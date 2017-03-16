#include <algorithm>
#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> pi;
typedef vector<pi> vp;

void solve()
{
	int n = 0;
	cin >> n;

	int total = 0;
	vp p(n);
	for (int i = 0; i < n; ++i)
	{
		int curr;
		cin >> curr;
		p[i].first = curr;
		p[i].second = i;
		total += curr;
	}

	while (total)
	{
		// for (int i = 0; i < n; ++i)
		// 	cout << p[i].first << " " << p[i].second << endl;
		sort(p.begin(), p.end(), greater<pi>());
		// for (int i = 0; i < n; ++i)
		// 	cout << p[i].first << " " << p[i].second << endl;
		if (total == 3 && p[0].first == 1)
		{
			cout << (char)(p[0].second + 'A') << " ";
			--p[0].first;
			--total;
		}
		else
		{
			cout << (char)(p[0].second + 'A') << (char)(p[1].second + 'A') << " ";
			--p[0].first;
			--p[1].first;
			total -= 2;
		}
	}
}

int main()
{
	int t = 0;
	cin >> t;
	for (int i = 0; i < t; ++i)
	{
		cout << "Case #" << i + 1 << ": ";
		solve();
		cout << endl;
	}
	return 0;
}
