/*****************************************************************************
 * codeforces:   knst
 * topcoder:     knstqq
 * projecteuler: knstqq
 * **************************************************************************/

#include <algorithm>
#include <iostream>
#include <limits>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <vector>

using namespace std;

namespace std {
    template <class T1, class T2>
    class hash<pair<T1, T2>> {
    public:
        size_t operator()(const pair<T1, T2>& p) const {
            return hash<T1>()(p.first) & hash<T2>()(p.second);
        }
    };
}

constexpr long double const_pi() { return std::atan(static_cast<long double>(1))*4; }

const int dx4[] = {-1, 0, 0, 1};
const int dy4[] = {0, -1, 1, 0};

const int dx8[] = {-1, -1, -1,  0,  0,  1,  1,  1};
const int dy8[] = {-1,  0,  1, -1,  1, -1,  0,  1};

int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    for (int T = 1; T <= t; ++T) {
        size_t n;
        cin >> n;
        vector<size_t> values(n);
        for (auto& i : values) {
            cin >> i;

        }
        size_t k = n;

        cout << "Case #" << T << ": ";

        while (k > 2) {
            size_t maximal = 0;
            size_t maxI = 0;
            for (size_t i = 0; i < n; ++i) {
                if (values[i] > maximal) {
                    maxI = i;
                    maximal = values[i];
                }
            }
            values[maxI]--;
            cout << static_cast<char>('A' + maxI) << ' ';
            if (values[maxI] == 0)
                --k;
        }
        size_t a = -1;
        size_t b = -1;
        do {
            a = -1;
            b = -1;
            for (size_t j = 0; j < n; ++j) {
                if (values[j]) {
                    a = b;
                    b = j;
                    values[j]--;
                }
            }
            if (a != b) {
                cout << static_cast<char>('A' + a);
                cout << static_cast<char>('A' + b) << ' ';
            }
        } while (a != b);

        cout << endl;
    }
    return 0;
}
