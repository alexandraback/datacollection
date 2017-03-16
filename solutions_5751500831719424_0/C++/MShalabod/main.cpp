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


int main() {
#ifdef MYLOCAL
    freopen("//home//maks//input.txt", "rt", stdin);
    freopen("//home//maks//output.txt", "wt", stdout);
    clock_t beginTime = clock();
#endif

    int te;
    cin >> te;
    DBN(te);
    for (int test = 0; test < te; ++test) {
         DBN(test);
        int n;
        cin >> n;
        DBN(n);
        int total = 0;
        vector< vector<int> > azaza;
        azaza.resize(n);

        string superStr = "1111";
        DBN(superStr);
        for (int i = 0; i < n; ++i) {
            string s;
            string s1;
            cin >> s;
            DBN(s);
            int loh = 0;

            for (int j = 0; j < s.size(); ++j) {
                if (s[j] != s[j + 1]) {
                    s1 += s[j];
                    azaza[i].push_back(loh + 1);
                    loh = 0;
                }
                else
                    ++loh;
            }

            if (superStr == "1111")
                superStr = s1;
            else
                if (s1 != superStr) {
                    superStr = "1111";
                    break;
                }
        }

        DBN(superStr);
        DBN(total);
        if (superStr == "1111")
            cout << "Case #" << test + 1 << ": " << "Fegla Won" << '\n';
        else {
            int superAns = 0;
            for (int i = 0; i < azaza[0].size(); ++i) {
                int total = 0;
                for (int j = 0; j < n; ++j) {
                    total += azaza[j][i];
                }
                DBN(total);
                if (total % n == 0) {
                    int m = total / n;
                    int ans = 0;
                    for (int j = 0; j < n; ++j) {
                        ans += abs(azaza[j][i] - m);
                    }
                    superAns += ans;
                    //cout << "Case #" << test + 1 << ": " << ans << '\n';
                }
                else {
                    int m1 = total / n;
                    int m2 = m1 + 1;
                    int ans1 = 0, ans2 = 0;
                    for (int j = 0; j < n; ++j) {
                        ans1 += abs(azaza[j][i] - m1);
                        ans2 += abs(azaza[j][i] - m2);
                    }
                    superAns += min(ans1, ans2);
                    //cout << "Case #" << test + 1 << ": " << min(ans1, ans2) << '\n';
                }
            }
            cout << "Case #" << test + 1 << ": " << superAns << '\n';
        }



    }

#ifdef MYLOCAL
    cout << endl << "time: " << double(clock() - beginTime) / CLOCKS_PER_SEC;
#endif
    return 0;
}
