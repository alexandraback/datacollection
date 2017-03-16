    
// compile this with a compiler supporting C++11
// link also the gmp library using the linker flags -lgmp -lgmpxx

//#define USE_DEBUG
//#define USE_BIGINT

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <cstdio>
#include <algorithm>
#include <numeric>
#include <cassert>
#include <random>
#include <cstdint>
#include <sstream>
#ifdef USE_BIGINT
  #include <gmpxx.h>
#endif

using namespace std;

#ifdef USE_DEBUG
  #define DBG
#else
  #define DBG if (0)
#endif

#ifdef USE_BIGINT
//typedef long long int int64;
//typedef long int64;
typedef mpz_class BigInt;
//typedef uint64_t BigInt;
#endif

bool check(const vector<int> &P) {
    int N = (int) P.size();
    int tot = 0;
    for (int i = 0; i < N; ++i)
        tot += P[i];
    float half = tot / 2.0f;
    for (int j = 0; j < N; ++j) {
        if (float(P[j]) > half) {
            printf("\nCHECK: ");
            for (int i = 0; i < N; ++i) {
                printf("%i ", P[i]);
            }
            printf(" FALSE\n");
            return false;
        }
    }
    return true;
}

int main(int argc, char **argv) {
    //cout.unsetf(ios::floatfield);
    cout.precision(10);

#if 1
    #define IN cin
#else
    ifstream IN("A-small-practice.in");
    if (!IN) {
        cerr << "Can't open input file\n";
        exit(1);
    }
#endif

    int T;
    IN >> T;
    for (int tc = 0; tc < T; ++tc) {
        int N;
        IN >> N;
        vector<int> P(N);
        int tot = 0;
        for (int i = 0; i < N; ++i) {
            IN >> P[i];
            tot += P[i];
        }

        cout << "Case #" << (tc + 1) << ":";

        while (tot > 0) {
            std::vector<int> idx(P.size());
            std::iota(idx.begin(), idx.end(), 0);
            std::sort(idx.begin(), idx.end(),
                [&P](int i1, int i2) { return P[i1] > P[i2]; } );
            if (P[idx[0]] > P[idx[1]] + 1 && tot != 3) {
                P[idx[0]] -= 2;
                if (check(P) == false)
                    printf(" ERROR!\n");
                tot -= 2;
                printf(" %c%c", 'A' + idx[0], 'A' + idx[0]);
            } else {
                if (P[idx[1]] >= 1 && tot != 3) {
                    --P[idx[0]];
                    --P[idx[1]];
                    if (check(P) == false)
                        printf(" ERROR!\n");
                    tot -= 2;
                    printf(" %c%c", 'A' + idx[0], 'A' + idx[1]);
                } else if (tot != 2) {
                    --P[idx[0]];
                    if (check(P) == false)
                        printf(" ERROR!\n");
                    --tot;
                    printf(" %c", 'A' + idx[0]);
                } else {
                    printf("WHAT TO DO?\n");
                    for (int i = 0; i < N; ++i) {
                        printf("%i ", P[i]);
                    }
                    exit(1);
                }
            }
        }
        
        cout << std::endl;
    }
    return 0;
}

