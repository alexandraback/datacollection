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

int B;
int N;

bool func(ll n, vector<int>& v) {
    ll sum = 0;
    for (int i = 0; i < B; i++) {
        sum += (n + v[i] - 1) / v[i];
    }
    return sum >= N;
}

int solve(vector<int>& v) {
    ll hi = 100000LL * N;
    ll lo = 0;
    while (hi - lo > 1) {
        ll mid = (hi + lo) / 2;
        if (func(mid, v)) {
            hi = mid;
        } else {
            lo = mid;
        }
    }
//    cout << hi << endl;
    ll total = 0;
    for (int i = 0; i < B; i++) {
        total += (hi - 1 + v[i] - 1) / v[i];
    }
    for (int i = 0; i < B; i++) {
        if (((hi + v[i] - 1) / v[i]) != (hi - 1 + v[i] - 1 ) / v[i]) {
            total++;
        }
        if (total >= N) {
            return i + 1;
        }
    }
    return 0;
}

//#define LARGE

int main() {

#ifndef LARGE
    ifstream in("B-small-attempt2.in");
    ofstream out("B-small-attempt2.out");
#else
    ifstream in("B-large.in");
    ofstream out("B-large.out");
#endif

    int T; in >> T;
    for (int t = 0; t < T; t++) {
        in >> B >> N;
        vector<int> M(B);
        for (int m = 0; m < B; m++) {
            in >> M[m];
        }
        int ret = solve(M);
        out << "Case #" << t + 1 << ": " << ret << endl;
        cout << "Case #" << t + 1 << ": " << ret << endl;
    }
    getchar();
    return 0;
}
