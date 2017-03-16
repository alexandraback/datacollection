#include <cstdio>
#include <algorithm>
using namespace std;
int T, r, c, n, ans, sum, d[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
bool ena(int x, int y) { return 0<=x && x<r && 0<=y && y<c; }
int val(int x, int y) { return (x*c+y); }
int main()
{
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
    scanf("%d", &T);
    for (int count = 1; count <= T; count++) {
        scanf("%d%d%d", &r, &c, &n);
        ans = ~0U>>1;
        for (int i = 0; i < 1<<(r*c); i++) {
            int sum = 0;
            for (int j = 0; j < r*c; j++) if ((i>>j)&1) sum++;
            if (sum == n) {
                int value = 0;
                for (int x = 0; x < r; x++)
                    for (int y = 0; y < c; y++) 
                        if ((i>>val(x,y))&1) {
                        for (int k = 0; k < 4; k++)
                            if (ena(x+d[k][0], y+d[k][1]) && ((i>>val(x+d[k][0], y+d[k][1]))&1)) {
                                value++;
                            }
                        //printf("%d %d %d\n", x, y, value);
                    }
                ans = min(ans, value/2);
            }
        }
        printf("Case #%d: %d\n", count, ans);
    }
}
