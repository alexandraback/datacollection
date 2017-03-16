#include <iostream>

using namespace std;

int T, m[1300];

int main()
{
	cin >> T;
	for (int C = 1; C <= T; C++)
	{
		int n;
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			cin >> m[i];
		}
		int ans = 0, md = 0;
		for (int i = 1; i < n; i++)
		{
			ans += max(0, m[i-1] - m[i]);
			md = max(md, m[i-1] - m[i]);
		}
		int ans2 = 0;
		for (int i = 0; i < n-1; i++)
		{
			ans2 += min(md, m[i]);
		}
		cout << "Case #" << C << ": " << ans << ' ' << ans2 << '\n';
	}

	return 0;
}

