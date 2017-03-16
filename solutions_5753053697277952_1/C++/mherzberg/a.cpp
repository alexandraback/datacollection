#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>

int main()
{
    int T;
    std::cin >> T;

    for (int t = 1; t <= T; ++t)
    {
        int N;
        std::cin >> N;

        std::vector<int> nums(N, 0);
        for (int n = 0; n < N; ++n)
        {
            std::cin >> nums[n];
        }

        std::cout << "Case #" << t << ":";

        while (std::count(nums.begin(), nums.end(), 0) < N - 2)
        {
            int max = -1;
            int maxindex = -1;
            for (int i = 0; i < N; ++i)
            {
                if (nums[i] > max)
                {
                    max = nums[i];
                    maxindex = i;
                }
            }

            nums[maxindex]--;
            std::cout << " " << (char)('A' + maxindex);
        }

        int a = -1, b = -1;
        for (int i = 0; i < N; ++i)
        {
            if (nums[i] > 0)
            {
                if (a == -1)
                    a = i;
                else
                    b = i;
            }
        }

        assert(nums[a] == nums[b]);
        while (nums[a] > 0)
        {
            std::cout << " " << (char)('A' + a) << (char)('A' + b);
            nums[a]--;
            nums[b]--;
        }

        std::cout << std::endl;
    }

    return 0;
}
