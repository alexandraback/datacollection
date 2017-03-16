#include <iostream>
#include <iomanip>
#include <vector>
#include <array>
#include <algorithm>
#include <hash_map>
#include <string>
#include <map>
#include <set>
#include <queue>

#if 0
#include <boost/multiprecision/cpp_int.hpp>
using namespace boost::multiprecision;
typedef int256_t lll;
typedef uint256_t ulll;
#endif

using namespace std;
using namespace std::tr1;
using namespace stdext;

typedef __int64 ll;
typedef unsigned __int64 ull;

int T, N;
string str[128];

int solve() {
    if (str[0].empty()) return 0;
    char ch = str[0][0];
    vector<int> cnts(N, 0);
    for (int n = 0; n != N; ++n) {
        for (int i = 0; i != str[n].size(); ++i) {
            if (str[n][i] != ch) break;
            cnts[n]++;
        }
    }

    int opt_dlt = 10000000;
    for (int c = 1; c != 128; ++c) {
        int dlt = 0;
        for (int n = 0; n != N; ++n) {
            dlt += abs(c - cnts[n]);
        }
        if (dlt < opt_dlt) {
            opt_dlt = dlt;
        }
    }
    for (int n = 0; n != N; ++n) {
        str[n] = str[n].substr(cnts[n]);
    }
    return opt_dlt + solve();
}

int main(int argc, char* argv[]) {
    cin >> dec >> T;
    for (int t = 0; t != T; ++t) {
        cout << "Case #" << (t + 1) << ": ";
        cin >> N;
        for (int n = 0; n != N; ++n) {
            cin >> str[n];
        }
        bool ok = true;
        string s = str[0];
        s.erase(unique(s.begin(), s.end()), s.end());
        for (int n = 0; ok && n != N; ++n) {
            string s1 = str[n];
            s1.erase(unique(s1.begin(), s1.end()), s1.end());
            ok = (s1 == s);
        }
        if (!ok) {
            cout << "Fegla Won" << "\n";
        } else {
            cout << solve() <<  "\n";
        }
    }
    return 0;
}
