#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cctype>
#include <climits>
#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <sstream>
#include <initializer_list>

using namespace std;

int main(int argc, char *argv[])
{
    int T = 0;

    if (argc > 1) {
        freopen(argv[1], "r", stdin);
    }
    
    cin >> T;

    for (int cas = 1; cas <= T; cas++) {
        int N = 0, R = 0, C = 0;
        int res = 0x7fffffff;
        cin >> R >> C >> N;
        int total = R * C;
        for (int mask = 0; mask < (1 << total); mask++) {
            int cell[16][16] = {{0}};
            int top = 1;
            int cnt = 0;

            int tmp = 0;
            for (int i = 0; i < R; i++) {
                for (int j = 0; j < C; j++) {
                    if (mask & top) {
                        cell[i][j] = 1;
                        cnt++;
                    }
                    top = top << 1;

                    if (i > 0 && cell[i][j] == 1 && cell[i - 1][j] == 1) {
                        tmp++;
                    }

                    if (j > 0 && cell[i][j] == 1 && cell[i][j - 1] == 1) {
                        tmp++;
                    }
                }
            }

            if (cnt == N) {
                res = std::min(tmp, res);
            }
        }

        cout << "Case #" << cas << ": " << res << endl;
        
    }

    return 0;
}
