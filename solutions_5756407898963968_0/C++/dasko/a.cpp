#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <sstream>
#include <iostream>
#include <set>
#include <map>
#include <cassert>

#define REP(AA,BB) for(int AA=0; AA<(BB); ++AA)
#define FOR(AA,BB,CC) for(int AA=(BB); AA<(CC); ++AA)
#define FC(AA,BB) for(__typeof((AA).begin()) BB=(AA).begin(); BB!=(AA).end(); ++BB)
#define SZ(AA) ((int)((AA).size()))
#define ALL(AA) (AA).begin(), (AA).end()
#define PB push_back
#define MP make_pair

using namespace std;

typedef vector<int> VI;
typedef pair<int, int> PII;
typedef long long LL;
typedef long double LD;

VI get() {
    int r; scanf("%d", &r); --r;
    VI res;
    REP (i, 4) {
        VI tmp;
        REP (j, 4) {
            int a; scanf("%d", &a);
            tmp.PB(a);
        }
        sort(ALL(tmp));
        if (i == r) {
            res = tmp;
        }
    }
    return res;
}

string test() {
    VI a = get(), b = get(), c(4);
    c.resize(set_intersection(ALL(a), ALL(b), c.begin()) - c.begin());
    stringstream res;
    if (SZ(c) == 1) {
        res << c[0];
    } else if (SZ(c) > 1) {
        res << "Bad magician!";
    } else {
        res << "Volunteer cheated!";
    }
    return res.str();
}

int main(void) {
    int T; scanf("%d", &T);
    for (int t = 1; t <= T; ++t) {
        printf("Case #%d: %s\n", t, test().c_str());
    }
    return 0;
}

