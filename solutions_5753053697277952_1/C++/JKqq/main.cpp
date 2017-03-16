#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;

#define ll long long
#define pii pair<ll, ll>
#define endl "\n"
#define mp make_pair
#define pll pair<ll,ll>

#include <fstream>
ifstream in("task.in");
ofstream out("task.out");

#define cin in
#define cout out
/**/



int main()
{
	ios_base::sync_with_stdio(0);

	int numTests;
	cin >> numTests;
	int ttt = 0;
	while (numTests--)
	{
		++ttt;
		int n;
		cin >> n;
		vector<pair<int, char>> a(n);
		for (int i = 0; i < n; ++i)
		{
			cin >> a[i].first;
			a[i].second = 'A' + i;
		}
		string output;
		while (true)
		{
			sort(a.rbegin(), a.rend());

			int mx = a[0].first;
			if (mx == 0)
				break;

			int cnt = 0;
			for (int i = 0; i < n; ++i)
				if (a[i].first == mx)
					++cnt;
			if (cnt %2 ==  1)
			{
				output.push_back(a[0].second);
				output.push_back(' ');
				--a[0].first;
			}
			else
			{
				output.push_back(a[0].second);
				output.push_back(a[1].second);
				output.push_back(' ');
				--a[0].first;
				--a[1].first;
			}
		}
		cout << "Case #"<<ttt<<": "<< output << endl;
	}


	return 0;
}