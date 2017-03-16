#define _CRT_SECURE_NO_DEPRECATE

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>

#define ld long double

std::vector<int> counts;
std::vector<std::vector<int>> result;
int n;

int readInt() {
    int x;
    std::cin >> x;
    return x;
}

void read() {
    std::cin >> n;
    counts.resize(n);
    for (int i = 0; i < n; ++i) {
        counts[i] = readInt();
    }
    result.clear();
}

void solve() {
    while (true) {
        int max = *max_element(begin(counts), end(counts));
        if (max == 0) {
            break;
        }
        int max_counts = count(begin(counts), end(counts), max);
        if (max_counts == 1 || (max == 1 && max_counts == 3)) {
            auto p = find(begin(counts), end(counts), max);
            result.push_back(std::vector<int>());
            for (int i = 0; i < 2 && *p - i > 0; ++i) {
                result.back().push_back(p - begin(counts));
            }
            *p = std::max(0, *p - 2);
        } else {
            auto p = find(begin(counts), end(counts), max);
            auto q = find(next(p), end(counts), max);

            result.push_back(std::vector<int> { p - begin(counts), q - begin(counts) });
            --(*p);
            --(*q);
        }
    }
}

void print() {
    for (auto v : result) {
        for (auto ch : v) {
            std::cout << static_cast<char>('A' + ch);
        }
        std::cout << ' ';
    }
    std::cout << std::endl;
}

int main() {
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    int t;
    std::cin >> t;
    for (int i = 0; i < t; ++i) {
        read();
        solve();
        std::cout << "Case #" << i + 1 << ": ";
        print();
    }

    return 0;
}