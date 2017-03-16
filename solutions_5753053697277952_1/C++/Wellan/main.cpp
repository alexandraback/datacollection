#include <algorithm>
#include <array>
#include <chrono>
#include <climits>
#include <cmath>
#include <cstdlib>
#include <deque>
#include <forward_list>
#include <functional>
#include <iostream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <regex>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <valarray>
#include <vector>
#include <cassert>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);

	int T;
	cin >> T;

	for (int t = 0; t < T; t++)
	{
		int N;
		cin >> N;
		vector<int> senators(N);
		int count = 0;
		for (int i = 0; i < N; i++)
		{
			cin >> senators[i];
			count += senators[i];
		}

		cout << "Case #" << t + 1 << ':';
		while (count > 0)
		{
			auto maxIt = max_element(senators.begin(), senators.end());
			int maxIdx = distance(senators.begin(), maxIt);
			int maxVal = *maxIt;
			int nbMaxVal = std::count(senators.begin(), senators.end(), maxVal);
			if (nbMaxVal != 2)
			{
				cout << ' ' << char(maxIdx + 'A');
				senators[maxIdx]--;
				count--;
			}
			else
			{
				int otherMaxIdx = -1;
				for (int i = maxIdx + 1; i < N; i++)
				{
					if (senators[i] == maxVal)
					{
						otherMaxIdx = i;
						break;
					}
				}
				assert(otherMaxIdx >= 0);
				cout << ' ' << char(maxIdx + 'A') << char(otherMaxIdx + 'A');
				senators[maxIdx]--;
				senators[otherMaxIdx]--;
				count -= 2;
			}
		}
		cout << endl;
	}

	return 0;
}
