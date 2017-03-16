// Copyright (C) 2016 Sayutin Dmitry.
//
// This program is free software; you can redistribute it and/or
// modify it under the terms of the GNU General Public License as
// published by the Free Software Foundation; version 3

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program; If not, see <http://www.gnu.org/licenses/>.

#include <iostream>
#include <vector>
#include <stdint.h>
#include <algorithm>
#include <set>
#include <map>
#include <array>
#include <queue>
#include <stack>
#include <functional>
#include <utility>
#include <string>
#include <assert.h>
#include <iterator>

using std::cin;
using std::cout;
using std::cerr;

using std::vector;
using std::map;
using std::array;
using std::set;
using std::string;

using std::pair;
using std::make_pair;

using std::min;
using std::abs;
using std::max;

template <typename T>
T input() {
    T res;
    cin >> res;
    return res;
}

#ifdef LOCAL
#define LASSERT(X) assert(X)
#else
#define LASSERT(X) {}
#endif

void validate(const std::set<pair<uint32_t, char>>& the_set, uint32_t cnt) {
    if (not the_set.empty()) {
        uint32_t big = std::prev(the_set.end(), 1)->first;
        assert(2 * big <= cnt);
    }
}

int main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    uint32_t T = input<uint32_t>();
    for (uint32_t t = 1; t <= T; ++t) {
        std::set<pair<uint32_t, char>> the_set;
        uint32_t n = input<uint32_t>();
        
        for (uint32_t i = 0; i != n; ++i)
            the_set.emplace(input<uint32_t>(), char('A' + i));

        uint32_t cnt = 0;
        for (auto v: the_set)
            cnt += v.first;

        string ans = "";
        
        while (not the_set.empty())
            if (the_set.size() == 1) {
                assert(false); /* we have failed */
            } else {
                auto elem1 = *(std::prev(the_set.end(), 1));
                auto elem2 = *(std::prev(the_set.end(), 2));
                the_set.erase(elem1);
                the_set.erase(elem2);

                if ((elem1.first == elem2.first) and (elem1.first != 1 or the_set.size() == 0 or the_set.size() >= 2)) {
                    ans += elem1.second;
                    ans += elem2.second;
                    ans += " ";
                    elem1.first -= 1, elem2.first -= 1, cnt -= 2;
                } else {
                    assert(elem1.first >= elem2.first);
                    ans += elem1.second;
                    ans += " ";
                    elem1.first -= 1, cnt -= 1;
                }
                
                if (elem1.first != 0)
                    the_set.insert(elem1);
                if (elem2.first != 0)
                    the_set.insert(elem2);
                validate(the_set, cnt);
            }
        cout << "Case #" << t << ": " << ans << "\n";
    }
    
    return 0;
}
