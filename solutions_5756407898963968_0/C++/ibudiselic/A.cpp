#include <algorithm>
#include <cassert>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <functional>
#include <iostream>
#include <iterator>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <string>
#include <sstream>
#include <utility>
#include <vector>

using namespace std;

const string BAD_MAGIC = "Bad magician!";
const string CHEAT = "Volunteer cheated!";

const int MAXN = 17;
bool ok[MAXN];
int A[4][4];
string solve() {
    fill(ok, ok+MAXN, true);
    for (int iter=0; iter<2; ++iter) {
        int ans;
        cin >> ans;
        for (int i=0; i<4; ++i) {
            for (int j=0; j<4; ++j) {
                cin >> A[i][j];
                if (i+1 != ans) ok[A[i][j]] = 0;
            }
        }
    }

    int cntok = 0;
    int sol = 0;
    for (int i=1; i<17; ++i) {
        if (ok[i]) {
            ++cntok;
            sol = i;
        }
    }
    if (cntok == 1) {
        assert(sol > 0);
        ostringstream os;
        os << sol;
        return os.str();
    } else if (cntok == 0) {
        return CHEAT;
    } else {
        return BAD_MAGIC;
    }
}

int main() {
    int T;
    cin >> T;
    for (int t=1; t<=T; ++t) {
        cout << "Case #" << t << ": " << solve() << '\n';
    }
	return 0;
}
