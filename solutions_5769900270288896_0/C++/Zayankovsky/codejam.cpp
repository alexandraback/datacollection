#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

std::vector<std::vector<bool>> rooms;

size_t get_unhappiness(size_t i, size_t j)
{
    if (!rooms[i][j])
        return 0;
    size_t result = 0;
    if (i > 0)
        result += rooms[i - 1][j];
    if (j > 0)
        result += rooms[i][j - 1];
    return result;
}

int main()
{
    size_t T, R, C, N, answer;
    std::cin >> T;
    for (size_t i = 1; i <= T; ++i)
    {
        std::cin >> R >> C >> N;
        answer = 1000000000;
        size_t total;
        for (size_t j = 0; j < pow(2, R * C); ++j)
        {
            rooms.resize(R);
            for (size_t r = 0; r < R; ++r)
            {
                rooms[r].assign(C, false);
            }
            total = 0;
            for (size_t r = 0; r < R; ++r)
                for (size_t c = 0; c < C; ++c)
                    if (j & (1 << (r * C + c)))
                    {
                        rooms[r][c] = true;
                        ++total;
                    }
            if (total != N)
            {
                continue;
            }
            size_t unhappiness = 0;
            for (size_t r = 0; r < R; ++r)
                for (size_t c = 0; c < C; ++c)
                    unhappiness += get_unhappiness(r, c);
            if (unhappiness < answer)
                answer = unhappiness;
        }
        std::cout << "Case #" << i << ": " << answer << std::endl;
    }
    return 0;
}
