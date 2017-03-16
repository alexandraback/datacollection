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
        std::vector<int> P(N, 0);
        int total = 0;
        for (int i = 0; i < N; ++i) {
            P[i] = read<int>();
            total += P[i];
        }
        std::vector<std::string> order;
        std::string current;
        int next = 0;
        while (total > 0) {
            if (P[next] > 0) {
                current.push_back('A' + next);
                --P[next];
                --total;
                if (current.size() == 2) {
                    order.push_back(current);
                    current.clear();
                }
            }
            next = (next + 1) % N;
        }
        if (!current.empty()) {
            order.push_back(current);
            current.clear();
        }
        std::reverse(order.begin(), order.end());
        for (std::string value : order) {
            if (!current.empty())
                current.push_back(' ');
            current.append(value);
        }
        printf("Case #%d: %s\n", caseNum, current.c_str());
    }
    return 0;
}
