/* This is template part for Google CodeJam contest
 * created by Shapovalov Nikita, 2014
 */

#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

namespace CodeJamUtility {

    class TestCaseUtil
    {
        std::clock_t start_test_time;

        int test_id_;
        int precision_;

        std::stringstream ss;

    public:
        TestCaseUtil(int test_id, int precision = 10) : 
            start_test_time(std::clock()), 
            test_id_(test_id), 
            precision_(precision),
            ss()
        {
            std::cerr << "Processing test #" << std::setw(4) << test_id << ": ";
            ss << std::fixed << std::setprecision(precision_);
        }

        TestCaseUtil(const TestCaseUtil &) = delete;

        TestCaseUtil &operator=(const TestCaseUtil &) = delete;

        ~TestCaseUtil()
        {
            std::cerr << "Ok. Time elapsed: " << std::setw(5) << 
                (std::clock() - start_test_time) / (1. * CLOCKS_PER_SEC) << " secs" << std::endl;
            std::cout << "Case #" << test_id_ << ": " << ss.str() << "\n";
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
}

#define EXECUTE_FUNCTION(NAME) \
    process(CodeJamUtility::TestCaseUtil & NAME)

#define CODEJAM_RUN_NEW_TEST(ID, NAME) \
    {\
        CodeJamUtility::TestCaseUtil NAME(ID);\
        process(NAME);\
    }

#define CODEJAM_RUN_ALL_TESTS(NAME)\
int main() \
{\
    std::ios_base::sync_with_stdio(false); \
    int testNumber##NAME;\
    std::cin >> testNumber##NAME;\
    for (int counter##NAME = 1; counter##NAME <= testNumber##NAME; ++counter##NAME) {\
        CODEJAM_RUN_NEW_TEST(counter##NAME, NAME);\
    }\
    return 0;\
}

#include <bits/stdc++.h>

using namespace std;

/* End of template part */

int dp[20][20][20];

const int INF = 1000000;

void
EXECUTE_FUNCTION(out)
{
    int r, c, n;
    cin >> r >> c >> n;
    if (r >= c) {
        swap(r, c);
    }
    for (int i = 0; i <= c; ++i) {
        for (int j = 0; j < (1 << r); ++j) {
            for (int sum = 0; sum <= n; ++sum) {
                dp[i][sum][j] = INF;
            }
        }
    }
    dp[0][0][0] = 0;
    for (int i = 0; i < c; ++i) {
        for (int sum = 0; sum <= n; ++sum) {
            if (sum + (c - i) * r < n) {
                continue;
            }
            for (int j = 0; j < (1 << r); ++j) {
                if (dp[i][sum][j] == INF) {
                    continue;
                }
                for (int nj = 0; nj < (1 << r) && __builtin_popcount(nj) + sum <= n; ++nj) {
                    int cur_isec = 0;
                    for (int kk = 0; kk < r; ++kk) {
                        cur_isec += ((j & nj) >> kk) & 1;
                    }
                    for (int kk = 1; kk < r; ++kk) {
                        cur_isec += (nj >> kk) & (nj >> (kk -1)) & 1;
                    }
                    int add = __builtin_popcount(nj);
                    dp[i + 1][sum + add][nj] = min(dp[i + 1][sum + add][nj], dp[i][sum][j] + cur_isec);
                }
            }
        }
    }
    int ans = INF;
    for (int bj = 0; bj < (1 << r); ++bj) {
        ans = min(ans, dp[c][n][bj]);
    }
    out << ans;
}

CODEJAM_RUN_ALL_TESTS(Round1B_2015_A)
