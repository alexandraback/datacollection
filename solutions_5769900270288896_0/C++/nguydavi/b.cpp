#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

const int MAXN = 20;
int R, C, N;
bool building[MAXN][MAXN];

bool isIn(int r, int c) {
    return r >= 0 && c >= 0 && r<R && c < C;
}

int unhappy() {
    int res = 0;
    for(int i=0;i<R;++i)
        for(int j=0;j<C;++j) {
            if(isIn(i+1, j) && building[i][j] && building[i+1][j])
                ++res;
            if(isIn(i, j+1) && building[i][j] && building[i][j+1])
                ++res;
        }

    /*
    for(int i=0;i<R;++i) {
        for(int j=0;j<C;++j)
            cout << building[i][j] << " ";
        cout << endl;
    }
    cout << "DEBUG " << res << endl;
    */

    return res;
}

int solve(int r, int c, int n) {
    if(n == 0)
        return unhappy();
    if(r>=R)
        return 3*N;

    building[r][c] = true;
    int res = solve(r+(c+1==C), (c+1)%C, n-1);
    building[r][c] = false;

    res = min (res, solve(r+(c+1==C), (c+1)%C, n));
    return res;
}

int main() {
    int tc;
    cin >> tc;
    for(int ii=1;ii<=tc;++ii) {
        memset(building, false, sizeof(building));
        cin >> R >> C >> N;
        cout << "Case #" << ii << ": " << solve(0, 0, N) << "\n";
    }

    return 0;
}
