#include <iostream>
#include <string>
#include <cmath>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <iterator>
#include <functional>
#include <vector>
#include <algorithm>

using namespace std;

void solve()
{
	int n; cin >> n;
	vector<pair<int, char> > a(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i].first;
		a[i].second = 'A' + i;
	}
	
	sort(a.begin(), a.end());

	if (a.size() > 2)
	{
		while (a[n - 1].first > 1)
		{
			while (a[n - 1].first >= a[n - 2].first)
			{
				if (a[n - 1].first > 1)
				{
					cout << a[n - 1].second << " ";
					--a[n - 1].first;
				}
				else
				{
					break;
				}
			}
			sort(a.begin(), a.end());
		}

		while (a.size() > 3)
		{
			cout << a[n - 1].second << a[n - 2].second << " ";
			a.pop_back(); a.pop_back();
			n -= 2;
		}

		if (a.size() == 3)
		{
			cout << a[n - 1].second << " ";
			a.pop_back();
			--n;
		}

		cout << a[n - 1].second << a[n - 2].second << endl;;
		a.pop_back(); a.pop_back();
	}
	else
	{
		while (a.back().first)
		{
			cout << a[0].second << a[1].second << " ";
			a.back().first--;
		}
		cout << endl;
	}
}

int main()
{
	//freopen("i:/input.txt", "rt", stdin);
	//freopen("i:/input.out", "wt", stdout);
	int T; cin >> T;
	for (int t = 1; t <= T; ++t)
	{
		cout << "Case #" << t << ": ";
		solve();
	}
	return 0;
}