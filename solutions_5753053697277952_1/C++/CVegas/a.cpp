#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	int T;
	cin >> T;
	for (int T0 = 1; T0 <= T; ++T0)
	{
		cout << "Case #" << T0 << ":";
		int n, tot;
		cin >> n;
		int count[26];
		tot = 0;
		for (int i = 0; i < n; ++i)
		{
			cin >> count[i];
			tot += count[i];
		}
			
		cout << " ";
		while (tot)
		{
			int m = 0, k;
			for (int i = 0; i < n; ++i)
			{
				if (count[i] > m)
				{
					m = count[i];
					k = i;
				}
			}
			cout << (char)('A' + k);
			if (tot & 1) cout << " ";
			--count[k];
			--tot;
		}
		cout << endl;
	}
}