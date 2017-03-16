#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
	int T;
	std::cin >> T;
	for (int x = 1; x <= T; ++x)
	{
		int N;
		std::cin >> N;
		std::vector<int> M(N);
		int y = 0, z = 0, m = 0;
		for (int k = 0; k < N; ++k)
		{
			std::cin >> M[k];
			if (k > 0)
			{
				int d = M[k - 1] - M[k];
				m = std::max(d, m);
				if (d > 0)
					y += M[k - 1] - M[k];				
			}
		}
		for (int k = 0; k < N - 1; ++k)
		{
			z += std::min(M[k], m);
		}

		std::cout << "Case #" << x << ": " << y << " " << z << "\n";
	}
}