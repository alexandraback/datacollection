#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <ctime>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <algorithm>
#include <functional>
#include <numeric>
#include <limits>
#include <string>
#include <map>
#include <vector>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <array>
#include <tuple>
#include <utility>
#include <cctype>
#include <typeinfo>
using namespace std;

#define len(x)  (int((x).size()))
#define append push_back
#define pp make_pair
#define ff(a, b)    for (int a = 0; a < int(b); ++a)
#define ii(n)    ff(i, n)
#define kk(n)    ff(k, n)
#define mm(n)    ff(m, n)
#define fff(a, b, c) for (int a = int(b); a < int(c); ++a)
#define iii(a, b) fff(i, a, b)
#define kkk(a, b) fff(k, a, b)
#define mmm(a, b) fff(m, a, b)
#define xx first
#define yy second
#define bb begin()
#define ee end()
#define all(x)  (x).bb, (x).ee
#define ite(v)   decltype((v).bb)
#define fe(i, v) for(ite(v) i = (v).bb; i != (v).ee; ++i)
#define err(...)    { fprintf(stderr, __VA_ARGS__); fflush(stderr); }

using LL = long long;
using pii = pair<int, int>;


//const LL INF = 9223372036854775807LL;
const int INF = 2147483647;
   


int house[20][20];

int R, C, N;

int best = INF;

void backtrack(int cell, int left) {
    if (R*C == cell || 0 == left) {
        int here = 0;
        ii (R)
        kk (C-1)
            if (house[i][k] && house[i][k+1])
                ++here;
        ii (C)
        kk (R-1)
            if (house[k][i] && house[k+1][i])
                ++here;

        best = min(best, here);

        return;
    }

    int r = cell / C;
    int c = cell % C;
    house[r][c] = 1;
    backtrack(cell+1, left-1);
    house[r][c] = 0;
    if (R*C - cell-1 >= left)
        backtrack(cell+1, left);
}


int main() {
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    //cout << '\n';
    
    int T;
    cin >> T;
    fff (icase, 1, 1+T) {
        printf("Case #%d: ", icase);

        
        cin >> R >> C >> N;
        best = INF;
        ii (20)
        kk (20)
            house[i][k] = 0;
        backtrack(0, N);
        printf("%d\n", best);
        
    }

    return 0;
}

