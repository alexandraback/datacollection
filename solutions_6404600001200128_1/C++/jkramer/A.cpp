#include <algorithm>
#include <bitset>
#include <deque>
#include <functional>
#include <iostream>
#include <iomanip>
#include <iterator>
#include <list>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <stack>
#include <unordered_map>
#include <utility>
#include <vector>
#include <cstdio>
#include <cmath>
#include <climits>
#include <cstdlib>
#include <ctime>

using namespace std;

namespace
{
template <typename T>
auto read(istream& is = cin)
{
    T i;
    is >> i;
    return i;
}
auto rl() { return read<long long>(); };
auto ri() { return read<int>(); };
auto rd() { return read<double>(); };
auto rc() { return read<char>(); };
auto rs() { return read<string>(); };

auto gl()
{
    string s;
    getline(cin, s);
    return s;
}

void test_case(int case_num)
{
    auto n = ri();
    vector<int> mushies(n);
    generate_n(begin(mushies), n, ri);

    auto prev = *begin(mushies);
    auto count = 0;
    auto maxd = 0;
    for (auto i = ++begin(mushies); i != end(mushies); ++i)
    {
        auto diff = prev - *i;
        if (diff > 0)
        {
            count += diff;
            maxd = max(maxd, diff);
        }
        prev = *i;
    }
    cout << count;


    count = 0;

    for (auto i = begin(mushies); i != --end(mushies); ++i)
    {
        count += min(*i, maxd);
    }
    cout << " " << count;
}
}

int main()
{
    auto num_cases = ri();
    cout << fixed << setprecision(7);
    for (auto i = 0; i < num_cases; ++i)
    {
        cout << "Case #" << i + 1 << ": ";
        test_case(i);
        cout << endl;
    }
}
