#include <iostream>
#include <cstdio>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
#include <cstring>
#include <map>
#include <cassert>

using namespace std;

int X,Y,N;
vector<vector<bool> > M;

bool get(int mask, int x){
    return ((mask & (1<<x))) > 0;
}
int f(int mask){
    int idx=0;
    int ans = 0;
    for(int i=0;i<Y;i++) {
        for(int j=0;j<X;j++) {
            M[i][j] = get(mask, idx);
            idx++;

            if (j > 0 and M[i][j-1] and M[i][j])ans++;
            if (i > 0 and M[i-1][j] and M[i][j])ans++;
        }
    }

    assert(idx == Y*X);
    return ans;
}
void solve() {
    scanf("%d %d %d",&X, &Y, &N);

    M.clear();
    for(int i=1;i<=Y;i++)M.push_back(vector<bool>(X,false));

    int lim = 1 << (X * Y);
    int ans = -1,tmp;
    for (int i=0;i<lim; i++) {
        if (__builtin_popcount(i) == N) {
            tmp = f(i);
            if (ans == -1 or tmp < ans) {
                ans = tmp;
            }
        }
    }
    printf("%d\n", ans);
}
int main() {
    int NC;scanf("%d", &NC);
    for (int i=1; i<= NC; i++) {
        printf("Case #%d: ", i);
        solve();
    }
}