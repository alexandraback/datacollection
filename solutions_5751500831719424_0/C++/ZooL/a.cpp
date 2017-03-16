#if 1
#include <iostream>
#include <cstdio>
#include <sstream>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <functional>
#include <string>
#include <numeric>
#include <cstring>
#include <ctime>
#include <unordered_map>

using namespace std;
#define mp make_pair
#define X first
#define Y second
#define pb push_back

typedef pair<int, int> pii ;
typedef long long LL;
typedef long double LD;
typedef vector<int> vi;

const LL inf = 1e9;
const LD eps = 1e-9;


int main()
{
	freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(false);
	int T;
	cin >> T;
	for (int q = 0; q < T; q++)
	{
		int n;
		cin >> n;
		vector <string> a(n);
		vector <int> pos(n);
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
		}

		bool fl = true;
		LL ans = 0;


		while (fl)
		{
			if (pos[0] == a[0].size())
			{
				for (int i = 0; i < n; i++)
					if (pos[i] != a[i].size())
					{
						fl = false;
						break;
					}
				break;
			}

			char c = a[0][pos[0]];
			vector <int> cnt(n);
			for (int i = 0; i < n; i++)
			{
				cnt[i] = 0;
				while (pos[i] < a[i].size() && a[i][pos[i]] == c)
				{
					pos[i]++;
					cnt[i]++;
				}
			
				if (cnt[i] == 0)
				{
					fl = false;
					break;
				}
			}

			int maxCnt = *max_element(cnt.begin(), cnt.end());
			int minCnt = *min_element(cnt.begin(), cnt.end());

			LL tmp = (inf) * inf;
			for (int j = minCnt; j <= maxCnt; j++)
			{
				LL res = 0;
				for (int i = 0; i < n; i++)
				{
					res += abs(cnt[i] - j);
				}
				tmp = min(tmp, res);
			}
			ans += tmp;
		}

		cout << "Case #" << q + 1 << ": ";
		if (!fl)
			cout << "Fegla Won" << endl;
		else
			cout << ans << endl;

	}
    return 0;
}
#endif