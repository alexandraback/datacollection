#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

int main()
{
	int T;
	std::cin >> T;
	for (int t = 1 ; t <= T ; ++t)
	{
        std::vector<int> v(16);
        for (int c = 0 ; c < 2 ; ++c)
        {
            int r;
            std::cin >> r;
            for (int i = 0 ; i < 4 ; ++i)
                for (int j = 0 ; j < 4 ; ++j)
                {
                    int k;
                    std::cin >> k;
                    if (i == r - 1)
                    {
                        ++v[k - 1];
                    }
                }
        }

        int m = -1;
        for (int i = 0 ; i < 16 ; ++i)
            if (v[i] == 2)
            {
                if (m == -1)
                    m = i;
                else
                    m = -2;
            }
        std::cout << "Case #" << t << ": ";
        if (m == -1)
            std::cout << "Volunteer cheated!\n";
        else if (m == -2)
            std::cout << "Bad magician!\n";
        else
            std::cout << m + 1 << "\n";
	}
	return 0;
}

