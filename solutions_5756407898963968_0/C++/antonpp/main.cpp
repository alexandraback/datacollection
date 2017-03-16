#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <iterator>

using namespace std;

const int N = 4;

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int t;
	cin >> t;

	set<int> m1, m2;
	vector<int> m3;

	for (int k = 0; k < t; ++k)
	{
		int x;
		int num;
		m1.clear();
		m2.clear();
		m3.clear();
		cin >> x;
		--x;
		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < N; ++j)
			{
				cin >> num;
				if (i == x)
					m1.insert(num);
			}
		}
		cin >> x;
		--x;
		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < N; ++j)
			{
				cin >> num;
				if (i == x)
					m2.insert(num);
			}
		}
		set_intersection(m1.begin(), m1.end(), m2.begin(), m2.end(),  back_inserter(m3));

		printf("Case #%i: ", k + 1);
		if (m3.empty())
			printf("Volunteer cheated!\n");
		if (m3.size() == 1)
			printf("%i\n", (*m3.begin()));
		if (m3.size() > 1)
			printf("Bad magician!\n");
	}


	return 0;
}
