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
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>

using namespace std;

#define pb push_back
#define mp make_pair

#define ALL(x) (x).begin(),(x).end()
#define CLR(a,b) memset(a,b,sizeof(a))
#define REPN(x,a,b) for (int x=a; x<b;++x)
#define REP(x,b) REPN(x, 0, b)

#define dbg(x) cout << #x << " = " << x << endl;
#define dbg2(x, y) cout << #x << " = " << x << "  " << #y << " = " << y << endl;
#define dbg3(x, y, z) cout << #x << " = " << x << "  " << #y << " = " << y << "  " << #z << " = " << z << endl;
#define dbg4(x, y, z, w) cout << #x << " = " << x << "  " << #y << " = " << y << "  " << #z << " = " << z << "  " << #w << " = " << w <<  endl;

int maze[20][20];

int main() { 

    int T;
    cin >> T;

    REP(tc, T) {
        int r, c, n;
        cin >> r >> c >> n;


        int best = 100;

        REP(i, (1<<(r*c))) {
            if (__builtin_popcount(i)==n) {
                CLR(maze, 0);
                REP(j, r*c) if (i & (1<<j)) {
                    maze[j/c][j%c] = 1;
                }
                int res = 0;
                REP(ii, r) REP(j, c) {
//                    dbg3(ii, j, maze[ii][j]);
                    if (ii < r-1) if (maze[ii][j] && maze[ii+1][j]) res++;
                    if (j < c-1) if (maze[ii][j] && maze[ii][j+1]) res++;
                }
                best = min(res, best);
            }
        }

        cout << "Case #" << tc+1 << ": " << best <<"\n";
    }

	return 0;
}

