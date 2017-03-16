#include <algorithm>
#include <cmath>
#include <iostream>
#include <limits>
#include <string>
#include <vector>

int computeAny(const std::vector<int>& M)
{
    int total = 0;

    for (int i = 1; i < M.size(); i++)
    {
        int diff = M[i - 1] - M[i];

        if (diff > 0)
        {
            total += diff;
        }
    }

    return total;
}

int computeConstantRate(const std::vector<int>& M)
{
    int maxRate = 0;

    for (int i = 1; i < M.size(); i++)
    {
        int diff = M[i - 1] - M[i];

        if (diff > 0 && diff > maxRate)
        {
            maxRate = diff;
        }
    }

    int total = 0;

    for (int i = 0; i < M.size() - 1; i++)
    {
        total += std::min(maxRate, M[i]);
    }

    return total;
}

int main()
{
    int T;
    std::cin >> T;

    for (int i = 1; i <= T; ++i)
    {
        int N;
        std::cin >> N;

        std::vector<int> M;
        for (int j = 0; j < N; j++)
        {
            int m;
            std::cin >> m;
            M.push_back(m);
        }

        std::cout << "Case #" << i << ": " << computeAny(M) << " " << computeConstantRate(M) << std::endl;
    }

    return 0;
}
