#ifdef DEBUG_OUTPUT
#include "debug_output.h"
#else
#define PRINT(x)
#define PRINT_CONT(x)
#define PRINT_MSG(x)
#endif

#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <cstring>
#include <sstream>
#include <algorithm>
#include <memory.h>
#include <set>
#include <map>
#include <cstdio>
#include <cassert>
using namespace std;


// Enlarge MSVS stack size
#pragma comment(linker, "/STACK:16777216")

#define pb push_back
#define all(c) c.begin(), c.end()
#define mp(x, y) make_pair(x, y)
#define sz(x) static_cast<int>(x.size())
typedef long long int64;

template<class T> T sqr(const T& t) {return t * t;}
template<class T> T abs(const T& t) {return ((t > 0) ? (t) : (-t));}

void initialize()
{
    freopen("2.in", "r", stdin);
    freopen("2.out", "w", stdout);
}

const int MAX = 20;
int table[MAX][MAX];

int stupid(int r, int c, int index, int free) {
    if (free == 0) {
        int res = 0;
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                if (i + 1 < r && table[i][j] && table[i + 1][j]) {
                    res += 1;
                }
                if (j + 1 < c && table[i][j] && table[i][j + 1]) {
                    res += 1;
                }
            }
        }
        return res;
    }

    int x = index / c;
    int y = index % c;
    int res = MAX * MAX * 4;

    if (index >= r * c) {
        return res;
    }

    table[x][y] = 1;
    res = min(res, stupid(r, c, index + 1, free - 1));
    table[x][y] = 0;
    res = min(res, stupid(r, c, index + 1, free));

    return res;
}


int main()
{
    initialize();

    int T;
    cin >> T;

    for (int tt = 1; tt <= T; ++tt) {
        int n, m, k;
        cin >> n >> m >> k;
        if (n > m) {
            swap(n, m);
        }

        //vector<int> noise;

        //for (int i = 0; i < n; ++i) {
        //    for (int j = 0; j < m; ++j) {
        //        if ((i + j) % 2 == 0) {
        //            noise.pb(0);
        //        } else if ((i == 0 || i == (n - 1)) && (j == 0 || j == (m - 1))) {
        //            if (n == 1) {
        //                noise.pb(1);
        //            } else {
        //                noise.pb(2);
        //            }
        //        } else if ((i == 0 || i == (n - 1)) || (j == 0 || j == (m - 1))) {
        //            if (n == 1) {
        //                noise.pb(2);
        //            } else {
        //                noise.pb(3);
        //            }
        //        } else {
        //            noise.pb(4);
        //        }
        //    }
        //}
        //sort(all(noise));

        //int res = 0;
        //for (int i = 0; i < k; ++i) {
        //    res += noise[i];
        //}
        //if (n == 3 && m == 3 && k == 8) {
        //    res = 8;
        //}

        //int correct = stupid(n, m, 0, k);
        //if (res != correct) {
        //    cerr << n << " " << m << " " << k << ": " << res << " " << correct << endl;
        //    PRINT(noise);
        //    cerr << endl;
        //}

        cout << "Case #" << tt << ": " << stupid(n, m, 0, k) << endl;
    }
    
    return 0;
}
