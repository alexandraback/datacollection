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

deque<PII> parse(string const& s) {
    deque<PII> p;
    int cnt = 0;
    char c = s[0];
    for (int i = 0; i < SIZE(s); ++i) {
        if (s[i] != c) {
            p.PB(MP(c, cnt));
            c = s[i];
            cnt = 1;
        } else {
            ++cnt;
        }
    }

    p.PB(MP(c, cnt));

    return p;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(false);

    int tests;
    cin >> tests;

    FOR (testId, tests) {
        int n;
        cin >> n;

        VS s(n);
        FOR (i, n) cin >> s[i];

        vector<deque<PII> > p;
        FOR (i, n) p.PB(parse(s[i]));

        int result = 0;
        while (true) {
            set<char> letters;
            VI count;
            set<int> ccc;
            FOR (j, SIZE(p)) {
                if (p[j].empty()) continue;
                letters.insert(p[j].front().first);
                count.PB(p[j].front().second);
                ccc.insert(p[j].front().second);
                p[j].pop_front();
            }

            if (count.empty()) break;
            if (SIZE(count) != n || letters.size() != 1) {
                printf("Case #%d: Fegla Won\n", testId + 1);
                goto next;
            }

            int best = -1;
            for (int size : ccc) {
                int moves = 0;
                FOR (i, n) {
                    moves += abs(count[i] - size);
                }

                if (best == -1 || best > moves)
                    best = moves;
            }

            result += best;
        }

        printf("Case #%d: %d\n", testId + 1, result);
        next:
        continue;
    }

    return 0;
}
