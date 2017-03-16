#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <set>
#include <map>
#include <algorithm>

#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
using namespace std;

const int INF = 0x3f3f3f3f;
const double EPS = 0.000000001;
const double PI = 3.141592653589793;
const long long LLINF = 99999999999999999LL;
const int MAX_N = 1000002;

int Ans[22][22][22];

void solve(int n, int m) {
    pair < int, int > v[20 * 20];

    int nrOfRooms = 0;
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= m; ++j) {
            v[nrOfRooms++] = make_pair(i, j);
        }
    }

    for(int rooms = 1; rooms <= 16; ++rooms) {
        Ans[n][m][rooms] = INF;
    }

    bool Grid[20][20];
    for(int conf = 0; conf < (1 << nrOfRooms); ++conf) {
        int rooms = 0;
        for(int i = 0; i < nrOfRooms; ++i) {
            int x = v[i].first, y = v[i].second;
            if(conf & (1 << i)) {
                Grid[x][y] = 1;
                ++rooms;
            }
            else {
                Grid[x][y] = 0;
            }
        }

        int cost = 0;
        for(int i = 1; i <= n; ++i) {
            for(int j = 2; j <= m; ++j) {
                if(Grid[i][j - 1] && Grid[i][j]) {
                    ++cost;
                }
            }
        }
        for(int i = 2; i <= n; ++i) {
            for(int j = 1; j <= m; ++j) {
                if(Grid[i - 1][j] && Grid[i][j]) {
                    ++cost;
                }
            }
        }

        Ans[n][m][rooms] = min(Ans[n][m][rooms], cost);
    }
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("data.in", "r", stdin);
        freopen("data.out", "w", stdout);
    #endif

    for(int i = 1; i <= 16; ++i) {
        for(int j = 1; j <= 16; ++j) {
            if(i * j <= 16) {
                solve(i, j);
            }
        }
    }

    int T;
    cin >> T;
    for(int test = 1; test <= T; ++test) {
        int N, M, rooms;

        cin >> N >> M >> rooms;

        printf("Case #%d: %d\n", test, Ans[N][M][rooms]);
    }

    return 0;
}
