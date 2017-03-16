#include <algorithm>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <utility>
#include <vector>

using namespace std;

typedef pair< int, char > pic;

clock_t start_test_time = 0;

class TestCaseUtil
{
    clock_t start_test_time;
    int test_id_;
    stringstream ss;
public:
    TestCaseUtil(int test_id) : start_test_time(clock()), test_id_(test_id), ss()
    {
        cerr << "Processing test #" << setw(3) << test_id << ": ";
    }
    TestCaseUtil(const TestCaseUtil &) = delete;
    TestCaseUtil &operator=(const TestCaseUtil &) = delete;
    ~TestCaseUtil()
    {
        cerr << "Ok. Time elapsed: " << setw(5) << 
            (clock() - start_test_time) / CLOCKS_PER_SEC << " secs" << endl;
        cout << "Case #" << test_id_ << ": " << ss.str() << endl;
    }
    template< class T >
    friend TestCaseUtil &operator<<(TestCaseUtil &, const T &obj);
};

template< class T >
TestCaseUtil &
operator<<(TestCaseUtil &t, const T &obj)
{
    t.ss << obj;
    return t;
}

vector< pic >
parse_string(const string &s)
{
    vector< pic > res;
    char prev_c = 0;
    for (auto x : s) {
        if (x != prev_c) {
            res.push_back(make_pair(x, 0));
        }
        auto &cur_pair = res.back();
        cur_pair.second++;
        prev_c = x;
    }
    return std::move(res);
}

bool
check(const vector< pic > &a, const vector< pic > &b)
{
    if (a.size() != b.size()) {
        return false;
    }
    for (size_t i = 0; i < a.size(); ++i) {
        if (a[i].first != b[i].first) {
            return false;
        }
    }
    return true;
}

int
get_ans(const vector< int > &sm)
{
    int min_v = *min_element(sm.begin(), sm.end());
    int max_v = *max_element(sm.begin(), sm.end());
    int ans = -1;
    for (int i = min_v; i <= max_v; ++i) {
        int cur_sum = 0;
        for (auto x : sm) {
            cur_sum += abs(x - i);
        }
        if (cur_sum < ans || ans == -1) {
            ans = cur_sum;
        }
    }
    return ans;
}

void
process(int test_id)
{
    TestCaseUtil cur_test(test_id);
    int n;
    cin >> n;
    vector< vector< pic > > pattern;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        pattern.push_back(parse_string(s));
    }
    for (int i = 1; i < int(pattern.size()); ++i) {
        if (!check(pattern[i - 1], pattern[i])) {
            cur_test << "Fegla Won";
            return;
        }
    }
    int res = 0;
    int len = int(pattern[0].size());
    for (int i = 0; i < len; ++i) {
        vector< int > nums;
        for (const auto &x : pattern) {
            nums.push_back(x[i].second);
        }
        res += get_ans(nums);
    }
    cur_test << res;
}

int
main()
{
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        process(i);
    }
    return 0;
}
