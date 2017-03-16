#include <algorithm>
#include <queue>
#include <cstring>
#include <stdio.h>
#include <iostream>
using namespace std;

typedef long long LL;

int n,m;
int anst[2000],a[2000];
int solve(LL t){
        int cnt = 0;
        LL tot = 0;
        for (int i = 0;i < n;i ++){
                tot += (t-1) / a[i] + 1;
                if (t % a[i] == 0) anst[cnt ++] = i;
        }      

        //cout << t << ' ' << tot << ' ' << cnt << ' ' << anst[2] << endl;
        if (tot + cnt < m) return -1;
        else if (tot < m && tot + cnt >= m) return anst[m - tot - 1];
        else return 1;

}

int main(){
        int tt,ca = 0;
        scanf("%d",&tt);
        while (tt --){
                scanf("%d%d",&n,&m);
                int maxm = 0;
                for (int i = 0;i < n;i ++) {
                        scanf("%d",&a[i]);
                        maxm = max(maxm,a[i]);
                }
                LL l = 0, r = (LL)maxm * (LL)m;
                while (l < r){
                        LL mid = (l + r) / 2;
                        int t = solve(mid);
                        if (t >= 0) r = mid;
                        else l = mid + 1;
                }
                int ans = solve(r);
                //cout << "r : " << r  << " ans: " << ans << endl;
                printf("Case #%d: %d\n",++ca, ans + 1);
        }
}
