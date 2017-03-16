#include <cstdio> 
#include <cstdlib> 
#include <cmath> 
#include <cstring> 
#include <climits> 
#include <cfloat> 
#include <map> 
#include <utility> 
#include <set> 
#include <iostream> 
#include <memory> 
#include <string> 
#include <vector> 
#include <algorithm> 
#include <functional> 
#include <sstream> 
#include <complex> 
#include <stack> 
#include <queue> 
#include <numeric>
#include <cassert>
#include <gmpxx.h>

#define FOR(i, min, max) for (int i = (min); i < (max); ++i) 
#define FORE(i, min, max) for (int i = (min); i <= (max); ++i) 
#define REP(i, n) for (int i = 0; i < (n); ++i) 
#define REPV(vec, i) for (int i = 0; i < (int)(vec.size()); ++i) 
#define FOR_EACH(vec, it) for (typeof((vec).begin()) it = (vec).begin(); it != (vec).end(); ++it)

using namespace std; 
static const double EPS = 1e-12; 
typedef long long ll; 
typedef mpz_class bint;

string solve(void)
{
    int cards[2][4][4];
    int row[2];

    REP(i, 2) {
        cin >> row[i];
        --row[i];
        REP(r, 4) REP(c, 4) {
            cin >> cards[i][r][c];
        }
    }

    int matchCount = 0;
    int matchNum = -1;
    REP(c0, 4) REP(c1, 4) {
        if (cards[0][row[0]][c0] == cards[1][row[1]][c1]) {
            matchCount++;
            matchNum = cards[0][row[0]][c0];
        }
    }

    if (matchCount == 0) {
        return "Volunteer cheated!";
    } else if (matchCount == 1) {
        ostringstream oss;
        oss << matchNum;
        return oss.str();
    } else {
        return "Bad magician!";
    }
}

int main(void)
{
    int T;
    cin >> T;
    REP(_t, T) {
        cout << "Case #" << _t+1 << ": " << solve() << endl;
    }

    return 0;
}

