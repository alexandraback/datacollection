#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

template<class T>
inline T read() {
    T value;
    std::cin >> value;
    return value;
}

struct Point {
    int64_t x, y;
};

int main() {
    int T = read<int>();
    for (int caseNum = 1; caseNum <= T; ++caseNum) {
        int N = read<int>();
        std::vector<Point> P;
        P.resize(N);
        for (int i = 0; i < N; ++i) {
            std::cin >> P[i].x;
            std::cin >> P[i].y;
        }
        printf("Case #%d:\n", caseNum);
        for (int i = 0; i < N; ++i) {
            // we try to connect every 2 points
            int cut = -1;
            for (int j = 0; j < N; ++j) {
                if (i == j)
                    continue;
                int64_t dx = P[j].x - P[i].x;
                int64_t dy = P[j].y - P[i].y;
                int cleft = 0, cright = 0;
                for (int k = 0; k < N; ++k) {
                    if (k == i || k == j)
                        continue;
                    int64_t kx = P[k].x - P[i].x;
                    int64_t ky = P[k].y - P[i].y;
                    int64_t t = dx * ky - kx * dy;
                    if (t > 0)
                        ++cleft;
                    if (t < 0)
                        ++cright;
                }
                int maybe = std::min(cleft, cright);
                if (cut == -1 || cut > maybe)
                    cut = maybe;
            }
            if (cut == -1)
                cut = 0;
            printf("%d\n", cut);
        }
    }
    return 0;
}
