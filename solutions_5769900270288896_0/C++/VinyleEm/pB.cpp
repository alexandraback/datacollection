#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int bitcount(int mask)
{
    return mask == 0 ? 0 : 
        (mask % 2 + bitcount(mask / 2));
}

int main(int argc, char **argv)
{
    int T;
    cin >> T;

    for (int t = 1;t <= T; t++) {
        int R, C, N;
        cin >> R >> C >> N;

        int ret = 1<<30, total = R * C;
        for (int mask = 0;mask < 1<<total; mask++)
            if (bitcount(mask) == N) {
                vector<int> rows, cols;
                for (int i = 0;i < total; ++i)
                    if (mask & (1<<i)) {
                        rows.push_back(i / C);
                        cols.push_back(i % C);
                    }

                int unhappy = 0;
                for (int i = 0;i < N; ++i)
                    for (int j = 0;j < i; ++j)
                        if (abs(rows[i] - rows[j]) + abs(cols[i] - cols[j]) == 1)
                            unhappy++;
            

                ret = min(ret, unhappy);
            }

        cout << "Case #" << t << ": " << ret << endl;
    }

    return 0;
}
