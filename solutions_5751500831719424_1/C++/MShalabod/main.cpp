#include <iostream>
#include <fstream>
#include <cstdio>
#include <iomanip>
#include <cassert>
#include <climits>
#include <cmath>
#include <ctime>
#include <vector>
#include <string>
#include <cstring>
#include <queue>
#include <deque>
#include <time.h>
#include <stack>
#include <map>
#include <set>
#include <functional>
#include <algorithm>
#include <bitset>

//#pragma comment(linker, "/STACK:256000000")

#define VA_NUM_ARGS(...) VA_NUM_ARGS_IMPL_((0,__VA_ARGS__, 5,4,3,2,1))
#define VA_NUM_ARGS_IMPL_(tuple) VA_NUM_ARGS_IMPL tuple
#define VA_NUM_ARGS_IMPL(_0,_1,_2,_3,_4,_5,N,...) N

#define macro_dispatcher(macro, ...) macro_dispatcher_(macro, VA_NUM_ARGS(__VA_ARGS__))
#define macro_dispatcher_(macro, nargs) macro_dispatcher__(macro, nargs)
#define macro_dispatcher__(macro, nargs) macro_dispatcher___(macro, nargs)
#define macro_dispatcher___(macro, nargs) macro ## nargs

#define DBN(...) macro_dispatcher(DBN, __VA_ARGS__)(__VA_ARGS__)

#define DBN1(a)         cerr<<#a<<"="<<(a)<<"\n"
#define DBN2(a,b)       cerr<<#a<<"="<<(a)<<", "<<#b<<"="<<(b)<<"\n"
#define DBN3(a,b,c)     cerr<<#a<<"="<<(a)<<", "<<#b<<"="<<(b)<<", "<<#c<<"="<<(c)<<"\n"
#define DBN4(a,b,c,d)   cerr<<#a<<"="<<(a)<<", "<<#b<<"="<<(b)<<", "<<#c<<"="<<(c)<<", "<<#d<<"="<<(d)<<"\n"

using namespace std;

typedef pair<int, int> pii;
typedef long long llong;
typedef pair<llong, llong> pll;
typedef unsigned long long ullong;
#define mp make_pair
#define sqr(x) ((x)*(x))
const double PI = 3.14159265359;
#define y1 Y1
#define y0 alalal1231



int main()
{
#ifdef MYLOCAL
    freopen("//home//maks//input.txt", "rt", stdin);
    freopen("//home//maks//output.txt", "wt", stdout);
#endif

    int t;
    cin >> t;
    for (int _i = 1; _i <= t; ++_i)
    {
        int n, cnt[101][101];
        string s[101];
        cin >> n;
        for (int i = 0; i < n; ++i)
            cin >> s[i];
        for (int i = 0; i < n; ++i)
        {
            int curCnt = 0;
            char prev = 0;
            int cur = 0;
            for (int j = 0; j < s[i].size(); ++j)
            {
                if (prev && prev != s[i][j])
                    cnt[i][cur++] = curCnt, curCnt = 0;
                prev = s[i][j];
                ++curCnt;
            }
            cnt[i][cur++] = curCnt;
        }
        for (int i = 0; i < n; ++i)
            s[i].erase(unique(s[i].begin(), s[i].end()), s[i].end());
        int ans = 0;
        for (int i = 0; i < n - 1; ++i)
            if (s[i] != s[i + 1])
                ans = INT_MIN;

        if (ans != INT_MIN)
        {
            int len = s[0].size();
            for (int i = 0; i < len; ++i)
            {
                int curBest = INT_MAX;
                for (int j = 1; j <= 101; ++j)
                {
                    int moves = 0;
                    for (int k = 0; k < n; ++k)
                        moves += abs(cnt[k][i] - j);
                    curBest = min(curBest, moves);
                }
                ans += curBest;
            }
        }

        printf("Case #%d: ", _i);
        if (ans == INT_MIN)
            puts("Fegla Won");
        else
            printf("%d\n", ans);
    }

    return 0;
}

