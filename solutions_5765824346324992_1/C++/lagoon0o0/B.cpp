#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <string>
#include <set>

using namespace std;
const int Mb = 1000 + 10;
int t[Mb];
int n,b;
inline bool check(long long val) {
    long long tot(0);
    for(int i = 1; i <= b; ++i)
        tot += (val + t[i] - 1) / t[i];
    return tot >= n;
}
int main() {
    freopen("B-large.in","r",stdin);
    freopen("B-large.out","w",stdout);
    int T;
    cin >> T;
    for(int cas = 1; cas <= T; ++cas) {
        scanf("%d%d",&b,&n);
        for(int i = 1; i <= b; ++i)
            scanf("%d",&t[i]);
        long long l = 0, r = 1e15;
        while(l <= r) {
            long long mid = l + r >> 1;
            if(check(mid)) {
                r = mid - 1;    
            }
            else 
                l = mid + 1;
        }
        int num(0);
        int tot(0);
        int ans(0);
        int cnt(0);
        for(int i = 1; i <= b; ++i)
            tot += (r + t[i] - 1) / t[i];
        tot = n - tot;
        for(int i = 1; i <= b; ++i) {
            if(r % t[i] == 0) {
                num++;
                if(num == tot) {
                    ans = i;
                    break;
                }
            }
        }
        //cerr << l << endl;
        printf("Case #%d: %d\n",cas,ans);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
} 
