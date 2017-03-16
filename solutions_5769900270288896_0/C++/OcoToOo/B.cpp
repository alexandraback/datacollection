#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <cstring>
#include <cmath>
#include <climits>
#include <ctime>
#include <cctype>
#include <fstream>

using namespace std;

typedef long long ll;

int R, C, N;
bool b[16][16];

int solve2() {
    int ret = 0;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (b[i][j]) {
                if (i != R - 1 && b[i + 1][j]) {
                    ret++;
                }
                if (j != C - 1 && b[i][j + 1]) {
                    ret++;
                }
            }
        }
    }
    return ret;
}

int solve() {
    int ret = INT_MAX;
    int n = R * C;
    for (int i = 0; i < (1 << n); i++) {
        int cnt = 0;
        for (int j = 0; j < n; j++) {
            if ((i & (1 << j))) {
                b[j / C][j % C] = true;
                cnt++;
            } else {
                b[j / C][j % C] = false;
            }
        }
        if (cnt != N) {
            continue;
        }
        ret = min(ret, solve2());
    }
    return ret;
}

//#define LARGE

int main() {

#ifndef LARGE
    ifstream in("B-small-attempt0.in");
    ofstream out("B-small-attempt0.out");
#else
    ifstream in("B-large.in");
    ofstream out("B-large.out");
#endif

    int T; in >> T;
    for (int t = 0; t < T; t++) {
        in >> R >> C >> N;
        int ret = solve();
        out << "Case #" << t + 1 << ": " << ret << endl;
    }
    return 0;
}
