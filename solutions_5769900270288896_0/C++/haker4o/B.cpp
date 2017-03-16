#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <cstring>
#include <cstdlib>
#include <map>
#include <set>
#include <queue>
#include <stack>

#define mp make_pair

using namespace std;

typedef long long ll;

int r, c, n;
bool v[20][20];
int calc(int mask) {
    memset(v, 0, sizeof(v));
    int i, j;
    for(i=0; i<r*c; ++i) {
        int cr = i/c;
        int cc = i%c;
        v[cr][cc] = ((mask >> i) & 1);
    }
    int res=0;
    for(i=0; i<r; ++i) {
        for(j=0; j<c; ++j) {
            if (!v[i][j]) continue;
            if (j+1 < c && v[i][j+1]) ++res;
            if (i+1 < r && v[i+1][j]) ++res;
        }
    }
    return res;
}

int main() {
    freopen("B-small-attempt0.in", "r", stdin);
    freopen("B-small-attempt0.out", "w", stdout);
    int T, NT;
    cin>>NT;
    int i, j, n, m;
    for(T=1; T<=NT; ++T) {
        cin>>r>>c>>n;
        int res= 100000;
        for(i=0; i<(1<<(r*c)); ++i) {
            if (__builtin_popcount(i) != n) continue;
            res = min(res, calc(i));
        }
        printf("Case #%d: %d\n", T, res);
    }
    return 0;
}
