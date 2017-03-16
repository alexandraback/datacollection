#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <map>
#include <set>
#include <vector>

using namespace std;

const int32_t N = 101;
vector<pair<char, int32_t> > D[N];
char str[N];
int32_t n;

void Parse(char str[N], int32_t idx) {
    int32_t count = 1;
    char c = str[0];
    D[idx].clear();
    for (int32_t i = 1; str[i]; i++) {
        if (str[i] == c) {
            count++;
        } else {
            D[idx].push_back(make_pair(c, count));
            count = 1;
            c = str[i];
        }
    }
    D[idx].push_back(make_pair(c, count));
}
bool Valid() {
    for (int32_t i = 1; i < n; i++) {
        if (D[i].size() != D[i - 1].size()) {
            return false;
        }
        for (int32_t j = 0; j < D[i].size(); j++) {
            if (D[i][j].first != D[i - 1][j].first) {
                return false;
            }
        }
    }
    return true;
}
int32_t OneColumn(const vector<int32_t> &v) {
    int32_t mmin = N + 1;
    int32_t mmax = 0;
    for (int32_t i = 0; i < v.size(); i++) {
        if (v[i] > mmax) {
            mmax = v[i];
        }
        if (v[i] < mmin) {
            mmin = v[i];
        }
    }
    int32_t ans = N * N;
    for (int32_t i = mmin; i <= mmax; i++) {
        int32_t cur = 0;
        for (int32_t j = 0; j < v.size(); j++) {
            cur += abs(v[j] - i);
        }
        if (cur < ans) {
            ans = cur;
        }
    }
    return ans;
}
int32_t Calc() {
    int32_t ans = 0;
    for (int32_t j = 0; j < D[0].size(); j++) {
        vector<int32_t> tmp;
        for (int32_t i = 0; i < n; i++) {
            tmp.push_back(D[i][j].second);
        }
        ans += OneColumn(tmp);
    }
    return ans;
}
int32_t main() {
    int32_t cas;
    scanf("%d", &cas);
    for (int32_t ic = 1; ic <= cas; ic ++) {
        scanf("%d", &n);
        for (int32_t i = 0; i < n; i++) {
            scanf("%s", str);
            Parse(str, i);
        }
        if (!Valid()) {
            printf("Case #%d: Fegla Won\n", ic);
        } else {
            printf("Case #%d: %d\n", ic, Calc());
        }
    }
}
