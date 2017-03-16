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

int solve1(vector<int>& v) {
    int size = v.size();
    int ret = 0;
    for (int i = 1; i < size; i++) {
        ret += max(0, v[i - 1] - v[i]);
    }
    return ret;
}

int solve2(vector<int>& v) {
    int size = v.size();
    int hi = 0;
    for (int i = 1; i < size; i++) {
        hi = max(hi, v[i - 1] - v[i]);
    }
    int ret = 0;
    for (int i = 0; i < size - 1; i++) {
        ret += min(hi, v[i]);
    }
    return ret;
}

#define LARGE

int main() {

#ifndef LARGE
    ifstream in("A-small-attempt0.in");
    ofstream out("A-small-attempt0.out");
#else
    ifstream in("A-large.in");
    ofstream out("A-large.out");
#endif

    int T; in >> T;
    for (int t = 0; t < T; t++) {
        int N; in >> N;
        vector<int> v(N);
        for (int n = 0; n < N; n++) {
            in >> v[n];
        }
        out << "Case #" << t + 1 << ": " << solve1(v) << " " << solve2(v) << endl;
    }
    return 0;
}
