#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cmath>

using namespace std;

int r, c, n;
int minU;

int grid[100000];

int occupied(int cr, int cc) {
    if (cr < 0)
        return 0;
    if (cr >= r)
        return 0;
    if (cc < 0)
        return 0;
    if (cc >= c)
        return 0;
    return grid[cr*c+cc];
}

int countNeigh(int where) {
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};
    int i;
    int ans = 0;
    for (i = 0; i < 4; i++)
        ans += occupied(where/c+dx[i], where%c+dy[i]);
    return ans;
}

void calcUnhappy() {
    int i;
    int ans = 0;
    for (i = 0; i < r*c; i++)
        if (grid[i])
            ans += countNeigh(i);
    if (ans < minU)
        minU = ans;
}

void solve(int place, int remain) {
    if (place == r*c && remain == 0) {
        calcUnhappy();
        return;
    }
    if (place > r*c)
        return;
    if (remain < 0)
        return;
    if (remain > r*c - place)
        return;
    
    grid[place] = 0;
    solve(place+1,remain);
    grid[place] = 1;
    solve(place+1, remain-1);
}

int main() {
    int TT, T;
    scanf("%d", &TT);
    for (T = 1; T <= TT; T++) {
        printf("Case #%d: ", T);
        scanf("%d%d%d", &r, &c, &n);
        
        minU = 1000000;
        solve(0, n);
        
        printf("%d\n", minU/2);
    }
}
        