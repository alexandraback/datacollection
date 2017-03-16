#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <iterator>

int main()
{
	int T;
	std::cin >> T;
	for (int x = 1; x <= T; ++x)
	{
		int B, N;
		std::cin >> B >> N;
		std::vector<int> M(B), m(B);
		std::copy_n(std::istream_iterator<int>(std::cin), B, M.begin());

		double person_per_min(0);
		for (int k = 0; k < B; ++k)
		{
			person_per_min += 1. / M[k];
		}
		long long min = static_cast<long long >((N - B)/person_per_min);
		for (int k = 0; k < B; ++k)
		{
			N -= min / M[k];
			m[k] = min % M[k];
		}
		int y;
		while (N--)
		{
			int k = std::max_element(m.cbegin(), m.cend()) - m.cbegin();
			if (N == 0)
				y = k;
			m[k] -= M[k];
		}



		std::cout << "Case #" << x << ": " << y << "\n";
	}
}