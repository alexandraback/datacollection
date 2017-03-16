#include <cstdio>
#include <iostream>
#include <set>
using namespace std;

int main() {
    freopen("A-small-attempt0.in", "r", stdin);
    freopen("A-small-attempt0.out", "w", stdout);
    int T;
    scanf("%d", &T);
    for ( int i = 1; i <= T; i++ ) {
        int A, B, grid1[4][4], grid2[4][4];
        scanf("%d", &A);
        for ( int j = 0; j < 4; j++ ) for ( int k = 0; k < 4; k++ ) scanf("%d", &grid1[j][k]);
        scanf("%d", &B);
        for ( int j = 0; j < 4; j++ ) for ( int k = 0; k < 4; k++ ) scanf("%d", &grid2[j][k]);
        int cnt = 0, ans = 0;
        for ( int j = 0; j < 4; j++ ) {
            for ( int k = 0; k < 4; k++ ) {
                if ( grid1[A-1][j] == grid2[B-1][k] ) {
                    cnt++;
                    ans = grid1[A-1][j];
                }
            }
        }
        if ( cnt == 0 ) printf("Case #%d: Volunteer cheated!\n", i);
        else if ( cnt == 1 ) printf("Case #%d: %d\n", i, ans);
        else printf("Case #%d: Bad magician!\n", i);
    }
}
