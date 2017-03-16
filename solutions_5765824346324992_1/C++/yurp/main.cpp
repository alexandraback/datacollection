
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

int64_t cntMinuteM(const VectorInt& barbers, int64_t m) {
    int64_t cnt = 0;
    for (int barber: barbers) {
        cnt += static_cast<int64_t>(m) / barber + 1;
    }

    return cnt;
}

void task() {
    int64_t b;
    int64_t n;
    std::cin >> b >> n;

    VectorInt barbers(b);
    int maxBarber = 0;
    for (int i = 0; i < b; ++i) {
        std::cin >> barbers[i];
        maxBarber = std::max(maxBarber, barbers[i]);
    }


    int64_t timeLeft = 0;
    int64_t timeRight = (n / b) * maxBarber;
    if (b < n) {

        while (timeLeft + 1 < timeRight) {
            int64_t timeMid = (timeLeft + timeRight) / 2;
            if (cntMinuteM(barbers, timeMid) >= n) {
                timeRight = timeMid;
            }
            else {
                timeLeft = timeMid;
            }
        }

        int64_t cnt = cntMinuteM(barbers, timeRight);
        VectorInt readyb;
        for (int i = 0; i < b; ++i) {
            if (timeRight % barbers[i] == 0) {
                readyb.push_back(i + 1);
            }
        }

        std::cout << readyb[readyb.size() - 1 - (cnt - n)];
    }
    else {
        std::cout << n;
    }


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
