#include <algorithm>
#include <queue>
#include <cstring>
#include <stdio.h>
#include <iostream>
using namespace std;

typedef long long LL;

struct Node{
        LL x,y,id;
} a[3010];

int ans[3010],n;

int solve(int x,int y){
        LL x1 = a[x].x;
        LL y1 = a[x].y;
        LL x2 = a[y].x;
        LL y2 = a[y].y;

        int cnt1 = 0, cnt2 = 0;
        for (int i = 0;i < n;i ++){
                LL t = (LL)(a[i].x - x1) * (y2 - y1) - (LL)(a[i].y - y1) * (x2 - x1);
                if (t > 0) cnt1 ++;
                else if (t < 0) cnt2 ++;
        }
        //cout << x << ' ' << y << ' ' << cnt1 << ' ' << cnt2 << endl;
        return min(cnt1, cnt2);
}

int main(){
        int tt,ca = 0;
        scanf("%d",&tt);
        while (tt --){
                scanf("%d",&n);
                for (int i = 0;i < n;i ++) {
                        scanf("%lld%lld",&a[i].x , &a[i].y);
                        a[i].id = i;
                }
                memset(ans,0x3f,sizeof(ans));
                for (int i = 0;i < n;i ++){
                        for (int j = 0;j < n;j ++){
                                if (i == j) continue;
                                ans[i] = min(ans[i],solve(i,j));
                        }
                }

                printf("Case #%d:\n",++ca);
                if (n == 1) printf("0\n");
                else for (int i = 0;i < n;i ++) printf("%d\n",ans[i]);
        }
}
