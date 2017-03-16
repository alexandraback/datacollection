#include <iostream>

void solveTestCase()
{
    int N;
    int p[26] = {0};
    int total = 0;
    
    auto violation = [&]() {
        for (int i = 0; i < 26; ++i)
            if (p[i]*2 > total)
                return true;
        return false;
    };
    auto pickNext = [&]() {
        int max = p[0];
        int maxI = 0;
        for (int i = 1; i < 26; ++i) {
            if (p[i] > max) {
                max = p[i];
                maxI = i;
            }
        }
        p[maxI]--;
        total--;
        return maxI;
    };
    
    std::cin >> N;
    for (int i = 0; i < N; ++i)
        std::cin >> p[i];
    
    for (int i = 0; i < N; ++i)
        total += p[i];
    
    while (total) {
        std::cout << " " << char('A' + pickNext());
        if (violation())
            std::cout << char('A' + pickNext());
    }
}

int main() {
    int t;
    std::cin >> t;

    for (int i = 0; i < t; ++i) {
        std::cout << "Case #" << (i + 1) << ":";
        solveTestCase();
        std::cout << std::endl;
    }
    return 0;
}
