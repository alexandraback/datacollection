#include <algorithm>
#include <complex>
#include <cstdarg>
#include <cstdio>
#include <cstdlib>
#include <functional>
#include <iomanip>
#include <istream>
#include <limits>
#include <map>
#include <numeric>
#include <ostream>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <string>
#include <tuple>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;

// Powered by caide (code generator, tester, and library code inliner)
class Solution {
public:
    void solve(std::istream& in, std::ostream& out) {
        int T; in >> T;
        for (int test = 1; test <= T; ++test) {
            out << "Case #" << test << ":";
            int N; in >> N;
            vector<pair<int, char>> cnt;
            for (int c = 'A'; c < 'A' + N; ++c) {
                int n; in >> n;
                cnt.emplace_back(n, c);
            }
            sort(cnt.rbegin(), cnt.rend());
            while (!cnt.empty()) {
                out << " " << cnt[0].second;
                --cnt[0].first;
                if (cnt.size() == 2 && (cnt[1].first > cnt[0].first)) {
                    out << cnt[1].second;
                    --cnt[1].first;
                }
                sort(cnt.rbegin(), cnt.rend());
                while (!cnt.empty() && cnt.back().first == 0)
                    cnt.pop_back();
            }
            out << "\n";
        }
    }
};

void solve(std::istream& in, std::ostream& out)
{
    out << std::setprecision(12);
    Solution solution;
    solution.solve(in, out);
}

#include <fstream>
#include <iostream>

int main() {
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    istream& in = cin;

    ostream& out = cout;

    solve(in, out);
    return 0;
}

