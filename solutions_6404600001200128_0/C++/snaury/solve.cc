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

int main() {
    int T = read<int>();
    for (int caseNum = 1; caseNum <= T; ++caseNum) {
        int N = read<int>();
        std::vector<int> m;
        m.resize(N);
        for (int i = 0; i < N; ++i)
            std::cin >> m[i];
        int y = 0;
        int zspeed = 0;
        for (int i = 1; i < N; ++i) {
            int d = m[i-1] - m[i];
            if (d > 0) {
                y += d;
                if (zspeed < d)
                    zspeed = d;
            }
        }
        int z = 0;
        for (int i = 0; i < N-1; ++i) {
            z += std::min(m[i], zspeed);
        }
        printf("Case #%d: %d %d\n", caseNum, y, z);
    }
    return 0;
}
