#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int a[1010];
int main() {
    freopen("E:\\NutStore\\Workspace\\ClionProjects\\ClionP\\input.txt", "r", stdin);
    freopen("E:\\NutStore\\Workspace\\ClionProjects\\ClionP\\output.txt", "w", stdout);
    int T;
    scanf("%d", &T);
    int cas = 0;
    while(T--) {
        int n;
        scanf("%d", &n);
        for(int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
        }
        int ans1 = 0;
        int ans2 = 0;
        bool fg = 1;
        for(int i = 1; i < n; i++) {
            if(a[i] - a[i + 1] > 0) {
                ans1 += a[i] - a[i + 1];
            } else {
                fg = 0;
            }
        }
        if(fg) {
            ans2 = 0;
        } else {
            ans2 = 100000000;
            for(int i = 0; i <= 10000; i++) {
                int now = a[1];
                bool tmp = 1;
                int sum = 0;
                for(int j = 2; j <= n; j++) {
                    sum += min(i, now);
                    now = max(now - i, 0);
                    if(now > a[j]) {
                        tmp = 0;
                    }
                    now = a[j];
                }
                if(tmp) {

                    ans2 = min(ans2, sum);
                }
            }
        }

        printf("Case #%d: %d %d\n", ++cas, ans1, ans2);
    }
    //SYSTEM("Pause");
    return 0;
}