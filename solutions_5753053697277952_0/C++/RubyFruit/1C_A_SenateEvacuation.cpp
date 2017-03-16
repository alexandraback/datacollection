#include <iostream>

using namespace std;

int main(void)
{
	int cnt[26];
	int T;
	cin >> T;
	for (int tc = 1; tc <= T; ++tc)
	{
		int N;
		cin >> N;
		int sum = 0;
		for (int i = 0; i < N; ++i)
		{
			cin >> cnt[i];
			sum += cnt[i];
		}
		
		cout << "Case #" << tc << ":";

		bool one = false;
		do
		{
			if (sum == 2)
			{
				cout << " AB\n";
				break;
			}

			int max = 0;
			int maxIdx = 0;
			for (int i = N - 1; i >= 0; --i)
			{
				if (cnt[i] > max)
				{
					max = cnt[i];
					maxIdx = i;
				}
			}

			if (one == false)
			{
				cout << " ";
			}
			cout << static_cast<char>('A' + maxIdx);
			one = !one;

			cnt[maxIdx]--;
			sum--;
		} while (sum > 0);
		// °è»ê
	}
	return 0;
}
