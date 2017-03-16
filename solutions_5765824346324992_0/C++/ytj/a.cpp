#include <iostream>
#include <stdexcept>
#include <vector>
#include <algorithm>
#include <boost/multiprecision/cpp_int.hpp>
using namespace std;

int n, b;
vector<int64_t> a;

void input() {
    a.clear();
    cin >> b >> n;
    for (int i = 0; i < b; i++) {
        int j;
        cin >> j;
        a.push_back(j);
    }
}

auto f(int64_t m) {
  boost::multiprecision::cpp_int s = 0;
    for (auto i : a) {
        s += m / i + 1;
    }
    return s;
}

int work() {
  cerr << 0 << ": " << f(0) << endl;
  cerr << 1 << ": " << f(1) << endl;
  cerr << 5 << ": " << f(5) << endl;
  cerr << 9 << ": " << f(9) << endl;
    int64_t l = -1, r = std::numeric_limits<int64_t>::max() - 10;
    while (true) {
        int64_t mid = (r - l) / 2 + l;
        if (f(mid) < n) {
            l = mid;
        } else {
            r = mid;
        }
        // cout << l << " " << r << endl;
        if (r - l == 1)
            break;
    }
    l = r;
    cerr << l << endl;

    for (auto i : a) {
        if (l % i != 0) {
            n -= l / i + 1;
        } else {
            n -= l / i;
        }
    }
    for (size_t i = 0; i < a.size(); i++) {
        if (l % a[i] == 0) {
            if (--n == 0) {
                return i + 1;
            }
        }
    }
    throw runtime_error(to_string(n));
}

int main() {
    cin.sync_with_stdio(false);
    int cases;
    cin >> cases;
    for (int i = 1; i <= cases; i++) {
        input();
        cout << "Case #" << i << ": " << work() << "\n";
    }
}
