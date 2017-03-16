#include <iostream>
#include <vector>
#include <string>
#include <climits>

using namespace std;

int main()
{
    int T;
    cin >> T;

    for (int testcase = 0; testcase < T; testcase++) {
        int R, C, N;
        cin >> R >> C >> N;

        int n = 1 << (R*C);
        int min = INT_MAX;
        for (int p = 0; p < n; p++) {
            int map[16];
            int q = 0;
            for (int i = 0; i < R*C; i++) {
                map[i] = !!(p & (1 << i));
                if (map[i])
                    q++;
            }
            if (q != N)
                continue;
            int u = 0;
            for (int r = 0; r < R-1; r++)
                for (int c = 0; c < C; c++)
                    if (map[r*C+c] && map[(r+1)*C+c])
                        u++;
            for (int c = 0; c < C-1; c++)
                for (int r = 0; r < R; r++)
                    if (map[r*C+c] && map[r*C+c+1])
                        u++;
            if (u < min)
                min = u;
        }

        cout << "Case #" << testcase+1 << ": ";
        cout << min << endl;
    }
    return 0;
}

// vim: set sw=4:
