#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int T;
	cin >> T;

	for (int t = 1; t <= T; t++)
	{
		int N;
		cin >> N;

		vector<int> P(N);
		for (int i = 0; i < N; i++)
		{
			cin >> P[i];
		}

		cout << "Case #" << t << ":";

		for (;;)
		{
			cout << " ";
			auto iter = max_element(P.begin(), P.end());
			if (*iter == 0)
			{
				break;
			}
			int i = iter - P.begin();
			cout << (char)(i + 'A');
			int r = *iter;
			(*iter)--;
			if (r == 1)
			{
				if (count(P.begin(), P.end(), 1) % 2 == 0)
				{
					continue;
				}
			}
			for (i++; i < N; i++)
			{
				if (r == P[i])
				{
					cout << (char)(i + 'A');
					P[i]--;
					break;
				}
			}
		}

		cout << endl;
	}
}