#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

int r[2];
int a[2][4][4];

int main() {
    int T;
    scanf("%d", &T);
    for (int cs = 1; cs <= T; ++cs) {
        printf("Case #%d: ", cs);
        for (int k = 0; k < 2; ++k) {
            scanf("%d", &r[k]);
            r[k]--;
            for (int i = 0; i < 4; ++i) {
                for (int j = 0; j < 4; ++j) {
                    scanf("%d", &a[k][i][j]);
                }
            }
        }
        int cnt = 0;
        int num = 0;
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 4; ++j) {
                if (a[0][r[0]][i] == a[1][r[1]][j]) {
                    cnt++;
                    num = a[0][r[0]][i];
                }
            }
        }
        if (cnt == 1) {
            printf("%d\n", num);
        } else if (cnt > 1) {
            printf("Bad magician!\n");
        } else {
            printf("Volunteer cheated!\n");
        }
    }
    return 0;
}


