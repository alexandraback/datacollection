#include <iostream>

int calc(int R, int C, int N, bool odd)
{
    if (R == 1) {
        int x = C;
        C = R;
        R = x;
    }
    if (C == 1) {
        if (2 * N <= R + 1)
            return 0;
        return 2 * N - (R + 1);
    }

    int RC = R * C;
    int fine = RC / 2;
    int corners = 2;
    if (RC % 2 == 0) {
        corners = 2;
    } else {
        if (odd) {
            corners = 0;
            ++fine;
        } else {
            corners = 4;
        }
    }
    int edges = R + C - 2 - corners;

    if (N <= fine)
        return 0;
    N -= fine;

    if (N <= corners)
        return N * 2;
    N -= corners;
    int bad = corners * 2;

    if (N <= edges)
        return bad + N * 3;
    N -= edges;
    bad += edges * 3;

    return bad + N * 4;
}

int main()
{
    int T;
    std::cin >> T;

    for (int t = 1; t <= T; ++t) {
        int R, C, N;
        std::cin >> R >> C >> N;
        int x = calc(R, C, N, true);
        int y = calc(R, C, N, false);
        if (x > y)
            x = y;
        std::cout << "Case #" << t << ": " << x << std::endl;
    }
}
