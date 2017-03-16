#!/usr/bin/env cppsh
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <set>
#include <iterator>
#include <vector>
#include <sstream>
#include <cmath>
#include <queue>

int solve(int R, int C, int N)
{
    std::vector<std::vector<bool> > grid(R, std::vector<bool>(C, false));
    std::string o(R*C, '0');
    for (int i = 0; i < N; ++i) {
        o[o.size()-1-i] = '1';
    }
    int best = 100000;
    do
    {
        for (int i = 0; i < o.size(); ++i)
        {
            grid[i/C][i%C] = (o[i] == '1');
        }
        int score = 0;
        for (int i = 0; i < R; ++i)
        for (int j = 0; j < C; ++j)
        {
            if (!grid[i][j])
                continue;
            for (int k = std::max(i-1, 0); k < std::min(i+2, R); ++k)
            for (int l = std::max(j-1, 0); l < std::min(j+2, C); ++l)
            {
                if (k == i && l == j)
                    continue;
                if ((k == i || l == j) && grid[k][l])
                    score++;
            }
        }
        //std::cout << o << std::endl;
        //std::cout << "score: " << score << std::endl;
        score /= 2;
        best = std::min(score, best);
    }
    while (std::next_permutation(o.begin(), o.end()));
    return best;
}

int main(int argc, char* argv[])
{
    std::string str;
    std::getline(std::cin, str);
    const int T = atoi(str.c_str());
    for (int it = 0; it < T; ++it)
    {
        int R, C, N;
        std::cin >> R >> C >> N;
        std::cout << "Case #" << (it+1) << ": " << solve(R, C, N) << std::endl;
    }
    return 0;
}
