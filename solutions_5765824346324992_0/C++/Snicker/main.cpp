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
        int pos;
        scanf("%d%d",&n, &pos);
        for(int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
        }
        long long l, r, mid;
        l = 0, r = (long long)1e15;
        while(l < r) {
            mid = (l + r) / 2;
            long long tot = 0;
            for(int i = 1; i <= n; i++) {
                tot += mid / a[i] + 1;
            }
           // cout<<tot<<" & "<<mid<<endl;
            if(tot >= pos) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        long long ans = -1;
        int who;
        for(int i = 1; i <= n; i++) {
            int cnt = r / a[i];
            pos -= cnt;
            if(r % a[i]) {
                pos--;
            }
        }
        //cout<<pos<<" "<<r<<endl;
        for(int i = 1; i <= n; i++) {
            if(r % a[i] == 0) {
                pos--;
                if(pos == 0) {
                    who = i;
                    break;
                }
            }
        }
        printf("Case #%d: %d\n", ++cas, who);
    }
    //SYSTEM("Pause");
    return 0;
}