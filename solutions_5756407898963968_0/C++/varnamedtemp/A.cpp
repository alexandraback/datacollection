#include <iostream>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

int cnt[17],  R1, R2;
int main() {
    freopen("A-small-attempt0.in.txt", "r", stdin);
    freopen("A.out", "w", stdout);
    int T;
    scanf("%d",&T);
    for(int t = 1;t<=T;t++) {
        fill(cnt, cnt + 17, 0);
        scanf("%d",&R1);
        for(int i = 1;i<=4;i++) {
            for(int j = 1;j<=4;j++) {
                int n;
                scanf("%d",&n);
                if(i == R1)
                    cnt[n]++;
            }
        }
        scanf("%d",&R2);
        for(int i = 1;i<=4;i++) {
            for(int j = 1;j<=4;j++) {
                int n;
                scanf("%d",&n);
                if(i == R2)
                    cnt[n]++;
            }
        }
        int ans = 0, numOk = 0;
        for(int i = 1;i<=16;i++) {
            if(cnt[i] == 2) {
                ans = i;
                numOk++;
            }
        }
        printf("Case #%d: ", t);
        if(numOk == 0) {
            printf("Volunteer cheated!\n");
        }
        else if(numOk == 1) {
            printf("%d\n", ans);
        }
        else {
            printf("Bad magician!\n");
        }
    }
    return 0;
}
