#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int TC, R, C, N;
    cin >> TC;
    for (int a = 1; a <= TC; ++a) {
        int grid[20][20] = {{0}};
        cin >> R >> C >> N;
        //cout << "INPUT " << R << " " << C << " " << N << "\n";
        int placed = 0, unhappiness = 0;
        if (C < R) swap(R, C);
        for (int b = 0; b < R; ++b) {
            for (int c = 0; c < C; ++c) {
                if ((R % 2 && C % 2 && N > (R * C / 2) + 2 ? (b + c) & 1 : (~ (b + c)) & 1)) {
                    grid[b][c] = 1;
                    placed++;
                }
            }
        }
        /*for (int b = 0; b < R; ++b) {
            for (int c = 0; c < C; ++c)
                cout << grid[b][c];
            cout << "\n";
        }*/
        int emptycorners = !(grid[0][C - 1]);
        if (C != 1) emptycorners += !(grid[0][0]);
        if (R != 1) {
            emptycorners += !(grid[R - 1][0]);
            if (C != 1) emptycorners += !(grid[R - 1][C - 1]);
        }
        int emptysides = 0;
        for (int b = 1; b < C - 1; ++b) {
            emptysides += !(grid[0][b]);
            if (R != 1)
                emptysides += !(grid[R - 1][b]);
        }
        for (int b = 1; b < R - 1; ++b)
            emptysides += !(grid[b][0]) + !(grid[b][C - 1]);
        //cout << "Corners: " << emptycorners << ", Sides: " << emptysides << "\n";
        //cout << "Placed " << placed << "\n";
        if (placed < N) {
            if (N - placed <= emptycorners) {
            //    cout << (N - placed) << " corners with cost of " << (N - placed) * (R == 1 ? C == 1 ? 0 : 1 : 2) << "\n";
                unhappiness += (N - placed) * (R == 1 ? C == 1 ? 0 : 1 : 2);
            }
            else if (N - placed <= emptycorners + emptysides) {
            //    cout << emptycorners << " corners with cost of " << emptycorners * (R == 1 ? C == 1 ? 0 : 1 : 2) << "\n";
            //    cout << (N - placed - emptycorners) << " edges with cost of " << (N - placed - emptycorners) * (R == 1 ? 2 : 3) << "\n";
                unhappiness += emptycorners * (R == 1 ? C == 1 ? 0 : 1 : 2) + (N - placed - emptycorners) * (R == 1 ? 2 : 3);
            }
            else {
            //    cout << emptycorners << " corners with cost of " << emptycorners * (R == 1 ? C == 1 ? 0 : 1 : 2) << "\n";
            //    cout << emptysides << " edges with cost of " << emptysides * (R == 1 ? 2 : 3) << "\n";
            //    cout << (N - placed - emptysides - emptycorners) << " normal with cost of " << (N - placed - emptysides - emptycorners) * 4 << "\n";
                unhappiness += emptycorners * (R == 1 ? C == 1 ? 0 : 1 : 2) + emptysides * (R == 1 ? 2 : 3) + (N - placed - emptysides - emptycorners) * 4;
            }
        }
        cout << "Case #" << a << ": " << unhappiness << "\n";
    }
    return 0;
}