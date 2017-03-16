#include <iostream> 
#include <algorithm>
#include <vector>
#include <limits>

using namespace std;

size_t best;
vector<vector<char> > grid;
void try_all(int cell, int N, int R, int C) {
    if (cell == R * C) {
        size_t unhappiness = 0;
        size_t total = 0;
        // Measure unhappiness, always looking left/above
        for (int i = 0; i < R; ++i) {
            for (int j = 0; j < C; ++j) {
                if (grid[i][j] == 0) continue;
                ++total;
                if (i && (grid[i - 1][j] == 1)) ++unhappiness;
                if (j && (grid[i][j - 1] == 1)) ++unhappiness;
            }
        }

        // if (unhappiness < best) {
        //     cout << "unhappiness: " << unhappiness << endl;
        //     for (int i = 0; i < R; ++i) {
        //         for (int j = 0; j < C; ++j) {
        //             cout << (int) grid[i][j];
        //         }
        //         cout << endl;
        //     }
        // }
        if (total == N)
            best = std::min(best, unhappiness);
    }
    else {
        int r = cell / C;
        int c = cell % C;
        grid[r][c] = 1;
        try_all(cell + 1, N, R, C);
        grid[r][c] = 0;
        try_all(cell + 1, N, R, C);
    }
}
////////////////////////////////////////////////////////////////////////////////
/*! Program entry point
//  @param[in]  argc    Number of arguments
//  @param[in]  argv    Argument strings
//  @return     status  (0 on success)
*///////////////////////////////////////////////////////////////////////////////
int main(int argc, char *argv[])
{
    size_t T;
    cin >> T;
    for (size_t t = 0; t < T; ++t) {
        best = numeric_limits<size_t>::max();
        int R, C, N;
        cin >> R >> C >> N;
        grid.assign(R, vector<char>(C, 0));
        try_all(0, N, R, C);
        cout << "Case #" << t + 1 << ": " << best << endl;
    }
}
