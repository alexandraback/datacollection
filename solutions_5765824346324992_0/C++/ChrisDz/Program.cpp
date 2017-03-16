#include <algorithm>
#include <cmath>
#include <iostream>
#include <limits>
#include <stdint.h>
#include <string>
#include <vector>

int compute(uint64_t B, uint64_t N, const std::vector<uint64_t>& M)
{
    if (N <= B)
    {
        return N;
    }

    uint64_t min = 1;
    uint64_t max = 1000000000000000ull;
    uint64_t current = (max - min) / 2 + min;

    while (true)
    {
        uint64_t totalPrev = B;
        uint64_t totalNow = B;

        for (size_t k = 0; k < M.size(); k++)
        {
            totalPrev += (current - 1) / M[k];
            totalNow += current / M[k];
        }

        if (totalPrev < N && totalNow >= N)
        {
            for (size_t k = 0; k < M.size(); k++)
            {
                if (current % M[k] == 0)
                {
                    if (++totalPrev == N)
                    {
                        return k + 1;
                    }
                }
            }
        }
        else if (totalNow >= N)
        {
            max = current - 1;
            current = (max - min) / 2 + min;
        }
        else
        {
            min = current + 1;
            current = (max - min) / 2 + min;
        }
    }
}

int main()
{
    int T;
    std::cin >> T;

    for (int i = 1; i <= T; ++i)
    {
        uint64_t B, N;
        std::cin >> B >> N;

        std::vector<uint64_t> M;
        for (int j = 0; j < B; j++)
        {
            uint64_t m;
            std::cin >> m;
            M.push_back(m);
        }

        std::cout << "Case #" << i << ": " << compute(B, N, M) << std::endl;
    }

    return 0;
}
