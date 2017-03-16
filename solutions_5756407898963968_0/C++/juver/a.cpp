#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cmath>
#include <ctime>
#include <float.h>

using namespace std;

#define REP(i, from, to) for (int i = (from); i < (to); ++i)
#define FOR(i, n) REP(i, 0, (n))
#define ALL(x) x.begin(), x.end()
#define SIZE(x) (int)x.size()
#define PB push_back
#define MP make_pair

typedef long long i64;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef vector<VS> VVS;
typedef pair<int, int> PII;

int find(int a[4][4], int n) {
    FOR (i, 4) FOR (j, 4) if (a[i][j] == n)
            return i;
    return -1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int tests;
    cin >> tests;

    FOR (t, tests) {
        int r1, r2;
        int a1[4][4], a2[4][4];

        cin >> r1;
        FOR (i, 4) FOR (j, 4) cin >> a1[i][j];
        cin >> r2;
        FOR (i, 4) FOR (j, 4) cin >> a2[i][j];

        --r1; --r2;

        VI candidates;
        REP (number, 1, 17) {
            int const row1 = find(a1, number);
            int const row2 = find(a2, number);

            if (row1 == r1 && row2 == r2)
                candidates.PB(number);
        }

        printf("Case #%d: ", t + 1);
        if (SIZE(candidates) == 1)
            printf("%d\n", candidates[0]);
        else if (SIZE(candidates) > 1)
            printf("Bad magician!\n");
        else
            printf("Volunteer cheated!\n");
    }

    return 0;
}
