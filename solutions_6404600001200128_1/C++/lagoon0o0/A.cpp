#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <string>
#include <set>

using namespace std;
const int Mn = 1000 + 10;
int m[Mn],n;
inline int solve1() {
    int res(0);
    for(int i = 1; i < n; ++i) {
        if(m[i + 1] < m[i])
            res += m[i] - m[i + 1];
    }
    return res;
}
inline int solve2() {
    double res(0);
    double spd(0);
    for(int i = 1; i < n; ++i) {
        if(m[i + 1] < m[i])
            spd = max(spd,(m[i] - m[i + 1]) / 10.0);
    }
    for(int i = 1; i < n; ++i) {
        res += min(10 * spd,1.0 * m[i]);   
    }
    return res;
}
int main() {
    freopen("A-large.in","r",stdin);
    freopen("A-large.out","w",stdout);
    int T;
    scanf("%d",&T);
    for(int cas = 1; cas <= T; ++cas) {
        scanf("%d",&n);
        for(int i = 1; i <= n; ++i) {
            scanf("%d",&m[i]);
        }
        printf("Case #%d: %d %d\n",cas,solve1(),solve2());
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
} 
