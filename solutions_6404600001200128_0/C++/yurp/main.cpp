
#include <iostream>
#include <iomanip>
#include <fstream>

#include <string>
#include <sstream>

#include <vector>
#include <queue>
#include <set>
#include <map>

#include <algorithm>
#include <limits>

#include <cctype>
#include <cassert>


#include <utility>
#include <numeric>
#include <tuple>
#include <list>
#include <unordered_set>
#include <unordered_map>

template<typename T>
using Vector2D = std::vector<std::vector<T>>;

using PairInt = std::pair<int, int>;
using PairInt64 = std::pair<int64_t, int64_t>;

using MapInt = std::map<int, int>;
using SetInt = std::set<int>;

using VectorInt = std::vector<int>;
using VectorInt2D = Vector2D<int>;
using VectorInt64 = std::vector<int64_t>;

using VectorChar = std::vector<char>;
using VectorChar2D = Vector2D<char>;
using VectorString = std::vector<std::string>;

using QueuePairInt = std::queue<PairInt>;

using PairInt = std::pair<int, int>;
using VectorPairInt = std::vector<PairInt>;
using VectorPairInt64 = std::vector<PairInt64>;
using SetInt = std::set<int>;
using UMapChar = std::map<char, int>;

using ListInt = std::list<int>;
using VectorListInt = std::vector<ListInt>;
using VectorDouble = std::vector<double>;

int methodOne(const VectorInt& v) {
    int sz = v.size();
    int sum = 0;
    for (int i = 1; i < sz; ++i) {
        if (v[i - 1] > v[i]) {
            sum += v[i - 1] - v[i];
        }
    }

    return sum;
}

int methodTwo(const VectorInt& v) {
    int sz = v.size();
    int maxCount = 0;
    for (int i = 1; i < sz; ++i) {
        if (v[i - 1] > v[i]) {
            maxCount = std::max(maxCount, v[i - 1] - v[i]);
        }
    }

    int sum = 0;
    if (maxCount > 0) {
        for (int i = 0; i < sz - 1; ++i) {
            sum += std::min(maxCount, v[i]);
        }
    }

    return sum;
}

void task() {
    int n;
    std::cin >> n;

    VectorInt v(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> v[i];
    }

    std::cout << methodOne(v) << " " << methodTwo(v);
}

int main()
{
#ifdef IN_TXT_ABSPATH
    std::ifstream in(IN_TXT_ABSPATH);
    std::cin.rdbuf(in.rdbuf());
#endif

#ifdef OUT_TXT_ABSPATH
    std::ofstream out(OUT_TXT_ABSPATH);
    std::cout.rdbuf(out.rdbuf());
#endif

    int t;
    std::cin >> t;
    for (int i = 1; i <= t; ++i) {
        std::cout << "Case #" << i << ": ";
        task();
        std::cout << "\n";

    }

    return 0;
}
