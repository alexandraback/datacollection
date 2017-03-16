// ================================================================================================
//  A.cpp
//  Written by Luis Garcia, 2015
// ================================================================================================

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <string>
#include <iterator>
#include <numeric>
#include <iostream>

using namespace std;

#if defined _OJ_PROJECT
_BEGIN_PROBLEM(_GCJ15_02A, "GCJ15 02A")
#endif // _OJ_PROJECT

#define infinite_loop for (;;)

int main() {
    int T, N;
    string S;
    cin >> T;

    for (int _T = 1; _T <= T; ++_T) {
        cin >> N;

        vector<int> m(N);
        for (int i = 0; i < N; ++i) cin >> m[i];

        int ans1 = 0, ans2 = 0;
        for (int i = 1; i < N; ++i)
            if (m[i - 1] > m[i])
                ans1 += m[i - 1] - m[i];

        double p = 0;
        for (int i = 0; i < N; ++i)
            for (int j = i + 1; j < N; ++j)
                if (m[i] >= m[j])
                    p = max(p, (m[i] - m[j]) / 10. / (j - i));

        if (p > 0.0000001)
            for (int i = 1; i < N; ++i) {
                if (m[i - 1] / p > 10.0000001)
                    ans2 += (int) floor(p * 10 + 0.0000001);
                else
                    ans2 += m[i - 1];
            }

        cout << "Case #" << _T << ": " << ans1 << " " << ans2 << endl;
    }

    return 0;
}

#if defined _OJ_PROJECT
_END_PROBLEM
#endif // _OJ_PROJECT

// ================================================================================================
//  End of file.
// ================================================================================================
