#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <functional>
#include <utility>
#include <numeric>
#include <string.h>

using namespace std;

typedef unsigned long long ulong;
typedef unsigned int uint;
typedef long long int64;


inline ulong max(ulong a, ulong b) {
    return a > b ? a : b;
}

inline ulong min(ulong a, ulong b) {
    return a < b ? a : b;
}

ulong num_bits(ulong bits) {
    ulong res = 0;
    while (bits != 0) {
        if ((bits & 1) != 0)
            ++res;
        bits >>= 1;
    }
    return res;
}

ulong unhappiness(ulong r, ulong c, ulong bits) {
    ulong sq = r*c;
    ulong res = 0;
    ulong bit = 1;
    for (ulong i = 0; i < sq; ++i, bit <<= 1) {
        if ((bits & bit) == 0)
            continue;

        ////cerr << "bit " << i << endl;
        if (i % c != c - 1) {
            ulong nextBit = bit << 1;
            if ((bits & nextBit) != 0) {
                //cerr << "next for " << i << endl;
                ++res;
            }
        }

        if (i / c < r - 1) {
            ulong downBit = bit << c;
            if ((bits & downBit) != 0) {
                //cerr << "down for " << i << endl;
                ++res;
            }
        }
    }
    return res;
}

int main() {
    //cout << num_bits(0) << ' ' << num_bits(1) << ' ' << num_bits(6) << endl;
    //cout << unhappiness(3, 2, 0b111101) << endl;
    //return 0;
    ulong numTests = 0;
    cin >> numTests;
    for (ulong t = 1; t <= numTests; ++t) {
        ulong r, c, n;
        cin >> r >> c >> n;

        ulong lim = 1 << (r*c);
        ulong minUnhappiness = 1000000000;

        for (ulong i = 0; i < lim; ++i) {
            if (num_bits(i) != n)
                continue;

            minUnhappiness = std::min(minUnhappiness, unhappiness(r, c, i));
        }


        cout << "Case #" << t << ": " << minUnhappiness << endl;
    }
    return 0;
}

