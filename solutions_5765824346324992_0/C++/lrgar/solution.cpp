// ================================================================================================
//  B.cpp
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
_BEGIN_PROBLEM(_GCJ15_02B, "GCJ15 02B")
#endif // _OJ_PROJECT

#define infinite_loop for (;;)

int main() {
    int T, B;
    long long N;
    string S;
    cin >> T;

    for (int _T = 1; _T <= T; ++_T) {
        cin >> B >> N;

        vector<int> M(B);
        for (int i = 0; i < B; ++i) cin >> M[i];

        auto f = [&M, &N](long long time) {
            long long processed = 0;
            for (int p : M) processed += (time + p - 1) / p;
            return processed <= N - 1;
        };

        long long low = 0, high = 10000000000000;
        while (low < high) {
            long long mid = (low + high + 1) / 2;
            if (f(mid))
                low = mid;
            else
                high = mid - 1;
        }

        vector<int> free;

        long long processed = 0;
        for (int i = 0; i < B; ++i) {
            if (low % M[i] == 0) free.push_back(i + 1);
            processed += (low + M[i] - 1) / M[i];
        }

        N -= processed;

        cout << "Case #" << _T << ": " << free[(int) N - 1] << endl;
    }

    return 0;
}

#if defined _OJ_PROJECT
_END_PROBLEM
#endif // _OJ_PROJECT

// ================================================================================================
//  End of file.
// ================================================================================================
