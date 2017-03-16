#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <limits.h>
#include <time.h>
#include <ctype.h>
#include <math.h>
#include <sstream>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <functional>
#include <numeric>
#include <utility>
#include <iomanip>
#include <float.h>
#include <fstream>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> PII;
vector<char> V[100];
int N;
vector<pair<char, int>> P[100];

int solve(vector<string>& v) {
    for (int i = 0; i < N; i++) {
        V[i].clear();
        P[i].clear();
        char c = '.';
        int cnt = 0;
        for (int j = 0; j < v[i].size(); j++) {
            if (c == '.') {
                V[i].push_back(v[i][j]);
                c = v[i][j];
                cnt++;
                if (j == (int)(v[i].size()) - 1) {
                    P[i].push_back(make_pair(c, cnt));
                }
            } else if (v[i][j] != c) {
                V[i].push_back(v[i][j]);
                P[i].push_back(make_pair(c, cnt));
                c = v[i][j];
                cnt = 1;
                if (j == (int)(v[i].size()) - 1) {
                    P[i].push_back(make_pair(c, cnt));
                }
            } else {
                cnt++;
                if (j == (int)(v[i].size()) - 1) {
                    P[i].push_back(make_pair(c, cnt));
                }
            }
        }
    }
    for (int i = 1; i < N; i++) {
        if (V[0] != V[i]) {
            return -1;
        }
    }
    int ret = 0;
    for (int i = 0; i < V[0].size(); i++) {
        char c = V[0][i];
        int low = INT_MAX;
        for (int j = 1; j <= 100; j++) {
            int cnt = 0;
            for (int n = 0; n < N; n++) {
                cnt += abs(P[n][i].second - j);
            }
            low = min(low, cnt);
        }
        ret += low;
    }
    return ret;
}

//#define LARGE

int main() {

#ifndef LARGE
    ifstream in("A-small-attempt0.in");
    ofstream out("A-small-attempt0.out");
#else
    ifstream in("A-large-attempt.in");
    ofstream out("A-large-attempt.out");
#endif

    int T; in >> T;
    for (int t = 0; t < T; t++) {
        in >> N;
        vector<string> v(N);
        for (int n = 0; n < N; n++) {
            in >> v[n];
        }
        int ret = solve(v);
        if (ret == -1) {
            out << "Case #" << t + 1 << ": " << "Fegla Won" << endl;
        } else {
            out << "Case #" << t + 1 << ": " << ret << endl;
        }
    }
    return 0;
}
