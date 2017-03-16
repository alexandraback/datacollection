#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
#include <cmath>
#include <set>
#include <functional>
#include <queue>
#include <iomanip>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pr;
typedef pair<ll,ll> prl;

#define double long double

#define REP(i, n) for (int i = 0; i < n; ++i)

using namespace std;

int a[4][4];
int b[4][4];
int x, y;

void solve(int t) {
    int k = 0;
    int res = -1;
    for (int i =0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            if (a[x][i] == b[y][j])
            {
                k++;
                res = a[x][i];
            }
        }
    }
    if (k == 0) {
        printf("Case #%d: Volunteer cheated!\n", t + 1);
    } else if (k == 1) {
        printf("Case #%d: %d\n", t + 1, res);
    } else {
         printf("Case #%d: Bad magician!\n", t + 1);
    }
}


    
int main() {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
 
    int T;
    scanf("%d", &T);
    
    
    for (int t = 0 ; t < T; ++t) {
        scanf("%d", &x);
        x--;
        REP(i, 4) {
            REP(j, 4) {
                scanf("%d", &a[i][j]);
            }
        }
        scanf("%d", &y);
        y--;
        REP(i, 4) {
            REP(j, 4) {
                scanf("%d", &b[i][j]);
            }
        }
        solve(t);
        
    }
    
    return 0;
}

