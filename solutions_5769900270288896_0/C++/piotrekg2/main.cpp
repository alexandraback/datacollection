#include <iostream>
#include <cstdint>
#include <cassert>
using namespace std;

bool occupied(uint32_t block, uint32_t r, uint32_t c, uint32_t R, uint32_t C)
{
    assert(r < R);
    assert(c < C);

    uint32_t shift = C * r + c;
    return (block & (uint32_t(1) << shift)) > 0;
}

uint32_t count(uint32_t block, uint32_t R, uint32_t C)
{
    uint32_t result = 0;
    for (auto c = 0u; c < C; ++c)
        for (auto r = 1u; r < R; ++r)
            result += occupied(block, r - 1, c, R, C) && occupied(block, r, c, R, C);

    for (auto r = 0u; r < R; ++r)
        for (auto c = 1u; c < C; ++c)
            result += occupied(block, r, c - 1, R, C) && occupied(block, r, c, R, C);
    return result;
}

int main(int argc, char **argv)
{
    ios_base::sync_with_stdio(false);
    auto& in = std::cin;

    int T;
    in >> T;

    for (int t = 1; t <= T; ++t)
    {
        uint32_t R, C, N;
        in >> R >> C >> N;

        uint32_t res = 10000000;
        for (uint32_t block = 0; block < (uint32_t(1) << (R * C)); ++block)
        {
            if(__builtin_popcount(block) == N)
            {
                res = std::min(res, count(block, R, C));
            }
        }
        std::cout << "Case #" << t << ": " << res << '\n';
    }

    return 0;
}
